/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2010 by Vector Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  ===================================================================================================================
 *  FILE DESCRIPTION
 *  ===================================================================================================================
 *         File:  IoHwAb.c
 *    Component:  EcuAb_AsrIoHwAb
 *       Module:  IoHwAb
 *    Generator:  -
 *
 *  Description:  This file is a template for implementing functionality to the IoHwAb.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
    Project:       EPS.ecuc
    Generated:  2015-08-15 09:02 am
    Licensee:    Nexteer Automotive Corporation (2502600608)
 
    This file is generated by DaVinci Configurator Pro - DAVINCICFG.EXE V4.0.66.0.

 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  AUTHOR IDENTITY
 *  ===================================================================================================================
 *  Name                          Initials      Company
 *  ===================================================================================================================
 *  Christian Marchl              Chm           Vector Informatik GmbH
 *  Christoph Ederer              Cer           Vector Informatik GmbH
 *  ===================================================================================================================
 *  REVISION HISTORY
 *  ===================================================================================================================
 *  Version   Date        Author  Change Id     Description
 *  ===================================================================================================================
 *  1.01.01   2007-11-26  Chm     ESCAN00022772 No changes here
 *                                ESCAN00023310 Changed line ending to CRLF
 *                                -             New file header added.
 *  1.01.02   2007-02-13  Chm     ESCAN00024551 GenRule G11 affected: replaced ON with STD_ON (in condition)
 *                                -             Function GenRules changed for more readability.
 *  1.02.00   2008-05-07  Cer     5006330       Created BSWMD, reworked transformation to use ECU-C file as input,
 *                                              multiple operations in one user defined port possible now, DCM
 *                                              interface added
 *  1.02.01   2008-06-13  Cer     ESCAN00027572 Rework of identifiers in Generation.xml and Validation.xml for
 *                                              EAD versions 3.2.4.341 and later, Indexes of EAD function
 *                                              RefValue() adjusted
 *  1.02.02   2008-07-10  Cer     ESCAN00028289 Read functions available for all signals now.
 *                                ESCAN00027419 Tags removed
 *                                ESCAN00026634 SIP check added
 *  1.02.03   2008-08-21  Cer     ESCAN00028337 View.xml added to Schemes
 *                                ESCAN00029093 Error in Transformation of SWC-structure reworked
 *                                ESCAN00028340 Critical section handling added
 *            2008-09-09  Chm     ESCAN00029855 Generation of references corrected
 *                                ESCAN00029854 Version defines corrected
 *                                ESCAN00029853 Corrected critical section handling
 *  1.03.00   2008-10-02  Cer     ESCAN00030019 Shortname adapted to AUTOSAR specification
 *                                ESCAN00029653 SWC generation for float data types reworked
 *  1.04.00   2008-12-05  Cer     -             Include of 'Rte_Type.h'/'IoHwAb_Types.h' moved from implementation
 *                                              to configuration header
 *                        Chm     ESCAN00031178 Added parameter IoHwAbstractionRequirementId
 *                        Chm     ESCAN00030122 Removed automatic definition of configuration container.
 *                        Chm     ESCAN00032103 Changed critical section handling to be independent of Board
 *                                              InterruptFunctionSet parameter if SchM is used.
 *  1.05.00   2008-12-19  Cer     ESCAN00032205 SubFunction 'ResetToDefault' added to DCM interface, Configuration of
 *                                              default value added to signal configuration
 *  1.05.01   2009-02-24  Cer     ESCAN00031178 RequirementId added to GUI
 *  1.05.02   2009-03-16  Cer     ESCAN00029642 Sortability added for all the tables in the view (IoHwAb.xml)
 *                                ESCAN00032636 Multiplicity of container IoHwAbDiscrete reworked (no discrete
 *                                              signal is created on startup anymore; Identifier.xml)
 *                                ESCAN00032636 Multiplicity of container IoHwAbDiscrete reworked (no discrete
 *                                              signal is created on startup anymore; Identifier.xml)
 *                                ESCAN00032763 Dev-Error Detection is disabled by default (Identifier.xml)
 *                                ESCAN00033386 RTE includes moved from configuration header to C-files
 *                                ESCAN00033387 Added support for generation of service ports (Identifer.xml,
 *                                              SWC_IoHwAb.xsl)
 *                                ESCAN00033645 Generation of data types of IOHWAB-specific default-values fixed
 *                                              (GenIoHwAbUserSourceTemplate.xml)
 *                                ESCAN00033835 Added ADMIN-DATA to SWC generation (SWC_IoHwAb.xsl)
 *  1.06.00   2009-07-10  Cer     ESCAN00034782 Added update of CalSourceType to avoid generation of empty DIO
 *                                              entity identifiers
 *                                ESCAN00036329 Fixed icon placement in view
 *                                ESCAN00036279 Automatic generation of SWC file added
 *                                ESCAN00032561 User blocks added to IoHwAb.c to avoid overwriting of user
 *                                              modifications in the generated template
 *                                ESCAN00029651 Added informative text about all the configured CAL entities
 *                                              to IoHwAb.c
 *                                ESCAN00036542 Added include of IoHwAbstraction types to the DCM header file
 *                                ESCAN00029887 Added dummy-statement mechanism to prevent compile warnings
 *  1.06.01   2009-09-22  Cer     ESCAN00037605 Reworked DCM services to provide multiple writing to the DCM
 *                                ESCAN00037601 Functionality of DCM sub-function 'resetToDefault' corrected
 *                                ESCAN00038188 Validation of default values extended to input signals
 *  1.06.02   2010-04-28  Cer     ESCAN00040647 Added general implementation are for local functions (IoHwAb.c)
 *                                ESCAN00040708 Reworked setting of parameter IoHwAbCalSourceType to ensure, that
 *                                              generation works correctly, even if the project is not saved
 *                                ESCAN00042720 'AS'-tag added to all identifers in Identifer.xml due to an in-
 *                                              compatibility with DaVinci Configurator from version 4.00.40
 *  1.06.03   2010-11-25  Cer     ESCAN00046423 Optional generation of symbolic name prefixes added
 *                                ESCAN00044073 Renamed 'Insert' buttons in the GUI to 'Append'
 *                                ESCAN00043885 Renamed control 'Component Name' and reworked description
 *                                ESCAN00043745 Default value selection removed from DIO entity parameter
 *                                -             Removed all unnecessary information from Identifer.xml (Labels, ...)
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <<USERBLOCK Start of version logging area>>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/* Version Control:
 * Date Created:      Wed Apr 13 12:17:00 2011
 * %version:          EA3#2 %
 * %derived_by:       CZ8L9T %
 * %date_modified:    Wed Feb 27 14:01:19 2013 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 03/01/13  4   	  JJW       Updated Priv Reg Write Api for Os 5.06 integration
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <</USERBLOCK>>                                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#define IOHWAB_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "IoHwAb.h"
#include "IoHwAb_Cbk.h"
#include "IoHwAb_Dcm.h"

#ifndef V_SUPPRESS_EXTENDED_VERSION_CHECK
    #include "v_ver.h"
#endif

#if ! defined (V_USE_DUMMY_STATEMENT)
 # error "The define V_USE_DUMMY_STATEMENT shall be defined either in Compiler_Cfg.h or as parameter for the Compiler"
#endif



/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <<USERBLOCK Start of include and declaration area>> DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "Port.h"
#include "esm_regs.h"

#define D_EKEYNORMAL_CNT_U32   0x00000000UL
#define D_EKEYFORCEERR_CNT_U32 0x0000000AUL

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <</USERBLOCK>>                                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/* Configuration switch */
#define IOHWAB_C

/* Include of configuration (private section and const structures) */
#include "IoHwAb_Cfg.h"

/*<IOHWAB_HEADER_INCLUDE>*/
/*</IOHWAB_HEADER_INCLUDE>*/



/**********************************************************************************************************************
 *  VERSION CHECK
 *********************************************************************************************************************/

#if (  (IOHWAB_CFG_MAJOR_VERSION != (1u)) \
    || (IOHWAB_CFG_MINOR_VERSION != (6u)))
        #error "Version numbers of IoHwAb.c and IoHwAb_Cfg.h are inconsistent!"
#endif

#if(   (IOHWAB_SW_MAJOR_VERSION != (1u)) \
    || (IOHWAB_SW_MINOR_VERSION != (3u)) \
    || (IOHWAB_AR_MAJOR_VERSION != (2u)) \
    || (IOHWAB_AR_MINOR_VERSION != (0u)) \
    || (IOHWAB_AR_PATCH_VERSION != (0u)))
    #error "Version numbers of IoHwAb.c and IoHwAb.h are inconsistent!"
#endif

#if(   (IOHWAB_DCM_MAJOR_VERSION != (1u)) \
    || (IOHWAB_DCM_MINOR_VERSION != (3u)))
    #error "Version numbers of IoHwAb.c and IoHwAb_Dcm.h are inconsistent!"
#endif



/**********************************************************************************************************************
 *  CONFIGURED CAL ENTITIES
 **********************************************************************************************************************

You can use the following CAL entities in the implementation of the I/O Hardware Abstraction. Please be aware of the
currently loaded runtime configuration of each component.

***** ADC CHANNELS *****
<IOHWAB_CAL_ADC>
</IOHWAB_CAL_ADC>

***** DIO ENTITIES *****
<IOHWAB_CAL_DIO>
- NHet
    - NHet_Ch4
    - NHet_Ch8
    - NHet_Ch15
    - NHet_Ch20
    - NHet_Ch22
    - NHet_Ch24
    - NHet_Ch26
    - DioChGrpNHet
- Adc1
    - ADC1_Ch0
    - DioChannelGroupAdc1
- Spi3
    - SPI3_NCS1
    - SPI_TCCS
    - DioChannelGroupSpi3
- CAN3_Rx
    - Can3Rx
    - DioChannelGroupCan3Rx
- CAN3_Tx
    - Can3Tx
    - DioChannelGroupCan3Tx
- Spi5
    - SPI5NENA
    - SPI5MISO
    - DioChannelGroupSpi5
- Esm
    - nERROR
    - DioChannelGroupEsm
- GIOB
    - GIOB0
    - GIOB1
    - GIOB2
    - DioChannelGroupGioB
- GIOA
    - GIOA0
    - DioChannelGroupGioA
</IOHWAB_CAL_DIO>

***** GPT CHANNELS *****
<IOHWAB_CAL_GPT>
Gpt_Runtime:
    - SystemTime_uS
</IOHWAB_CAL_GPT>

***** ICU CHANNELS *****
<IOHWAB_CAL_ICU>
</IOHWAB_CAL_ICU>

***** PORT PINS *****
<IOHWAB_CAL_PORT>
Port_Runtime:
    - SYS_FAULT_2B
    - GA_UPPER
    - GA_LOWER
    - GB_UPPER
    - FF1_DATA_DRV_DEF
    - FF2_CLK_DRV_DEF
    - FET_DRV_RESET_DEF
    - WdReset
    - WdMonitor
    - FetDrvResetABC
    - POS_SDA_DSP
    - POS_SCL_DSP
    - GB_LOWER
    - VPH_C_DSP
    - GC_UPPER
    - VPH_A_DSP
    - FetDrvCntl
    - GC_LOWER
    - VPH_E_DSP
    - PwrSwitchEn
    - VPH_D_DSP
    - T1_SENT
    - VPH_B_DSP
    - T1_SENT_Sync
    - SPI_50us_Trigger
    - SysFault2A
    - ePWM_Sync
    - SPI_1m_Trigger
    - TODReset
    - OvrVoltFdbk
    - FetFlt1Data
    - FetFlt2_Clk_ABC
    - T2_SENT
    - T2_SENT_Sync
    - PhaseC
    - PhaseA
    - PhaseB
    - EpsEn
</IOHWAB_CAL_PORT>

***** PWM CHANNELS *****
<IOHWAB_CAL_PWM>
</IOHWAB_CAL_PWM>

***** SPI SEQUENCES *****
<IOHWAB_CAL_SPI>
</IOHWAB_CAL_SPI>*/



/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

/*<IOHWAB_USERDEF_DEFAULT_VALUES>*/
/*</IOHWAB_USERDEF_DEFAULT_VALUES>*/



/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

#define IOHWAB_START_SEC_CONST_32BIT
#include "MemMap.h"

#ifndef V_SUPPRESS_EXTENDED_VERSION_CHECK
    CONST(uint32, IOHWAB_CONST) ECUAB_ASRIOHWAB_LIB_SYMBOL = ECUAB_ASRIOHWAB_LIB_VERSION;
#endif

#define IOHWAB_STOP_SEC_CONST_32BIT
#include "MemMap.h"


#define IOHWAB_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#include "MemMap.h"

/*<IOHWAB_USERDEF_DCM_VARIABLES>*/
/*</IOHWAB_USERDEF_DCM_VARIABLES>*/

#define IOHWAB_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
#include "MemMap.h"



/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

#define IOHWAB_START_SEC_CODE
#include "MemMap.h"

#if (STD_ON == IOHWAB_VERSION_INFO_API)
/**********************************************************************************************************************
 * IoHwAb_GetVersionInfo
 **********************************************************************************************************************
 *! \brief      This method Returns module version and vendor information.
 *  \param[out] Std_VersionInfoType     ConfigPtr               Pointer to where to store the version information.
 *  \return     void
 *********************************************************************************************************************/
FUNC(void, IOHWAB_CODE) IoHwAb_GetVersionInfo
(
      P2VAR(Std_VersionInfoType, AUTOMATIC, IOHWAB_APPL_DATA) versioninfo
)
{
    #if (STD_ON == IOHWAB_CFG_CHK_PARAM_PTR)
        if (NULL_PTR == versioninfo)
        {
            IoHwAb_Errorhook(IOHWAB_SID_GET_VERSION_INFO,
                                                    IOHWAB_E_NULL_POINTER);
            return;
        }
        else
        {
            /* Intentionally left free */
        }
    #endif
    versioninfo->vendorID         = ( IOHWAB_VENDOR_ID );
    versioninfo->moduleID         = ( IOHWAB_MODULE_ID );
    versioninfo->instanceID       = 0;
    versioninfo->sw_major_version = ( IOHWAB_SW_MAJOR_VERSION );
    versioninfo->sw_minor_version = ( IOHWAB_SW_MINOR_VERSION );
    versioninfo->sw_patch_version = ( IOHWAB_SW_PATCH_VERSION );
    return;
} /* IoHwAb_GetVersionInfo()*/
#endif  /* (IOHWAB_VERSION_INFO_API == STD_ON)*/



#if (STD_ON == IOHWAB_USE_INIT_FUNCTION)
/**********************************************************************************************************************
 *  IoHwAb_Init
 *********************************************************************************************************************/
/*! \brief      This method is the IoHwAb initialization function. If initialization is needed, add the code to this
 *              function.
 *  \return     void
 *********************************************************************************************************************/
FUNC(void, IOHWAB_CODE) IoHwAb_Init(void)
{

    /* ----- Implementation ----------------------------------------------- */

    /******************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!     <USERBLOCK Start of initialization code>              DO NOT CHANGE THIS COMMENT!
    ******************************************************************************************************************/

    /* TODO: Add the implementation of the initialization code here */

    /******************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!                       </USERBLOCK>                        DO NOT CHANGE THIS COMMENT!
    ******************************************************************************************************************/

    /*<IOHWAB_INITIALIZATION_CODE>*/
    /*</IOHWAB_INITIALIZATION_CODE>*/

    return;
}/*IoHwAb_Init(void)*/
#endif /*(STD_ON == IOHWAB_USE_INIT_FUNCTION)*/



/*<IOHWAB_GENERATED_USER_SIGNAL_FUNCTIONS>*/
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 +  OPERATIONS OF PORT 'IoHwAbPortConfig'
 ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

/**********************************************************************************************************************
 *  IoHwAb_OutputSetFet1Flt2ToOutput
 **********************************************************************************************************************
 *! \brief      The method IoHwAb_OutputSetFet1Flt2ToOutput is a user defined IoHwAb Output-function.
 *              This function has no unit defined.
 *  \param[in]  signal                  Signal for output.
 *  \retval     E_OK - Successful execution
 *  \retval     E_NOT_OK - An error occured
 *********************************************************************************************************************/
FUNC(Std_ReturnType, IOHWAB_APPL_CODE) IoHwAb_OutputSetFet1Flt2ToOutput
(
    IoHwAb_BoolType signal
)
{

    
    /******************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!     <USERBLOCK bfacd983-da09-4e24-8b97-66bed16e3c3c>     DO NOT CHANGE THIS COMMENT!
	 ******************************************************************************************************************/

	if (TRUE == signal)
	{
		Port_SetPinDirection(FetFlt2_Clk_ABC, PORT_PIN_OUT);
	}
	else
	{
		Port_SetPinDirection(FetFlt2_Clk_ABC, PORT_PIN_IN);
	}

	/******************************************************************************************************************
	 * DO NOT CHANGE THIS COMMENT!                       </USERBLOCK>                        DO NOT CHANGE THIS COMMENT!
    ******************************************************************************************************************/

    #if (V_USE_DUMMY_STATEMENT == STD_ON)
        signal = signal; /* Dummy assignment to prevent compiler warnings */
    #endif /* (V_USE_DUMMY_STATEMENT == STD_ON) */

    return E_OK;
}/* IoHwAb_OutputSetFet1Flt2ToOutput() */

 
 
/**********************************************************************************************************************
 *  IoHwAb_OutputSetFet2Flt2ToOutput
 **********************************************************************************************************************
 *! \brief      The method IoHwAb_OutputSetFet2Flt2ToOutput is a user defined IoHwAb Output-function.
 *              This function has no unit defined.
 *  \param[in]  signal                  Signal for output.
 *  \retval     E_OK - Successful execution
 *  \retval     E_NOT_OK - An error occured
 *********************************************************************************************************************/
FUNC(Std_ReturnType, IOHWAB_APPL_CODE) IoHwAb_OutputSetFet2Flt2ToOutput
(
    IoHwAb_BoolType signal
)
{

    
    /******************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!     <USERBLOCK aaf41cf2-cae9-48de-b607-7047b359f7e8>     DO NOT CHANGE THIS COMMENT!
    ******************************************************************************************************************/

	if (TRUE == signal)
	{
		Port_SetPinDirection(FF2_CLK_DRV_DEF, PORT_PIN_OUT);
	}
	else
	{
		Port_SetPinDirection(FF2_CLK_DRV_DEF, PORT_PIN_IN);
	}

    /******************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!                       </USERBLOCK>                        DO NOT CHANGE THIS COMMENT!
    ******************************************************************************************************************/

    #if (V_USE_DUMMY_STATEMENT == STD_ON)
        signal = signal; /* Dummy assignment to prevent compiler warnings */
    #endif /* (V_USE_DUMMY_STATEMENT == STD_ON) */

    return E_OK;
}/* IoHwAb_OutputSetFet2Flt2ToOutput() */

 
 
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 +  OPERATIONS OF PORT 'SysFault3'
 ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

/**********************************************************************************************************************
 *  IoHwAb_InputOP_GET
 **********************************************************************************************************************
 *! \brief      The method IoHwAb_InputOP_GET is a user defined IoHwAb Input-function.
 *              This function has no unit defined.
 *  \param[out] signal                  Pointer to where to write the value.
 *  \retval     E_OK - Successful execution
 *  \retval     E_NOT_OK - An error occured
 *********************************************************************************************************************/
FUNC(Std_ReturnType, IOHWAB_APPL_CODE) IoHwAb_InputOP_GET
(
    P2VAR(IoHwAb_BoolType, AUTOMATIC, IOHWAB_APPL_DATA) signal
)
{

    #if (STD_ON == IOHWAB_CFG_CHK_PARAM_PTR)
        if (NULL_PTR == signal)
        {
            IoHwAb_Errorhook(IOHWAB_SID_OPT_GET_USER_DEFINED,IOHWAB_E_NULL_POINTER);
            return E_NOT_OK;
        }
        else
        {
            /* No error */
        }
    #endif
    /******************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!     <USERBLOCK 7c578b4d-99ae-4fb2-9cbb-4d8dcd90d094>     DO NOT CHANGE THIS COMMENT!
    ******************************************************************************************************************/

    /* TODO: Add the implementation of the Input-operation here */
    *signal = (IoHwAb_BoolType)Dio_ReadChannel(nERROR);

    /******************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!                       </USERBLOCK>                        DO NOT CHANGE THIS COMMENT!
    ******************************************************************************************************************/

    #if (V_USE_DUMMY_STATEMENT == STD_ON)
        signal = signal; /* Dummy assignment to prevent compiler warnings */
    #endif /* (V_USE_DUMMY_STATEMENT == STD_ON) */

    return E_OK;
}/* IoHwAb_InputOP_GET() */

 
 
/**********************************************************************************************************************
 *  IoHwAb_OutputOP_SET
 **********************************************************************************************************************
 *! \brief      The method IoHwAb_OutputOP_SET is a user defined IoHwAb Output-function.
 *              This function has no unit defined.
 *  \param[in]  signal                  Signal for output.
 *  \retval     E_OK - Successful execution
 *  \retval     E_NOT_OK - An error occured
 *********************************************************************************************************************/
FUNC(Std_ReturnType, IOHWAB_APPL_CODE) IoHwAb_OutputOP_SET
(
    IoHwAb_BoolType signal
)
{

    
    /******************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!     <USERBLOCK 36bdad7b-2166-49a0-a243-bf2ffa94e8c8>     DO NOT CHANGE THIS COMMENT!
    ******************************************************************************************************************/

    /* TODO: Add the implementation of the Output-operation here */
    /* ESMEKR register's EKEY field is at the only defined to be 4 bits long and aligned to the lowest 4 bits of register.
	 * The smallest write size on the TMS570 is 8bits, and the 4 bits above the EKEY field are reserved with writes having no effect.
	 */
    if (STD_HIGH == signal)
    {
    	osWritePeripheral32(OS_MEM_AREA_ESMEKR, (osuint32)&(ESMREGS->ESMEKR), D_EKEYNORMAL_CNT_U32 );  /*Sets nERROR pin to normal mode (i.e. nERROR will return high if no Error has been detected)*/
    }
	else
	{
		osWritePeripheral32(OS_MEM_AREA_ESMEKR, (osuint32)&(ESMREGS->ESMEKR), D_EKEYFORCEERR_CNT_U32);  /*Forces nERROR pin low*/
	}

    /******************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!                       </USERBLOCK>                        DO NOT CHANGE THIS COMMENT!
    ******************************************************************************************************************/

    #if (V_USE_DUMMY_STATEMENT == STD_ON)
        signal = signal; /* Dummy assignment to prevent compiler warnings */
    #endif /* (V_USE_DUMMY_STATEMENT == STD_ON) */

    return E_OK;
}/* IoHwAb_OutputOP_SET() */

 
 
/*</IOHWAB_GENERATED_USER_SIGNAL_FUNCTIONS>*/



/*<IOHWAB_HANDLER_FUNCTIONS>*/
/*</IOHWAB_HANDLER_FUNCTIONS>*/



/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <<USERBLOCK Start of general implementation area>> DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <</USERBLOCK>>                                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/



/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <<USERBLOCK Start of removed code area>>           DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/***  End of saved runnable code    ***/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <</USERBLOCK>>                                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#define IOHWAB_STOP_SEC_CODE
#include "MemMap.h"
/**********************************************************************************************************************
 *  END OF FILE: IoHwAb.c
 *********************************************************************************************************************/


