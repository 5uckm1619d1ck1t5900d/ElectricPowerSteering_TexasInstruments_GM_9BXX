/* -----------------------------------------------------------------------------
  Filename:    ggda_par.h
  Description: Toolversion: 08.31.00.01.01.01.23.01.00.00
                
                Serial Number: CBD1010123
                Customer Info: Nexteer
                               Package: GMLAN 3.0 Multi Channel 
                               Micro: TI TMS570 LS2125
                               Compiler: Texas Instruments 4.9.0
                
                
                Generator Fwk   : GENy 
                Generator Module: Diag_CanDescGgdaExt_Gm
                
                Configuration   : C:\CMSynergy_Projects\Chrysler_C1xx\Chrysler_LWR_EPS_TMS570\Tools\AsrProject\GENy\RT_2.0_Mod.gny
                
                ECU: 
                        TargetSystem: Hw_Tms470/570Cpu (Dcan)
                        Compiler:     TexasInstruments
                        Derivates:    TMS570PSFC66
                
                Channel "Channel0":
                        Databasefile: C:\Synergy\GM_K2XX_EPS_TMS570-zz4r1x\GM_K2XX_EPS_TMS570\Tools\AsrProject\GENy\GlobalA_HS.dbc
                        Bussystem:    CAN
                        Manufacturer: General Motors
                        Node:         EPS_HS
                Channel "Channel1":
                        Databasefile: GlobalA_CE.dbc
                        Bussystem:    CAN
                        Manufacturer: General Motors
                        Node:         EPS_CE

  Generated by , 2013-07-16  15:26:14
 ----------------------------------------------------------------------------- */
/* -----------------------------------------------------------------------------
  C O P Y R I G H T
 -------------------------------------------------------------------------------
  Copyright (c) 2001-2008 by Vector Informatik GmbH. All rights reserved.
 
  This software is copyright protected and proprietary to Vector Informatik 
  GmbH.
  
  Vector Informatik GmbH grants to you only those rights as set out in the 
  license conditions.
  
  All other rights remain with Vector Informatik GmbH.
 -------------------------------------------------------------------------------
 ----------------------------------------------------------------------------- */

#if !defined(__GGDA_PAR_H__)
#define __GGDA_PAR_H__

#define GGDA_CONFIG_OFF                      0
#define GGDA_CONFIG_ON                       1

#define GGDA_CONFIG_VERSION                  0x203u

#define GGDA_CONFIG_DEBUG                    GGDA_CONFIG_OFF

/* Support of mode $A9 */
#define GGDA_CONFIG_SERVICE_A9_SUPPORT       GGDA_CONFIG_OFF
#define GGDA_CONFIG_SERVICE_A9_80_SUPPORT    GGDA_CONFIG_OFF
#define GGDA_CONFIG_SERVICE_A9_82_SUPPORT    GGDA_CONFIG_OFF

/* Configuration of mode $10 */
#define GGDA_CONFIG_SERVICE_10_02_SUPPORT    GGDA_CONFIG_OFF
#define GGDA_CONFIG_SERVICE_10_04_SUPPORT    GGDA_CONFIG_OFF

/* Configuration of mode $A5 */
#define GGDA_CONFIG_SERVICE_A5_02_SUPPORT    GGDA_CONFIG_OFF

#ifdef DESC_ENABLE_GW_ECU_ADDR
#define GGDA_CONFIG_GW_SUPPORT               GGDA_CONFIG_ON
#else
#define GGDA_CONFIG_GW_SUPPORT               GGDA_CONFIG_OFF
#endif


#define kGgdaNumContexts                     1

#define kGgdaEcuNumber                       kDescEcuAddress

#define kGgdaTimerMsCycle                    10
#define kGgdaTimeoutS1                       5000
#define kGgdaTimeoutP2                       50
#define kGgdaTimeoutP2Ex                     2000
#define kGgdaTimeoutVnDiagnostics            8000
#define kGgdaCanConfirmTimeout               100

typedef vuint8 GgdaContextIndexType;
typedef struct GgdaTpConfigTypeTag
{
  canuint8 tpTxChannel;
  canuint8 tpRxChannel;
} GgdaTpConfigType;
typedef struct GgdaCanConfigTypeTag
{
  CanChannelHandle canChannel;
  vbittype optionalModes : 8;
} GgdaCanConfigType;

#define kGgdaDisableAll                      ((vbittype) 0x00u)
#define kGgdaEnableModeA502                  ((vbittype) 0x01u)
#define kGgdaEnableMode1002                  ((vbittype) 0x02u)
#define kGgdaEnableMode1004                  ((vbittype) 0x04u)
#define kGgdaEnableModeA980                  ((vbittype) 0x10u)
#define kGgdaEnableModeA981                  ((vbittype) 0x20u)
#define kGgdaEnableModeA982                  ((vbittype) 0x40u)
#define kGgdaEnableMode10xx                  ((vbittype) (kGgdaEnableMode1002|kGgdaEnableMode1004))
#define kGgdaEnableModeA9xx                  ((vbittype) 0x70u)
#define kGgdaEnableAll                       ((vbittype) (kGgdaEnableModeA502|kGgdaEnableMode10xx|kGgdaEnableModeA9xx))

V_MEMROM0 extern  V_MEMROM1 GgdaCanConfigType V_MEMROM2 ggdaCanConfig[kGgdaNumContexts];
V_MEMROM0 extern  V_MEMROM1 GgdaTpConfigType V_MEMROM2 ggdaTpConfig[kGgdaNumContexts];


/* begin Fileversion check */
#ifndef SKIP_MAGIC_NUMBER
#ifdef MAGIC_NUMBER
  #if MAGIC_NUMBER != 133574485
      #error "The magic number of the generated file <C:\CMSynergy_Projects\Chrysler_C1xx\Chrysler_LWR_EPS_TMS570\SwProject\Source\_GenData\ggda_par.h> is different. Please check time and date of generated files!"
  #endif
#else
  #define MAGIC_NUMBER 133574485
#endif  /* MAGIC_NUMBER */
#endif  /* SKIP_MAGIC_NUMBER */

/* end Fileversion check */

#endif /* __GGDA_PAR_H__ */
