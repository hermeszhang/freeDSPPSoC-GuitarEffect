    IF :LNOT::DEF:INCLUDED_CYFITTERRV_INC
INCLUDED_CYFITTERRV_INC EQU 1
    GET cydevicerv.inc
    GET cydevicerv_trm.inc

; SPIS_BSPIS
SPIS_BSPIS_BitCounter__16BIT_CONTROL_AUX_CTL_REG EQU CYREG_B0_UDB10_11_ACTL
SPIS_BSPIS_BitCounter__16BIT_CONTROL_CONTROL_REG EQU CYREG_B0_UDB10_11_CTL
SPIS_BSPIS_BitCounter__16BIT_CONTROL_COUNT_REG EQU CYREG_B0_UDB10_11_CTL
SPIS_BSPIS_BitCounter__16BIT_COUNT_CONTROL_REG EQU CYREG_B0_UDB10_11_CTL
SPIS_BSPIS_BitCounter__16BIT_COUNT_COUNT_REG EQU CYREG_B0_UDB10_11_CTL
SPIS_BSPIS_BitCounter__16BIT_MASK_MASK_REG EQU CYREG_B0_UDB10_11_MSK
SPIS_BSPIS_BitCounter__16BIT_MASK_PERIOD_REG EQU CYREG_B0_UDB10_11_MSK
SPIS_BSPIS_BitCounter__16BIT_PERIOD_MASK_REG EQU CYREG_B0_UDB10_11_MSK
SPIS_BSPIS_BitCounter__16BIT_PERIOD_PERIOD_REG EQU CYREG_B0_UDB10_11_MSK
SPIS_BSPIS_BitCounter__CONTROL_AUX_CTL_REG EQU CYREG_B0_UDB10_ACTL
SPIS_BSPIS_BitCounter__CONTROL_REG EQU CYREG_B0_UDB10_CTL
SPIS_BSPIS_BitCounter__CONTROL_ST_REG EQU CYREG_B0_UDB10_ST_CTL
SPIS_BSPIS_BitCounter__COUNT_REG EQU CYREG_B0_UDB10_CTL
SPIS_BSPIS_BitCounter__COUNT_ST_REG EQU CYREG_B0_UDB10_ST_CTL
SPIS_BSPIS_BitCounter__MASK_CTL_AUX_CTL_REG EQU CYREG_B0_UDB10_MSK_ACTL
SPIS_BSPIS_BitCounter__PER_CTL_AUX_CTL_REG EQU CYREG_B0_UDB10_MSK_ACTL
SPIS_BSPIS_BitCounter__PERIOD_REG EQU CYREG_B0_UDB10_MSK
SPIS_BSPIS_BitCounter_ST__16BIT_STATUS_AUX_CTL_REG EQU CYREG_B0_UDB10_11_ACTL
SPIS_BSPIS_BitCounter_ST__16BIT_STATUS_REG EQU CYREG_B0_UDB10_11_ST
SPIS_BSPIS_BitCounter_ST__MASK_REG EQU CYREG_B0_UDB10_MSK
SPIS_BSPIS_BitCounter_ST__MASK_ST_AUX_CTL_REG EQU CYREG_B0_UDB10_MSK_ACTL
SPIS_BSPIS_BitCounter_ST__PER_ST_AUX_CTL_REG EQU CYREG_B0_UDB10_MSK_ACTL
SPIS_BSPIS_BitCounter_ST__STATUS_AUX_CTL_REG EQU CYREG_B0_UDB10_ACTL
SPIS_BSPIS_BitCounter_ST__STATUS_CNT_REG EQU CYREG_B0_UDB10_ST_CTL
SPIS_BSPIS_BitCounter_ST__STATUS_CONTROL_REG EQU CYREG_B0_UDB10_ST_CTL
SPIS_BSPIS_BitCounter_ST__STATUS_REG EQU CYREG_B0_UDB10_ST
SPIS_BSPIS_RxStsReg__16BIT_STATUS_AUX_CTL_REG EQU CYREG_B0_UDB11_12_ACTL
SPIS_BSPIS_RxStsReg__16BIT_STATUS_REG EQU CYREG_B0_UDB11_12_ST
SPIS_BSPIS_RxStsReg__3__MASK EQU 0x08
SPIS_BSPIS_RxStsReg__3__POS EQU 3
SPIS_BSPIS_RxStsReg__4__MASK EQU 0x10
SPIS_BSPIS_RxStsReg__4__POS EQU 4
SPIS_BSPIS_RxStsReg__5__MASK EQU 0x20
SPIS_BSPIS_RxStsReg__5__POS EQU 5
SPIS_BSPIS_RxStsReg__6__MASK EQU 0x40
SPIS_BSPIS_RxStsReg__6__POS EQU 6
SPIS_BSPIS_RxStsReg__MASK EQU 0x78
SPIS_BSPIS_RxStsReg__MASK_REG EQU CYREG_B0_UDB11_MSK
SPIS_BSPIS_RxStsReg__STATUS_AUX_CTL_REG EQU CYREG_B0_UDB11_ACTL
SPIS_BSPIS_RxStsReg__STATUS_REG EQU CYREG_B0_UDB11_ST
SPIS_BSPIS_sR16_Dp_u0__16BIT_A0_REG EQU CYREG_B0_UDB10_11_A0
SPIS_BSPIS_sR16_Dp_u0__16BIT_A1_REG EQU CYREG_B0_UDB10_11_A1
SPIS_BSPIS_sR16_Dp_u0__16BIT_D0_REG EQU CYREG_B0_UDB10_11_D0
SPIS_BSPIS_sR16_Dp_u0__16BIT_D1_REG EQU CYREG_B0_UDB10_11_D1
SPIS_BSPIS_sR16_Dp_u0__16BIT_DP_AUX_CTL_REG EQU CYREG_B0_UDB10_11_ACTL
SPIS_BSPIS_sR16_Dp_u0__16BIT_F0_REG EQU CYREG_B0_UDB10_11_F0
SPIS_BSPIS_sR16_Dp_u0__16BIT_F1_REG EQU CYREG_B0_UDB10_11_F1
SPIS_BSPIS_sR16_Dp_u0__A0_A1_REG EQU CYREG_B0_UDB10_A0_A1
SPIS_BSPIS_sR16_Dp_u0__A0_REG EQU CYREG_B0_UDB10_A0
SPIS_BSPIS_sR16_Dp_u0__A1_REG EQU CYREG_B0_UDB10_A1
SPIS_BSPIS_sR16_Dp_u0__D0_D1_REG EQU CYREG_B0_UDB10_D0_D1
SPIS_BSPIS_sR16_Dp_u0__D0_REG EQU CYREG_B0_UDB10_D0
SPIS_BSPIS_sR16_Dp_u0__D1_REG EQU CYREG_B0_UDB10_D1
SPIS_BSPIS_sR16_Dp_u0__DP_AUX_CTL_REG EQU CYREG_B0_UDB10_ACTL
SPIS_BSPIS_sR16_Dp_u0__F0_F1_REG EQU CYREG_B0_UDB10_F0_F1
SPIS_BSPIS_sR16_Dp_u0__F0_REG EQU CYREG_B0_UDB10_F0
SPIS_BSPIS_sR16_Dp_u0__F1_REG EQU CYREG_B0_UDB10_F1
SPIS_BSPIS_sR16_Dp_u0__MSK_DP_AUX_CTL_REG EQU CYREG_B0_UDB10_MSK_ACTL
SPIS_BSPIS_sR16_Dp_u0__PER_DP_AUX_CTL_REG EQU CYREG_B0_UDB10_MSK_ACTL
SPIS_BSPIS_sR16_Dp_u1__16BIT_A0_REG EQU CYREG_B0_UDB11_12_A0
SPIS_BSPIS_sR16_Dp_u1__16BIT_A1_REG EQU CYREG_B0_UDB11_12_A1
SPIS_BSPIS_sR16_Dp_u1__16BIT_D0_REG EQU CYREG_B0_UDB11_12_D0
SPIS_BSPIS_sR16_Dp_u1__16BIT_D1_REG EQU CYREG_B0_UDB11_12_D1
SPIS_BSPIS_sR16_Dp_u1__16BIT_DP_AUX_CTL_REG EQU CYREG_B0_UDB11_12_ACTL
SPIS_BSPIS_sR16_Dp_u1__16BIT_F0_REG EQU CYREG_B0_UDB11_12_F0
SPIS_BSPIS_sR16_Dp_u1__16BIT_F1_REG EQU CYREG_B0_UDB11_12_F1
SPIS_BSPIS_sR16_Dp_u1__A0_A1_REG EQU CYREG_B0_UDB11_A0_A1
SPIS_BSPIS_sR16_Dp_u1__A0_REG EQU CYREG_B0_UDB11_A0
SPIS_BSPIS_sR16_Dp_u1__A1_REG EQU CYREG_B0_UDB11_A1
SPIS_BSPIS_sR16_Dp_u1__D0_D1_REG EQU CYREG_B0_UDB11_D0_D1
SPIS_BSPIS_sR16_Dp_u1__D0_REG EQU CYREG_B0_UDB11_D0
SPIS_BSPIS_sR16_Dp_u1__D1_REG EQU CYREG_B0_UDB11_D1
SPIS_BSPIS_sR16_Dp_u1__DP_AUX_CTL_REG EQU CYREG_B0_UDB11_ACTL
SPIS_BSPIS_sR16_Dp_u1__F0_F1_REG EQU CYREG_B0_UDB11_F0_F1
SPIS_BSPIS_sR16_Dp_u1__F0_REG EQU CYREG_B0_UDB11_F0
SPIS_BSPIS_sR16_Dp_u1__F1_REG EQU CYREG_B0_UDB11_F1
SPIS_BSPIS_TxStsReg__0__MASK EQU 0x01
SPIS_BSPIS_TxStsReg__0__POS EQU 0
SPIS_BSPIS_TxStsReg__1__MASK EQU 0x02
SPIS_BSPIS_TxStsReg__1__POS EQU 1
SPIS_BSPIS_TxStsReg__16BIT_STATUS_AUX_CTL_REG EQU CYREG_B0_UDB12_13_ACTL
SPIS_BSPIS_TxStsReg__16BIT_STATUS_REG EQU CYREG_B0_UDB12_13_ST
SPIS_BSPIS_TxStsReg__2__MASK EQU 0x04
SPIS_BSPIS_TxStsReg__2__POS EQU 2
SPIS_BSPIS_TxStsReg__6__MASK EQU 0x40
SPIS_BSPIS_TxStsReg__6__POS EQU 6
SPIS_BSPIS_TxStsReg__MASK EQU 0x47
SPIS_BSPIS_TxStsReg__MASK_REG EQU CYREG_B0_UDB12_MSK
SPIS_BSPIS_TxStsReg__STATUS_AUX_CTL_REG EQU CYREG_B0_UDB12_ACTL
SPIS_BSPIS_TxStsReg__STATUS_REG EQU CYREG_B0_UDB12_ST

; SPIS_IntClock
SPIS_IntClock__CFG0 EQU CYREG_CLKDIST_DCFG0_CFG0
SPIS_IntClock__CFG1 EQU CYREG_CLKDIST_DCFG0_CFG1
SPIS_IntClock__CFG2 EQU CYREG_CLKDIST_DCFG0_CFG2
SPIS_IntClock__CFG2_SRC_SEL_MASK EQU 0x07
SPIS_IntClock__INDEX EQU 0x00
SPIS_IntClock__PM_ACT_CFG EQU CYREG_PM_ACT_CFG2
SPIS_IntClock__PM_ACT_MSK EQU 0x01
SPIS_IntClock__PM_STBY_CFG EQU CYREG_PM_STBY_CFG2
SPIS_IntClock__PM_STBY_MSK EQU 0x01

; SS_1
SS_1__0__INTTYPE EQU CYREG_PICU3_INTTYPE3
SS_1__0__MASK EQU 0x08
SS_1__0__PC EQU CYREG_PRT3_PC3
SS_1__0__PORT EQU 3
SS_1__0__SHIFT EQU 3
SS_1__AG EQU CYREG_PRT3_AG
SS_1__AMUX EQU CYREG_PRT3_AMUX
SS_1__BIE EQU CYREG_PRT3_BIE
SS_1__BIT_MASK EQU CYREG_PRT3_BIT_MASK
SS_1__BYP EQU CYREG_PRT3_BYP
SS_1__CTL EQU CYREG_PRT3_CTL
SS_1__DM0 EQU CYREG_PRT3_DM0
SS_1__DM1 EQU CYREG_PRT3_DM1
SS_1__DM2 EQU CYREG_PRT3_DM2
SS_1__DR EQU CYREG_PRT3_DR
SS_1__INP_DIS EQU CYREG_PRT3_INP_DIS
SS_1__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU3_BASE
SS_1__LCD_COM_SEG EQU CYREG_PRT3_LCD_COM_SEG
SS_1__LCD_EN EQU CYREG_PRT3_LCD_EN
SS_1__MASK EQU 0x08
SS_1__PORT EQU 3
SS_1__PRT EQU CYREG_PRT3_PRT
SS_1__PRTDSI__CAPS_SEL EQU CYREG_PRT3_CAPS_SEL
SS_1__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT3_DBL_SYNC_IN
SS_1__PRTDSI__OE_SEL0 EQU CYREG_PRT3_OE_SEL0
SS_1__PRTDSI__OE_SEL1 EQU CYREG_PRT3_OE_SEL1
SS_1__PRTDSI__OUT_SEL0 EQU CYREG_PRT3_OUT_SEL0
SS_1__PRTDSI__OUT_SEL1 EQU CYREG_PRT3_OUT_SEL1
SS_1__PRTDSI__SYNC_OUT EQU CYREG_PRT3_SYNC_OUT
SS_1__PS EQU CYREG_PRT3_PS
SS_1__SHIFT EQU 3
SS_1__SLW EQU CYREG_PRT3_SLW

; Dev_ss
Dev_ss__0__INTTYPE EQU CYREG_PICU0_INTTYPE3
Dev_ss__0__MASK EQU 0x08
Dev_ss__0__PC EQU CYREG_PRT0_PC3
Dev_ss__0__PORT EQU 0
Dev_ss__0__SHIFT EQU 3
Dev_ss__AG EQU CYREG_PRT0_AG
Dev_ss__AMUX EQU CYREG_PRT0_AMUX
Dev_ss__BIE EQU CYREG_PRT0_BIE
Dev_ss__BIT_MASK EQU CYREG_PRT0_BIT_MASK
Dev_ss__BYP EQU CYREG_PRT0_BYP
Dev_ss__CTL EQU CYREG_PRT0_CTL
Dev_ss__DM0 EQU CYREG_PRT0_DM0
Dev_ss__DM1 EQU CYREG_PRT0_DM1
Dev_ss__DM2 EQU CYREG_PRT0_DM2
Dev_ss__DR EQU CYREG_PRT0_DR
Dev_ss__INP_DIS EQU CYREG_PRT0_INP_DIS
Dev_ss__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU0_BASE
Dev_ss__LCD_COM_SEG EQU CYREG_PRT0_LCD_COM_SEG
Dev_ss__LCD_EN EQU CYREG_PRT0_LCD_EN
Dev_ss__MASK EQU 0x08
Dev_ss__PORT EQU 0
Dev_ss__PRT EQU CYREG_PRT0_PRT
Dev_ss__PRTDSI__CAPS_SEL EQU CYREG_PRT0_CAPS_SEL
Dev_ss__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT0_DBL_SYNC_IN
Dev_ss__PRTDSI__OE_SEL0 EQU CYREG_PRT0_OE_SEL0
Dev_ss__PRTDSI__OE_SEL1 EQU CYREG_PRT0_OE_SEL1
Dev_ss__PRTDSI__OUT_SEL0 EQU CYREG_PRT0_OUT_SEL0
Dev_ss__PRTDSI__OUT_SEL1 EQU CYREG_PRT0_OUT_SEL1
Dev_ss__PRTDSI__SYNC_OUT EQU CYREG_PRT0_SYNC_OUT
Dev_ss__PS EQU CYREG_PRT0_PS
Dev_ss__SHIFT EQU 3
Dev_ss__SLW EQU CYREG_PRT0_SLW

; MISO_1
MISO_1__0__INTTYPE EQU CYREG_PICU3_INTTYPE0
MISO_1__0__MASK EQU 0x01
MISO_1__0__PC EQU CYREG_PRT3_PC0
MISO_1__0__PORT EQU 3
MISO_1__0__SHIFT EQU 0
MISO_1__AG EQU CYREG_PRT3_AG
MISO_1__AMUX EQU CYREG_PRT3_AMUX
MISO_1__BIE EQU CYREG_PRT3_BIE
MISO_1__BIT_MASK EQU CYREG_PRT3_BIT_MASK
MISO_1__BYP EQU CYREG_PRT3_BYP
MISO_1__CTL EQU CYREG_PRT3_CTL
MISO_1__DM0 EQU CYREG_PRT3_DM0
MISO_1__DM1 EQU CYREG_PRT3_DM1
MISO_1__DM2 EQU CYREG_PRT3_DM2
MISO_1__DR EQU CYREG_PRT3_DR
MISO_1__INP_DIS EQU CYREG_PRT3_INP_DIS
MISO_1__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU3_BASE
MISO_1__LCD_COM_SEG EQU CYREG_PRT3_LCD_COM_SEG
MISO_1__LCD_EN EQU CYREG_PRT3_LCD_EN
MISO_1__MASK EQU 0x01
MISO_1__PORT EQU 3
MISO_1__PRT EQU CYREG_PRT3_PRT
MISO_1__PRTDSI__CAPS_SEL EQU CYREG_PRT3_CAPS_SEL
MISO_1__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT3_DBL_SYNC_IN
MISO_1__PRTDSI__OE_SEL0 EQU CYREG_PRT3_OE_SEL0
MISO_1__PRTDSI__OE_SEL1 EQU CYREG_PRT3_OE_SEL1
MISO_1__PRTDSI__OUT_SEL0 EQU CYREG_PRT3_OUT_SEL0
MISO_1__PRTDSI__OUT_SEL1 EQU CYREG_PRT3_OUT_SEL1
MISO_1__PRTDSI__SYNC_OUT EQU CYREG_PRT3_SYNC_OUT
MISO_1__PS EQU CYREG_PRT3_PS
MISO_1__SHIFT EQU 0
MISO_1__SLW EQU CYREG_PRT3_SLW

; MOSI_1
MOSI_1__0__INTTYPE EQU CYREG_PICU3_INTTYPE1
MOSI_1__0__MASK EQU 0x02
MOSI_1__0__PC EQU CYREG_PRT3_PC1
MOSI_1__0__PORT EQU 3
MOSI_1__0__SHIFT EQU 1
MOSI_1__AG EQU CYREG_PRT3_AG
MOSI_1__AMUX EQU CYREG_PRT3_AMUX
MOSI_1__BIE EQU CYREG_PRT3_BIE
MOSI_1__BIT_MASK EQU CYREG_PRT3_BIT_MASK
MOSI_1__BYP EQU CYREG_PRT3_BYP
MOSI_1__CTL EQU CYREG_PRT3_CTL
MOSI_1__DM0 EQU CYREG_PRT3_DM0
MOSI_1__DM1 EQU CYREG_PRT3_DM1
MOSI_1__DM2 EQU CYREG_PRT3_DM2
MOSI_1__DR EQU CYREG_PRT3_DR
MOSI_1__INP_DIS EQU CYREG_PRT3_INP_DIS
MOSI_1__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU3_BASE
MOSI_1__LCD_COM_SEG EQU CYREG_PRT3_LCD_COM_SEG
MOSI_1__LCD_EN EQU CYREG_PRT3_LCD_EN
MOSI_1__MASK EQU 0x02
MOSI_1__PORT EQU 3
MOSI_1__PRT EQU CYREG_PRT3_PRT
MOSI_1__PRTDSI__CAPS_SEL EQU CYREG_PRT3_CAPS_SEL
MOSI_1__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT3_DBL_SYNC_IN
MOSI_1__PRTDSI__OE_SEL0 EQU CYREG_PRT3_OE_SEL0
MOSI_1__PRTDSI__OE_SEL1 EQU CYREG_PRT3_OE_SEL1
MOSI_1__PRTDSI__OUT_SEL0 EQU CYREG_PRT3_OUT_SEL0
MOSI_1__PRTDSI__OUT_SEL1 EQU CYREG_PRT3_OUT_SEL1
MOSI_1__PRTDSI__SYNC_OUT EQU CYREG_PRT3_SYNC_OUT
MOSI_1__PS EQU CYREG_PRT3_PS
MOSI_1__SHIFT EQU 1
MOSI_1__SLW EQU CYREG_PRT3_SLW

; SCLK_1
SCLK_1__0__INTTYPE EQU CYREG_PICU3_INTTYPE2
SCLK_1__0__MASK EQU 0x04
SCLK_1__0__PC EQU CYREG_PRT3_PC2
SCLK_1__0__PORT EQU 3
SCLK_1__0__SHIFT EQU 2
SCLK_1__AG EQU CYREG_PRT3_AG
SCLK_1__AMUX EQU CYREG_PRT3_AMUX
SCLK_1__BIE EQU CYREG_PRT3_BIE
SCLK_1__BIT_MASK EQU CYREG_PRT3_BIT_MASK
SCLK_1__BYP EQU CYREG_PRT3_BYP
SCLK_1__CTL EQU CYREG_PRT3_CTL
SCLK_1__DM0 EQU CYREG_PRT3_DM0
SCLK_1__DM1 EQU CYREG_PRT3_DM1
SCLK_1__DM2 EQU CYREG_PRT3_DM2
SCLK_1__DR EQU CYREG_PRT3_DR
SCLK_1__INP_DIS EQU CYREG_PRT3_INP_DIS
SCLK_1__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU3_BASE
SCLK_1__LCD_COM_SEG EQU CYREG_PRT3_LCD_COM_SEG
SCLK_1__LCD_EN EQU CYREG_PRT3_LCD_EN
SCLK_1__MASK EQU 0x04
SCLK_1__PORT EQU 3
SCLK_1__PRT EQU CYREG_PRT3_PRT
SCLK_1__PRTDSI__CAPS_SEL EQU CYREG_PRT3_CAPS_SEL
SCLK_1__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT3_DBL_SYNC_IN
SCLK_1__PRTDSI__OE_SEL0 EQU CYREG_PRT3_OE_SEL0
SCLK_1__PRTDSI__OE_SEL1 EQU CYREG_PRT3_OE_SEL1
SCLK_1__PRTDSI__OUT_SEL0 EQU CYREG_PRT3_OUT_SEL0
SCLK_1__PRTDSI__OUT_SEL1 EQU CYREG_PRT3_OUT_SEL1
SCLK_1__PRTDSI__SYNC_OUT EQU CYREG_PRT3_SYNC_OUT
SCLK_1__PS EQU CYREG_PRT3_PS
SCLK_1__SHIFT EQU 2
SCLK_1__SLW EQU CYREG_PRT3_SLW

; Dev_GND
Dev_GND__0__INTTYPE EQU CYREG_PICU0_INTTYPE4
Dev_GND__0__MASK EQU 0x10
Dev_GND__0__PC EQU CYREG_PRT0_PC4
Dev_GND__0__PORT EQU 0
Dev_GND__0__SHIFT EQU 4
Dev_GND__AG EQU CYREG_PRT0_AG
Dev_GND__AMUX EQU CYREG_PRT0_AMUX
Dev_GND__BIE EQU CYREG_PRT0_BIE
Dev_GND__BIT_MASK EQU CYREG_PRT0_BIT_MASK
Dev_GND__BYP EQU CYREG_PRT0_BYP
Dev_GND__CTL EQU CYREG_PRT0_CTL
Dev_GND__DM0 EQU CYREG_PRT0_DM0
Dev_GND__DM1 EQU CYREG_PRT0_DM1
Dev_GND__DM2 EQU CYREG_PRT0_DM2
Dev_GND__DR EQU CYREG_PRT0_DR
Dev_GND__INP_DIS EQU CYREG_PRT0_INP_DIS
Dev_GND__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU0_BASE
Dev_GND__LCD_COM_SEG EQU CYREG_PRT0_LCD_COM_SEG
Dev_GND__LCD_EN EQU CYREG_PRT0_LCD_EN
Dev_GND__MASK EQU 0x10
Dev_GND__PORT EQU 0
Dev_GND__PRT EQU CYREG_PRT0_PRT
Dev_GND__PRTDSI__CAPS_SEL EQU CYREG_PRT0_CAPS_SEL
Dev_GND__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT0_DBL_SYNC_IN
Dev_GND__PRTDSI__OE_SEL0 EQU CYREG_PRT0_OE_SEL0
Dev_GND__PRTDSI__OE_SEL1 EQU CYREG_PRT0_OE_SEL1
Dev_GND__PRTDSI__OUT_SEL0 EQU CYREG_PRT0_OUT_SEL0
Dev_GND__PRTDSI__OUT_SEL1 EQU CYREG_PRT0_OUT_SEL1
Dev_GND__PRTDSI__SYNC_OUT EQU CYREG_PRT0_SYNC_OUT
Dev_GND__PS EQU CYREG_PRT0_PS
Dev_GND__SHIFT EQU 4
Dev_GND__SLW EQU CYREG_PRT0_SLW

; Dev_miso
Dev_miso__0__INTTYPE EQU CYREG_PICU0_INTTYPE0
Dev_miso__0__MASK EQU 0x01
Dev_miso__0__PC EQU CYREG_PRT0_PC0
Dev_miso__0__PORT EQU 0
Dev_miso__0__SHIFT EQU 0
Dev_miso__AG EQU CYREG_PRT0_AG
Dev_miso__AMUX EQU CYREG_PRT0_AMUX
Dev_miso__BIE EQU CYREG_PRT0_BIE
Dev_miso__BIT_MASK EQU CYREG_PRT0_BIT_MASK
Dev_miso__BYP EQU CYREG_PRT0_BYP
Dev_miso__CTL EQU CYREG_PRT0_CTL
Dev_miso__DM0 EQU CYREG_PRT0_DM0
Dev_miso__DM1 EQU CYREG_PRT0_DM1
Dev_miso__DM2 EQU CYREG_PRT0_DM2
Dev_miso__DR EQU CYREG_PRT0_DR
Dev_miso__INP_DIS EQU CYREG_PRT0_INP_DIS
Dev_miso__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU0_BASE
Dev_miso__LCD_COM_SEG EQU CYREG_PRT0_LCD_COM_SEG
Dev_miso__LCD_EN EQU CYREG_PRT0_LCD_EN
Dev_miso__MASK EQU 0x01
Dev_miso__PORT EQU 0
Dev_miso__PRT EQU CYREG_PRT0_PRT
Dev_miso__PRTDSI__CAPS_SEL EQU CYREG_PRT0_CAPS_SEL
Dev_miso__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT0_DBL_SYNC_IN
Dev_miso__PRTDSI__OE_SEL0 EQU CYREG_PRT0_OE_SEL0
Dev_miso__PRTDSI__OE_SEL1 EQU CYREG_PRT0_OE_SEL1
Dev_miso__PRTDSI__OUT_SEL0 EQU CYREG_PRT0_OUT_SEL0
Dev_miso__PRTDSI__OUT_SEL1 EQU CYREG_PRT0_OUT_SEL1
Dev_miso__PRTDSI__SYNC_OUT EQU CYREG_PRT0_SYNC_OUT
Dev_miso__PS EQU CYREG_PRT0_PS
Dev_miso__SHIFT EQU 0
Dev_miso__SLW EQU CYREG_PRT0_SLW

; Dev_mosi
Dev_mosi__0__INTTYPE EQU CYREG_PICU0_INTTYPE1
Dev_mosi__0__MASK EQU 0x02
Dev_mosi__0__PC EQU CYREG_PRT0_PC1
Dev_mosi__0__PORT EQU 0
Dev_mosi__0__SHIFT EQU 1
Dev_mosi__AG EQU CYREG_PRT0_AG
Dev_mosi__AMUX EQU CYREG_PRT0_AMUX
Dev_mosi__BIE EQU CYREG_PRT0_BIE
Dev_mosi__BIT_MASK EQU CYREG_PRT0_BIT_MASK
Dev_mosi__BYP EQU CYREG_PRT0_BYP
Dev_mosi__CTL EQU CYREG_PRT0_CTL
Dev_mosi__DM0 EQU CYREG_PRT0_DM0
Dev_mosi__DM1 EQU CYREG_PRT0_DM1
Dev_mosi__DM2 EQU CYREG_PRT0_DM2
Dev_mosi__DR EQU CYREG_PRT0_DR
Dev_mosi__INP_DIS EQU CYREG_PRT0_INP_DIS
Dev_mosi__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU0_BASE
Dev_mosi__LCD_COM_SEG EQU CYREG_PRT0_LCD_COM_SEG
Dev_mosi__LCD_EN EQU CYREG_PRT0_LCD_EN
Dev_mosi__MASK EQU 0x02
Dev_mosi__PORT EQU 0
Dev_mosi__PRT EQU CYREG_PRT0_PRT
Dev_mosi__PRTDSI__CAPS_SEL EQU CYREG_PRT0_CAPS_SEL
Dev_mosi__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT0_DBL_SYNC_IN
Dev_mosi__PRTDSI__OE_SEL0 EQU CYREG_PRT0_OE_SEL0
Dev_mosi__PRTDSI__OE_SEL1 EQU CYREG_PRT0_OE_SEL1
Dev_mosi__PRTDSI__OUT_SEL0 EQU CYREG_PRT0_OUT_SEL0
Dev_mosi__PRTDSI__OUT_SEL1 EQU CYREG_PRT0_OUT_SEL1
Dev_mosi__PRTDSI__SYNC_OUT EQU CYREG_PRT0_SYNC_OUT
Dev_mosi__PS EQU CYREG_PRT0_PS
Dev_mosi__SHIFT EQU 1
Dev_mosi__SLW EQU CYREG_PRT0_SLW

; Dev_sclk
Dev_sclk__0__INTTYPE EQU CYREG_PICU0_INTTYPE2
Dev_sclk__0__MASK EQU 0x04
Dev_sclk__0__PC EQU CYREG_PRT0_PC2
Dev_sclk__0__PORT EQU 0
Dev_sclk__0__SHIFT EQU 2
Dev_sclk__AG EQU CYREG_PRT0_AG
Dev_sclk__AMUX EQU CYREG_PRT0_AMUX
Dev_sclk__BIE EQU CYREG_PRT0_BIE
Dev_sclk__BIT_MASK EQU CYREG_PRT0_BIT_MASK
Dev_sclk__BYP EQU CYREG_PRT0_BYP
Dev_sclk__CTL EQU CYREG_PRT0_CTL
Dev_sclk__DM0 EQU CYREG_PRT0_DM0
Dev_sclk__DM1 EQU CYREG_PRT0_DM1
Dev_sclk__DM2 EQU CYREG_PRT0_DM2
Dev_sclk__DR EQU CYREG_PRT0_DR
Dev_sclk__INP_DIS EQU CYREG_PRT0_INP_DIS
Dev_sclk__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU0_BASE
Dev_sclk__LCD_COM_SEG EQU CYREG_PRT0_LCD_COM_SEG
Dev_sclk__LCD_EN EQU CYREG_PRT0_LCD_EN
Dev_sclk__MASK EQU 0x04
Dev_sclk__PORT EQU 0
Dev_sclk__PRT EQU CYREG_PRT0_PRT
Dev_sclk__PRTDSI__CAPS_SEL EQU CYREG_PRT0_CAPS_SEL
Dev_sclk__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT0_DBL_SYNC_IN
Dev_sclk__PRTDSI__OE_SEL0 EQU CYREG_PRT0_OE_SEL0
Dev_sclk__PRTDSI__OE_SEL1 EQU CYREG_PRT0_OE_SEL1
Dev_sclk__PRTDSI__OUT_SEL0 EQU CYREG_PRT0_OUT_SEL0
Dev_sclk__PRTDSI__OUT_SEL1 EQU CYREG_PRT0_OUT_SEL1
Dev_sclk__PRTDSI__SYNC_OUT EQU CYREG_PRT0_SYNC_OUT
Dev_sclk__PS EQU CYREG_PRT0_PS
Dev_sclk__SHIFT EQU 2
Dev_sclk__SLW EQU CYREG_PRT0_SLW

; LCD_Char_LCDPort
LCD_Char_LCDPort__0__INTTYPE EQU CYREG_PICU2_INTTYPE0
LCD_Char_LCDPort__0__MASK EQU 0x01
LCD_Char_LCDPort__0__PC EQU CYREG_PRT2_PC0
LCD_Char_LCDPort__0__PORT EQU 2
LCD_Char_LCDPort__0__SHIFT EQU 0
LCD_Char_LCDPort__1__INTTYPE EQU CYREG_PICU2_INTTYPE1
LCD_Char_LCDPort__1__MASK EQU 0x02
LCD_Char_LCDPort__1__PC EQU CYREG_PRT2_PC1
LCD_Char_LCDPort__1__PORT EQU 2
LCD_Char_LCDPort__1__SHIFT EQU 1
LCD_Char_LCDPort__2__INTTYPE EQU CYREG_PICU2_INTTYPE2
LCD_Char_LCDPort__2__MASK EQU 0x04
LCD_Char_LCDPort__2__PC EQU CYREG_PRT2_PC2
LCD_Char_LCDPort__2__PORT EQU 2
LCD_Char_LCDPort__2__SHIFT EQU 2
LCD_Char_LCDPort__3__INTTYPE EQU CYREG_PICU2_INTTYPE3
LCD_Char_LCDPort__3__MASK EQU 0x08
LCD_Char_LCDPort__3__PC EQU CYREG_PRT2_PC3
LCD_Char_LCDPort__3__PORT EQU 2
LCD_Char_LCDPort__3__SHIFT EQU 3
LCD_Char_LCDPort__4__INTTYPE EQU CYREG_PICU2_INTTYPE4
LCD_Char_LCDPort__4__MASK EQU 0x10
LCD_Char_LCDPort__4__PC EQU CYREG_PRT2_PC4
LCD_Char_LCDPort__4__PORT EQU 2
LCD_Char_LCDPort__4__SHIFT EQU 4
LCD_Char_LCDPort__5__INTTYPE EQU CYREG_PICU2_INTTYPE5
LCD_Char_LCDPort__5__MASK EQU 0x20
LCD_Char_LCDPort__5__PC EQU CYREG_PRT2_PC5
LCD_Char_LCDPort__5__PORT EQU 2
LCD_Char_LCDPort__5__SHIFT EQU 5
LCD_Char_LCDPort__6__INTTYPE EQU CYREG_PICU2_INTTYPE6
LCD_Char_LCDPort__6__MASK EQU 0x40
LCD_Char_LCDPort__6__PC EQU CYREG_PRT2_PC6
LCD_Char_LCDPort__6__PORT EQU 2
LCD_Char_LCDPort__6__SHIFT EQU 6
LCD_Char_LCDPort__AG EQU CYREG_PRT2_AG
LCD_Char_LCDPort__AMUX EQU CYREG_PRT2_AMUX
LCD_Char_LCDPort__BIE EQU CYREG_PRT2_BIE
LCD_Char_LCDPort__BIT_MASK EQU CYREG_PRT2_BIT_MASK
LCD_Char_LCDPort__BYP EQU CYREG_PRT2_BYP
LCD_Char_LCDPort__CTL EQU CYREG_PRT2_CTL
LCD_Char_LCDPort__DM0 EQU CYREG_PRT2_DM0
LCD_Char_LCDPort__DM1 EQU CYREG_PRT2_DM1
LCD_Char_LCDPort__DM2 EQU CYREG_PRT2_DM2
LCD_Char_LCDPort__DR EQU CYREG_PRT2_DR
LCD_Char_LCDPort__INP_DIS EQU CYREG_PRT2_INP_DIS
LCD_Char_LCDPort__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU2_BASE
LCD_Char_LCDPort__LCD_COM_SEG EQU CYREG_PRT2_LCD_COM_SEG
LCD_Char_LCDPort__LCD_EN EQU CYREG_PRT2_LCD_EN
LCD_Char_LCDPort__MASK EQU 0x7F
LCD_Char_LCDPort__PORT EQU 2
LCD_Char_LCDPort__PRT EQU CYREG_PRT2_PRT
LCD_Char_LCDPort__PRTDSI__CAPS_SEL EQU CYREG_PRT2_CAPS_SEL
LCD_Char_LCDPort__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT2_DBL_SYNC_IN
LCD_Char_LCDPort__PRTDSI__OE_SEL0 EQU CYREG_PRT2_OE_SEL0
LCD_Char_LCDPort__PRTDSI__OE_SEL1 EQU CYREG_PRT2_OE_SEL1
LCD_Char_LCDPort__PRTDSI__OUT_SEL0 EQU CYREG_PRT2_OUT_SEL0
LCD_Char_LCDPort__PRTDSI__OUT_SEL1 EQU CYREG_PRT2_OUT_SEL1
LCD_Char_LCDPort__PRTDSI__SYNC_OUT EQU CYREG_PRT2_SYNC_OUT
LCD_Char_LCDPort__PS EQU CYREG_PRT2_PS
LCD_Char_LCDPort__SHIFT EQU 0
LCD_Char_LCDPort__SLW EQU CYREG_PRT2_SLW

; Miscellaneous
BCLK__BUS_CLK__HZ EQU 24000000
BCLK__BUS_CLK__KHZ EQU 24000
BCLK__BUS_CLK__MHZ EQU 24
CYDEV_CHIP_DIE_LEOPARD EQU 1
CYDEV_CHIP_DIE_PANTHER EQU 18
CYDEV_CHIP_DIE_PSOC4A EQU 10
CYDEV_CHIP_DIE_PSOC5LP EQU 17
CYDEV_CHIP_DIE_TMA4 EQU 2
CYDEV_CHIP_DIE_UNKNOWN EQU 0
CYDEV_CHIP_FAMILY_PSOC3 EQU 1
CYDEV_CHIP_FAMILY_PSOC4 EQU 2
CYDEV_CHIP_FAMILY_PSOC5 EQU 3
CYDEV_CHIP_FAMILY_UNKNOWN EQU 0
CYDEV_CHIP_FAMILY_USED EQU CYDEV_CHIP_FAMILY_PSOC5
CYDEV_CHIP_JTAG_ID EQU 0x2E161069
CYDEV_CHIP_MEMBER_3A EQU 1
CYDEV_CHIP_MEMBER_4A EQU 10
CYDEV_CHIP_MEMBER_4C EQU 15
CYDEV_CHIP_MEMBER_4D EQU 6
CYDEV_CHIP_MEMBER_4E EQU 4
CYDEV_CHIP_MEMBER_4F EQU 11
CYDEV_CHIP_MEMBER_4G EQU 2
CYDEV_CHIP_MEMBER_4H EQU 9
CYDEV_CHIP_MEMBER_4I EQU 14
CYDEV_CHIP_MEMBER_4J EQU 7
CYDEV_CHIP_MEMBER_4K EQU 8
CYDEV_CHIP_MEMBER_4L EQU 13
CYDEV_CHIP_MEMBER_4M EQU 12
CYDEV_CHIP_MEMBER_4N EQU 5
CYDEV_CHIP_MEMBER_4U EQU 3
CYDEV_CHIP_MEMBER_5A EQU 17
CYDEV_CHIP_MEMBER_5B EQU 16
CYDEV_CHIP_MEMBER_UNKNOWN EQU 0
CYDEV_CHIP_MEMBER_USED EQU CYDEV_CHIP_MEMBER_5B
CYDEV_CHIP_DIE_EXPECT EQU CYDEV_CHIP_MEMBER_USED
CYDEV_CHIP_DIE_ACTUAL EQU CYDEV_CHIP_DIE_EXPECT
CYDEV_CHIP_REV_LEOPARD_ES1 EQU 0
CYDEV_CHIP_REV_LEOPARD_ES2 EQU 1
CYDEV_CHIP_REV_LEOPARD_ES3 EQU 3
CYDEV_CHIP_REV_LEOPARD_PRODUCTION EQU 3
CYDEV_CHIP_REV_PANTHER_ES0 EQU 0
CYDEV_CHIP_REV_PANTHER_ES1 EQU 1
CYDEV_CHIP_REV_PANTHER_PRODUCTION EQU 1
CYDEV_CHIP_REV_PSOC4A_ES0 EQU 17
CYDEV_CHIP_REV_PSOC4A_PRODUCTION EQU 17
CYDEV_CHIP_REV_PSOC5LP_ES0 EQU 0
CYDEV_CHIP_REV_PSOC5LP_PRODUCTION EQU 0
CYDEV_CHIP_REV_TMA4_ES EQU 17
CYDEV_CHIP_REV_TMA4_ES2 EQU 33
CYDEV_CHIP_REV_TMA4_PRODUCTION EQU 17
CYDEV_CHIP_REVISION_3A_ES1 EQU 0
CYDEV_CHIP_REVISION_3A_ES2 EQU 1
CYDEV_CHIP_REVISION_3A_ES3 EQU 3
CYDEV_CHIP_REVISION_3A_PRODUCTION EQU 3
CYDEV_CHIP_REVISION_4A_ES0 EQU 17
CYDEV_CHIP_REVISION_4A_PRODUCTION EQU 17
CYDEV_CHIP_REVISION_4C_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4D_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4E_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4F_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4F_PRODUCTION_256DMA EQU 0
CYDEV_CHIP_REVISION_4F_PRODUCTION_256K EQU 0
CYDEV_CHIP_REVISION_4G_ES EQU 17
CYDEV_CHIP_REVISION_4G_ES2 EQU 33
CYDEV_CHIP_REVISION_4G_PRODUCTION EQU 17
CYDEV_CHIP_REVISION_4H_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4I_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4J_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4K_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4L_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4M_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4N_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4U_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_5A_ES0 EQU 0
CYDEV_CHIP_REVISION_5A_ES1 EQU 1
CYDEV_CHIP_REVISION_5A_PRODUCTION EQU 1
CYDEV_CHIP_REVISION_5B_ES0 EQU 0
CYDEV_CHIP_REVISION_5B_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_USED EQU CYDEV_CHIP_REVISION_5B_PRODUCTION
CYDEV_CHIP_REV_EXPECT EQU CYDEV_CHIP_REVISION_USED
CYDEV_CONFIG_FASTBOOT_ENABLED EQU 1
CYDEV_CONFIG_UNUSED_IO_AllowButWarn EQU 0
CYDEV_CONFIG_UNUSED_IO EQU CYDEV_CONFIG_UNUSED_IO_AllowButWarn
CYDEV_CONFIG_UNUSED_IO_AllowWithInfo EQU 1
CYDEV_CONFIG_UNUSED_IO_Disallowed EQU 2
CYDEV_CONFIGURATION_COMPRESSED EQU 0
CYDEV_CONFIGURATION_DMA EQU 1
CYDEV_CONFIGURATION_ECC EQU 1
CYDEV_CONFIGURATION_IMOENABLED EQU CYDEV_CONFIG_FASTBOOT_ENABLED
CYDEV_CONFIGURATION_MODE_COMPRESSED EQU 0
CYDEV_CONFIGURATION_MODE_DMA EQU 2
CYDEV_CONFIGURATION_MODE EQU CYDEV_CONFIGURATION_MODE_DMA
CYDEV_CONFIGURATION_MODE_UNCOMPRESSED EQU 1
CYDEV_DEBUG_ENABLE_MASK EQU 0x20
CYDEV_DEBUG_ENABLE_REGISTER EQU CYREG_MLOGIC_DEBUG
CYDEV_DEBUGGING_DPS_Disable EQU 3
CYDEV_DEBUGGING_DPS_JTAG_4 EQU 1
CYDEV_DEBUGGING_DPS_JTAG_5 EQU 0
CYDEV_DEBUGGING_DPS_SWD EQU 2
CYDEV_DEBUGGING_DPS_SWD_SWV EQU 6
CYDEV_DEBUGGING_DPS EQU CYDEV_DEBUGGING_DPS_SWD_SWV
CYDEV_DEBUGGING_ENABLE EQU 1
CYDEV_DEBUGGING_XRES EQU 0
CYDEV_DMA_CHANNELS_AVAILABLE EQU 24
CYDEV_ECC_ENABLE EQU 0
CYDEV_HEAP_SIZE EQU 0x1000
CYDEV_INSTRUCT_CACHE_ENABLED EQU 1
CYDEV_INTR_RISING EQU 0x00000000
CYDEV_IS_EXPORTING_CODE EQU 0
CYDEV_IS_IMPORTING_CODE EQU 0
CYDEV_PROJ_TYPE EQU 0
CYDEV_PROJ_TYPE_BOOTLOADER EQU 1
CYDEV_PROJ_TYPE_LAUNCHER EQU 5
CYDEV_PROJ_TYPE_LOADABLE EQU 2
CYDEV_PROJ_TYPE_LOADABLEANDBOOTLOADER EQU 4
CYDEV_PROJ_TYPE_MULTIAPPBOOTLOADER EQU 3
CYDEV_PROJ_TYPE_STANDARD EQU 0
CYDEV_PROTECTION_ENABLE EQU 0
CYDEV_STACK_SIZE EQU 0x4000
CYDEV_USE_BUNDLED_CMSIS EQU 1
CYDEV_VARIABLE_VDDA EQU 0
CYDEV_VDDA_MV EQU 5000
CYDEV_VDDD_MV EQU 5000
CYDEV_VDDIO0_MV EQU 5000
CYDEV_VDDIO1_MV EQU 5000
CYDEV_VDDIO2_MV EQU 5000
CYDEV_VDDIO3_MV EQU 5000
CYDEV_VIO0_MV EQU 5000
CYDEV_VIO1_MV EQU 5000
CYDEV_VIO2_MV EQU 5000
CYDEV_VIO3_MV EQU 5000
CYIPBLOCK_ARM_CM3_VERSION EQU 0
CYIPBLOCK_P3_ANAIF_VERSION EQU 0
CYIPBLOCK_P3_CAN_VERSION EQU 0
CYIPBLOCK_P3_CAPSENSE_VERSION EQU 0
CYIPBLOCK_P3_COMP_VERSION EQU 0
CYIPBLOCK_P3_DECIMATOR_VERSION EQU 0
CYIPBLOCK_P3_DFB_VERSION EQU 0
CYIPBLOCK_P3_DMA_VERSION EQU 0
CYIPBLOCK_P3_DRQ_VERSION EQU 0
CYIPBLOCK_P3_DSM_VERSION EQU 0
CYIPBLOCK_P3_EMIF_VERSION EQU 0
CYIPBLOCK_P3_I2C_VERSION EQU 0
CYIPBLOCK_P3_LCD_VERSION EQU 0
CYIPBLOCK_P3_LPF_VERSION EQU 0
CYIPBLOCK_P3_OPAMP_VERSION EQU 0
CYIPBLOCK_P3_PM_VERSION EQU 0
CYIPBLOCK_P3_SCCT_VERSION EQU 0
CYIPBLOCK_P3_TIMER_VERSION EQU 0
CYIPBLOCK_P3_USB_VERSION EQU 0
CYIPBLOCK_P3_VIDAC_VERSION EQU 0
CYIPBLOCK_P3_VREF_VERSION EQU 0
CYIPBLOCK_S8_GPIO_VERSION EQU 0
CYIPBLOCK_S8_IRQ_VERSION EQU 0
CYIPBLOCK_S8_SAR_VERSION EQU 0
CYIPBLOCK_S8_SIO_VERSION EQU 0
CYIPBLOCK_S8_UDB_VERSION EQU 0
DMA_CHANNELS_USED__MASK0 EQU 0x00000000
CYDEV_BOOTLOADER_ENABLE EQU 0
    ENDIF
    END