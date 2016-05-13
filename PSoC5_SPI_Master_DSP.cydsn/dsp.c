/*******************************************************************************
* File Name: dsp.c
*
* Version: 1.0
* Author: Lukas Creutzburg
*
* Description:
*   Component sends data via SPI as Master
*   Can send arrays
*
*******************************************************************************/

#include "dsp.h"

uint8 e2prom_hex[E2PROM_HEX_SIZE] = { 0x01 , 0x00 , 0x05 , 0x00 , 0x08 , 0x1C , 0x00 , 0x58 ,
                                      0x03 , 0x03 , 0x03 , 0x03 , 0x03 , 0x03 , 0x03 , 0x03 ,
                                      0x03 , 0x03 , 0x03 , 0x03 , 0x03 , 0x03 , 0x03 , 0x03 ,
                                      0x03 , 0x03 , 0x01 , 0x00 , 0x23 , 0x00 , 0x08 , 0x00 ,
                                      0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 ,
                                      0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 ,
                                      0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 ,
                                      0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 ,
                                      0x01 , 0x00 , 0x0B , 0x00 , 0x00 , 0x00 , 0x00 , 0x80 ,
                                      0x00 , 0x00 , 0x00 , 0x80 , 0x00 , 0x00 , 0x01 , 0x01 ,
                                      0x43 , 0x00 , 0x04 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 ,
                                      0x01 , 0x00 , 0x00 , 0x00 , 0xE8 , 0x01 , 0x00 , 0x00 ,
                                      0x00 , 0x00 , 0x01 , 0x00 , 0x08 , 0x00 , 0xE8 , 0x01 ,
                                      0x00 , 0x02 , 0x00 , 0x20 , 0x01 , 0x00 , 0x10 , 0x00 ,
                                      0xE2 , 0x01 , 0x00 , 0x00 , 0x00 , 0x00 , 0x01 , 0x00 ,
                                      0x0A , 0x01 , 0x20 , 0x01 , 0x00 , 0x18 , 0x00 , 0xE2 ,
                                      0x01 , 0x00 , 0x00 , 0x00 , 0x00 , 0x01 , 0x00 , 0x11 ,
                                      0x08 , 0x20 , 0x01 , 0xFF , 0x68 , 0x00 , 0x02 , 0x01 ,
                                      0x00 , 0x19 , 0x08 , 0x20 , 0x01 , 0xFF , 0x70 , 0x00 ,
                                      0x02 , 0x01 , 0x00 , 0x00 , 0x00 , 0x00 , 0x01 , 0x00 ,
                                      0x00 , 0x00 , 0x00 , 0x01 , 0x00 , 0x00 , 0x00 , 0x00 ,
                                      0x01 , 0x00 , 0x00 , 0x00 , 0x00 , 0x01 , 0x00 , 0x00 ,
                                      0x00 , 0x00 , 0x01 , 0x00 , 0x00 , 0x00 , 0x00 , 0x01 ,
                                      0x00 , 0x00 , 0x00 , 0x00 , 0x01 , 0x00 , 0x00 , 0x00 ,
                                      0x00 , 0x01 , 0x00 , 0x00 , 0x00 , 0x00 , 0x01 , 0x00 ,
                                      0x00 , 0x00 , 0x00 , 0x01 , 0x00 , 0x00 , 0x00 , 0x00 ,
                                      0x01 , 0x00 , 0x00 , 0x00 , 0x00 , 0x01 , 0x00 , 0x00 ,
                                      0x00 , 0x00 , 0x01 , 0x00 , 0x00 , 0x00 , 0x00 , 0x01 ,
                                      0x00 , 0x00 , 0x00 , 0x00 , 0x01 , 0x00 , 0x00 , 0x00 ,
                                      0x00 , 0x01 , 0x00 , 0x00 , 0x00 , 0x00 , 0x01 , 0x00 ,
                                      0x00 , 0x00 , 0x00 , 0x01 , 0x00 , 0x00 , 0x00 , 0x00 ,
                                      0x01 , 0x00 , 0x00 , 0x00 , 0x00 , 0x01 , 0x00 , 0x00 ,
                                      0x00 , 0x00 , 0x01 , 0x00 , 0x00 , 0x00 , 0x00 , 0x01 ,
                                      0x00 , 0x00 , 0x00 , 0x00 , 0x01 , 0x00 , 0x00 , 0x00 ,
                                      0x00 , 0x01 , 0x00 , 0x00 , 0x00 , 0x00 , 0x01 , 0x00 ,
                                      0x00 , 0x00 , 0x00 , 0x01 , 0x00 , 0x00 , 0x00 , 0x00 ,
                                      0x01 , 0x00 , 0x00 , 0x00 , 0x00 , 0x01 , 0x00 , 0x00 ,
                                      0x00 , 0x00 , 0x01 , 0x00 , 0x00 , 0x00 , 0x00 , 0x01 ,
                                      0x00 , 0x00 , 0x00 , 0x00 , 0x01 , 0x00 , 0x00 , 0x00 ,
                                      0x00 , 0x01 , 0x00 , 0x00 , 0x00 , 0x00 , 0x01 , 0x00 ,
                                      0x00 , 0x00 , 0x00 , 0x01 , 0x00 , 0x00 , 0x00 , 0x00 ,
                                      0x01 , 0x00 , 0x00 , 0x00 , 0x00 , 0x01 , 0x00 , 0x00 ,
                                      0x00 , 0x00 , 0x01 , 0x00 , 0x00 , 0x00 , 0x00 , 0x01 ,
                                      0x00 , 0x00 , 0x00 , 0x00 , 0x01 , 0x00 , 0x00 , 0x00 ,
                                      0x00 , 0x01 , 0x00 , 0x00 , 0x00 , 0x00 , 0x01 , 0x00 ,
                                      0x00 , 0x00 , 0x00 , 0x01 , 0x00 , 0x00 , 0x00 , 0x00 ,
                                      0x01 , 0x00 , 0x00 , 0x00 , 0x00 , 0x01 , 0x00 , 0x00 ,
                                      0x00 , 0x00 , 0x01 , 0x00 , 0x00 , 0x00 , 0x00 , 0x01 ,
                                      0x00 , 0x00 , 0x00 , 0x00 , 0x01 , 0x00 , 0x00 , 0x00 ,
                                      0x00 , 0x01 , 0x00 , 0x00 , 0x00 , 0x00 , 0x01 , 0x00 ,
                                      0x00 , 0x00 , 0x00 , 0x01 , 0x01 , 0x00 , 0x05 , 0x00 ,
                                      0x08 , 0x1C , 0x00 , 0x1C , 0x01 , 0x00 , 0x04 , 0x00 ,
                                      0x08 , 0x1D , 0x08 , 0x01 , 0x00 , 0x05 , 0x00 , 0x08 ,
                                      0x1E , 0x00 , 0x00 , 0x01 , 0x00 , 0x04 , 0x00 , 0x08 ,
                                      0x1F , 0x00 , 0x01 , 0x00 , 0x06 , 0x00 , 0x08 , 0x20 ,
                                      0x00 , 0x00 , 0x00 , 0x01 , 0x00 , 0x06 , 0x00 , 0x08 ,
                                      0x21 , 0x00 , 0x00 , 0x00 , 0x01 , 0x00 , 0x05 , 0x00 ,
                                      0x08 , 0x22 , 0x00 , 0x00 , 0x01 , 0x00 , 0x05 , 0x00 ,
                                      0x08 , 0x23 , 0x00 , 0x00 , 0x01 , 0x00 , 0x05 , 0x00 ,
                                      0x08 , 0x24 , 0x80 , 0x00 , 0x01 , 0x00 , 0x05 , 0x00 ,
                                      0x08 , 0x25 , 0x00 , 0x00 , 0x01 , 0x00 , 0x05 , 0x00 ,
                                      0x08 , 0x26 , 0x00 , 0x00 , 0x01 , 0x00 , 0x05 , 0x00 ,
                                      0x08 , 0x27 , 0x00 , 0x01 , 0x01 , 0x00 , 0x05 , 0x00 ,
                                      0x08 , 0x1C , 0x00 , 0x1C , 0x06 , 0x00 , 0x00 , 0x00 ,
                                      0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 ,
                                      0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 ,
                                      0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 ,
                                      0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00
                                    };

/*******************************************************************************
* Function Name: DSPinit
********************************************************************************
*
* Summary:
*  Initialize communication
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void DSPinit()
{
    /* SPI intialisieren */
    SPIinit();
    
    /* Umschalten des DSP von I2C auf SPI (3 mal dummy senden) */
    SPIsendNumber((uint16)0x01);
    SPIsendNumber((uint16)0x01);
    SPIsendNumber((uint16)0x01);
    CyDelay(10);
    
    /* Schreiben des EEPROM zu Beginn */
    uint16 sendArray[2];
    uint16 address = 0;
    int i;
    for(i=0;i<E2PROM_HEX_SIZE;i++)
    {
        sendArray[0] = (CHIPADDRESS << 8) | (address >> 8);
        //sendArray[1] = (address << 8) | ()
    }
}

/*******************************************************************************
* Function Name: writeDSP
********************************************************************************
*
* Summary:
*  Sending data to DSP
*
* Parameters:
*  uint16 number
*
* Return:
*  None.
*
*******************************************************************************/
//void SPIsendNumber(uint16 number)
//{
//
//    /* Clear the transmit buffer before next reading (good practice) */
//    SPIM_ClearTxBuffer();
//
//    temp = SPIM_ReadTxStatus();
//
//    /* Ensure that previous SPI read is done, or SPI is idle before sending data */
//    if((temp & (SPIM_STS_SPI_DONE | SPIM_STS_SPI_IDLE)))
//    {
//        SPIM_WriteTxData(number);
//    }
//}


/*******************************************************************************
* Function Name: SPIsendArray
********************************************************************************
*
* Summary:
*  Sending an Array via SPI as Master
*
* Parameters:
*  uint8 numbers[]
*
* Return:
*  None.
*
*******************************************************************************/
//void SPIsendArray(uint16 numbers[])
//{
//
//    /* Clear the transmit buffer before next reading (good practice) */
//    SPIM_ClearTxBuffer();
//
//    temp = SPIM_ReadTxStatus();
//
//    /* Ensure that previous SPI read is done, or SPI is idle before sending data */
//    if((temp & (SPIM_STS_SPI_DONE | SPIM_STS_SPI_IDLE)))
//    {
//        SPIM_PutArray(numbers,2);
//    }
//}


/* [] END OF FILE */