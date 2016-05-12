/*******************************************************************************
* File Name: I2CS_INT.c
* Version 3.50
*
* Description:
*  This file provides the source code of Interrupt Service Routine (ISR)
*  for the I2C component.
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "I2CS_PVT.h"
#include "cyapicallbacks.h"


/*******************************************************************************
*  Place your includes, defines and code here.
********************************************************************************/
/* `#START I2CS_ISR_intc` */

/* `#END` */


/*******************************************************************************
* Function Name: I2CS_ISR
********************************************************************************
*
* Summary:
*  The handler for the I2C interrupt. The slave and master operations are
*  handled here.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Reentrant:
*  No.
*
*******************************************************************************/
CY_ISR(I2CS_ISR)
{
#if (I2CS_MODE_SLAVE_ENABLED)
   uint8  tmp8;
#endif  /* (I2CS_MODE_SLAVE_ENABLED) */

    uint8  tmpCsr;
    
#ifdef I2CS_ISR_ENTRY_CALLBACK
    I2CS_ISR_EntryCallback();
#endif /* I2CS_ISR_ENTRY_CALLBACK */
    

#if(I2CS_TIMEOUT_FF_ENABLED)
    if(0u != I2CS_TimeoutGetStatus())
    {
        I2CS_TimeoutReset();
        I2CS_state = I2CS_SM_EXIT_IDLE;
        /* I2CS_CSR_REG should be cleared after reset */
    }
#endif /* (I2CS_TIMEOUT_FF_ENABLED) */


    tmpCsr = I2CS_CSR_REG;      /* Make copy as interrupts clear */

#if(I2CS_MODE_MULTI_MASTER_SLAVE_ENABLED)
    if(I2CS_CHECK_START_GEN(I2CS_MCSR_REG))
    {
        I2CS_CLEAR_START_GEN;

        /* Set transfer complete and error flags */
        I2CS_mstrStatus |= (I2CS_MSTAT_ERR_XFER |
                                        I2CS_GET_MSTAT_CMPLT);

        /* Slave was addressed */
        I2CS_state = I2CS_SM_SLAVE;
    }
#endif /* (I2CS_MODE_MULTI_MASTER_SLAVE_ENABLED) */


#if(I2CS_MODE_MULTI_MASTER_ENABLED)
    if(I2CS_CHECK_LOST_ARB(tmpCsr))
    {
        /* Set errors */
        I2CS_mstrStatus |= (I2CS_MSTAT_ERR_XFER     |
                                        I2CS_MSTAT_ERR_ARB_LOST |
                                        I2CS_GET_MSTAT_CMPLT);

        I2CS_DISABLE_INT_ON_STOP; /* Interrupt on Stop is enabled by write */

        #if(I2CS_MODE_MULTI_MASTER_SLAVE_ENABLED)
            if(I2CS_CHECK_ADDRESS_STS(tmpCsr))
            {
                /* Slave was addressed */
                I2CS_state = I2CS_SM_SLAVE;
            }
            else
            {
                I2CS_BUS_RELEASE;

                I2CS_state = I2CS_SM_EXIT_IDLE;
            }
        #else
            I2CS_BUS_RELEASE;

            I2CS_state = I2CS_SM_EXIT_IDLE;

        #endif /* (I2CS_MODE_MULTI_MASTER_SLAVE_ENABLED) */
    }
#endif /* (I2CS_MODE_MULTI_MASTER_ENABLED) */

    /* Check for master operation mode */
    if(I2CS_CHECK_SM_MASTER)
    {
    #if(I2CS_MODE_MASTER_ENABLED)
        if(I2CS_CHECK_BYTE_COMPLETE(tmpCsr))
        {
            switch (I2CS_state)
            {
            case I2CS_SM_MSTR_WR_ADDR:  /* After address is sent, write data */
            case I2CS_SM_MSTR_RD_ADDR:  /* After address is sent, read data */

                tmpCsr &= ((uint8) ~I2CS_CSR_STOP_STATUS); /* Clear Stop bit history on address phase */

                if(I2CS_CHECK_ADDR_ACK(tmpCsr))
                {
                    /* Setup for transmit or receive of data */
                    if(I2CS_state == I2CS_SM_MSTR_WR_ADDR)   /* TRANSMIT data */
                    {
                        /* Check if at least one byte to transfer */
                        if(I2CS_mstrWrBufSize > 0u)
                        {
                            /* Load the 1st data byte */
                            I2CS_DATA_REG = I2CS_mstrWrBufPtr[0u];
                            I2CS_TRANSMIT_DATA;
                            I2CS_mstrWrBufIndex = 1u;   /* Set index to 2nd element */

                            /* Set transmit state until done */
                            I2CS_state = I2CS_SM_MSTR_WR_DATA;
                        }
                        /* End of buffer: complete writing */
                        else if(I2CS_CHECK_NO_STOP(I2CS_mstrControl))
                        {
                            /* Set write complete and master halted */
                            I2CS_mstrStatus |= (I2CS_MSTAT_XFER_HALT |
                                                            I2CS_MSTAT_WR_CMPLT);

                            I2CS_state = I2CS_SM_MSTR_HALT; /* Expect ReStart */
                            I2CS_DisableInt();
                        }
                        else
                        {
                            I2CS_ENABLE_INT_ON_STOP; /* Enable interrupt on Stop, to catch it */
                            I2CS_GENERATE_STOP;
                        }
                    }
                    else  /* Master receive data */
                    {
                        I2CS_READY_TO_READ; /* Release bus to read data */

                        I2CS_state  = I2CS_SM_MSTR_RD_DATA;
                    }
                }
                /* Address is NACKed */
                else if(I2CS_CHECK_ADDR_NAK(tmpCsr))
                {
                    /* Set Address NAK error */
                    I2CS_mstrStatus |= (I2CS_MSTAT_ERR_XFER |
                                                    I2CS_MSTAT_ERR_ADDR_NAK);

                    if(I2CS_CHECK_NO_STOP(I2CS_mstrControl))
                    {
                        I2CS_mstrStatus |= (I2CS_MSTAT_XFER_HALT |
                                                        I2CS_GET_MSTAT_CMPLT);

                        I2CS_state = I2CS_SM_MSTR_HALT; /* Expect RESTART */
                        I2CS_DisableInt();
                    }
                    else  /* Do normal Stop */
                    {
                        I2CS_ENABLE_INT_ON_STOP; /* Enable interrupt on Stop, to catch it */
                        I2CS_GENERATE_STOP;
                    }
                }
                else
                {
                    /* Address phase is not set for some reason: error */
                    #if(I2CS_TIMEOUT_ENABLED)
                        /* Exit interrupt to take chance for timeout timer to handle this case */
                        I2CS_DisableInt();
                        I2CS_ClearPendingInt();
                    #else
                        /* Block execution flow: unexpected condition */
                        CYASSERT(0u != 0u);
                    #endif /* (I2CS_TIMEOUT_ENABLED) */
                }
                break;

            case I2CS_SM_MSTR_WR_DATA:

                if(I2CS_CHECK_DATA_ACK(tmpCsr))
                {
                    /* Check if end of buffer */
                    if(I2CS_mstrWrBufIndex  < I2CS_mstrWrBufSize)
                    {
                        I2CS_DATA_REG =
                                                 I2CS_mstrWrBufPtr[I2CS_mstrWrBufIndex];
                        I2CS_TRANSMIT_DATA;
                        I2CS_mstrWrBufIndex++;
                    }
                    /* End of buffer: complete writing */
                    else if(I2CS_CHECK_NO_STOP(I2CS_mstrControl))
                    {
                        /* Set write complete and master halted */
                        I2CS_mstrStatus |= (I2CS_MSTAT_XFER_HALT |
                                                        I2CS_MSTAT_WR_CMPLT);

                        I2CS_state = I2CS_SM_MSTR_HALT;    /* Expect restart */
                        I2CS_DisableInt();
                    }
                    else  /* Do normal Stop */
                    {
                        I2CS_ENABLE_INT_ON_STOP;    /* Enable interrupt on Stop, to catch it */
                        I2CS_GENERATE_STOP;
                    }
                }
                /* Last byte NAKed: end writing */
                else if(I2CS_CHECK_NO_STOP(I2CS_mstrControl))
                {
                    /* Set write complete, short transfer and master halted */
                    I2CS_mstrStatus |= (I2CS_MSTAT_ERR_XFER       |
                                                    I2CS_MSTAT_ERR_SHORT_XFER |
                                                    I2CS_MSTAT_XFER_HALT      |
                                                    I2CS_MSTAT_WR_CMPLT);

                    I2CS_state = I2CS_SM_MSTR_HALT;    /* Expect ReStart */
                    I2CS_DisableInt();
                }
                else  /* Do normal Stop */
                {
                    I2CS_ENABLE_INT_ON_STOP;    /* Enable interrupt on Stop, to catch it */
                    I2CS_GENERATE_STOP;

                    /* Set short transfer and error flag */
                    I2CS_mstrStatus |= (I2CS_MSTAT_ERR_SHORT_XFER |
                                                    I2CS_MSTAT_ERR_XFER);
                }

                break;

            case I2CS_SM_MSTR_RD_DATA:

                I2CS_mstrRdBufPtr[I2CS_mstrRdBufIndex] = I2CS_DATA_REG;
                I2CS_mstrRdBufIndex++;

                /* Check if end of buffer */
                if(I2CS_mstrRdBufIndex < I2CS_mstrRdBufSize)
                {
                    I2CS_ACK_AND_RECEIVE;       /* ACK and receive byte */
                }
                /* End of buffer: complete reading */
                else if(I2CS_CHECK_NO_STOP(I2CS_mstrControl))
                {
                    /* Set read complete and master halted */
                    I2CS_mstrStatus |= (I2CS_MSTAT_XFER_HALT |
                                                    I2CS_MSTAT_RD_CMPLT);

                    I2CS_state = I2CS_SM_MSTR_HALT;    /* Expect ReStart */
                    I2CS_DisableInt();
                }
                else
                {
                    I2CS_ENABLE_INT_ON_STOP;
                    I2CS_NAK_AND_RECEIVE;       /* NACK and TRY to generate Stop */
                }
                break;

            default: /* This is an invalid state and should not occur */

            #if(I2CS_TIMEOUT_ENABLED)
                /* Exit interrupt to take chance for timeout timer to handles this case */
                I2CS_DisableInt();
                I2CS_ClearPendingInt();
            #else
                /* Block execution flow: unexpected condition */
                CYASSERT(0u != 0u);
            #endif /* (I2CS_TIMEOUT_ENABLED) */

                break;
            }
        }

        /* Catches Stop: end of transaction */
        if(I2CS_CHECK_STOP_STS(tmpCsr))
        {
            I2CS_mstrStatus |= I2CS_GET_MSTAT_CMPLT;

            I2CS_DISABLE_INT_ON_STOP;
            I2CS_state = I2CS_SM_IDLE;
        }
    #endif /* (I2CS_MODE_MASTER_ENABLED) */
    }
    else if(I2CS_CHECK_SM_SLAVE)
    {
    #if(I2CS_MODE_SLAVE_ENABLED)

        if((I2CS_CHECK_STOP_STS(tmpCsr)) || /* Stop || Restart */
           (I2CS_CHECK_BYTE_COMPLETE(tmpCsr) && I2CS_CHECK_ADDRESS_STS(tmpCsr)))
        {
            /* Catch end of master write transaction: use interrupt on Stop */
            /* The Stop bit history on address phase does not have correct state */
            if(I2CS_SM_SL_WR_DATA == I2CS_state)
            {
                I2CS_DISABLE_INT_ON_STOP;

                I2CS_slStatus &= ((uint8) ~I2CS_SSTAT_WR_BUSY);
                I2CS_slStatus |= ((uint8)  I2CS_SSTAT_WR_CMPLT);

                I2CS_state = I2CS_SM_IDLE;
            }
        }

        if(I2CS_CHECK_BYTE_COMPLETE(tmpCsr))
        {
            /* The address only issued after Start or ReStart: so check the address
               to catch these events:
                FF : sets an address phase with a byte_complete interrupt trigger.
                UDB: sets an address phase immediately after Start or ReStart. */
            if(I2CS_CHECK_ADDRESS_STS(tmpCsr))
            {
            /* Check for software address detection */
            #if(I2CS_SW_ADRR_DECODE)
                tmp8 = I2CS_GET_SLAVE_ADDR(I2CS_DATA_REG);

                if(tmp8 == I2CS_slAddress)   /* Check for address match */
                {
                    if(0u != (I2CS_DATA_REG & I2CS_READ_FLAG))
                    {
                        /* Place code to prepare read buffer here                  */
                        /* `#START I2CS_SW_PREPARE_READ_BUF_interrupt` */

                        /* `#END` */

                    #ifdef I2CS_SW_PREPARE_READ_BUF_CALLBACK
                        I2CS_SwPrepareReadBuf_Callback();
                    #endif /* I2CS_SW_PREPARE_READ_BUF_CALLBACK */
                        
                        /* Prepare next operation to read, get data and place in data register */
                        if(I2CS_slRdBufIndex < I2CS_slRdBufSize)
                        {
                            /* Load first data byte from array */
                            I2CS_DATA_REG = I2CS_slRdBufPtr[I2CS_slRdBufIndex];
                            I2CS_ACK_AND_TRANSMIT;
                            I2CS_slRdBufIndex++;

                            I2CS_slStatus |= I2CS_SSTAT_RD_BUSY;
                        }
                        else    /* Overflow: provide 0xFF on bus */
                        {
                            I2CS_DATA_REG = I2CS_OVERFLOW_RETURN;
                            I2CS_ACK_AND_TRANSMIT;

                            I2CS_slStatus  |= (I2CS_SSTAT_RD_BUSY |
                                                           I2CS_SSTAT_RD_ERR_OVFL);
                        }

                        I2CS_state = I2CS_SM_SL_RD_DATA;
                    }
                    else  /* Write transaction: receive 1st byte */
                    {
                        I2CS_ACK_AND_RECEIVE;
                        I2CS_state = I2CS_SM_SL_WR_DATA;

                        I2CS_slStatus |= I2CS_SSTAT_WR_BUSY;
                        I2CS_ENABLE_INT_ON_STOP;
                    }
                }
                else
                {
                    /*     Place code to compare for additional address here    */
                    /* `#START I2CS_SW_ADDR_COMPARE_interruptStart` */

                    /* `#END` */

                #ifdef I2CS_SW_ADDR_COMPARE_ENTRY_CALLBACK
                    I2CS_SwAddrCompare_EntryCallback();
                #endif /* I2CS_SW_ADDR_COMPARE_ENTRY_CALLBACK */
                    
                    I2CS_NAK_AND_RECEIVE;   /* NACK address */

                    /* Place code to end of condition for NACK generation here */
                    /* `#START I2CS_SW_ADDR_COMPARE_interruptEnd`  */

                    /* `#END` */

                #ifdef I2CS_SW_ADDR_COMPARE_EXIT_CALLBACK
                    I2CS_SwAddrCompare_ExitCallback();
                #endif /* I2CS_SW_ADDR_COMPARE_EXIT_CALLBACK */
                }

            #else /* (I2CS_HW_ADRR_DECODE) */

                if(0u != (I2CS_DATA_REG & I2CS_READ_FLAG))
                {
                    /* Place code to prepare read buffer here                  */
                    /* `#START I2CS_HW_PREPARE_READ_BUF_interrupt` */

                    /* `#END` */
                    
                #ifdef I2CS_HW_PREPARE_READ_BUF_CALLBACK
                    I2CS_HwPrepareReadBuf_Callback();
                #endif /* I2CS_HW_PREPARE_READ_BUF_CALLBACK */

                    /* Prepare next operation to read, get data and place in data register */
                    if(I2CS_slRdBufIndex < I2CS_slRdBufSize)
                    {
                        /* Load first data byte from array */
                        I2CS_DATA_REG = I2CS_slRdBufPtr[I2CS_slRdBufIndex];
                        I2CS_ACK_AND_TRANSMIT;
                        I2CS_slRdBufIndex++;

                        I2CS_slStatus |= I2CS_SSTAT_RD_BUSY;
                    }
                    else    /* Overflow: provide 0xFF on bus */
                    {
                        I2CS_DATA_REG = I2CS_OVERFLOW_RETURN;
                        I2CS_ACK_AND_TRANSMIT;

                        I2CS_slStatus  |= (I2CS_SSTAT_RD_BUSY |
                                                       I2CS_SSTAT_RD_ERR_OVFL);
                    }

                    I2CS_state = I2CS_SM_SL_RD_DATA;
                }
                else  /* Write transaction: receive 1st byte */
                {
                    I2CS_ACK_AND_RECEIVE;
                    I2CS_state = I2CS_SM_SL_WR_DATA;

                    I2CS_slStatus |= I2CS_SSTAT_WR_BUSY;
                    I2CS_ENABLE_INT_ON_STOP;
                }

            #endif /* (I2CS_SW_ADRR_DECODE) */
            }
            /* Data states */
            /* Data master writes into slave */
            else if(I2CS_state == I2CS_SM_SL_WR_DATA)
            {
                if(I2CS_slWrBufIndex < I2CS_slWrBufSize)
                {
                    tmp8 = I2CS_DATA_REG;
                    I2CS_ACK_AND_RECEIVE;
                    I2CS_slWrBufPtr[I2CS_slWrBufIndex] = tmp8;
                    I2CS_slWrBufIndex++;
                }
                else  /* of array: complete write, send NACK */
                {
                    I2CS_NAK_AND_RECEIVE;

                    I2CS_slStatus |= I2CS_SSTAT_WR_ERR_OVFL;
                }
            }
            /* Data master reads from slave */
            else if(I2CS_state == I2CS_SM_SL_RD_DATA)
            {
                if(I2CS_CHECK_DATA_ACK(tmpCsr))
                {
                    if(I2CS_slRdBufIndex < I2CS_slRdBufSize)
                    {
                         /* Get data from array */
                        I2CS_DATA_REG = I2CS_slRdBufPtr[I2CS_slRdBufIndex];
                        I2CS_TRANSMIT_DATA;
                        I2CS_slRdBufIndex++;
                    }
                    else   /* Overflow: provide 0xFF on bus */
                    {
                        I2CS_DATA_REG = I2CS_OVERFLOW_RETURN;
                        I2CS_TRANSMIT_DATA;

                        I2CS_slStatus |= I2CS_SSTAT_RD_ERR_OVFL;
                    }
                }
                else  /* Last byte was NACKed: read complete */
                {
                    /* Only NACK appears on bus */
                    I2CS_DATA_REG = I2CS_OVERFLOW_RETURN;
                    I2CS_NAK_AND_TRANSMIT;

                    I2CS_slStatus &= ((uint8) ~I2CS_SSTAT_RD_BUSY);
                    I2CS_slStatus |= ((uint8)  I2CS_SSTAT_RD_CMPLT);

                    I2CS_state = I2CS_SM_IDLE;
                }
            }
            else
            {
            #if(I2CS_TIMEOUT_ENABLED)
                /* Exit interrupt to take chance for timeout timer to handle this case */
                I2CS_DisableInt();
                I2CS_ClearPendingInt();
            #else
                /* Block execution flow: unexpected condition */
                CYASSERT(0u != 0u);
            #endif /* (I2CS_TIMEOUT_ENABLED) */
            }
        }
    #endif /* (I2CS_MODE_SLAVE_ENABLED) */
    }
    else
    {
        /* The FSM skips master and slave processing: return to IDLE */
        I2CS_state = I2CS_SM_IDLE;
    }

#ifdef I2CS_ISR_EXIT_CALLBACK
    I2CS_ISR_ExitCallback();
#endif /* I2CS_ISR_EXIT_CALLBACK */    
}


#if ((I2CS_FF_IMPLEMENTED) && (I2CS_WAKEUP_ENABLED))
    /*******************************************************************************
    * Function Name: I2CS_WAKEUP_ISR
    ********************************************************************************
    *
    * Summary:
    *  The interrupt handler to trigger after a wakeup.
    *
    * Parameters:
    *  None.
    *
    * Return:
    *  None.
    *
    *******************************************************************************/
    CY_ISR(I2CS_WAKEUP_ISR)
    {
    #ifdef I2CS_WAKEUP_ISR_ENTRY_CALLBACK
        I2CS_WAKEUP_ISR_EntryCallback();
    #endif /* I2CS_WAKEUP_ISR_ENTRY_CALLBACK */
         
        /* Set flag to notify that matched address is received */
        I2CS_wakeupSource = 1u;

        /* SCL is stretched until the I2C_Wake() is called */

    #ifdef I2CS_WAKEUP_ISR_EXIT_CALLBACK
        I2CS_WAKEUP_ISR_ExitCallback();
    #endif /* I2CS_WAKEUP_ISR_EXIT_CALLBACK */
    }
#endif /* ((I2CS_FF_IMPLEMENTED) && (I2CS_WAKEUP_ENABLED)) */


/* [] END OF FILE */