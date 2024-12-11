/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: mcb_pmsm_foc_qep_f28379d.c
 *
 * Code generated for Simulink model 'mcb_pmsm_foc_qep_f28379d'.
 *
 * Model version                  : 9.0
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Tue Dec 10 10:17:02 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "mcb_pmsm_foc_qep_f28379d.h"
#include "rtwtypes.h"
#include "mcb_pmsm_foc_qep_f28379d_private.h"
#include <math.h>
#include "rt_nonfinite.h"
#include <string.h>

/* Block signals (default storage) */
B_mcb_pmsm_foc_qep_f28379d_T mcb_pmsm_foc_qep_f28379d_B;

/* Block states (default storage) */
DW_mcb_pmsm_foc_qep_f28379d_T mcb_pmsm_foc_qep_f28379d_DW;

/* Real-time model */
static RT_MODEL_mcb_pmsm_foc_qep_f28_T mcb_pmsm_foc_qep_f28379d_M_;
RT_MODEL_mcb_pmsm_foc_qep_f28_T *const mcb_pmsm_foc_qep_f28379d_M =
  &mcb_pmsm_foc_qep_f28379d_M_;
static void rate_monotonic_scheduler(void);

#ifndef __TMS320C28XX_CLA__

uint16_T MW_adcCInitFlag = 0;

#endif

#ifndef __TMS320C28XX_CLA__

uint16_T MW_adcBInitFlag = 0;

#endif

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to remember which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void mcb_pmsm_foc_qep_f28379d_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(mcb_pmsm_foc_qep_f28379d_M, 1));
}

/*
 *         This function updates active task flag for each subrate
 *         and rate transition flags for tasks that exchange data.
 *         The function assumes rate-monotonic multitasking scheduler.
 *         The function must be called at model base rate so that
 *         the generated code self-manages all its subrates and rate
 *         transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (mcb_pmsm_foc_qep_f28379d_M->Timing.TaskCounters.TID[1])++;
  if ((mcb_pmsm_foc_qep_f28379d_M->Timing.TaskCounters.TID[1]) > 999) {/* Sample time: [0.5s, 0.0s] */
    mcb_pmsm_foc_qep_f28379d_M->Timing.TaskCounters.TID[1] = 0;
  }
}

/*
 * Output and update for atomic system:
 *    '<S19>/Two inputs CRL'
 *    '<S175>/Two inputs CRL'
 */
void mcb_pmsm_foc_q_TwoinputsCRL(real32_T rtu_Ds, real32_T rtu_Qs, real32_T
  rtu_sin, real32_T rtu_cos, B_TwoinputsCRL_mcb_pmsm_foc_q_T *localB)
{
  /* Product: '<S152>/qcos' */
  localB->qcos = rtu_Qs * rtu_cos;

  /* Product: '<S152>/dsin' */
  localB->dsin = rtu_Ds * rtu_sin;

  /* Sum: '<S152>/sum_beta' */
  localB->sum_beta = localB->qcos + localB->dsin;

  /* Product: '<S152>/dcos' */
  localB->dcos = rtu_Ds * rtu_cos;

  /* Product: '<S152>/qsin' */
  localB->qsin = rtu_Qs * rtu_sin;

  /* Sum: '<S152>/sum_alpha' */
  localB->sum_alpha = localB->dcos - localB->qsin;

  /* Switch: '<S153>/Switch' */
  localB->Switch[0] = localB->sum_alpha;
  localB->Switch[1] = localB->sum_beta;

  /* AlgorithmDescriptorDelegate generated from: '<S152>/a16' */
  localB->algDD_o1 = localB->Switch[0];

  /* AlgorithmDescriptorDelegate generated from: '<S152>/a16' */
  localB->algDD_o2 = localB->Switch[1];
}

/*
 * Output and update for action system:
 *    '<S158>/If Action Subsystem'
 *    '<S182>/If Action Subsystem'
 */
void mcb_pmsm__IfActionSubsystem(real32_T rtu_In1, real32_T *rty_Out1,
  B_IfActionSubsystem_mcb_pmsm__T *localB)
{
  /* DataTypeConversion: '<S161>/Convert_uint16' */
  localB->Convert_uint16 = (int16_T)(real32_T)floor(rtu_In1);

  /* DataTypeConversion: '<S161>/Convert_back' */
  localB->Convert_back = localB->Convert_uint16;

  /* Sum: '<S161>/Sum' */
  *rty_Out1 = rtu_In1 - localB->Convert_back;
}

/*
 * Output and update for action system:
 *    '<S158>/If Action Subsystem1'
 *    '<S182>/If Action Subsystem1'
 */
void mcb_pmsm_IfActionSubsystem1(real32_T rtu_In1, real32_T *rty_Out1,
  B_IfActionSubsystem1_mcb_pmsm_T *localB)
{
  /* DataTypeConversion: '<S162>/Convert_uint16' */
  localB->Convert_uint16 = (int16_T)rtu_In1;

  /* DataTypeConversion: '<S162>/Convert_back' */
  localB->Convert_back = localB->Convert_uint16;

  /* Sum: '<S162>/Sum' */
  *rty_Out1 = rtu_In1 - localB->Convert_back;
}

/* System initialize for function-call system: '<Root>/Current Control' */
void mcb_pms_CurrentControl_Init(void)
{
  /* Start for S-Function (c280xqep): '<S190>/eQEP' */
  config_QEP_eQEP1((uint32_T)65535U,(uint32_T)0, (uint32_T)0, (uint32_T)0,
                   (uint16_T)0, (uint16_T)448, (uint16_T)8232, (uint16_T)32768,
                   (uint16_T)119,(uint16_T)0);

  /* Start for S-Function (c2802xadc): '<S190>/ADC_C_IN2' */
  if (MW_adcCInitFlag == 0U) {
    InitAdcC();
    MW_adcCInitFlag = 1U;
  }

  config_ADCC_SOC0 ();

  /* Start for S-Function (c2802xadc): '<S190>/ADC_B_IN2' */
  if (MW_adcBInitFlag == 0U) {
    InitAdcB();
    MW_adcBInitFlag = 1U;
  }

  config_ADCB_SOC0 ();

  /* Start for S-Function (c280xgpio_do): '<S223>/DRV830x Enable' */
  EALLOW;
  GpioCtrlRegs.GPDMUX2.all &= 0xFCFFFFFFU;
  GpioCtrlRegs.GPDDIR.all |= 0x10000000U;
  EDIS;

  /* Start for S-Function (c2802xpwm): '<S223>/ePWM1' */
  real32_T tbprdValue1 = (real32_T)EPwm1Regs.TBPRD;

  /*** Initialize ePWM1 modules ***/
  {
    /*  -- Time Base Control Register
       EPwm1Regs.TBCTL.bit.CTRMODE              = 2U;          -- Counter Mode
       EPwm1Regs.TBCTL.bit.SYNCOSEL             = 1U;          -- Sync Output Select

       EPwm1Regs.TBCTL.bit.PRDLD                = 0U;          -- Shadow select

       EPwm1Regs.TBCTL2.bit.PRDLDSYNC           = 0U;          -- Shadow select

       EPwm1Regs.TBCTL.bit.PHSEN                = 0U;          -- Phase Load Enable
       EPwm1Regs.TBCTL.bit.PHSDIR               = 0U;          -- Phase Direction Bit
       EPwm1Regs.TBCTL.bit.HSPCLKDIV            = 0U;          -- High Speed TBCLK Pre-scaler
       EPwm1Regs.TBCTL.bit.CLKDIV               = 0U;          -- Time Base Clock Pre-scaler
     */
    EPwm1Regs.TBCTL.all = (EPwm1Regs.TBCTL.all & ~0x3FFFU) | 0x12U;
    EPwm1Regs.TBCTL2.all = (EPwm1Regs.TBCTL2.all & ~0xC000U) | 0x0U;

    /*-- Setup Time-Base (TB) Submodule --*/
    EPwm1Regs.TBPRD = 5000U;           // Time Base Period Register

    /* -- Time-Base Phase Register
       EPwm1Regs.TBPHS.bit.TBPHS               = 0U;          -- Phase offset register
     */
    EPwm1Regs.TBPHS.all = (EPwm1Regs.TBPHS.all & ~0xFFFF0000U) | 0x0U;

    // Time Base Counter Register
    EPwm1Regs.TBCTR = 0x0000U;         /* Clear counter*/

    /*-- Setup Counter_Compare (CC) Submodule --*/
    /*	-- Counter Compare Control Register

       EPwm1Regs.CMPCTL.bit.LOADASYNC           = 0U;          -- Active Compare A Load SYNC Option
       EPwm1Regs.CMPCTL.bit.LOADBSYNC           = 0U;          -- Active Compare B Load SYNC Option
       EPwm1Regs.CMPCTL.bit.LOADAMODE           = 0U;          -- Active Compare A Load
       EPwm1Regs.CMPCTL.bit.LOADBMODE           = 0U;          -- Active Compare B Load
       EPwm1Regs.CMPCTL.bit.SHDWAMODE           = 0U;          -- Compare A Register Block Operating Mode
       EPwm1Regs.CMPCTL.bit.SHDWBMODE           = 0U;          -- Compare B Register Block Operating Mode
     */
    EPwm1Regs.CMPCTL.all = (EPwm1Regs.CMPCTL.all & ~0x3C5FU) | 0x0U;

    /* EPwm1Regs.CMPCTL2.bit.SHDWCMODE           = 0U;          -- Compare C Register Block Operating Mode
       EPwm1Regs.CMPCTL2.bit.SHDWDMODE           = 0U;          -- Compare D Register Block Operating Mode
       EPwm1Regs.CMPCTL2.bit.LOADCSYNC           = 0U;          -- Active Compare C Load SYNC Option
       EPwm1Regs.CMPCTL2.bit.LOADDSYNC           = 0U;          -- Active Compare D Load SYNC Option
       EPwm1Regs.CMPCTL2.bit.LOADCMODE           = 0U;          -- Active Compare C Load
       EPwm1Regs.CMPCTL2.bit.LOADDMODE           = 0U;          -- Active Compare D Load
     */
    EPwm1Regs.CMPCTL2.all = (EPwm1Regs.CMPCTL2.all & ~0x3C5FU) | 0x0U;
    EPwm1Regs.CMPA.bit.CMPA = 2501U;   // Counter Compare A Register
    EPwm1Regs.CMPB.bit.CMPB = 2501U;   // Counter Compare B Register
    EPwm1Regs.CMPC = 32000U;           // Counter Compare C Register
    EPwm1Regs.CMPD = 32000U;           // Counter Compare D Register

    /*-- Setup Action-Qualifier (AQ) Submodule --*/
    EPwm1Regs.AQCTLA.all = 144U;
                               // Action Qualifier Control Register For Output A
    EPwm1Regs.AQCTLB.all = 2310U;
                               // Action Qualifier Control Register For Output B

    /*	-- Action Qualifier Software Force Register
       EPwm1Regs.AQSFRC.bit.RLDCSF              = 0U;          -- Reload from Shadow Options
     */
    EPwm1Regs.AQSFRC.all = (EPwm1Regs.AQSFRC.all & ~0xC0U) | 0x0U;

    /*	-- Action Qualifier Continuous S/W Force Register
       EPwm1Regs.AQCSFRC.bit.CSFA               = 0U;          -- Continuous Software Force on output A
       EPwm1Regs.AQCSFRC.bit.CSFB               = 0U;          -- Continuous Software Force on output B
     */
    EPwm1Regs.AQCSFRC.all = (EPwm1Regs.AQCSFRC.all & ~0xFU) | 0x0U;

    /*-- Setup Dead-Band Generator (DB) Submodule --*/
    /*	-- Dead-Band Generator Control Register
       EPwm1Regs.DBCTL.bit.OUT_MODE             = 3U;          -- Dead Band Output Mode Control
       EPwm1Regs.DBCTL.bit.IN_MODE              = 0U;          -- Dead Band Input Select Mode Control
       EPwm1Regs.DBCTL.bit.POLSEL               = 2U;          -- Polarity Select Control
       EPwm1Regs.DBCTL.bit.HALFCYCLE            = 0U;          -- Half Cycle Clocking Enable
       EPwm1Regs.DBCTL.bit.SHDWDBREDMODE        = 0U;          -- DBRED shadow mode
       EPwm1Regs.DBCTL.bit.SHDWDBFEDMODE        = 0U;          -- DBFED shadow mode
       EPwm1Regs.DBCTL.bit.LOADREDMODE          = 4U;        -- DBRED load
       EPwm1Regs.DBCTL.bit.LOADFEDMODE          = 4U;        -- DBFED load
     */
    EPwm1Regs.DBCTL.all = (EPwm1Regs.DBCTL.all & ~0x8FFFU) | 0xBU;
    EPwm1Regs.DBRED.bit.DBRED = (uint16_T)(15.0);
                         // Dead-Band Generator Rising Edge Delay Count Register
    EPwm1Regs.DBFED.bit.DBFED = (uint16_T)(15.0);
                        // Dead-Band Generator Falling Edge Delay Count Register

    /*-- Setup Event-Trigger (ET) Submodule --*/
    /*	-- Event Trigger Selection and Pre-Scale Register
       EPwm1Regs.ETSEL.bit.SOCAEN               = 1U;          -- Start of Conversion A Enable
       EPwm1Regs.ETSEL.bit.SOCASELCMP           = 0U;
       EPwm1Regs.ETSEL.bit.SOCASEL              = 2U;          -- Start of Conversion A Select
       EPwm1Regs.ETPS.bit.SOCPSSEL              = 1U;          -- EPWM1SOC Period Select
       EPwm1Regs.ETSOCPS.bit.SOCAPRD2           = 1U;
       EPwm1Regs.ETSEL.bit.SOCBEN               = 0U;          -- Start of Conversion B Enable
       EPwm1Regs.ETSEL.bit.SOCBSELCMP           = 0U;
       EPwm1Regs.ETSEL.bit.SOCBSEL              = 1U;          -- Start of Conversion A Select
       EPwm1Regs.ETPS.bit.SOCPSSEL              = 1;          -- EPWM1SOCB Period Select
       EPwm1Regs.ETSOCPS.bit.SOCBPRD2           = 1U;
       EPwm1Regs.ETSEL.bit.INTEN                = 0U;          -- EPWM1INTn Enable
       EPwm1Regs.ETSEL.bit.INTSELCMP            = 0U;
       EPwm1Regs.ETSEL.bit.INTSEL               = 1U;          -- Start of Conversion A Select
       EPwm1Regs.ETPS.bit.INTPSSEL              = 1U;          // EPWM1INTn Period Select
       EPwm1Regs.ETINTPS.bit.INTPRD2            = 1U;
     */
    EPwm1Regs.ETSEL.all = (EPwm1Regs.ETSEL.all & ~0xFF7FU) | 0x1A01U;
    EPwm1Regs.ETPS.all = (EPwm1Regs.ETPS.all & ~0x30U) | 0x30U;
    EPwm1Regs.ETSOCPS.all = (EPwm1Regs.ETSOCPS.all & ~0xF0FU) | 0x101U;
    EPwm1Regs.ETINTPS.all = (EPwm1Regs.ETINTPS.all & ~0xFU) | 0x1U;

    /*-- Setup PWM-Chopper (PC) Submodule --*/
    /*	-- PWM Chopper Control Register
       EPwm1Regs.PCCTL.bit.CHPEN                = 0U;          -- PWM chopping enable
       EPwm1Regs.PCCTL.bit.CHPFREQ              = 0U;          -- Chopping clock frequency
       EPwm1Regs.PCCTL.bit.OSHTWTH              = 0U;          -- One-shot pulse width
       EPwm1Regs.PCCTL.bit.CHPDUTY              = 0U;          -- Chopping clock Duty cycle
     */
    EPwm1Regs.PCCTL.all = (EPwm1Regs.PCCTL.all & ~0x7FFU) | 0x0U;

    /*-- Set up Trip-Zone (TZ) Submodule --*/
    EALLOW;
    EPwm1Regs.TZSEL.all = 0U;          // Trip Zone Select Register

    /*	-- Trip Zone Control Register
       EPwm1Regs.TZCTL.bit.TZA                  = 3U;          -- TZ1 to TZ6 Trip Action On EPWM1A
       EPwm1Regs.TZCTL.bit.TZB                  = 3U;          -- TZ1 to TZ6 Trip Action On EPWM1B
       EPwm1Regs.TZCTL.bit.DCAEVT1              = 3U;          -- EPWM1A action on DCAEVT1
       EPwm1Regs.TZCTL.bit.DCAEVT2              = 3U;          -- EPWM1A action on DCAEVT2
       EPwm1Regs.TZCTL.bit.DCBEVT1              = 3U;          -- EPWM1B action on DCBEVT1
       EPwm1Regs.TZCTL.bit.DCBEVT2              = 3U;          -- EPWM1B action on DCBEVT2
     */
    EPwm1Regs.TZCTL.all = (EPwm1Regs.TZCTL.all & ~0xFFFU) | 0xFFFU;

    /*	-- Trip Zone Enable Interrupt Register
       EPwm1Regs.TZEINT.bit.OST                 = 0U;          -- Trip Zones One Shot Int Enable
       EPwm1Regs.TZEINT.bit.CBC                 = 0U;          -- Trip Zones Cycle By Cycle Int Enable
       EPwm1Regs.TZEINT.bit.DCAEVT1             = 0U;          -- Digital Compare A Event 1 Int Enable
       EPwm1Regs.TZEINT.bit.DCAEVT2             = 0U;          -- Digital Compare A Event 2 Int Enable
       EPwm1Regs.TZEINT.bit.DCBEVT1             = 0U;          -- Digital Compare B Event 1 Int Enable
       EPwm1Regs.TZEINT.bit.DCBEVT2             = 0U;          -- Digital Compare B Event 2 Int Enable
     */
    EPwm1Regs.TZEINT.all = (EPwm1Regs.TZEINT.all & ~0x7EU) | 0x0U;

    /*	-- Digital Compare A Control Register
       EPwm1Regs.DCACTL.bit.EVT1SYNCE           = 0U;          -- DCAEVT1 SYNC Enable
       EPwm1Regs.DCACTL.bit.EVT1SOCE            = 1U;          -- DCAEVT1 SOC Enable
       EPwm1Regs.DCACTL.bit.EVT1FRCSYNCSEL      = 0U;          -- DCAEVT1 Force Sync Signal
       EPwm1Regs.DCACTL.bit.EVT1SRCSEL          = 0U;          -- DCAEVT1 Source Signal
       EPwm1Regs.DCACTL.bit.EVT2FRCSYNCSEL      = 0U;          -- DCAEVT2 Force Sync Signal
       EPwm1Regs.DCACTL.bit.EVT2SRCSEL          = 0U;          -- DCAEVT2 Source Signal
     */
    EPwm1Regs.DCACTL.all = (EPwm1Regs.DCACTL.all & ~0x30FU) | 0x4U;

    /*	-- Digital Compare B Control Register
       EPwm1Regs.DCBCTL.bit.EVT1SYNCE           = 0U;          -- DCBEVT1 SYNC Enable
       EPwm1Regs.DCBCTL.bit.EVT1SOCE            = 0U;          -- DCBEVT1 SOC Enable
       EPwm1Regs.DCBCTL.bit.EVT1FRCSYNCSEL      = 0U;          -- DCBEVT1 Force Sync Signal
       EPwm1Regs.DCBCTL.bit.EVT1SRCSEL          = 0U;          -- DCBEVT1 Source Signal
       EPwm1Regs.DCBCTL.bit.EVT2FRCSYNCSEL      = 0U;          -- DCBEVT2 Force Sync Signal
       EPwm1Regs.DCBCTL.bit.EVT2SRCSEL          = 0U;          -- DCBEVT2 Source Signal
     */
    EPwm1Regs.DCBCTL.all = (EPwm1Regs.DCBCTL.all & ~0x30FU) | 0x0U;

    /*	-- Digital Compare Trip Select Register
       EPwm1Regs.DCTRIPSEL.bit.DCAHCOMPSEL      = 0U;          -- Digital Compare A High COMP Input Select

       EPwm1Regs.DCTRIPSEL.bit.DCALCOMPSEL      = 1U;          -- Digital Compare A Low COMP Input Select
       EPwm1Regs.DCTRIPSEL.bit.DCBHCOMPSEL      = 0U;          -- Digital Compare B High COMP Input Select
       EPwm1Regs.DCTRIPSEL.bit.DCBLCOMPSEL      = 1U;          -- Digital Compare B Low COMP Input Select
     */
    EPwm1Regs.DCTRIPSEL.all = (EPwm1Regs.DCTRIPSEL.all & ~ 0xFFFFU) | 0x1010U;

    /*	-- Trip Zone Digital Comparator Select Register
       EPwm1Regs.TZDCSEL.bit.DCAEVT1            = 0U;          -- Digital Compare Output A Event 1
       EPwm1Regs.TZDCSEL.bit.DCAEVT2            = 0U;          -- Digital Compare Output A Event 2
       EPwm1Regs.TZDCSEL.bit.DCBEVT1            = 0U;          -- Digital Compare Output B Event 1
       EPwm1Regs.TZDCSEL.bit.DCBEVT2            = 0U;          -- Digital Compare Output B Event 2
     */
    EPwm1Regs.TZDCSEL.all = (EPwm1Regs.TZDCSEL.all & ~0xFFFU) | 0x0U;

    /*	-- Digital Compare Filter Control Register
       EPwm1Regs.DCFCTL.bit.BLANKE              = 0U;          -- Blanking Enable/Disable
       EPwm1Regs.DCFCTL.bit.PULSESEL            = 1U;          -- Pulse Select for Blanking & Capture Alignment
       EPwm1Regs.DCFCTL.bit.BLANKINV            = 0U;          -- Blanking Window Inversion
       EPwm1Regs.DCFCTL.bit.SRCSEL              = 0U;          -- Filter Block Signal Source Select
     */
    EPwm1Regs.DCFCTL.all = (EPwm1Regs.DCFCTL.all & ~0x3FU) | 0x10U;
    EPwm1Regs.DCFOFFSET = 0U;          // Digital Compare Filter Offset Register
    EPwm1Regs.DCFWINDOW = 0U;          // Digital Compare Filter Window Register

    /*	-- Digital Compare Capture Control Register
       EPwm1Regs.DCCAPCTL.bit.CAPE              = 0U;          -- Counter Capture Enable
     */
    EPwm1Regs.DCCAPCTL.all = (EPwm1Regs.DCCAPCTL.all & ~0x1U) | 0x0U;

    /*	-- HRPWM Configuration Register
       EPwm1Regs.HRCNFG.bit.SWAPAB              = 0U;          -- Swap EPWMA and EPWMB Outputs Bit
       EPwm1Regs.HRCNFG.bit.SELOUTB             = 0U;          -- EPWMB Output Selection Bit
     */
    EPwm1Regs.HRCNFG.all = (EPwm1Regs.HRCNFG.all & ~0xA0U) | 0x0U;

    /* Update the Link Registers with the link value for all the Compare values and TBPRD */
    /* No error is thrown if the ePWM register exists in the model or not */
    EPwm1Regs.EPWMXLINK.bit.TBPRDLINK = 0U;
    EPwm1Regs.EPWMXLINK.bit.CMPALINK = 0U;
    EPwm1Regs.EPWMXLINK.bit.CMPBLINK = 0U;
    EPwm1Regs.EPWMXLINK.bit.CMPCLINK = 0U;
    EPwm1Regs.EPWMXLINK.bit.CMPDLINK = 0U;

    /* SYNCPER - Peripheral synchronization output event
       EPwm1Regs.HRPCTL.bit.PWMSYNCSEL            = 0U;          -- EPWMSYNCPER selection
       EPwm1Regs.HRPCTL.bit.PWMSYNCSELX           = 0U;          --  EPWMSYNCPER selection
     */
    EPwm1Regs.HRPCTL.all = (EPwm1Regs.HRPCTL.all & ~0x72U) | 0x0U;
    EDIS;
  }

  /* Start for S-Function (c2802xpwm): '<S223>/ePWM2' */
  real32_T tbprdValue2 = (real32_T)EPwm2Regs.TBPRD;

  /*** Initialize ePWM2 modules ***/
  {
    /*  -- Time Base Control Register
       EPwm2Regs.TBCTL.bit.CTRMODE              = 2U;          -- Counter Mode
       EPwm2Regs.TBCTL.bit.SYNCOSEL             = 0U;          -- Sync Output Select

       EPwm2Regs.TBCTL.bit.PRDLD                = 0U;          -- Shadow select

       EPwm2Regs.TBCTL2.bit.PRDLDSYNC           = 0U;          -- Shadow select

       EPwm2Regs.TBCTL.bit.PHSEN                = 1U;          -- Phase Load Enable
       EPwm2Regs.TBCTL.bit.PHSDIR               = 1U;          -- Phase Direction Bit
       EPwm2Regs.TBCTL.bit.HSPCLKDIV            = 0U;          -- High Speed TBCLK Pre-scaler
       EPwm2Regs.TBCTL.bit.CLKDIV               = 0U;          -- Time Base Clock Pre-scaler
     */
    EPwm2Regs.TBCTL.all = (EPwm2Regs.TBCTL.all & ~0x3FFFU) | 0x2006U;
    EPwm2Regs.TBCTL2.all = (EPwm2Regs.TBCTL2.all & ~0xC000U) | 0x0U;

    /*-- Setup Time-Base (TB) Submodule --*/
    EPwm2Regs.TBPRD = 5000U;           // Time Base Period Register

    /* -- Time-Base Phase Register
       EPwm2Regs.TBPHS.bit.TBPHS               = 0U;          -- Phase offset register
     */
    EPwm2Regs.TBPHS.all = (EPwm2Regs.TBPHS.all & ~0xFFFF0000U) | 0x0U;

    // Time Base Counter Register
    EPwm2Regs.TBCTR = 0x0000U;         /* Clear counter*/

    /*-- Setup Counter_Compare (CC) Submodule --*/
    /*	-- Counter Compare Control Register

       EPwm2Regs.CMPCTL.bit.LOADASYNC           = 0U;          -- Active Compare A Load SYNC Option
       EPwm2Regs.CMPCTL.bit.LOADBSYNC           = 0U;          -- Active Compare B Load SYNC Option
       EPwm2Regs.CMPCTL.bit.LOADAMODE           = 0U;          -- Active Compare A Load
       EPwm2Regs.CMPCTL.bit.LOADBMODE           = 0U;          -- Active Compare B Load
       EPwm2Regs.CMPCTL.bit.SHDWAMODE           = 0U;          -- Compare A Register Block Operating Mode
       EPwm2Regs.CMPCTL.bit.SHDWBMODE           = 0U;          -- Compare B Register Block Operating Mode
     */
    EPwm2Regs.CMPCTL.all = (EPwm2Regs.CMPCTL.all & ~0x3C5FU) | 0x0U;

    /* EPwm2Regs.CMPCTL2.bit.SHDWCMODE           = 0U;          -- Compare C Register Block Operating Mode
       EPwm2Regs.CMPCTL2.bit.SHDWDMODE           = 0U;          -- Compare D Register Block Operating Mode
       EPwm2Regs.CMPCTL2.bit.LOADCSYNC           = 0U;          -- Active Compare C Load SYNC Option
       EPwm2Regs.CMPCTL2.bit.LOADDSYNC           = 0U;          -- Active Compare D Load SYNC Option
       EPwm2Regs.CMPCTL2.bit.LOADCMODE           = 0U;          -- Active Compare C Load
       EPwm2Regs.CMPCTL2.bit.LOADDMODE           = 0U;          -- Active Compare D Load
     */
    EPwm2Regs.CMPCTL2.all = (EPwm2Regs.CMPCTL2.all & ~0x3C5FU) | 0x0U;
    EPwm2Regs.CMPA.bit.CMPA = 2501U;   // Counter Compare A Register
    EPwm2Regs.CMPB.bit.CMPB = 2501U;   // Counter Compare B Register
    EPwm2Regs.CMPC = 32000U;           // Counter Compare C Register
    EPwm2Regs.CMPD = 32000U;           // Counter Compare D Register

    /*-- Setup Action-Qualifier (AQ) Submodule --*/
    EPwm2Regs.AQCTLA.all = 144U;
                               // Action Qualifier Control Register For Output A
    EPwm2Regs.AQCTLB.all = 2310U;
                               // Action Qualifier Control Register For Output B

    /*	-- Action Qualifier Software Force Register
       EPwm2Regs.AQSFRC.bit.RLDCSF              = 0U;          -- Reload from Shadow Options
     */
    EPwm2Regs.AQSFRC.all = (EPwm2Regs.AQSFRC.all & ~0xC0U) | 0x0U;

    /*	-- Action Qualifier Continuous S/W Force Register
       EPwm2Regs.AQCSFRC.bit.CSFA               = 0U;          -- Continuous Software Force on output A
       EPwm2Regs.AQCSFRC.bit.CSFB               = 0U;          -- Continuous Software Force on output B
     */
    EPwm2Regs.AQCSFRC.all = (EPwm2Regs.AQCSFRC.all & ~0xFU) | 0x0U;

    /*-- Setup Dead-Band Generator (DB) Submodule --*/
    /*	-- Dead-Band Generator Control Register
       EPwm2Regs.DBCTL.bit.OUT_MODE             = 3U;          -- Dead Band Output Mode Control
       EPwm2Regs.DBCTL.bit.IN_MODE              = 0U;          -- Dead Band Input Select Mode Control
       EPwm2Regs.DBCTL.bit.POLSEL               = 2U;          -- Polarity Select Control
       EPwm2Regs.DBCTL.bit.HALFCYCLE            = 0U;          -- Half Cycle Clocking Enable
       EPwm2Regs.DBCTL.bit.SHDWDBREDMODE        = 0U;          -- DBRED shadow mode
       EPwm2Regs.DBCTL.bit.SHDWDBFEDMODE        = 0U;          -- DBFED shadow mode
       EPwm2Regs.DBCTL.bit.LOADREDMODE          = 4U;        -- DBRED load
       EPwm2Regs.DBCTL.bit.LOADFEDMODE          = 4U;        -- DBFED load
     */
    EPwm2Regs.DBCTL.all = (EPwm2Regs.DBCTL.all & ~0x8FFFU) | 0xBU;
    EPwm2Regs.DBRED.bit.DBRED = (uint16_T)(15.0);
                         // Dead-Band Generator Rising Edge Delay Count Register
    EPwm2Regs.DBFED.bit.DBFED = (uint16_T)(15.0);
                        // Dead-Band Generator Falling Edge Delay Count Register

    /*-- Setup Event-Trigger (ET) Submodule --*/
    /*	-- Event Trigger Selection and Pre-Scale Register
       EPwm2Regs.ETSEL.bit.SOCAEN               = 0U;          -- Start of Conversion A Enable
       EPwm2Regs.ETSEL.bit.SOCASELCMP           = 0U;
       EPwm2Regs.ETSEL.bit.SOCASEL              = 2U;          -- Start of Conversion A Select
       EPwm2Regs.ETPS.bit.SOCPSSEL              = 1U;          -- EPWM2SOC Period Select
       EPwm2Regs.ETSOCPS.bit.SOCAPRD2           = 1U;
       EPwm2Regs.ETSEL.bit.SOCBEN               = 0U;          -- Start of Conversion B Enable
       EPwm2Regs.ETSEL.bit.SOCBSELCMP           = 0U;
       EPwm2Regs.ETSEL.bit.SOCBSEL              = 1U;          -- Start of Conversion A Select
       EPwm2Regs.ETPS.bit.SOCPSSEL              = 1;          -- EPWM2SOCB Period Select
       EPwm2Regs.ETSOCPS.bit.SOCBPRD2           = 1U;
       EPwm2Regs.ETSEL.bit.INTEN                = 0U;          -- EPWM2INTn Enable
       EPwm2Regs.ETSEL.bit.INTSELCMP            = 0U;
       EPwm2Regs.ETSEL.bit.INTSEL               = 1U;          -- Start of Conversion A Select
       EPwm2Regs.ETPS.bit.INTPSSEL              = 1U;          // EPWM2INTn Period Select
       EPwm2Regs.ETINTPS.bit.INTPRD2            = 1U;
     */
    EPwm2Regs.ETSEL.all = (EPwm2Regs.ETSEL.all & ~0xFF7FU) | 0x1201U;
    EPwm2Regs.ETPS.all = (EPwm2Regs.ETPS.all & ~0x30U) | 0x30U;
    EPwm2Regs.ETSOCPS.all = (EPwm2Regs.ETSOCPS.all & ~0xF0FU) | 0x101U;
    EPwm2Regs.ETINTPS.all = (EPwm2Regs.ETINTPS.all & ~0xFU) | 0x1U;

    /*-- Setup PWM-Chopper (PC) Submodule --*/
    /*	-- PWM Chopper Control Register
       EPwm2Regs.PCCTL.bit.CHPEN                = 0U;          -- PWM chopping enable
       EPwm2Regs.PCCTL.bit.CHPFREQ              = 0U;          -- Chopping clock frequency
       EPwm2Regs.PCCTL.bit.OSHTWTH              = 0U;          -- One-shot pulse width
       EPwm2Regs.PCCTL.bit.CHPDUTY              = 0U;          -- Chopping clock Duty cycle
     */
    EPwm2Regs.PCCTL.all = (EPwm2Regs.PCCTL.all & ~0x7FFU) | 0x0U;

    /*-- Set up Trip-Zone (TZ) Submodule --*/
    EALLOW;
    EPwm2Regs.TZSEL.all = 0U;          // Trip Zone Select Register

    /*	-- Trip Zone Control Register
       EPwm2Regs.TZCTL.bit.TZA                  = 3U;          -- TZ1 to TZ6 Trip Action On EPWM2A
       EPwm2Regs.TZCTL.bit.TZB                  = 3U;          -- TZ1 to TZ6 Trip Action On EPWM2B
       EPwm2Regs.TZCTL.bit.DCAEVT1              = 3U;          -- EPWM2A action on DCAEVT1
       EPwm2Regs.TZCTL.bit.DCAEVT2              = 3U;          -- EPWM2A action on DCAEVT2
       EPwm2Regs.TZCTL.bit.DCBEVT1              = 3U;          -- EPWM2B action on DCBEVT1
       EPwm2Regs.TZCTL.bit.DCBEVT2              = 3U;          -- EPWM2B action on DCBEVT2
     */
    EPwm2Regs.TZCTL.all = (EPwm2Regs.TZCTL.all & ~0xFFFU) | 0xFFFU;

    /*	-- Trip Zone Enable Interrupt Register
       EPwm2Regs.TZEINT.bit.OST                 = 0U;          -- Trip Zones One Shot Int Enable
       EPwm2Regs.TZEINT.bit.CBC                 = 0U;          -- Trip Zones Cycle By Cycle Int Enable
       EPwm2Regs.TZEINT.bit.DCAEVT1             = 0U;          -- Digital Compare A Event 1 Int Enable
       EPwm2Regs.TZEINT.bit.DCAEVT2             = 0U;          -- Digital Compare A Event 2 Int Enable
       EPwm2Regs.TZEINT.bit.DCBEVT1             = 0U;          -- Digital Compare B Event 1 Int Enable
       EPwm2Regs.TZEINT.bit.DCBEVT2             = 0U;          -- Digital Compare B Event 2 Int Enable
     */
    EPwm2Regs.TZEINT.all = (EPwm2Regs.TZEINT.all & ~0x7EU) | 0x0U;

    /*	-- Digital Compare A Control Register
       EPwm2Regs.DCACTL.bit.EVT1SYNCE           = 0U;          -- DCAEVT1 SYNC Enable
       EPwm2Regs.DCACTL.bit.EVT1SOCE            = 1U;          -- DCAEVT1 SOC Enable
       EPwm2Regs.DCACTL.bit.EVT1FRCSYNCSEL      = 0U;          -- DCAEVT1 Force Sync Signal
       EPwm2Regs.DCACTL.bit.EVT1SRCSEL          = 0U;          -- DCAEVT1 Source Signal
       EPwm2Regs.DCACTL.bit.EVT2FRCSYNCSEL      = 0U;          -- DCAEVT2 Force Sync Signal
       EPwm2Regs.DCACTL.bit.EVT2SRCSEL          = 0U;          -- DCAEVT2 Source Signal
     */
    EPwm2Regs.DCACTL.all = (EPwm2Regs.DCACTL.all & ~0x30FU) | 0x4U;

    /*	-- Digital Compare B Control Register
       EPwm2Regs.DCBCTL.bit.EVT1SYNCE           = 0U;          -- DCBEVT1 SYNC Enable
       EPwm2Regs.DCBCTL.bit.EVT1SOCE            = 0U;          -- DCBEVT1 SOC Enable
       EPwm2Regs.DCBCTL.bit.EVT1FRCSYNCSEL      = 0U;          -- DCBEVT1 Force Sync Signal
       EPwm2Regs.DCBCTL.bit.EVT1SRCSEL          = 0U;          -- DCBEVT1 Source Signal
       EPwm2Regs.DCBCTL.bit.EVT2FRCSYNCSEL      = 0U;          -- DCBEVT2 Force Sync Signal
       EPwm2Regs.DCBCTL.bit.EVT2SRCSEL          = 0U;          -- DCBEVT2 Source Signal
     */
    EPwm2Regs.DCBCTL.all = (EPwm2Regs.DCBCTL.all & ~0x30FU) | 0x0U;

    /*	-- Digital Compare Trip Select Register
       EPwm2Regs.DCTRIPSEL.bit.DCAHCOMPSEL      = 0U;          -- Digital Compare A High COMP Input Select

       EPwm2Regs.DCTRIPSEL.bit.DCALCOMPSEL      = 1U;          -- Digital Compare A Low COMP Input Select
       EPwm2Regs.DCTRIPSEL.bit.DCBHCOMPSEL      = 0U;          -- Digital Compare B High COMP Input Select
       EPwm2Regs.DCTRIPSEL.bit.DCBLCOMPSEL      = 1U;          -- Digital Compare B Low COMP Input Select
     */
    EPwm2Regs.DCTRIPSEL.all = (EPwm2Regs.DCTRIPSEL.all & ~ 0xFFFFU) | 0x1010U;

    /*	-- Trip Zone Digital Comparator Select Register
       EPwm2Regs.TZDCSEL.bit.DCAEVT1            = 0U;          -- Digital Compare Output A Event 1
       EPwm2Regs.TZDCSEL.bit.DCAEVT2            = 0U;          -- Digital Compare Output A Event 2
       EPwm2Regs.TZDCSEL.bit.DCBEVT1            = 0U;          -- Digital Compare Output B Event 1
       EPwm2Regs.TZDCSEL.bit.DCBEVT2            = 0U;          -- Digital Compare Output B Event 2
     */
    EPwm2Regs.TZDCSEL.all = (EPwm2Regs.TZDCSEL.all & ~0xFFFU) | 0x0U;

    /*	-- Digital Compare Filter Control Register
       EPwm2Regs.DCFCTL.bit.BLANKE              = 0U;          -- Blanking Enable/Disable
       EPwm2Regs.DCFCTL.bit.PULSESEL            = 1U;          -- Pulse Select for Blanking & Capture Alignment
       EPwm2Regs.DCFCTL.bit.BLANKINV            = 0U;          -- Blanking Window Inversion
       EPwm2Regs.DCFCTL.bit.SRCSEL              = 0U;          -- Filter Block Signal Source Select
     */
    EPwm2Regs.DCFCTL.all = (EPwm2Regs.DCFCTL.all & ~0x3FU) | 0x10U;
    EPwm2Regs.DCFOFFSET = 0U;          // Digital Compare Filter Offset Register
    EPwm2Regs.DCFWINDOW = 0U;          // Digital Compare Filter Window Register

    /*	-- Digital Compare Capture Control Register
       EPwm2Regs.DCCAPCTL.bit.CAPE              = 0U;          -- Counter Capture Enable
     */
    EPwm2Regs.DCCAPCTL.all = (EPwm2Regs.DCCAPCTL.all & ~0x1U) | 0x0U;

    /*	-- HRPWM Configuration Register
       EPwm2Regs.HRCNFG.bit.SWAPAB              = 0U;          -- Swap EPWMA and EPWMB Outputs Bit
       EPwm2Regs.HRCNFG.bit.SELOUTB             = 0U;          -- EPWMB Output Selection Bit
     */
    EPwm2Regs.HRCNFG.all = (EPwm2Regs.HRCNFG.all & ~0xA0U) | 0x0U;

    /* Update the Link Registers with the link value for all the Compare values and TBPRD */
    /* No error is thrown if the ePWM register exists in the model or not */
    EPwm2Regs.EPWMXLINK.bit.TBPRDLINK = 1U;
    EPwm2Regs.EPWMXLINK.bit.CMPALINK = 1U;
    EPwm2Regs.EPWMXLINK.bit.CMPBLINK = 1U;
    EPwm2Regs.EPWMXLINK.bit.CMPCLINK = 1U;
    EPwm2Regs.EPWMXLINK.bit.CMPDLINK = 1U;

    /* SYNCPER - Peripheral synchronization output event
       EPwm2Regs.HRPCTL.bit.PWMSYNCSEL            = 0U;          -- EPWMSYNCPER selection
       EPwm2Regs.HRPCTL.bit.PWMSYNCSELX           = 0U;          --  EPWMSYNCPER selection
     */
    EPwm2Regs.HRPCTL.all = (EPwm2Regs.HRPCTL.all & ~0x72U) | 0x0U;
    EDIS;
  }

  /* Start for S-Function (c2802xpwm): '<S223>/ePWM3' */
  real32_T tbprdValue3 = (real32_T)EPwm3Regs.TBPRD;

  /*** Initialize ePWM3 modules ***/
  {
    /*  -- Time Base Control Register
       EPwm3Regs.TBCTL.bit.CTRMODE              = 2U;          -- Counter Mode
       EPwm3Regs.TBCTL.bit.SYNCOSEL             = 0U;          -- Sync Output Select

       EPwm3Regs.TBCTL.bit.PRDLD                = 0U;          -- Shadow select

       EPwm3Regs.TBCTL2.bit.PRDLDSYNC           = 0U;          -- Shadow select

       EPwm3Regs.TBCTL.bit.PHSEN                = 1U;          -- Phase Load Enable
       EPwm3Regs.TBCTL.bit.PHSDIR               = 1U;          -- Phase Direction Bit
       EPwm3Regs.TBCTL.bit.HSPCLKDIV            = 0U;          -- High Speed TBCLK Pre-scaler
       EPwm3Regs.TBCTL.bit.CLKDIV               = 0U;          -- Time Base Clock Pre-scaler
     */
    EPwm3Regs.TBCTL.all = (EPwm3Regs.TBCTL.all & ~0x3FFFU) | 0x2006U;
    EPwm3Regs.TBCTL2.all = (EPwm3Regs.TBCTL2.all & ~0xC000U) | 0x0U;

    /*-- Setup Time-Base (TB) Submodule --*/
    EPwm3Regs.TBPRD = 5000U;           // Time Base Period Register

    /* -- Time-Base Phase Register
       EPwm3Regs.TBPHS.bit.TBPHS               = 0U;          -- Phase offset register
     */
    EPwm3Regs.TBPHS.all = (EPwm3Regs.TBPHS.all & ~0xFFFF0000U) | 0x0U;

    // Time Base Counter Register
    EPwm3Regs.TBCTR = 0x0000U;         /* Clear counter*/

    /*-- Setup Counter_Compare (CC) Submodule --*/
    /*	-- Counter Compare Control Register

       EPwm3Regs.CMPCTL.bit.LOADASYNC           = 0U;          -- Active Compare A Load SYNC Option
       EPwm3Regs.CMPCTL.bit.LOADBSYNC           = 0U;          -- Active Compare B Load SYNC Option
       EPwm3Regs.CMPCTL.bit.LOADAMODE           = 0U;          -- Active Compare A Load
       EPwm3Regs.CMPCTL.bit.LOADBMODE           = 0U;          -- Active Compare B Load
       EPwm3Regs.CMPCTL.bit.SHDWAMODE           = 0U;          -- Compare A Register Block Operating Mode
       EPwm3Regs.CMPCTL.bit.SHDWBMODE           = 0U;          -- Compare B Register Block Operating Mode
     */
    EPwm3Regs.CMPCTL.all = (EPwm3Regs.CMPCTL.all & ~0x3C5FU) | 0x0U;

    /* EPwm3Regs.CMPCTL2.bit.SHDWCMODE           = 0U;          -- Compare C Register Block Operating Mode
       EPwm3Regs.CMPCTL2.bit.SHDWDMODE           = 0U;          -- Compare D Register Block Operating Mode
       EPwm3Regs.CMPCTL2.bit.LOADCSYNC           = 0U;          -- Active Compare C Load SYNC Option
       EPwm3Regs.CMPCTL2.bit.LOADDSYNC           = 0U;          -- Active Compare D Load SYNC Option
       EPwm3Regs.CMPCTL2.bit.LOADCMODE           = 0U;          -- Active Compare C Load
       EPwm3Regs.CMPCTL2.bit.LOADDMODE           = 0U;          -- Active Compare D Load
     */
    EPwm3Regs.CMPCTL2.all = (EPwm3Regs.CMPCTL2.all & ~0x3C5FU) | 0x0U;
    EPwm3Regs.CMPA.bit.CMPA = 2501U;   // Counter Compare A Register
    EPwm3Regs.CMPB.bit.CMPB = 2501U;   // Counter Compare B Register
    EPwm3Regs.CMPC = 32000U;           // Counter Compare C Register
    EPwm3Regs.CMPD = 32000U;           // Counter Compare D Register

    /*-- Setup Action-Qualifier (AQ) Submodule --*/
    EPwm3Regs.AQCTLA.all = 144U;
                               // Action Qualifier Control Register For Output A
    EPwm3Regs.AQCTLB.all = 2310U;
                               // Action Qualifier Control Register For Output B

    /*	-- Action Qualifier Software Force Register
       EPwm3Regs.AQSFRC.bit.RLDCSF              = 0U;          -- Reload from Shadow Options
     */
    EPwm3Regs.AQSFRC.all = (EPwm3Regs.AQSFRC.all & ~0xC0U) | 0x0U;

    /*	-- Action Qualifier Continuous S/W Force Register
       EPwm3Regs.AQCSFRC.bit.CSFA               = 0U;          -- Continuous Software Force on output A
       EPwm3Regs.AQCSFRC.bit.CSFB               = 0U;          -- Continuous Software Force on output B
     */
    EPwm3Regs.AQCSFRC.all = (EPwm3Regs.AQCSFRC.all & ~0xFU) | 0x0U;

    /*-- Setup Dead-Band Generator (DB) Submodule --*/
    /*	-- Dead-Band Generator Control Register
       EPwm3Regs.DBCTL.bit.OUT_MODE             = 3U;          -- Dead Band Output Mode Control
       EPwm3Regs.DBCTL.bit.IN_MODE              = 0U;          -- Dead Band Input Select Mode Control
       EPwm3Regs.DBCTL.bit.POLSEL               = 2U;          -- Polarity Select Control
       EPwm3Regs.DBCTL.bit.HALFCYCLE            = 0U;          -- Half Cycle Clocking Enable
       EPwm3Regs.DBCTL.bit.SHDWDBREDMODE        = 0U;          -- DBRED shadow mode
       EPwm3Regs.DBCTL.bit.SHDWDBFEDMODE        = 0U;          -- DBFED shadow mode
       EPwm3Regs.DBCTL.bit.LOADREDMODE          = 4U;        -- DBRED load
       EPwm3Regs.DBCTL.bit.LOADFEDMODE          = 4U;        -- DBFED load
     */
    EPwm3Regs.DBCTL.all = (EPwm3Regs.DBCTL.all & ~0x8FFFU) | 0xBU;
    EPwm3Regs.DBRED.bit.DBRED = (uint16_T)(15.0);
                         // Dead-Band Generator Rising Edge Delay Count Register
    EPwm3Regs.DBFED.bit.DBFED = (uint16_T)(15.0);
                        // Dead-Band Generator Falling Edge Delay Count Register

    /*-- Setup Event-Trigger (ET) Submodule --*/
    /*	-- Event Trigger Selection and Pre-Scale Register
       EPwm3Regs.ETSEL.bit.SOCAEN               = 0U;          -- Start of Conversion A Enable
       EPwm3Regs.ETSEL.bit.SOCASELCMP           = 0U;
       EPwm3Regs.ETSEL.bit.SOCASEL              = 2U;          -- Start of Conversion A Select
       EPwm3Regs.ETPS.bit.SOCPSSEL              = 1U;          -- EPWM3SOC Period Select
       EPwm3Regs.ETSOCPS.bit.SOCAPRD2           = 1U;
       EPwm3Regs.ETSEL.bit.SOCBEN               = 0U;          -- Start of Conversion B Enable
       EPwm3Regs.ETSEL.bit.SOCBSELCMP           = 0U;
       EPwm3Regs.ETSEL.bit.SOCBSEL              = 1U;          -- Start of Conversion A Select
       EPwm3Regs.ETPS.bit.SOCPSSEL              = 1;          -- EPWM3SOCB Period Select
       EPwm3Regs.ETSOCPS.bit.SOCBPRD2           = 1U;
       EPwm3Regs.ETSEL.bit.INTEN                = 0U;          -- EPWM3INTn Enable
       EPwm3Regs.ETSEL.bit.INTSELCMP            = 0U;
       EPwm3Regs.ETSEL.bit.INTSEL               = 1U;          -- Start of Conversion A Select
       EPwm3Regs.ETPS.bit.INTPSSEL              = 1U;          // EPWM3INTn Period Select
       EPwm3Regs.ETINTPS.bit.INTPRD2            = 1U;
     */
    EPwm3Regs.ETSEL.all = (EPwm3Regs.ETSEL.all & ~0xFF7FU) | 0x1201U;
    EPwm3Regs.ETPS.all = (EPwm3Regs.ETPS.all & ~0x30U) | 0x30U;
    EPwm3Regs.ETSOCPS.all = (EPwm3Regs.ETSOCPS.all & ~0xF0FU) | 0x101U;
    EPwm3Regs.ETINTPS.all = (EPwm3Regs.ETINTPS.all & ~0xFU) | 0x1U;

    /*-- Setup PWM-Chopper (PC) Submodule --*/
    /*	-- PWM Chopper Control Register
       EPwm3Regs.PCCTL.bit.CHPEN                = 0U;          -- PWM chopping enable
       EPwm3Regs.PCCTL.bit.CHPFREQ              = 0U;          -- Chopping clock frequency
       EPwm3Regs.PCCTL.bit.OSHTWTH              = 0U;          -- One-shot pulse width
       EPwm3Regs.PCCTL.bit.CHPDUTY              = 0U;          -- Chopping clock Duty cycle
     */
    EPwm3Regs.PCCTL.all = (EPwm3Regs.PCCTL.all & ~0x7FFU) | 0x0U;

    /*-- Set up Trip-Zone (TZ) Submodule --*/
    EALLOW;
    EPwm3Regs.TZSEL.all = 0U;          // Trip Zone Select Register

    /*	-- Trip Zone Control Register
       EPwm3Regs.TZCTL.bit.TZA                  = 3U;          -- TZ1 to TZ6 Trip Action On EPWM3A
       EPwm3Regs.TZCTL.bit.TZB                  = 3U;          -- TZ1 to TZ6 Trip Action On EPWM3B
       EPwm3Regs.TZCTL.bit.DCAEVT1              = 3U;          -- EPWM3A action on DCAEVT1
       EPwm3Regs.TZCTL.bit.DCAEVT2              = 3U;          -- EPWM3A action on DCAEVT2
       EPwm3Regs.TZCTL.bit.DCBEVT1              = 3U;          -- EPWM3B action on DCBEVT1
       EPwm3Regs.TZCTL.bit.DCBEVT2              = 3U;          -- EPWM3B action on DCBEVT2
     */
    EPwm3Regs.TZCTL.all = (EPwm3Regs.TZCTL.all & ~0xFFFU) | 0xFFFU;

    /*	-- Trip Zone Enable Interrupt Register
       EPwm3Regs.TZEINT.bit.OST                 = 0U;          -- Trip Zones One Shot Int Enable
       EPwm3Regs.TZEINT.bit.CBC                 = 0U;          -- Trip Zones Cycle By Cycle Int Enable
       EPwm3Regs.TZEINT.bit.DCAEVT1             = 0U;          -- Digital Compare A Event 1 Int Enable
       EPwm3Regs.TZEINT.bit.DCAEVT2             = 0U;          -- Digital Compare A Event 2 Int Enable
       EPwm3Regs.TZEINT.bit.DCBEVT1             = 0U;          -- Digital Compare B Event 1 Int Enable
       EPwm3Regs.TZEINT.bit.DCBEVT2             = 0U;          -- Digital Compare B Event 2 Int Enable
     */
    EPwm3Regs.TZEINT.all = (EPwm3Regs.TZEINT.all & ~0x7EU) | 0x0U;

    /*	-- Digital Compare A Control Register
       EPwm3Regs.DCACTL.bit.EVT1SYNCE           = 0U;          -- DCAEVT1 SYNC Enable
       EPwm3Regs.DCACTL.bit.EVT1SOCE            = 1U;          -- DCAEVT1 SOC Enable
       EPwm3Regs.DCACTL.bit.EVT1FRCSYNCSEL      = 0U;          -- DCAEVT1 Force Sync Signal
       EPwm3Regs.DCACTL.bit.EVT1SRCSEL          = 0U;          -- DCAEVT1 Source Signal
       EPwm3Regs.DCACTL.bit.EVT2FRCSYNCSEL      = 0U;          -- DCAEVT2 Force Sync Signal
       EPwm3Regs.DCACTL.bit.EVT2SRCSEL          = 0U;          -- DCAEVT2 Source Signal
     */
    EPwm3Regs.DCACTL.all = (EPwm3Regs.DCACTL.all & ~0x30FU) | 0x4U;

    /*	-- Digital Compare B Control Register
       EPwm3Regs.DCBCTL.bit.EVT1SYNCE           = 0U;          -- DCBEVT1 SYNC Enable
       EPwm3Regs.DCBCTL.bit.EVT1SOCE            = 0U;          -- DCBEVT1 SOC Enable
       EPwm3Regs.DCBCTL.bit.EVT1FRCSYNCSEL      = 0U;          -- DCBEVT1 Force Sync Signal
       EPwm3Regs.DCBCTL.bit.EVT1SRCSEL          = 0U;          -- DCBEVT1 Source Signal
       EPwm3Regs.DCBCTL.bit.EVT2FRCSYNCSEL      = 0U;          -- DCBEVT2 Force Sync Signal
       EPwm3Regs.DCBCTL.bit.EVT2SRCSEL          = 0U;          -- DCBEVT2 Source Signal
     */
    EPwm3Regs.DCBCTL.all = (EPwm3Regs.DCBCTL.all & ~0x30FU) | 0x0U;

    /*	-- Digital Compare Trip Select Register
       EPwm3Regs.DCTRIPSEL.bit.DCAHCOMPSEL      = 0U;          -- Digital Compare A High COMP Input Select

       EPwm3Regs.DCTRIPSEL.bit.DCALCOMPSEL      = 1U;          -- Digital Compare A Low COMP Input Select
       EPwm3Regs.DCTRIPSEL.bit.DCBHCOMPSEL      = 0U;          -- Digital Compare B High COMP Input Select
       EPwm3Regs.DCTRIPSEL.bit.DCBLCOMPSEL      = 1U;          -- Digital Compare B Low COMP Input Select
     */
    EPwm3Regs.DCTRIPSEL.all = (EPwm3Regs.DCTRIPSEL.all & ~ 0xFFFFU) | 0x1010U;

    /*	-- Trip Zone Digital Comparator Select Register
       EPwm3Regs.TZDCSEL.bit.DCAEVT1            = 0U;          -- Digital Compare Output A Event 1
       EPwm3Regs.TZDCSEL.bit.DCAEVT2            = 0U;          -- Digital Compare Output A Event 2
       EPwm3Regs.TZDCSEL.bit.DCBEVT1            = 0U;          -- Digital Compare Output B Event 1
       EPwm3Regs.TZDCSEL.bit.DCBEVT2            = 0U;          -- Digital Compare Output B Event 2
     */
    EPwm3Regs.TZDCSEL.all = (EPwm3Regs.TZDCSEL.all & ~0xFFFU) | 0x0U;

    /*	-- Digital Compare Filter Control Register
       EPwm3Regs.DCFCTL.bit.BLANKE              = 0U;          -- Blanking Enable/Disable
       EPwm3Regs.DCFCTL.bit.PULSESEL            = 1U;          -- Pulse Select for Blanking & Capture Alignment
       EPwm3Regs.DCFCTL.bit.BLANKINV            = 0U;          -- Blanking Window Inversion
       EPwm3Regs.DCFCTL.bit.SRCSEL              = 0U;          -- Filter Block Signal Source Select
     */
    EPwm3Regs.DCFCTL.all = (EPwm3Regs.DCFCTL.all & ~0x3FU) | 0x10U;
    EPwm3Regs.DCFOFFSET = 0U;          // Digital Compare Filter Offset Register
    EPwm3Regs.DCFWINDOW = 0U;          // Digital Compare Filter Window Register

    /*	-- Digital Compare Capture Control Register
       EPwm3Regs.DCCAPCTL.bit.CAPE              = 0U;          -- Counter Capture Enable
     */
    EPwm3Regs.DCCAPCTL.all = (EPwm3Regs.DCCAPCTL.all & ~0x1U) | 0x0U;

    /*	-- HRPWM Configuration Register
       EPwm3Regs.HRCNFG.bit.SWAPAB              = 0U;          -- Swap EPWMA and EPWMB Outputs Bit
       EPwm3Regs.HRCNFG.bit.SELOUTB             = 0U;          -- EPWMB Output Selection Bit
     */
    EPwm3Regs.HRCNFG.all = (EPwm3Regs.HRCNFG.all & ~0xA0U) | 0x0U;

    /* Update the Link Registers with the link value for all the Compare values and TBPRD */
    /* No error is thrown if the ePWM register exists in the model or not */
    EPwm3Regs.EPWMXLINK.bit.TBPRDLINK = 2U;
    EPwm3Regs.EPWMXLINK.bit.CMPALINK = 2U;
    EPwm3Regs.EPWMXLINK.bit.CMPBLINK = 2U;
    EPwm3Regs.EPWMXLINK.bit.CMPCLINK = 2U;
    EPwm3Regs.EPWMXLINK.bit.CMPDLINK = 2U;

    /* SYNCPER - Peripheral synchronization output event
       EPwm3Regs.HRPCTL.bit.PWMSYNCSEL            = 0U;          -- EPWMSYNCPER selection
       EPwm3Regs.HRPCTL.bit.PWMSYNCSELX           = 0U;          --  EPWMSYNCPER selection
     */
    EPwm3Regs.HRPCTL.all = (EPwm3Regs.HRPCTL.all & ~0x72U) | 0x0U;
    EDIS;
  }

  /* InitializeConditions for Delay: '<S197>/Delay' */
  mcb_pmsm_foc_qep_f28379d_DW.CircBufIdx = 0U;

  /* SystemInitialize for Enabled SubSystem: '<S8>/Closed Loop Control' */
  /* Start for Constant: '<S27>/Kp1' */
  mcb_pmsm_foc_qep_f28379d_B.Kp1 = 0.0F;

  /* Start for Constant: '<S26>/Ki1' */
  mcb_pmsm_foc_qep_f28379d_B.Ki1 = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S134>/Integrator' */
  mcb_pmsm_foc_qep_f28379d_DW.Integrator_DSTATE = 0.0F;
  mcb_pmsm_foc_qep_f28379d_DW.Integrator_PrevResetState = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S79>/Integrator' */
  mcb_pmsm_foc_qep_f28379d_DW.Integrator_DSTATE_o = 0.0F;
  mcb_pmsm_foc_qep_f28379d_DW.Integrator_PrevResetState_k = 0;

  /* End of SystemInitialize for SubSystem: '<S8>/Closed Loop Control' */
}

/* System reset for function-call system: '<Root>/Current Control' */
void mcb_pm_CurrentControl_Reset(void)
{
  /* InitializeConditions for Delay: '<S197>/Delay' */
  mcb_pmsm_foc_qep_f28379d_DW.CircBufIdx = 0U;
}

/* Disable for function-call system: '<Root>/Current Control' */
#pragma CODE_SECTION (mcb__CurrentControl_Disable, "ramfuncs")

void mcb__CurrentControl_Disable(void)
{
  /* Disable for Enabled SubSystem: '<S8>/Open Loop Start-Up' */
  if (mcb_pmsm_foc_qep_f28379d_DW.OpenLoopStartUp_MODE) {
    /* Disable for DiscreteIntegrator: '<S173>/Ramp Generator' */
    mcb_pmsm_foc_qep_f28379d_DW.RampGenerator_DSTATE =
      mcb_pmsm_foc_qep_f28379d_B.Eps;
    mcb_pmsm_foc_qep_f28379d_DW.OpenLoopStartUp_MODE = false;
  }

  /* End of Disable for SubSystem: '<S8>/Open Loop Start-Up' */
}

/* Output and update for function-call system: '<Root>/Current Control' */
#pragma CODE_SECTION (mcb_pmsm_foc_CurrentControl, "ramfuncs")

void mcb_pmsm_foc_CurrentControl(void)
{
  real32_T Bias;
  real32_T u0_0;
  uint32_T Sum_e;
  int16_T s227_iter;
  uint16_T u0;
  uint16_T u1;

  /* S-Function (c280xqep): '<S190>/eQEP' */
  {
    mcb_pmsm_foc_qep_f28379d_B.eQEP_o1 = EQep1Regs.QPOSCNT;/*eQEP Position Counter*/
    mcb_pmsm_foc_qep_f28379d_B.eQEP_o2 = EQep1Regs.QPOSILAT;
         /* The position-counter value is latched into this register on an IEL*/
  }

  /* Delay: '<S191>/Delay' */
  mcb_pmsm_foc_qep_f28379d_B.Delay_p =
    mcb_pmsm_foc_qep_f28379d_DW.Delay_DSTATE_m;

  /* Logic: '<S191>/NOT' */
  mcb_pmsm_foc_qep_f28379d_B.NOT_m = !mcb_pmsm_foc_qep_f28379d_B.Delay_p;

  /* Outputs for Enabled SubSystem: '<S191>/IndexFinder' incorporates:
   *  EnablePort: '<S194>/Enable'
   */
  if (mcb_pmsm_foc_qep_f28379d_B.NOT_m) {
    /* Delay: '<S194>/Delay3' */
    mcb_pmsm_foc_qep_f28379d_B.Delay3 =
      mcb_pmsm_foc_qep_f28379d_DW.Delay3_DSTATE;

    /* RelationalOperator: '<S201>/Compare' incorporates:
     *  Constant: '<S201>/Constant'
     */
    mcb_pmsm_foc_qep_f28379d_B.Compare = (mcb_pmsm_foc_qep_f28379d_B.Delay3 ==
      0U);

    /* RelationalOperator: '<S202>/Compare' incorporates:
     *  Constant: '<S202>/Constant'
     */
    mcb_pmsm_foc_qep_f28379d_B.Compare_e = (mcb_pmsm_foc_qep_f28379d_B.eQEP_o2 >
      0U);

    /* Logic: '<S194>/AND' */
    mcb_pmsm_foc_qep_f28379d_B.AND = (mcb_pmsm_foc_qep_f28379d_B.Compare &&
      mcb_pmsm_foc_qep_f28379d_B.Compare_e);

    /* Update for Delay: '<S194>/Delay3' */
    mcb_pmsm_foc_qep_f28379d_DW.Delay3_DSTATE =
      mcb_pmsm_foc_qep_f28379d_B.eQEP_o2;
  }

  /* End of Outputs for SubSystem: '<S191>/IndexFinder' */

  /* DataStoreWrite: '<S8>/Data Store Write' */
  mcb_pmsm_foc_qep_f28379d_DW.EnClosedLoop = mcb_pmsm_foc_qep_f28379d_B.AND;

  /* DataStoreRead: '<S192>/Data Store Read1' */
  mcb_pmsm_foc_qep_f28379d_B.DataStoreRead1 =
    mcb_pmsm_foc_qep_f28379d_DW.IaOffset;

  /* DataStoreRead: '<S192>/Data Store Read2' */
  mcb_pmsm_foc_qep_f28379d_B.DataStoreRead2 =
    mcb_pmsm_foc_qep_f28379d_DW.IbOffset;

  /* S-Function (c2802xadc): '<S190>/ADC_C_IN2' */
  {
    /*  Internal Reference Voltage : Fixed scale 0 to 3.3 V range.  */
    /*  External Reference Voltage : Allowable ranges of VREFHI(ADCINA0) = 3.3 and VREFLO(tied to ground) = 0  */
    mcb_pmsm_foc_qep_f28379d_B.ADC_C_IN2 = (AdccResultRegs.ADCRESULT0);
  }

  /* S-Function (c2802xadc): '<S190>/ADC_B_IN2' */
  {
    /*  Internal Reference Voltage : Fixed scale 0 to 3.3 V range.  */
    /*  External Reference Voltage : Allowable ranges of VREFHI(ADCINA0) = 3.3 and VREFLO(tied to ground) = 0  */
    mcb_pmsm_foc_qep_f28379d_B.ADC_B_IN2 = (AdcbResultRegs.ADCRESULT0);
  }

  /* DataTypeConversion: '<S192>/Data Type Conversion' */
  mcb_pmsm_foc_qep_f28379d_B.DataTypeConversion_c[0] =
    mcb_pmsm_foc_qep_f28379d_B.ADC_C_IN2;
  mcb_pmsm_foc_qep_f28379d_B.DataTypeConversion_c[1] =
    mcb_pmsm_foc_qep_f28379d_B.ADC_B_IN2;

  /* Sum: '<S192>/Add' */
  mcb_pmsm_foc_qep_f28379d_B.Add_e[0] =
    mcb_pmsm_foc_qep_f28379d_B.DataTypeConversion_c[0] -
    mcb_pmsm_foc_qep_f28379d_B.DataStoreRead1;
  mcb_pmsm_foc_qep_f28379d_B.Add_e[1] =
    mcb_pmsm_foc_qep_f28379d_B.DataTypeConversion_c[1] -
    mcb_pmsm_foc_qep_f28379d_B.DataStoreRead2;

  /* Gain: '<S222>/Get ADC Voltage' */
  Bias = 0.000732600747F * (real32_T)mcb_pmsm_foc_qep_f28379d_B.Add_e[0];
  mcb_pmsm_foc_qep_f28379d_B.GetADCVoltage[0] = Bias;

  /* Gain: '<S222>/Get Currents' */
  Bias *= 14.2857141F;
  mcb_pmsm_foc_qep_f28379d_B.GetCurrents[0] = Bias;

  /* Gain: '<S222>/PU_Conversion' */
  mcb_pmsm_foc_qep_f28379d_B.PU_Conversion[0] = 0.0466666669F * Bias;

  /* Gain: '<S222>/Get ADC Voltage' */
  Bias = 0.000732600747F * (real32_T)mcb_pmsm_foc_qep_f28379d_B.Add_e[1];
  mcb_pmsm_foc_qep_f28379d_B.GetADCVoltage[1] = Bias;

  /* Gain: '<S222>/Get Currents' */
  Bias *= 14.2857141F;
  mcb_pmsm_foc_qep_f28379d_B.GetCurrents[1] = Bias;

  /* Gain: '<S222>/PU_Conversion' */
  mcb_pmsm_foc_qep_f28379d_B.PU_Conversion[1] = 0.0466666669F * Bias;

  /* Outputs for IfAction SubSystem: '<S196>/PositionNoReset' incorporates:
   *  ActionPort: '<S212>/Action Port'
   */
  /* If: '<S196>/If1' incorporates:
   *  Constant: '<S217>/Constant'
   *  Merge: '<S196>/Merge'
   *  MinMax: '<S212>/MinMax'
   *  Sum: '<S212>/Sum3'
   *  Sum: '<S212>/Sum7'
   */
  mcb_pmsm_foc_qep_f28379d_B.Sum3_a = mcb_pmsm_foc_qep_f28379d_B.eQEP_o1 -
    mcb_pmsm_foc_qep_f28379d_B.eQEP_o2;
  mcb_pmsm_foc_qep_f28379d_B.Sum7 = mcb_pmsm_foc_qep_f28379d_B.Sum3_a + 4000U;
  u0 = mcb_pmsm_foc_qep_f28379d_B.Sum3_a;
  u1 = mcb_pmsm_foc_qep_f28379d_B.Sum7;
  if (u0 <= u1) {
    u1 = u0;
  }

  mcb_pmsm_foc_qep_f28379d_B.Merge_h5 = u1;

  /* End of If: '<S196>/If1' */
  /* End of Outputs for SubSystem: '<S196>/PositionNoReset' */

  /* DataTypeConversion: '<S215>/DTC' */
  mcb_pmsm_foc_qep_f28379d_B.DTC = mcb_pmsm_foc_qep_f28379d_B.Merge_h5;

  /* Product: '<S196>/Product' incorporates:
   *  Constant: '<S218>/Constant'
   */
  mcb_pmsm_foc_qep_f28379d_B.Product = mcb_pmsm_foc_qep_f28379d_B.DTC * 0.00025F;

  /* Switch: '<S204>/Switch' incorporates:
   *  Constant: '<S11>/IndexOffset'
   */
  mcb_pmsm_foc_qep_f28379d_B.Switch = 0.0765F;

  /* If: '<S205>/If' */
  if (mcb_pmsm_foc_qep_f28379d_B.Product <= 0.0765F) {
    /* Outputs for IfAction SubSystem: '<S205>/If Action Subsystem' incorporates:
     *  ActionPort: '<S207>/Action Port'
     */
    /* Merge: '<S205>/Merge' incorporates:
     *  Constant: '<S207>/Constant'
     *  Sum: '<S207>/Add'
     */
    mcb_pmsm_foc_qep_f28379d_B.Merge = (mcb_pmsm_foc_qep_f28379d_B.Product +
      1.0F) - 0.0765F;

    /* End of Outputs for SubSystem: '<S205>/If Action Subsystem' */
  } else {
    /* Outputs for IfAction SubSystem: '<S205>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S208>/Action Port'
     */
    /* Merge: '<S205>/Merge' incorporates:
     *  Sum: '<S208>/Add'
     */
    mcb_pmsm_foc_qep_f28379d_B.Merge = mcb_pmsm_foc_qep_f28379d_B.Product -
      0.0765F;

    /* End of Outputs for SubSystem: '<S205>/If Action Subsystem1' */
  }

  /* End of If: '<S205>/If' */

  /* Gain: '<S210>/Number of pole pairs' */
  mcb_pmsm_foc_qep_f28379d_B.Numberofpolepairs = 4.0F *
    mcb_pmsm_foc_qep_f28379d_B.Merge;

  /* Rounding: '<S206>/Floor' */
  mcb_pmsm_foc_qep_f28379d_B.Floor = (real32_T)floor
    (mcb_pmsm_foc_qep_f28379d_B.Numberofpolepairs);

  /* Sum: '<S206>/Add' */
  mcb_pmsm_foc_qep_f28379d_B.Add_c =
    mcb_pmsm_foc_qep_f28379d_B.Numberofpolepairs -
    mcb_pmsm_foc_qep_f28379d_B.Floor;

  /* Outputs for Enabled SubSystem: '<S8>/Closed Loop Control' incorporates:
   *  EnablePort: '<S15>/Enable'
   */
  if (mcb_pmsm_foc_qep_f28379d_B.AND) {
    /* Outputs for Atomic SubSystem: '<S23>/Two phase CRL wrap' */
    /* Sum: '<S24>/a_plus_2b' */
    mcb_pmsm_foc_qep_f28379d_B.a_plus_2b =
      (mcb_pmsm_foc_qep_f28379d_B.PU_Conversion[0] +
       mcb_pmsm_foc_qep_f28379d_B.PU_Conversion[1]) +
      mcb_pmsm_foc_qep_f28379d_B.PU_Conversion[1];

    /* Gain: '<S24>/one_by_sqrt3' */
    mcb_pmsm_foc_qep_f28379d_B.one_by_sqrt3 = 0.577350259F *
      mcb_pmsm_foc_qep_f28379d_B.a_plus_2b;

    /* AlgorithmDescriptorDelegate generated from: '<S24>/a16' */
    mcb_pmsm_foc_qep_f28379d_B.algDD_o1_e =
      mcb_pmsm_foc_qep_f28379d_B.PU_Conversion[0];

    /* AlgorithmDescriptorDelegate generated from: '<S24>/a16' */
    mcb_pmsm_foc_qep_f28379d_B.algDD_o2_h =
      mcb_pmsm_foc_qep_f28379d_B.one_by_sqrt3;

    /* End of Outputs for SubSystem: '<S23>/Two phase CRL wrap' */

    /* Switch: '<S30>/Switch1' incorporates:
     *  Constant: '<S30>/ChosenMethod'
     */
    mcb_pmsm_foc_qep_f28379d_B.Switch1_jb = 3U;

    /* SignalConversion generated from: '<S15>/Idq_ref_PU' */
    mcb_pmsm_foc_qep_f28379d_B.Idq_ref_PU[0] = mcb_pmsm_foc_qep_f28379d_B.RT2[0];
    mcb_pmsm_foc_qep_f28379d_B.Idq_ref_PU[1] = mcb_pmsm_foc_qep_f28379d_B.RT2[1];

    /* RelationalOperator: '<S160>/Compare' incorporates:
     *  Constant: '<S160>/Constant'
     */
    mcb_pmsm_foc_qep_f28379d_B.Compare_d = (mcb_pmsm_foc_qep_f28379d_B.Add_c <
      0.0F);

    /* DataTypeConversion: '<S158>/Data Type Conversion' */
    mcb_pmsm_foc_qep_f28379d_B.DataTypeConversion_p =
      mcb_pmsm_foc_qep_f28379d_B.Compare_d;

    /* If: '<S158>/If' */
    if (mcb_pmsm_foc_qep_f28379d_B.DataTypeConversion_p > 0U) {
      /* Outputs for IfAction SubSystem: '<S158>/If Action Subsystem' incorporates:
       *  ActionPort: '<S161>/Action Port'
       */
      mcb_pmsm__IfActionSubsystem(mcb_pmsm_foc_qep_f28379d_B.Add_c,
        &mcb_pmsm_foc_qep_f28379d_B.Merge_b,
        &mcb_pmsm_foc_qep_f28379d_B.IfActionSubsystem_m);

      /* End of Outputs for SubSystem: '<S158>/If Action Subsystem' */
    } else {
      /* Outputs for IfAction SubSystem: '<S158>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S162>/Action Port'
       */
      mcb_pmsm_IfActionSubsystem1(mcb_pmsm_foc_qep_f28379d_B.Add_c,
        &mcb_pmsm_foc_qep_f28379d_B.Merge_b,
        &mcb_pmsm_foc_qep_f28379d_B.IfActionSubsystem1_m);

      /* End of Outputs for SubSystem: '<S158>/If Action Subsystem1' */
    }

    /* End of If: '<S158>/If' */

    /* Gain: '<S156>/indexing' */
    mcb_pmsm_foc_qep_f28379d_B.indexing_n = 800.0F *
      mcb_pmsm_foc_qep_f28379d_B.Merge_b;

    /* DataTypeConversion: '<S156>/Get_Integer' */
    mcb_pmsm_foc_qep_f28379d_B.Get_Integer_l = (uint16_T)
      mcb_pmsm_foc_qep_f28379d_B.indexing_n;

    /* Sum: '<S156>/Sum' incorporates:
     *  Constant: '<S156>/offset'
     */
    Sum_e = mcb_pmsm_foc_qep_f28379d_B.Get_Integer_l + 1UL;
    mcb_pmsm_foc_qep_f28379d_B.Sum_e[0] = Sum_e;

    /* Selector: '<S156>/Lookup' incorporates:
     *  Constant: '<S156>/sine_table_values'
     */
    mcb_pmsm_foc_qep_f28379d_B.Lookup_p[0] =
      mcb_pmsm_foc_qep_f28379d_ConstP.pooled5[(int16_T)Sum_e];

    /* Sum: '<S156>/Sum' */
    Sum_e = mcb_pmsm_foc_qep_f28379d_B.Get_Integer_l;
    mcb_pmsm_foc_qep_f28379d_B.Sum_e[1] = Sum_e;

    /* Selector: '<S156>/Lookup' incorporates:
     *  Constant: '<S156>/sine_table_values'
     */
    mcb_pmsm_foc_qep_f28379d_B.Lookup_p[1] =
      mcb_pmsm_foc_qep_f28379d_ConstP.pooled5[(int16_T)Sum_e];

    /* Sum: '<S156>/Sum' incorporates:
     *  Constant: '<S156>/offset'
     */
    Sum_e = mcb_pmsm_foc_qep_f28379d_B.Get_Integer_l + 201UL;
    mcb_pmsm_foc_qep_f28379d_B.Sum_e[2] = Sum_e;

    /* Selector: '<S156>/Lookup' incorporates:
     *  Constant: '<S156>/sine_table_values'
     */
    mcb_pmsm_foc_qep_f28379d_B.Lookup_p[2] =
      mcb_pmsm_foc_qep_f28379d_ConstP.pooled5[(int16_T)Sum_e];

    /* Sum: '<S156>/Sum' incorporates:
     *  Constant: '<S156>/offset'
     */
    Sum_e = mcb_pmsm_foc_qep_f28379d_B.Get_Integer_l + 200UL;
    mcb_pmsm_foc_qep_f28379d_B.Sum_e[3] = Sum_e;

    /* Selector: '<S156>/Lookup' incorporates:
     *  Constant: '<S156>/sine_table_values'
     */
    mcb_pmsm_foc_qep_f28379d_B.Lookup_p[3] =
      mcb_pmsm_foc_qep_f28379d_ConstP.pooled5[(int16_T)Sum_e];

    /* Sum: '<S157>/Sum3' */
    mcb_pmsm_foc_qep_f28379d_B.Sum3_p = mcb_pmsm_foc_qep_f28379d_B.Lookup_p[0] -
      mcb_pmsm_foc_qep_f28379d_B.Lookup_p[1];

    /* DataTypeConversion: '<S156>/Data Type Conversion1' */
    mcb_pmsm_foc_qep_f28379d_B.DataTypeConversion1_h =
      mcb_pmsm_foc_qep_f28379d_B.Get_Integer_l;

    /* Sum: '<S156>/Sum2' */
    mcb_pmsm_foc_qep_f28379d_B.Sum2_j = mcb_pmsm_foc_qep_f28379d_B.indexing_n -
      mcb_pmsm_foc_qep_f28379d_B.DataTypeConversion1_h;

    /* Product: '<S157>/Product' */
    mcb_pmsm_foc_qep_f28379d_B.Product_n = mcb_pmsm_foc_qep_f28379d_B.Sum3_p *
      mcb_pmsm_foc_qep_f28379d_B.Sum2_j;

    /* Sum: '<S157>/Sum4' */
    mcb_pmsm_foc_qep_f28379d_B.Sum4_l = mcb_pmsm_foc_qep_f28379d_B.Product_n +
      mcb_pmsm_foc_qep_f28379d_B.Lookup_p[1];

    /* Sum: '<S157>/Sum5' */
    mcb_pmsm_foc_qep_f28379d_B.Sum5_j = mcb_pmsm_foc_qep_f28379d_B.Lookup_p[2] -
      mcb_pmsm_foc_qep_f28379d_B.Lookup_p[3];

    /* Product: '<S157>/Product1' */
    mcb_pmsm_foc_qep_f28379d_B.Product1_g = mcb_pmsm_foc_qep_f28379d_B.Sum5_j *
      mcb_pmsm_foc_qep_f28379d_B.Sum2_j;

    /* Sum: '<S157>/Sum6' */
    mcb_pmsm_foc_qep_f28379d_B.Sum6_a = mcb_pmsm_foc_qep_f28379d_B.Product1_g +
      mcb_pmsm_foc_qep_f28379d_B.Lookup_p[3];

    /* Outputs for Atomic SubSystem: '<S20>/Two inputs CRL' */
    /* Product: '<S154>/acos' */
    mcb_pmsm_foc_qep_f28379d_B.acos_b = mcb_pmsm_foc_qep_f28379d_B.algDD_o1_e *
      mcb_pmsm_foc_qep_f28379d_B.Sum6_a;

    /* Product: '<S154>/bsin' */
    mcb_pmsm_foc_qep_f28379d_B.bsin = mcb_pmsm_foc_qep_f28379d_B.algDD_o2_h *
      mcb_pmsm_foc_qep_f28379d_B.Sum4_l;

    /* Sum: '<S154>/sum_Ds' */
    mcb_pmsm_foc_qep_f28379d_B.sum_Ds = mcb_pmsm_foc_qep_f28379d_B.acos_b +
      mcb_pmsm_foc_qep_f28379d_B.bsin;

    /* Product: '<S154>/bcos' */
    mcb_pmsm_foc_qep_f28379d_B.bcos = mcb_pmsm_foc_qep_f28379d_B.algDD_o2_h *
      mcb_pmsm_foc_qep_f28379d_B.Sum6_a;

    /* Product: '<S154>/asin' */
    mcb_pmsm_foc_qep_f28379d_B.asin_o = mcb_pmsm_foc_qep_f28379d_B.algDD_o1_e *
      mcb_pmsm_foc_qep_f28379d_B.Sum4_l;

    /* Sum: '<S154>/sum_Qs' */
    mcb_pmsm_foc_qep_f28379d_B.sum_Qs = mcb_pmsm_foc_qep_f28379d_B.bcos -
      mcb_pmsm_foc_qep_f28379d_B.asin_o;

    /* Switch: '<S155>/Switch' */
    mcb_pmsm_foc_qep_f28379d_B.Switch_h[0] = mcb_pmsm_foc_qep_f28379d_B.sum_Ds;
    mcb_pmsm_foc_qep_f28379d_B.Switch_h[1] = mcb_pmsm_foc_qep_f28379d_B.sum_Qs;

    /* AlgorithmDescriptorDelegate generated from: '<S154>/a16' */
    mcb_pmsm_foc_qep_f28379d_B.algDD_o1 = mcb_pmsm_foc_qep_f28379d_B.Switch_h[0];

    /* AlgorithmDescriptorDelegate generated from: '<S154>/a16' */
    mcb_pmsm_foc_qep_f28379d_B.algDD_o2 = mcb_pmsm_foc_qep_f28379d_B.Switch_h[1];

    /* End of Outputs for SubSystem: '<S20>/Two inputs CRL' */

    /* Sum: '<S27>/Sum' */
    mcb_pmsm_foc_qep_f28379d_B.Sum_o = mcb_pmsm_foc_qep_f28379d_B.Idq_ref_PU[1]
      - mcb_pmsm_foc_qep_f28379d_B.algDD_o2;

    /* Product: '<S139>/PProd Out' incorporates:
     *  Constant: '<S27>/Kp'
     */
    mcb_pmsm_foc_qep_f28379d_B.PProdOut = mcb_pmsm_foc_qep_f28379d_B.Sum_o *
      3.09294796F;

    /* DataStoreRead: '<S27>/Data Store Read1' */
    mcb_pmsm_foc_qep_f28379d_B.DataStoreRead1_b =
      mcb_pmsm_foc_qep_f28379d_DW.Enable;

    /* Logic: '<S27>/Logical Operator' */
    mcb_pmsm_foc_qep_f28379d_B.LogicalOperator =
      !mcb_pmsm_foc_qep_f28379d_B.DataStoreRead1_b;

    /* Constant: '<S27>/Kp1' */
    mcb_pmsm_foc_qep_f28379d_B.Kp1 = 0.0F;

    /* DiscreteIntegrator: '<S134>/Integrator' */
    if (mcb_pmsm_foc_qep_f28379d_B.LogicalOperator ||
        (mcb_pmsm_foc_qep_f28379d_DW.Integrator_PrevResetState != 0)) {
      mcb_pmsm_foc_qep_f28379d_DW.Integrator_DSTATE = 0.0F;
    }

    /* DiscreteIntegrator: '<S134>/Integrator' */
    mcb_pmsm_foc_qep_f28379d_B.Integrator =
      mcb_pmsm_foc_qep_f28379d_DW.Integrator_DSTATE;

    /* Sum: '<S143>/Sum' */
    mcb_pmsm_foc_qep_f28379d_B.Sum_m = mcb_pmsm_foc_qep_f28379d_B.PProdOut +
      mcb_pmsm_foc_qep_f28379d_B.Integrator;

    /* Saturate: '<S141>/Saturation' */
    u0_0 = mcb_pmsm_foc_qep_f28379d_B.Sum_m;
    if (u0_0 > 1.0F) {
      /* Saturate: '<S141>/Saturation' */
      mcb_pmsm_foc_qep_f28379d_B.Saturation = 1.0F;
    } else if (u0_0 < -1.0F) {
      /* Saturate: '<S141>/Saturation' */
      mcb_pmsm_foc_qep_f28379d_B.Saturation = -1.0F;
    } else {
      /* Saturate: '<S141>/Saturation' */
      mcb_pmsm_foc_qep_f28379d_B.Saturation = u0_0;
    }

    /* End of Saturate: '<S141>/Saturation' */

    /* Sum: '<S26>/Sum' */
    mcb_pmsm_foc_qep_f28379d_B.Sum_j = mcb_pmsm_foc_qep_f28379d_B.Idq_ref_PU[0]
      - mcb_pmsm_foc_qep_f28379d_B.algDD_o1;

    /* Product: '<S84>/PProd Out' incorporates:
     *  Constant: '<S26>/Kp'
     */
    mcb_pmsm_foc_qep_f28379d_B.PProdOut_g = mcb_pmsm_foc_qep_f28379d_B.Sum_j *
      3.09294796F;

    /* DataStoreRead: '<S26>/Data Store Read1' */
    mcb_pmsm_foc_qep_f28379d_B.DataStoreRead1_m =
      mcb_pmsm_foc_qep_f28379d_DW.Enable;

    /* Logic: '<S26>/Logical Operator' */
    mcb_pmsm_foc_qep_f28379d_B.LogicalOperator_a =
      !mcb_pmsm_foc_qep_f28379d_B.DataStoreRead1_m;

    /* Constant: '<S26>/Ki1' */
    mcb_pmsm_foc_qep_f28379d_B.Ki1 = 0.0F;

    /* DiscreteIntegrator: '<S79>/Integrator' */
    if (mcb_pmsm_foc_qep_f28379d_B.LogicalOperator_a ||
        (mcb_pmsm_foc_qep_f28379d_DW.Integrator_PrevResetState_k != 0)) {
      mcb_pmsm_foc_qep_f28379d_DW.Integrator_DSTATE_o = 0.0F;
    }

    /* DiscreteIntegrator: '<S79>/Integrator' */
    mcb_pmsm_foc_qep_f28379d_B.Integrator_f =
      mcb_pmsm_foc_qep_f28379d_DW.Integrator_DSTATE_o;

    /* Sum: '<S88>/Sum' */
    mcb_pmsm_foc_qep_f28379d_B.Sum_g = mcb_pmsm_foc_qep_f28379d_B.PProdOut_g +
      mcb_pmsm_foc_qep_f28379d_B.Integrator_f;

    /* Saturate: '<S86>/Saturation' */
    u0_0 = mcb_pmsm_foc_qep_f28379d_B.Sum_g;
    if (u0_0 > 1.0F) {
      /* Saturate: '<S86>/Saturation' */
      mcb_pmsm_foc_qep_f28379d_B.Saturation_f = 1.0F;
    } else if (u0_0 < -1.0F) {
      /* Saturate: '<S86>/Saturation' */
      mcb_pmsm_foc_qep_f28379d_B.Saturation_f = -1.0F;
    } else {
      /* Saturate: '<S86>/Saturation' */
      mcb_pmsm_foc_qep_f28379d_B.Saturation_f = u0_0;
    }

    /* End of Saturate: '<S86>/Saturation' */

    /* Switch: '<S30>/Switch' incorporates:
     *  Constant: '<S30>/Constant3'
     */
    mcb_pmsm_foc_qep_f28379d_B.Switch_n = 0.95F;

    /* Product: '<S30>/Product' */
    mcb_pmsm_foc_qep_f28379d_B.Product_j = 0.9025F;

    /* Product: '<S31>/Product' */
    mcb_pmsm_foc_qep_f28379d_B.Product_f =
      mcb_pmsm_foc_qep_f28379d_B.Saturation_f *
      mcb_pmsm_foc_qep_f28379d_B.Saturation_f;

    /* Product: '<S31>/Product1' */
    mcb_pmsm_foc_qep_f28379d_B.Product1_gr =
      mcb_pmsm_foc_qep_f28379d_B.Saturation *
      mcb_pmsm_foc_qep_f28379d_B.Saturation;

    /* Sum: '<S31>/Sum1' */
    mcb_pmsm_foc_qep_f28379d_B.Sum1 = mcb_pmsm_foc_qep_f28379d_B.Product_f +
      mcb_pmsm_foc_qep_f28379d_B.Product1_gr;

    /* Outputs for IfAction SubSystem: '<S25>/D-Q Equivalence' incorporates:
     *  ActionPort: '<S28>/Action Port'
     */
    /* If: '<S25>/If' incorporates:
     *  DataTypeConversion: '<S28>/Data Type Conversion'
     *  RelationalOperator: '<S28>/Relational Operator'
     */
    mcb_pmsm_foc_qep_f28379d_B.RelationalOperator_k =
      (mcb_pmsm_foc_qep_f28379d_B.Sum1 > 0.9025F);
    mcb_pmsm_foc_qep_f28379d_B.DataTypeConversion_f =
      mcb_pmsm_foc_qep_f28379d_B.RelationalOperator_k;

    /* If: '<S28>/If' incorporates:
     *  If: '<S25>/If'
     */
    if (mcb_pmsm_foc_qep_f28379d_B.DataTypeConversion_f != 0U) {
      /* Outputs for IfAction SubSystem: '<S28>/Limiter' incorporates:
       *  ActionPort: '<S32>/Action Port'
       */
      /* Product: '<S32>/Product' */
      mcb_pmsm_foc_qep_f28379d_B.Product_o[0] =
        mcb_pmsm_foc_qep_f28379d_B.Saturation_f * 0.95F;
      mcb_pmsm_foc_qep_f28379d_B.Product_o[1] =
        mcb_pmsm_foc_qep_f28379d_B.Saturation * 0.95F;

      /* Sqrt: '<S32>/Square Root' */
      mcb_pmsm_foc_qep_f28379d_B.SquareRoot = (real32_T)sqrt
        (mcb_pmsm_foc_qep_f28379d_B.Sum1);

      /* Switch: '<S32>/Switch' */
      if (mcb_pmsm_foc_qep_f28379d_B.SquareRoot != 0.0F) {
        /* Switch: '<S32>/Switch' */
        mcb_pmsm_foc_qep_f28379d_B.Switch_as =
          mcb_pmsm_foc_qep_f28379d_B.SquareRoot;
      } else {
        /* Switch: '<S32>/Switch' incorporates:
         *  Constant: '<S32>/Constant'
         */
        mcb_pmsm_foc_qep_f28379d_B.Switch_as = 1.0F;
      }

      /* End of Switch: '<S32>/Switch' */

      /* Merge: '<S25>/Merge' incorporates:
       *  Product: '<S32>/Divide'
       */
      mcb_pmsm_foc_qep_f28379d_B.Merge_i[0] =
        mcb_pmsm_foc_qep_f28379d_B.Product_o[0] /
        mcb_pmsm_foc_qep_f28379d_B.Switch_as;
      mcb_pmsm_foc_qep_f28379d_B.Merge_i[1] =
        mcb_pmsm_foc_qep_f28379d_B.Product_o[1] /
        mcb_pmsm_foc_qep_f28379d_B.Switch_as;

      /* End of Outputs for SubSystem: '<S28>/Limiter' */
    } else {
      /* Outputs for IfAction SubSystem: '<S28>/Passthrough' incorporates:
       *  ActionPort: '<S33>/Action Port'
       */
      /* Merge: '<S25>/Merge' incorporates:
       *  SignalConversion generated from: '<S33>/dqRef'
       */
      mcb_pmsm_foc_qep_f28379d_B.Merge_i[0] =
        mcb_pmsm_foc_qep_f28379d_B.Saturation_f;
      mcb_pmsm_foc_qep_f28379d_B.Merge_i[1] =
        mcb_pmsm_foc_qep_f28379d_B.Saturation;

      /* End of Outputs for SubSystem: '<S28>/Passthrough' */
    }

    /* End of If: '<S28>/If' */
    /* End of Outputs for SubSystem: '<S25>/D-Q Equivalence' */

    /* DeadZone: '<S71>/DeadZone' */
    if (mcb_pmsm_foc_qep_f28379d_B.Sum_g > 1.0F) {
      /* DeadZone: '<S71>/DeadZone' */
      mcb_pmsm_foc_qep_f28379d_B.DeadZone = mcb_pmsm_foc_qep_f28379d_B.Sum_g -
        1.0F;
    } else if (mcb_pmsm_foc_qep_f28379d_B.Sum_g >= -1.0F) {
      /* DeadZone: '<S71>/DeadZone' */
      mcb_pmsm_foc_qep_f28379d_B.DeadZone = 0.0F;
    } else {
      /* DeadZone: '<S71>/DeadZone' */
      mcb_pmsm_foc_qep_f28379d_B.DeadZone = mcb_pmsm_foc_qep_f28379d_B.Sum_g -
        -1.0F;
    }

    /* End of DeadZone: '<S71>/DeadZone' */

    /* RelationalOperator: '<S69>/Relational Operator' incorporates:
     *  Constant: '<S69>/Clamping_zero'
     */
    mcb_pmsm_foc_qep_f28379d_B.RelationalOperator =
      (mcb_pmsm_foc_qep_f28379d_B.DeadZone != 0.0F);

    /* RelationalOperator: '<S69>/fix for DT propagation issue' incorporates:
     *  Constant: '<S69>/Clamping_zero'
     */
    mcb_pmsm_foc_qep_f28379d_B.fixforDTpropagationissue =
      (mcb_pmsm_foc_qep_f28379d_B.DeadZone > 0.0F);

    /* Switch: '<S69>/Switch1' */
    if (mcb_pmsm_foc_qep_f28379d_B.fixforDTpropagationissue) {
      /* Switch: '<S69>/Switch1' incorporates:
       *  Constant: '<S69>/Constant'
       */
      mcb_pmsm_foc_qep_f28379d_B.Switch1_h = 1;
    } else {
      /* Switch: '<S69>/Switch1' incorporates:
       *  Constant: '<S69>/Constant2'
       */
      mcb_pmsm_foc_qep_f28379d_B.Switch1_h = -1;
    }

    /* End of Switch: '<S69>/Switch1' */

    /* Product: '<S76>/IProd Out' incorporates:
     *  Constant: '<S26>/Ki'
     */
    mcb_pmsm_foc_qep_f28379d_B.IProdOut = mcb_pmsm_foc_qep_f28379d_B.Sum_j *
      0.281716F;

    /* RelationalOperator: '<S69>/fix for DT propagation issue1' incorporates:
     *  Constant: '<S69>/Clamping_zero'
     */
    mcb_pmsm_foc_qep_f28379d_B.fixforDTpropagationissue1 =
      (mcb_pmsm_foc_qep_f28379d_B.IProdOut > 0.0F);

    /* Switch: '<S69>/Switch2' */
    if (mcb_pmsm_foc_qep_f28379d_B.fixforDTpropagationissue1) {
      /* Switch: '<S69>/Switch2' incorporates:
       *  Constant: '<S69>/Constant3'
       */
      mcb_pmsm_foc_qep_f28379d_B.Switch2_l = 1;
    } else {
      /* Switch: '<S69>/Switch2' incorporates:
       *  Constant: '<S69>/Constant4'
       */
      mcb_pmsm_foc_qep_f28379d_B.Switch2_l = -1;
    }

    /* End of Switch: '<S69>/Switch2' */

    /* RelationalOperator: '<S69>/Equal1' incorporates:
     *  Switch: '<S69>/Switch1'
     *  Switch: '<S69>/Switch2'
     */
    mcb_pmsm_foc_qep_f28379d_B.Equal1 = (mcb_pmsm_foc_qep_f28379d_B.Switch1_h ==
      mcb_pmsm_foc_qep_f28379d_B.Switch2_l);

    /* Logic: '<S69>/AND3' */
    mcb_pmsm_foc_qep_f28379d_B.AND3 =
      (mcb_pmsm_foc_qep_f28379d_B.RelationalOperator &&
       mcb_pmsm_foc_qep_f28379d_B.Equal1);

    /* Switch: '<S69>/Switch' */
    if (mcb_pmsm_foc_qep_f28379d_B.AND3) {
      /* Switch: '<S69>/Switch' incorporates:
       *  Constant: '<S69>/Constant1'
       */
      mcb_pmsm_foc_qep_f28379d_B.Switch_f = 0.0F;
    } else {
      /* Switch: '<S69>/Switch' */
      mcb_pmsm_foc_qep_f28379d_B.Switch_f = mcb_pmsm_foc_qep_f28379d_B.IProdOut;
    }

    /* End of Switch: '<S69>/Switch' */

    /* DeadZone: '<S126>/DeadZone' */
    if (mcb_pmsm_foc_qep_f28379d_B.Sum_m > 1.0F) {
      /* DeadZone: '<S126>/DeadZone' */
      mcb_pmsm_foc_qep_f28379d_B.DeadZone_a = mcb_pmsm_foc_qep_f28379d_B.Sum_m -
        1.0F;
    } else if (mcb_pmsm_foc_qep_f28379d_B.Sum_m >= -1.0F) {
      /* DeadZone: '<S126>/DeadZone' */
      mcb_pmsm_foc_qep_f28379d_B.DeadZone_a = 0.0F;
    } else {
      /* DeadZone: '<S126>/DeadZone' */
      mcb_pmsm_foc_qep_f28379d_B.DeadZone_a = mcb_pmsm_foc_qep_f28379d_B.Sum_m -
        -1.0F;
    }

    /* End of DeadZone: '<S126>/DeadZone' */

    /* RelationalOperator: '<S124>/Relational Operator' incorporates:
     *  Constant: '<S124>/Clamping_zero'
     */
    mcb_pmsm_foc_qep_f28379d_B.RelationalOperator_e =
      (mcb_pmsm_foc_qep_f28379d_B.DeadZone_a != 0.0F);

    /* RelationalOperator: '<S124>/fix for DT propagation issue' incorporates:
     *  Constant: '<S124>/Clamping_zero'
     */
    mcb_pmsm_foc_qep_f28379d_B.fixforDTpropagationissue_j =
      (mcb_pmsm_foc_qep_f28379d_B.DeadZone_a > 0.0F);

    /* Switch: '<S124>/Switch1' */
    if (mcb_pmsm_foc_qep_f28379d_B.fixforDTpropagationissue_j) {
      /* Switch: '<S124>/Switch1' incorporates:
       *  Constant: '<S124>/Constant'
       */
      mcb_pmsm_foc_qep_f28379d_B.Switch1_l = 1;
    } else {
      /* Switch: '<S124>/Switch1' incorporates:
       *  Constant: '<S124>/Constant2'
       */
      mcb_pmsm_foc_qep_f28379d_B.Switch1_l = -1;
    }

    /* End of Switch: '<S124>/Switch1' */

    /* Product: '<S131>/IProd Out' incorporates:
     *  Constant: '<S27>/Ki'
     */
    mcb_pmsm_foc_qep_f28379d_B.IProdOut_b = mcb_pmsm_foc_qep_f28379d_B.Sum_o *
      0.281716F;

    /* RelationalOperator: '<S124>/fix for DT propagation issue1' incorporates:
     *  Constant: '<S124>/Clamping_zero'
     */
    mcb_pmsm_foc_qep_f28379d_B.fixforDTpropagationissue1_o =
      (mcb_pmsm_foc_qep_f28379d_B.IProdOut_b > 0.0F);

    /* Switch: '<S124>/Switch2' */
    if (mcb_pmsm_foc_qep_f28379d_B.fixforDTpropagationissue1_o) {
      /* Switch: '<S124>/Switch2' incorporates:
       *  Constant: '<S124>/Constant3'
       */
      mcb_pmsm_foc_qep_f28379d_B.Switch2_c = 1;
    } else {
      /* Switch: '<S124>/Switch2' incorporates:
       *  Constant: '<S124>/Constant4'
       */
      mcb_pmsm_foc_qep_f28379d_B.Switch2_c = -1;
    }

    /* End of Switch: '<S124>/Switch2' */

    /* RelationalOperator: '<S124>/Equal1' incorporates:
     *  Switch: '<S124>/Switch1'
     *  Switch: '<S124>/Switch2'
     */
    mcb_pmsm_foc_qep_f28379d_B.Equal1_i = (mcb_pmsm_foc_qep_f28379d_B.Switch1_l ==
      mcb_pmsm_foc_qep_f28379d_B.Switch2_c);

    /* Logic: '<S124>/AND3' */
    mcb_pmsm_foc_qep_f28379d_B.AND3_n =
      (mcb_pmsm_foc_qep_f28379d_B.RelationalOperator_e &&
       mcb_pmsm_foc_qep_f28379d_B.Equal1_i);

    /* Switch: '<S124>/Switch' */
    if (mcb_pmsm_foc_qep_f28379d_B.AND3_n) {
      /* Switch: '<S124>/Switch' incorporates:
       *  Constant: '<S124>/Constant1'
       */
      mcb_pmsm_foc_qep_f28379d_B.Switch_a = 0.0F;
    } else {
      /* Switch: '<S124>/Switch' */
      mcb_pmsm_foc_qep_f28379d_B.Switch_a =
        mcb_pmsm_foc_qep_f28379d_B.IProdOut_b;
    }

    /* End of Switch: '<S124>/Switch' */

    /* Outputs for Atomic SubSystem: '<S19>/Two inputs CRL' */
    mcb_pmsm_foc_q_TwoinputsCRL(mcb_pmsm_foc_qep_f28379d_B.Merge_i[0],
      mcb_pmsm_foc_qep_f28379d_B.Merge_i[1], mcb_pmsm_foc_qep_f28379d_B.Sum4_l,
      mcb_pmsm_foc_qep_f28379d_B.Sum6_a,
      &mcb_pmsm_foc_qep_f28379d_B.TwoinputsCRL);

    /* End of Outputs for SubSystem: '<S19>/Two inputs CRL' */

    /* Gain: '<S170>/one_by_two' */
    mcb_pmsm_foc_qep_f28379d_B.one_by_two_l = 0.5F *
      mcb_pmsm_foc_qep_f28379d_B.TwoinputsCRL.algDD_o1;

    /* Gain: '<S170>/sqrt3_by_two' */
    mcb_pmsm_foc_qep_f28379d_B.sqrt3_by_two_l = 0.866025388F *
      mcb_pmsm_foc_qep_f28379d_B.TwoinputsCRL.algDD_o2;

    /* Sum: '<S170>/add_b' */
    mcb_pmsm_foc_qep_f28379d_B.add_b_e =
      mcb_pmsm_foc_qep_f28379d_B.sqrt3_by_two_l -
      mcb_pmsm_foc_qep_f28379d_B.one_by_two_l;

    /* Sum: '<S170>/add_c' */
    mcb_pmsm_foc_qep_f28379d_B.add_c_m = (0.0F -
      mcb_pmsm_foc_qep_f28379d_B.one_by_two_l) -
      mcb_pmsm_foc_qep_f28379d_B.sqrt3_by_two_l;

    /* MinMax: '<S167>/Max' */
    u0_0 = mcb_pmsm_foc_qep_f28379d_B.TwoinputsCRL.algDD_o1;
    Bias = mcb_pmsm_foc_qep_f28379d_B.add_b_e;
    if ((u0_0 >= Bias) || rtIsNaNF(Bias)) {
      Bias = u0_0;
    }

    u0_0 = mcb_pmsm_foc_qep_f28379d_B.add_c_m;
    if ((!(Bias >= u0_0)) && (!rtIsNaNF(u0_0))) {
      Bias = u0_0;
    }

    /* MinMax: '<S167>/Max' */
    mcb_pmsm_foc_qep_f28379d_B.Max = Bias;

    /* MinMax: '<S167>/Min' */
    u0_0 = mcb_pmsm_foc_qep_f28379d_B.TwoinputsCRL.algDD_o1;
    Bias = mcb_pmsm_foc_qep_f28379d_B.add_b_e;
    if ((u0_0 <= Bias) || rtIsNaNF(Bias)) {
      Bias = u0_0;
    }

    u0_0 = mcb_pmsm_foc_qep_f28379d_B.add_c_m;
    if ((!(Bias <= u0_0)) && (!rtIsNaNF(u0_0))) {
      Bias = u0_0;
    }

    /* MinMax: '<S167>/Min' */
    mcb_pmsm_foc_qep_f28379d_B.Min = Bias;

    /* Sum: '<S167>/Add' */
    mcb_pmsm_foc_qep_f28379d_B.Add_n = mcb_pmsm_foc_qep_f28379d_B.Max +
      mcb_pmsm_foc_qep_f28379d_B.Min;

    /* Gain: '<S167>/one_by_two' */
    mcb_pmsm_foc_qep_f28379d_B.one_by_two_lh = -0.5F *
      mcb_pmsm_foc_qep_f28379d_B.Add_n;

    /* Sum: '<S166>/Add1' */
    mcb_pmsm_foc_qep_f28379d_B.Add1_d = mcb_pmsm_foc_qep_f28379d_B.add_b_e +
      mcb_pmsm_foc_qep_f28379d_B.one_by_two_lh;

    /* Sum: '<S166>/Add2' */
    mcb_pmsm_foc_qep_f28379d_B.Add2 = mcb_pmsm_foc_qep_f28379d_B.one_by_two_lh +
      mcb_pmsm_foc_qep_f28379d_B.add_c_m;

    /* Sum: '<S166>/Add3' */
    mcb_pmsm_foc_qep_f28379d_B.Add3 =
      mcb_pmsm_foc_qep_f28379d_B.TwoinputsCRL.algDD_o1 +
      mcb_pmsm_foc_qep_f28379d_B.one_by_two_lh;

    /* Gain: '<S166>/Gain' */
    mcb_pmsm_foc_qep_f28379d_B.Gain[0] = 1.15470052F *
      mcb_pmsm_foc_qep_f28379d_B.Add3;
    mcb_pmsm_foc_qep_f28379d_B.Gain[1] = 1.15470052F *
      mcb_pmsm_foc_qep_f28379d_B.Add1_d;
    mcb_pmsm_foc_qep_f28379d_B.Gain[2] = 1.15470052F *
      mcb_pmsm_foc_qep_f28379d_B.Add2;

    /* Update for DiscreteIntegrator: '<S134>/Integrator' */
    mcb_pmsm_foc_qep_f28379d_DW.Integrator_DSTATE +=
      mcb_pmsm_foc_qep_f28379d_B.Switch_a;
    mcb_pmsm_foc_qep_f28379d_DW.Integrator_PrevResetState = (int16_T)
      mcb_pmsm_foc_qep_f28379d_B.LogicalOperator;

    /* Update for DiscreteIntegrator: '<S79>/Integrator' */
    mcb_pmsm_foc_qep_f28379d_DW.Integrator_DSTATE_o +=
      mcb_pmsm_foc_qep_f28379d_B.Switch_f;
    mcb_pmsm_foc_qep_f28379d_DW.Integrator_PrevResetState_k = (int16_T)
      mcb_pmsm_foc_qep_f28379d_B.LogicalOperator_a;
  }

  /* End of Outputs for SubSystem: '<S8>/Closed Loop Control' */

  /* Logic: '<S8>/NOT' */
  mcb_pmsm_foc_qep_f28379d_B.NOT_p = !mcb_pmsm_foc_qep_f28379d_B.AND;

  /* Outputs for Enabled SubSystem: '<S8>/Open Loop Start-Up' incorporates:
   *  EnablePort: '<S16>/Enable'
   */
  if (mcb_pmsm_foc_qep_f28379d_B.NOT_p) {
    mcb_pmsm_foc_qep_f28379d_DW.OpenLoopStartUp_MODE = true;

    /* Gain: '<S16>/rpm2freq' incorporates:
     *  Constant: '<S16>/Speed_ref(rpm)'
     */
    mcb_pmsm_foc_qep_f28379d_B.rpm2freq = 54.760006F;

    /* DataStoreRead: '<S16>/Data Store Read1' */
    mcb_pmsm_foc_qep_f28379d_B.DataStoreRead1_c =
      mcb_pmsm_foc_qep_f28379d_DW.Enable;

    /* Logic: '<S173>/NOT' */
    mcb_pmsm_foc_qep_f28379d_B.NOT_b =
      !mcb_pmsm_foc_qep_f28379d_B.DataStoreRead1_c;

    /* DiscreteIntegrator: '<S173>/Ramp Generator' */
    if (mcb_pmsm_foc_qep_f28379d_B.NOT_b) {
      mcb_pmsm_foc_qep_f28379d_DW.RampGenerator_DSTATE = 0.0F;
    }

    /* DiscreteIntegrator: '<S173>/Ramp Generator' */
    mcb_pmsm_foc_qep_f28379d_B.Eps =
      mcb_pmsm_foc_qep_f28379d_DW.RampGenerator_DSTATE;

    /* Product: '<S16>/Product' */
    mcb_pmsm_foc_qep_f28379d_B.Product_k = 54.760006F *
      mcb_pmsm_foc_qep_f28379d_B.Eps;

    /* Abs: '<S16>/Abs' */
    mcb_pmsm_foc_qep_f28379d_B.Frequency = fabsf
      (mcb_pmsm_foc_qep_f28379d_B.Product_k);

    /* Gain: '<S16>/V-by-f' */
    mcb_pmsm_foc_qep_f28379d_B.Vbyf = 0.00365230092F *
      mcb_pmsm_foc_qep_f28379d_B.Frequency;

    /* Gain: '<S16>/Correction_Factor_sinePWM' */
    mcb_pmsm_foc_qep_f28379d_B.Correction_Factor_sinePWM = 1.15470052F *
      mcb_pmsm_foc_qep_f28379d_B.Vbyf;

    /* Saturate: '<S16>/Saturation' */
    u0_0 = mcb_pmsm_foc_qep_f28379d_B.Correction_Factor_sinePWM;
    if (u0_0 > 0.95F) {
      /* Saturate: '<S16>/Saturation' */
      mcb_pmsm_foc_qep_f28379d_B.Amplitude = 0.95F;
    } else if (u0_0 < 0.15F) {
      /* Saturate: '<S16>/Saturation' */
      mcb_pmsm_foc_qep_f28379d_B.Amplitude = 0.15F;
    } else {
      /* Saturate: '<S16>/Saturation' */
      mcb_pmsm_foc_qep_f28379d_B.Amplitude = u0_0;
    }

    /* End of Saturate: '<S16>/Saturation' */

    /* UnaryMinus: '<S171>/Unary Minus' */
    mcb_pmsm_foc_qep_f28379d_B.UnaryMinus =
      -mcb_pmsm_foc_qep_f28379d_B.Amplitude;

    /* Gain: '<S16>/position_increment' */
    mcb_pmsm_foc_qep_f28379d_B.position_increment = 0.000314159261F *
      mcb_pmsm_foc_qep_f28379d_B.Frequency;

    /* Gain: '<S172>/scaleIn' */
    mcb_pmsm_foc_qep_f28379d_B.scaleIn = 0.159154937F *
      mcb_pmsm_foc_qep_f28379d_B.position_increment;

    /* UnitDelay: '<S172>/Unit Delay' */
    mcb_pmsm_foc_qep_f28379d_B.UnitDelay_d =
      mcb_pmsm_foc_qep_f28379d_DW.UnitDelay_DSTATE_h;

    /* Logic: '<S172>/NOT' incorporates:
     *  Constant: '<S172>/Constant_Reset'
     */
    mcb_pmsm_foc_qep_f28379d_B.NOT_o = true;

    /* Outputs for Enabled SubSystem: '<S172>/Accumulate' incorporates:
     *  EnablePort: '<S188>/Enable'
     */
    /* Delay: '<S188>/Delay' */
    mcb_pmsm_foc_qep_f28379d_B.Delay_o =
      mcb_pmsm_foc_qep_f28379d_DW.Delay_DSTATE_j;

    /* Outputs for Enabled SubSystem: '<S188>/Subsystem' incorporates:
     *  EnablePort: '<S189>/Enable'
     */
    if (mcb_pmsm_foc_qep_f28379d_B.Delay_o) {
      /* SignalConversion generated from: '<S189>/Input' */
      mcb_pmsm_foc_qep_f28379d_B.Input = mcb_pmsm_foc_qep_f28379d_B.scaleIn;
    }

    /* End of Outputs for SubSystem: '<S188>/Subsystem' */

    /* Sum: '<S188>/Add' */
    mcb_pmsm_foc_qep_f28379d_B.Add_m = mcb_pmsm_foc_qep_f28379d_B.Input +
      mcb_pmsm_foc_qep_f28379d_B.UnitDelay_d;

    /* DataTypeConversion: '<S188>/Data Type Conversion' */
    mcb_pmsm_foc_qep_f28379d_B.DataTypeConversion_flc = (int16_T)(real32_T)floor
      (mcb_pmsm_foc_qep_f28379d_B.Add_m);

    /* DataTypeConversion: '<S188>/Data Type Conversion1' */
    mcb_pmsm_foc_qep_f28379d_B.DataTypeConversion1_f =
      mcb_pmsm_foc_qep_f28379d_B.DataTypeConversion_flc;

    /* Sum: '<S188>/Add1' */
    mcb_pmsm_foc_qep_f28379d_B.Add1_c = mcb_pmsm_foc_qep_f28379d_B.Add_m -
      mcb_pmsm_foc_qep_f28379d_B.DataTypeConversion1_f;

    /* Update for Delay: '<S188>/Delay' incorporates:
     *  Constant: '<S188>/Constant'
     */
    mcb_pmsm_foc_qep_f28379d_DW.Delay_DSTATE_j = true;

    /* End of Outputs for SubSystem: '<S172>/Accumulate' */

    /* Gain: '<S172>/scaleOut' */
    mcb_pmsm_foc_qep_f28379d_B.scaleOut = 6.28318548F *
      mcb_pmsm_foc_qep_f28379d_B.Add1_c;

    /* DataStoreRead: '<S16>/Data Store Read' */
    mcb_pmsm_foc_qep_f28379d_B.DataStoreRead_p =
      mcb_pmsm_foc_qep_f28379d_DW.SpeedRef;

    /* Switch: '<S16>/Direction' */
    if (mcb_pmsm_foc_qep_f28379d_B.DataStoreRead_p > 0.0F) {
      /* Switch: '<S16>/Direction' */
      mcb_pmsm_foc_qep_f28379d_B.Eps_g = mcb_pmsm_foc_qep_f28379d_B.scaleOut;
    } else {
      /* Sum: '<S16>/Sum' incorporates:
       *  Constant: '<S16>/ '
       */
      mcb_pmsm_foc_qep_f28379d_B.Sum_f = 6.28318548F -
        mcb_pmsm_foc_qep_f28379d_B.scaleOut;

      /* Switch: '<S16>/Direction' */
      mcb_pmsm_foc_qep_f28379d_B.Eps_g = mcb_pmsm_foc_qep_f28379d_B.Sum_f;
    }

    /* End of Switch: '<S16>/Direction' */

    /* Gain: '<S182>/convert_pu' */
    mcb_pmsm_foc_qep_f28379d_B.convert_pu = 0.159154937F *
      mcb_pmsm_foc_qep_f28379d_B.Eps_g;

    /* RelationalOperator: '<S184>/Compare' incorporates:
     *  Constant: '<S184>/Constant'
     */
    mcb_pmsm_foc_qep_f28379d_B.Compare_n =
      (mcb_pmsm_foc_qep_f28379d_B.convert_pu < 0.0F);

    /* DataTypeConversion: '<S182>/Data Type Conversion' */
    mcb_pmsm_foc_qep_f28379d_B.DataTypeConversion_o =
      mcb_pmsm_foc_qep_f28379d_B.Compare_n;

    /* If: '<S182>/If' */
    if (mcb_pmsm_foc_qep_f28379d_B.DataTypeConversion_o > 0U) {
      /* Outputs for IfAction SubSystem: '<S182>/If Action Subsystem' incorporates:
       *  ActionPort: '<S185>/Action Port'
       */
      mcb_pmsm__IfActionSubsystem(mcb_pmsm_foc_qep_f28379d_B.convert_pu,
        &mcb_pmsm_foc_qep_f28379d_B.Merge_h,
        &mcb_pmsm_foc_qep_f28379d_B.IfActionSubsystem_o);

      /* End of Outputs for SubSystem: '<S182>/If Action Subsystem' */
    } else {
      /* Outputs for IfAction SubSystem: '<S182>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S186>/Action Port'
       */
      mcb_pmsm_IfActionSubsystem1(mcb_pmsm_foc_qep_f28379d_B.convert_pu,
        &mcb_pmsm_foc_qep_f28379d_B.Merge_h,
        &mcb_pmsm_foc_qep_f28379d_B.IfActionSubsystem1_h);

      /* End of Outputs for SubSystem: '<S182>/If Action Subsystem1' */
    }

    /* End of If: '<S182>/If' */

    /* Gain: '<S180>/indexing' */
    mcb_pmsm_foc_qep_f28379d_B.indexing = 800.0F *
      mcb_pmsm_foc_qep_f28379d_B.Merge_h;

    /* DataTypeConversion: '<S180>/Get_Integer' */
    mcb_pmsm_foc_qep_f28379d_B.Get_Integer = (uint16_T)
      mcb_pmsm_foc_qep_f28379d_B.indexing;

    /* Sum: '<S180>/Sum' incorporates:
     *  Constant: '<S180>/offset'
     */
    Sum_e = mcb_pmsm_foc_qep_f28379d_B.Get_Integer + 1UL;
    mcb_pmsm_foc_qep_f28379d_B.Sum[0] = Sum_e;

    /* Selector: '<S180>/Lookup' incorporates:
     *  Constant: '<S180>/sine_table_values'
     */
    mcb_pmsm_foc_qep_f28379d_B.Lookup[0] =
      mcb_pmsm_foc_qep_f28379d_ConstP.pooled5[(int16_T)Sum_e];

    /* Sum: '<S180>/Sum' */
    Sum_e = mcb_pmsm_foc_qep_f28379d_B.Get_Integer;
    mcb_pmsm_foc_qep_f28379d_B.Sum[1] = Sum_e;

    /* Selector: '<S180>/Lookup' incorporates:
     *  Constant: '<S180>/sine_table_values'
     */
    mcb_pmsm_foc_qep_f28379d_B.Lookup[1] =
      mcb_pmsm_foc_qep_f28379d_ConstP.pooled5[(int16_T)Sum_e];

    /* Sum: '<S180>/Sum' incorporates:
     *  Constant: '<S180>/offset'
     */
    Sum_e = mcb_pmsm_foc_qep_f28379d_B.Get_Integer + 201UL;
    mcb_pmsm_foc_qep_f28379d_B.Sum[2] = Sum_e;

    /* Selector: '<S180>/Lookup' incorporates:
     *  Constant: '<S180>/sine_table_values'
     */
    mcb_pmsm_foc_qep_f28379d_B.Lookup[2] =
      mcb_pmsm_foc_qep_f28379d_ConstP.pooled5[(int16_T)Sum_e];

    /* Sum: '<S180>/Sum' incorporates:
     *  Constant: '<S180>/offset'
     */
    Sum_e = mcb_pmsm_foc_qep_f28379d_B.Get_Integer + 200UL;
    mcb_pmsm_foc_qep_f28379d_B.Sum[3] = Sum_e;

    /* Selector: '<S180>/Lookup' incorporates:
     *  Constant: '<S180>/sine_table_values'
     */
    mcb_pmsm_foc_qep_f28379d_B.Lookup[3] =
      mcb_pmsm_foc_qep_f28379d_ConstP.pooled5[(int16_T)Sum_e];

    /* Sum: '<S181>/Sum3' */
    mcb_pmsm_foc_qep_f28379d_B.Sum3 = mcb_pmsm_foc_qep_f28379d_B.Lookup[0] -
      mcb_pmsm_foc_qep_f28379d_B.Lookup[1];

    /* DataTypeConversion: '<S180>/Data Type Conversion1' */
    mcb_pmsm_foc_qep_f28379d_B.DataTypeConversion1 =
      mcb_pmsm_foc_qep_f28379d_B.Get_Integer;

    /* Sum: '<S180>/Sum2' */
    mcb_pmsm_foc_qep_f28379d_B.Sum2 = mcb_pmsm_foc_qep_f28379d_B.indexing -
      mcb_pmsm_foc_qep_f28379d_B.DataTypeConversion1;

    /* Product: '<S181>/Product' */
    mcb_pmsm_foc_qep_f28379d_B.Product_b = mcb_pmsm_foc_qep_f28379d_B.Sum3 *
      mcb_pmsm_foc_qep_f28379d_B.Sum2;

    /* Sum: '<S181>/Sum4' */
    mcb_pmsm_foc_qep_f28379d_B.Sum4 = mcb_pmsm_foc_qep_f28379d_B.Product_b +
      mcb_pmsm_foc_qep_f28379d_B.Lookup[1];

    /* Sum: '<S181>/Sum5' */
    mcb_pmsm_foc_qep_f28379d_B.Sum5 = mcb_pmsm_foc_qep_f28379d_B.Lookup[2] -
      mcb_pmsm_foc_qep_f28379d_B.Lookup[3];

    /* Product: '<S181>/Product1' */
    mcb_pmsm_foc_qep_f28379d_B.Product1_c = mcb_pmsm_foc_qep_f28379d_B.Sum5 *
      mcb_pmsm_foc_qep_f28379d_B.Sum2;

    /* Sum: '<S181>/Sum6' */
    mcb_pmsm_foc_qep_f28379d_B.Sum6 = mcb_pmsm_foc_qep_f28379d_B.Product1_c +
      mcb_pmsm_foc_qep_f28379d_B.Lookup[3];

    /* Outputs for Atomic SubSystem: '<S175>/Two inputs CRL' */
    /* Constant: '<S171>/Constant' */
    mcb_pmsm_foc_q_TwoinputsCRL(0.0F, mcb_pmsm_foc_qep_f28379d_B.UnaryMinus,
      mcb_pmsm_foc_qep_f28379d_B.Sum4, mcb_pmsm_foc_qep_f28379d_B.Sum6,
      &mcb_pmsm_foc_qep_f28379d_B.TwoinputsCRL_l);

    /* End of Outputs for SubSystem: '<S175>/Two inputs CRL' */

    /* Gain: '<S177>/Ka' */
    mcb_pmsm_foc_qep_f28379d_B.Ka =
      mcb_pmsm_foc_qep_f28379d_B.TwoinputsCRL_l.algDD_o1;

    /* Gain: '<S177>/one_by_two' */
    mcb_pmsm_foc_qep_f28379d_B.one_by_two = 0.5F *
      mcb_pmsm_foc_qep_f28379d_B.TwoinputsCRL_l.algDD_o1;

    /* Gain: '<S177>/sqrt3_by_two' */
    mcb_pmsm_foc_qep_f28379d_B.sqrt3_by_two = 0.866025388F *
      mcb_pmsm_foc_qep_f28379d_B.TwoinputsCRL_l.algDD_o2;

    /* Sum: '<S177>/add_b' */
    mcb_pmsm_foc_qep_f28379d_B.add_b = mcb_pmsm_foc_qep_f28379d_B.sqrt3_by_two -
      mcb_pmsm_foc_qep_f28379d_B.one_by_two;

    /* Gain: '<S177>/Kb' */
    mcb_pmsm_foc_qep_f28379d_B.Kb = mcb_pmsm_foc_qep_f28379d_B.add_b;

    /* Sum: '<S177>/add_c' */
    mcb_pmsm_foc_qep_f28379d_B.add_c = (0.0F -
      mcb_pmsm_foc_qep_f28379d_B.one_by_two) -
      mcb_pmsm_foc_qep_f28379d_B.sqrt3_by_two;

    /* Gain: '<S177>/Kc' */
    mcb_pmsm_foc_qep_f28379d_B.Kc = mcb_pmsm_foc_qep_f28379d_B.add_c;

    /* Product: '<S173>/Divide' incorporates:
     *  Constant: '<S16>/Ramp_Time (sec)'
     *  Constant: '<S173>/One'
     */
    mcb_pmsm_foc_qep_f28379d_B.Divide = 0.333333343F;

    /* Gain: '<S173>/Sample_Time' */
    mcb_pmsm_foc_qep_f28379d_B.Sample_Time = 1.66666669E-5F;

    /* Update for DiscreteIntegrator: '<S173>/Ramp Generator' */
    mcb_pmsm_foc_qep_f28379d_DW.RampGenerator_DSTATE += 1.66666669E-5F;
    if (mcb_pmsm_foc_qep_f28379d_DW.RampGenerator_DSTATE > 1.0F) {
      mcb_pmsm_foc_qep_f28379d_DW.RampGenerator_DSTATE = 1.0F;
    } else if (mcb_pmsm_foc_qep_f28379d_DW.RampGenerator_DSTATE < 0.0F) {
      mcb_pmsm_foc_qep_f28379d_DW.RampGenerator_DSTATE = 0.0F;
    }

    /* End of Update for DiscreteIntegrator: '<S173>/Ramp Generator' */

    /* Update for UnitDelay: '<S172>/Unit Delay' */
    mcb_pmsm_foc_qep_f28379d_DW.UnitDelay_DSTATE_h =
      mcb_pmsm_foc_qep_f28379d_B.Add1_c;
  } else if (mcb_pmsm_foc_qep_f28379d_DW.OpenLoopStartUp_MODE) {
    /* Disable for DiscreteIntegrator: '<S173>/Ramp Generator' */
    mcb_pmsm_foc_qep_f28379d_DW.RampGenerator_DSTATE =
      mcb_pmsm_foc_qep_f28379d_B.Eps;
    mcb_pmsm_foc_qep_f28379d_DW.OpenLoopStartUp_MODE = false;
  }

  /* End of Outputs for SubSystem: '<S8>/Open Loop Start-Up' */

  /* UnitDelay: '<S229>/Output' */
  mcb_pmsm_foc_qep_f28379d_B.Output = mcb_pmsm_foc_qep_f28379d_DW.Output_DSTATE;

  /* DataStoreRead: '<S1>/Data Store Read' */
  mcb_pmsm_foc_qep_f28379d_B.DataStoreRead =
    mcb_pmsm_foc_qep_f28379d_DW.SpeedRef;

  /* Gain: '<S197>/PositionToCount' */
  mcb_pmsm_foc_qep_f28379d_B.PositionToCount = (uint32_T)(4.2949673E+9F *
    mcb_pmsm_foc_qep_f28379d_B.Product);

  /* Delay: '<S197>/Delay' */
  mcb_pmsm_foc_qep_f28379d_B.Delay =
    mcb_pmsm_foc_qep_f28379d_DW.Delay_DSTATE[mcb_pmsm_foc_qep_f28379d_DW.CircBufIdx];

  /* Sum: '<S197>/SpeedCount' */
  mcb_pmsm_foc_qep_f28379d_B.SpeedCount = (int32_T)
    mcb_pmsm_foc_qep_f28379d_B.PositionToCount - (int32_T)
    mcb_pmsm_foc_qep_f28379d_B.Delay;

  /* DataTypeConversion: '<S220>/DTC' */
  mcb_pmsm_foc_qep_f28379d_B.DTC_p = (real32_T)
    mcb_pmsm_foc_qep_f28379d_B.SpeedCount;

  /* Gain: '<S197>/SpeedGain' */
  mcb_pmsm_foc_qep_f28379d_B.SpeedGain = 3.40147022E-9F *
    mcb_pmsm_foc_qep_f28379d_B.DTC_p;

  /* Switch: '<S193>/Switch1' incorporates:
   *  Constant: '<S193>/FilterConstant'
   *  Constant: '<S193>/OneMinusFilterConstant'
   */
  mcb_pmsm_foc_qep_f28379d_B.Switch1[0] = 0.01F;
  mcb_pmsm_foc_qep_f28379d_B.Switch1[1] = 0.99F;

  /* Product: '<S200>/Product' */
  mcb_pmsm_foc_qep_f28379d_B.Product_m = mcb_pmsm_foc_qep_f28379d_B.SpeedGain *
    0.01F;

  /* UnitDelay: '<S200>/Unit Delay' */
  mcb_pmsm_foc_qep_f28379d_B.UnitDelay =
    mcb_pmsm_foc_qep_f28379d_DW.UnitDelay_DSTATE;

  /* Product: '<S200>/Product1' */
  mcb_pmsm_foc_qep_f28379d_B.Product1 = 0.99F *
    mcb_pmsm_foc_qep_f28379d_B.UnitDelay;

  /* Sum: '<S200>/Add1' */
  mcb_pmsm_foc_qep_f28379d_B.Add1 = mcb_pmsm_foc_qep_f28379d_B.Product_m +
    mcb_pmsm_foc_qep_f28379d_B.Product1;

  /* SignalConversion generated from: '<S9>/Selector' */
  mcb_pmsm_foc_qep_f28379d_B.TmpSignalConversionAtSelectorIn[0] =
    mcb_pmsm_foc_qep_f28379d_B.DataStoreRead;
  mcb_pmsm_foc_qep_f28379d_B.TmpSignalConversionAtSelectorIn[1] =
    mcb_pmsm_foc_qep_f28379d_B.Add1;
  mcb_pmsm_foc_qep_f28379d_B.TmpSignalConversionAtSelectorIn[2] =
    mcb_pmsm_foc_qep_f28379d_B.PU_Conversion[0];
  mcb_pmsm_foc_qep_f28379d_B.TmpSignalConversionAtSelectorIn[3] =
    mcb_pmsm_foc_qep_f28379d_B.PU_Conversion[1];
  mcb_pmsm_foc_qep_f28379d_B.TmpSignalConversionAtSelectorIn[4] =
    mcb_pmsm_foc_qep_f28379d_B.Idq_ref_PU[0];
  mcb_pmsm_foc_qep_f28379d_B.TmpSignalConversionAtSelectorIn[5] =
    mcb_pmsm_foc_qep_f28379d_B.algDD_o1;
  mcb_pmsm_foc_qep_f28379d_B.TmpSignalConversionAtSelectorIn[6] =
    mcb_pmsm_foc_qep_f28379d_B.Idq_ref_PU[1];
  mcb_pmsm_foc_qep_f28379d_B.TmpSignalConversionAtSelectorIn[7] =
    mcb_pmsm_foc_qep_f28379d_B.algDD_o2;
  mcb_pmsm_foc_qep_f28379d_B.TmpSignalConversionAtSelectorIn[8] =
    mcb_pmsm_foc_qep_f28379d_B.Add_c;

  /* DataStoreRead: '<S9>/Data Store Read' */
  mcb_pmsm_foc_qep_f28379d_B.DataStoreRead_j =
    mcb_pmsm_foc_qep_f28379d_DW.Debug_signals;

  /* MultiPortSwitch: '<S9>/Multiport Switch' */
  switch (mcb_pmsm_foc_qep_f28379d_B.DataStoreRead_j) {
   case 1:
    /* MultiPortSwitch: '<S9>/Multiport Switch' incorporates:
     *  Constant: '<S9>/speed_control'
     */
    mcb_pmsm_foc_qep_f28379d_B.MultiportSwitch[0] = 1U;
    mcb_pmsm_foc_qep_f28379d_B.MultiportSwitch[1] = 2U;
    break;

   case 2:
    /* MultiPortSwitch: '<S9>/Multiport Switch' incorporates:
     *  Constant: '<S9>/Id_control'
     */
    mcb_pmsm_foc_qep_f28379d_B.MultiportSwitch[0] = 5U;
    mcb_pmsm_foc_qep_f28379d_B.MultiportSwitch[1] = 6U;
    break;

   case 3:
    /* MultiPortSwitch: '<S9>/Multiport Switch' incorporates:
     *  Constant: '<S9>/Iq_control'
     */
    mcb_pmsm_foc_qep_f28379d_B.MultiportSwitch[0] = 7U;
    mcb_pmsm_foc_qep_f28379d_B.MultiportSwitch[1] = 8U;
    break;

   case 4:
    /* MultiPortSwitch: '<S9>/Multiport Switch' incorporates:
     *  Constant: '<S9>/Iab'
     */
    mcb_pmsm_foc_qep_f28379d_B.MultiportSwitch[0] = 3U;
    mcb_pmsm_foc_qep_f28379d_B.MultiportSwitch[1] = 4U;
    break;

   default:
    /* MultiPortSwitch: '<S9>/Multiport Switch' incorporates:
     *  Constant: '<S9>/Ia_Pos'
     */
    mcb_pmsm_foc_qep_f28379d_B.MultiportSwitch[0] = 3U;
    mcb_pmsm_foc_qep_f28379d_B.MultiportSwitch[1] = 9U;
    break;
  }

  /* End of MultiPortSwitch: '<S9>/Multiport Switch' */

  /* Selector: '<S9>/Selector' */
  mcb_pmsm_foc_qep_f28379d_B.Selector[0] =
    mcb_pmsm_foc_qep_f28379d_B.TmpSignalConversionAtSelectorIn[(int16_T)
    mcb_pmsm_foc_qep_f28379d_B.MultiportSwitch[0] - 1];
  mcb_pmsm_foc_qep_f28379d_B.Selector[1] =
    mcb_pmsm_foc_qep_f28379d_B.TmpSignalConversionAtSelectorIn[(int16_T)
    mcb_pmsm_foc_qep_f28379d_B.MultiportSwitch[1] - 1];

  /* S-Function (any2byte_svd): '<S228>/Byte Pack' */

  /* Pack: <S228>/Byte Pack */
  {
    uint32_T MW_outputPortOffset = 0U;
    uint16_T MW_inputPortWidth = 0U;

    /* Packed output data type - uint32_T */
    void* packData = &mcb_pmsm_foc_qep_f28379d_B.BytePack[0];

    /* Packing the values of Input 1 */
    /* Input data type - real32_T, size - 2 */
    {
      MW_inputPortWidth = (uint16_T)2 * sizeof(real32_T);
      memcpy((void *)&(((uint16_T *)packData)[MW_outputPortOffset]), (void*)
             &mcb_pmsm_foc_qep_f28379d_B.Selector[0], MW_inputPortWidth);
    }
  }

  /* If: '<S226>/If' */
  if (mcb_pmsm_foc_qep_f28379d_B.Output == 0U) {
    /* Outputs for IfAction SubSystem: '<S226>/Start' incorporates:
     *  ActionPort: '<S232>/Action Port'
     */
    /* Merge: '<S226>/Merge' incorporates:
     *  Constant: '<S232>/Start'
     *  SignalConversion generated from: '<S232>/Data_out'
     */
    mcb_pmsm_foc_qep_f28379d_B.SCI_Tx_Data[0] = 1397969747UL;

    /* SignalConversion generated from: '<S232>/Data' */
    Sum_e = mcb_pmsm_foc_qep_f28379d_B.BytePack[0];

    /* End of Outputs for SubSystem: '<S226>/Start' */
    mcb_pmsm_foc_qep_f28379d_B.Data_fw[0] = Sum_e;

    /* Outputs for IfAction SubSystem: '<S226>/Start' incorporates:
     *  ActionPort: '<S232>/Action Port'
     */
    /* Merge: '<S226>/Merge' incorporates:
     *  SignalConversion generated from: '<S232>/Data_out'
     */
    mcb_pmsm_foc_qep_f28379d_B.SCI_Tx_Data[1] = Sum_e;

    /* SignalConversion generated from: '<S232>/Data' */
    Sum_e = mcb_pmsm_foc_qep_f28379d_B.BytePack[1];

    /* End of Outputs for SubSystem: '<S226>/Start' */
    mcb_pmsm_foc_qep_f28379d_B.Data_fw[1] = Sum_e;

    /* Outputs for IfAction SubSystem: '<S226>/Start' incorporates:
     *  ActionPort: '<S232>/Action Port'
     */
    /* Merge: '<S226>/Merge' incorporates:
     *  SignalConversion generated from: '<S232>/Data_out'
     */
    mcb_pmsm_foc_qep_f28379d_B.SCI_Tx_Data[2] = Sum_e;

    /* Merge: '<S226>/Merge1' incorporates:
     *  Bias: '<S232>/Bias'
     */
    mcb_pmsm_foc_qep_f28379d_B.SCI_Tx_Iteration =
      mcb_pmsm_foc_qep_f28379d_ConstB.Width + 1UL;

    /* End of Outputs for SubSystem: '<S226>/Start' */
  } else if (mcb_pmsm_foc_qep_f28379d_B.Output == 599U) {
    /* Outputs for IfAction SubSystem: '<S226>/End' incorporates:
     *  ActionPort: '<S231>/Action Port'
     */
    /* SignalConversion generated from: '<S231>/Data' */
    Sum_e = mcb_pmsm_foc_qep_f28379d_B.BytePack[0];

    /* End of Outputs for SubSystem: '<S226>/End' */
    mcb_pmsm_foc_qep_f28379d_B.Data_f[0] = Sum_e;

    /* Outputs for IfAction SubSystem: '<S226>/End' incorporates:
     *  ActionPort: '<S231>/Action Port'
     */
    /* Merge: '<S226>/Merge' incorporates:
     *  SignalConversion generated from: '<S231>/Data_out'
     */
    mcb_pmsm_foc_qep_f28379d_B.SCI_Tx_Data[0] = Sum_e;

    /* SignalConversion generated from: '<S231>/Data' */
    Sum_e = mcb_pmsm_foc_qep_f28379d_B.BytePack[1];

    /* End of Outputs for SubSystem: '<S226>/End' */
    mcb_pmsm_foc_qep_f28379d_B.Data_f[1] = Sum_e;

    /* Outputs for IfAction SubSystem: '<S226>/End' incorporates:
     *  ActionPort: '<S231>/Action Port'
     */
    /* Merge: '<S226>/Merge' incorporates:
     *  Constant: '<S231>/End'
     *  SignalConversion generated from: '<S231>/Data_out'
     */
    mcb_pmsm_foc_qep_f28379d_B.SCI_Tx_Data[1] = Sum_e;
    mcb_pmsm_foc_qep_f28379d_B.SCI_Tx_Data[2] = 1162167621UL;

    /* Merge: '<S226>/Merge1' incorporates:
     *  Bias: '<S231>/Bias'
     */
    mcb_pmsm_foc_qep_f28379d_B.SCI_Tx_Iteration =
      mcb_pmsm_foc_qep_f28379d_ConstB.Width + 1UL;

    /* End of Outputs for SubSystem: '<S226>/End' */
  } else {
    /* Outputs for IfAction SubSystem: '<S226>/Data' incorporates:
     *  ActionPort: '<S230>/Action Port'
     */
    /* SignalConversion generated from: '<S230>/Data' */
    Sum_e = mcb_pmsm_foc_qep_f28379d_B.BytePack[0];

    /* End of Outputs for SubSystem: '<S226>/Data' */
    mcb_pmsm_foc_qep_f28379d_B.Data[0] = Sum_e;

    /* Outputs for IfAction SubSystem: '<S226>/Data' incorporates:
     *  ActionPort: '<S230>/Action Port'
     */
    /* Merge: '<S226>/Merge' incorporates:
     *  SignalConversion generated from: '<S230>/Data_out'
     */
    mcb_pmsm_foc_qep_f28379d_B.SCI_Tx_Data[0] = Sum_e;

    /* SignalConversion generated from: '<S230>/Data' */
    Sum_e = mcb_pmsm_foc_qep_f28379d_B.BytePack[1];

    /* End of Outputs for SubSystem: '<S226>/Data' */
    mcb_pmsm_foc_qep_f28379d_B.Data[1] = Sum_e;

    /* Outputs for IfAction SubSystem: '<S226>/Data' incorporates:
     *  ActionPort: '<S230>/Action Port'
     */
    /* Merge: '<S226>/Merge' incorporates:
     *  Constant: '<S230>/Dummy'
     *  SignalConversion generated from: '<S230>/Data_out'
     */
    mcb_pmsm_foc_qep_f28379d_B.SCI_Tx_Data[1] = Sum_e;
    mcb_pmsm_foc_qep_f28379d_B.SCI_Tx_Data[2] = 0UL;

    /* Merge: '<S226>/Merge1' incorporates:
     *  SignalConversion generated from: '<S230>/Data_width'
     */
    mcb_pmsm_foc_qep_f28379d_B.SCI_Tx_Iteration =
      mcb_pmsm_foc_qep_f28379d_ConstB.Width;

    /* End of Outputs for SubSystem: '<S226>/Data' */
  }

  /* End of If: '<S226>/If' */

  /* Outputs for Iterator SubSystem: '<S224>/While Iterator Subsystem' incorporates:
   *  WhileIterator: '<S227>/While Iterator'
   */
  s227_iter = 1;
  do {
    mcb_pmsm_foc_qep_f28379d_B.WhileIterator = s227_iter;
    mcb_pmsm_foc_qep_f28379d_B.IndexVector =
      mcb_pmsm_foc_qep_f28379d_B.SCI_Tx_Data[mcb_pmsm_foc_qep_f28379d_B.WhileIterator
      - 1];

    {
      if (checkSCITransmitInProgressA != 1U) {
        checkSCITransmitInProgressA = 1U;
        int16_T errFlgHeader = NOERROR;
        int16_T errFlgData = NOERROR;
        int16_T errFlgTail = NOERROR;
        errFlgData = scia_xmit((uchar_T*)&mcb_pmsm_foc_qep_f28379d_B.IndexVector,
          4, 4);
        checkSCITransmitInProgressA = 0U;
      }
    }

    mcb_pmsm_foc_qep_f28379d_B.Add = mcb_pmsm_foc_qep_f28379d_B.SCI_Tx_Iteration
      - (uint32_T)mcb_pmsm_foc_qep_f28379d_B.WhileIterator;
    s227_iter++;
  } while (mcb_pmsm_foc_qep_f28379d_B.Add != 0UL);

  /* End of Outputs for SubSystem: '<S224>/While Iterator Subsystem' */

  /* Sum: '<S233>/FixPt Sum1' incorporates:
   *  Constant: '<S233>/FixPt Constant'
   */
  mcb_pmsm_foc_qep_f28379d_B.FixPtSum1 = mcb_pmsm_foc_qep_f28379d_B.Output + 1U;

  /* Switch: '<S234>/FixPt Switch' */
  if (mcb_pmsm_foc_qep_f28379d_B.FixPtSum1 > 599U) {
    /* Switch: '<S234>/FixPt Switch' incorporates:
     *  Constant: '<S234>/Constant'
     */
    mcb_pmsm_foc_qep_f28379d_B.FixPtSwitch = 0U;
  } else {
    /* Switch: '<S234>/FixPt Switch' */
    mcb_pmsm_foc_qep_f28379d_B.FixPtSwitch =
      mcb_pmsm_foc_qep_f28379d_B.FixPtSum1;
  }

  /* End of Switch: '<S234>/FixPt Switch' */

  /* DataStoreRead: '<S13>/Enable' */
  mcb_pmsm_foc_qep_f28379d_B.PWM_En = mcb_pmsm_foc_qep_f28379d_DW.Enable;

  /* DataTypeConversion: '<S13>/Data Type Conversion' */
  mcb_pmsm_foc_qep_f28379d_B.DataTypeConversion =
    mcb_pmsm_foc_qep_f28379d_B.PWM_En;

  /* Switch: '<S223>/Switch' */
  mcb_pmsm_foc_qep_f28379d_B.Switch_g =
    mcb_pmsm_foc_qep_f28379d_B.DataTypeConversion;

  /* S-Function (c280xgpio_do): '<S223>/DRV830x Enable' */
  {
    if (mcb_pmsm_foc_qep_f28379d_B.Switch_g) {
      GpioDataRegs.GPDSET.bit.GPIO124 = 1U;
    } else {
      GpioDataRegs.GPDCLEAR.bit.GPIO124 = 1U;
    }
  }

  /* Switch: '<S223>/Switch1' */
  if (mcb_pmsm_foc_qep_f28379d_B.DataTypeConversion >= 0.5F) {
    /* Switch: '<S8>/Switch' */
    if (mcb_pmsm_foc_qep_f28379d_B.AND) {
      /* Switch: '<S8>/Switch' */
      mcb_pmsm_foc_qep_f28379d_B.Switch_b[0] = mcb_pmsm_foc_qep_f28379d_B.Gain[0];
      mcb_pmsm_foc_qep_f28379d_B.Switch_b[1] = mcb_pmsm_foc_qep_f28379d_B.Gain[1];
      mcb_pmsm_foc_qep_f28379d_B.Switch_b[2] = mcb_pmsm_foc_qep_f28379d_B.Gain[2];
    } else {
      /* Switch: '<S8>/Switch' */
      mcb_pmsm_foc_qep_f28379d_B.Switch_b[0] = mcb_pmsm_foc_qep_f28379d_B.Ka;
      mcb_pmsm_foc_qep_f28379d_B.Switch_b[1] = mcb_pmsm_foc_qep_f28379d_B.Kb;
      mcb_pmsm_foc_qep_f28379d_B.Switch_b[2] = mcb_pmsm_foc_qep_f28379d_B.Kc;
    }

    /* End of Switch: '<S8>/Switch' */

    /* Gain: '<S13>/One_by_Two' */
    Bias = 0.5F * mcb_pmsm_foc_qep_f28379d_B.Switch_b[0];
    mcb_pmsm_foc_qep_f28379d_B.One_by_Two[0] = Bias;

    /* Sum: '<S13>/Sum' incorporates:
     *  Constant: '<S13>/Constant'
     */
    Bias += 0.5F;
    mcb_pmsm_foc_qep_f28379d_B.PWM_Duty_Cycles[0] = Bias;

    /* Gain: '<S223>/Scale_to_PWM_Counter_PRD' */
    u0 = (uint16_T)(5000.0F * Bias);
    mcb_pmsm_foc_qep_f28379d_B.Scale_to_PWM_Counter_PRD[0] = u0;

    /* Switch: '<S223>/Switch1' */
    mcb_pmsm_foc_qep_f28379d_B.Switch1_j[0] = u0;

    /* Gain: '<S13>/One_by_Two' */
    Bias = 0.5F * mcb_pmsm_foc_qep_f28379d_B.Switch_b[1];
    mcb_pmsm_foc_qep_f28379d_B.One_by_Two[1] = Bias;

    /* Sum: '<S13>/Sum' incorporates:
     *  Constant: '<S13>/Constant'
     */
    Bias += 0.5F;
    mcb_pmsm_foc_qep_f28379d_B.PWM_Duty_Cycles[1] = Bias;

    /* Gain: '<S223>/Scale_to_PWM_Counter_PRD' */
    u0 = (uint16_T)(5000.0F * Bias);
    mcb_pmsm_foc_qep_f28379d_B.Scale_to_PWM_Counter_PRD[1] = u0;

    /* Switch: '<S223>/Switch1' */
    mcb_pmsm_foc_qep_f28379d_B.Switch1_j[1] = u0;

    /* Gain: '<S13>/One_by_Two' */
    Bias = 0.5F * mcb_pmsm_foc_qep_f28379d_B.Switch_b[2];
    mcb_pmsm_foc_qep_f28379d_B.One_by_Two[2] = Bias;

    /* Sum: '<S13>/Sum' incorporates:
     *  Constant: '<S13>/Constant'
     */
    Bias += 0.5F;
    mcb_pmsm_foc_qep_f28379d_B.PWM_Duty_Cycles[2] = Bias;

    /* Gain: '<S223>/Scale_to_PWM_Counter_PRD' */
    u0 = (uint16_T)(5000.0F * Bias);
    mcb_pmsm_foc_qep_f28379d_B.Scale_to_PWM_Counter_PRD[2] = u0;

    /* Switch: '<S223>/Switch1' */
    mcb_pmsm_foc_qep_f28379d_B.Switch1_j[2] = u0;
  } else {
    /* Switch: '<S223>/Switch1' incorporates:
     *  Constant: '<S223>/stop'
     */
    mcb_pmsm_foc_qep_f28379d_B.Switch1_j[0] = 0U;
    mcb_pmsm_foc_qep_f28379d_B.Switch1_j[1] = 0U;
    mcb_pmsm_foc_qep_f28379d_B.Switch1_j[2] = 0U;
  }

  /* End of Switch: '<S223>/Switch1' */

  /* S-Function (c2802xpwm): '<S223>/ePWM1' */
  uint16_T tbprdValue1Outputs = EPwm1Regs.TBPRD;

  /*-- Update CMPA value for ePWM1 --*/
  {
    EPwm1Regs.CMPA.bit.CMPA = (uint16_T)(mcb_pmsm_foc_qep_f28379d_B.Switch1_j[0]);
  }

  /* S-Function (c2802xpwm): '<S223>/ePWM2' */
  uint16_T tbprdValue2Outputs = EPwm2Regs.TBPRD;

  /*-- Update CMPA value for ePWM2 --*/
  {
    EPwm2Regs.CMPA.bit.CMPA = (uint16_T)(mcb_pmsm_foc_qep_f28379d_B.Switch1_j[1]);
  }

  /* S-Function (c2802xpwm): '<S223>/ePWM3' */
  uint16_T tbprdValue3Outputs = EPwm3Regs.TBPRD;

  /*-- Update CMPA value for ePWM3 --*/
  {
    EPwm3Regs.CMPA.bit.CMPA = (uint16_T)(mcb_pmsm_foc_qep_f28379d_B.Switch1_j[2]);
  }

  /* Update for Delay: '<S191>/Delay' */
  mcb_pmsm_foc_qep_f28379d_DW.Delay_DSTATE_m = mcb_pmsm_foc_qep_f28379d_B.AND;

  /* Update for UnitDelay: '<S229>/Output' */
  mcb_pmsm_foc_qep_f28379d_DW.Output_DSTATE =
    mcb_pmsm_foc_qep_f28379d_B.FixPtSwitch;

  /* Update for Delay: '<S197>/Delay' */
  mcb_pmsm_foc_qep_f28379d_DW.Delay_DSTATE[mcb_pmsm_foc_qep_f28379d_DW.CircBufIdx]
    = mcb_pmsm_foc_qep_f28379d_B.PositionToCount;
  if (mcb_pmsm_foc_qep_f28379d_DW.CircBufIdx < 19U) {
    mcb_pmsm_foc_qep_f28379d_DW.CircBufIdx++;
  } else {
    mcb_pmsm_foc_qep_f28379d_DW.CircBufIdx = 0U;
  }

  /* End of Update for Delay: '<S197>/Delay' */

  /* Update for UnitDelay: '<S200>/Unit Delay' */
  mcb_pmsm_foc_qep_f28379d_DW.UnitDelay_DSTATE = mcb_pmsm_foc_qep_f28379d_B.Add1;
}

/* System initialize for atomic system: */
void mcb__SPIMasterTransfer_Init(DW_SPIMasterTransfer_mcb_pmsm_T *localDW)
{
  uint32_T SPIPinsLoc;

  /* Start for MATLABSystem: '<S253>/SPI Master Transfer' */
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  localDW->obj.isInitialized = 1L;
  SPIPinsLoc = MW_UNDEFINED_VALUE;
  localDW->obj.MW_SPI_HANDLE = MW_SPI_Open(0UL, SPIPinsLoc, SPIPinsLoc,
    SPIPinsLoc, MW_UNDEFINED_VALUE, true, 0U);
  MW_SPI_SetFormat(localDW->obj.MW_SPI_HANDLE, 16U, MW_SPI_MODE_0,
                   MW_SPI_MOST_SIGNIFICANT_BIT_FIRST);
  localDW->obj.isSetupComplete = true;
}

/* Output and update for atomic system: */
void mcb_pmsm__SPIMasterTransfer(uint16_T rtu_0, B_SPIMasterTransfer_mcb_pmsm__T
  *localB, DW_SPIMasterTransfer_mcb_pmsm_T *localDW)
{
  uint16_T rdDataRaw;
  uint16_T status;

  /* MATLABSystem: '<S253>/SPI Master Transfer' */
  MW_SPI_SetSlaveSelect(localDW->obj.MW_SPI_HANDLE, 0U, true);
  status = MW_SPI_SetFormat(localDW->obj.MW_SPI_HANDLE, 16U, MW_SPI_MODE_0,
    MW_SPI_MOST_SIGNIFICANT_BIT_FIRST);
  if (status == 0U) {
    MW_SPI_MasterWriteRead_8bits(localDW->obj.MW_SPI_HANDLE, &rtu_0, &rdDataRaw,
      1UL);
  }

  /* MATLABSystem: '<S253>/SPI Master Transfer' */
  localB->SPIMasterTransfer = rdDataRaw;
}

/* Termination for atomic system: */
void mcb__SPIMasterTransfer_Term(DW_SPIMasterTransfer_mcb_pmsm_T *localDW)
{
  uint32_T SPIPinsLoc;

  /* Terminate for MATLABSystem: '<S253>/SPI Master Transfer' */
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
    if ((localDW->obj.isInitialized == 1L) && localDW->obj.isSetupComplete) {
      SPIPinsLoc = MW_UNDEFINED_VALUE;
      MW_SPI_Close(localDW->obj.MW_SPI_HANDLE, SPIPinsLoc, SPIPinsLoc,
                   SPIPinsLoc, MW_UNDEFINED_VALUE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S253>/SPI Master Transfer' */
}

/* System initialize for atomic system: '<Root>/Speed Control' */
void mcb_pmsm__SpeedControl_Init(B_SpeedControl_mcb_pmsm_foc_q_T *localB,
  DW_SpeedControl_mcb_pmsm_foc__T *localDW)
{
  /* Start for Constant: '<S263>/Ki2' */
  localB->Ki2 = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S303>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
  localDW->Integrator_PrevResetState = 0;
}

/* Output and update for atomic system: '<Root>/Speed Control' */
void mcb_pmsm_foc_q_SpeedControl(real32_T rtu_Speed_Ref_PU, real32_T
  rtu_Speed_Meas_PU, const boolean_T *rtd_EnClosedLoop, const boolean_T
  *rtd_Enable, B_SpeedControl_mcb_pmsm_foc_q_T *localB,
  DW_SpeedControl_mcb_pmsm_foc__T *localDW)
{
  real32_T u0;

  /* Constant: '<S7>/Id_ref' */
  localB->Id_ref = 0.0F;

  /* DataStoreRead: '<S263>/Data Store Read1' */
  localB->DataStoreRead1 = *rtd_Enable;

  /* DataStoreRead: '<S264>/Data Store Read' */
  localB->DataStoreRead = *rtd_EnClosedLoop;

  /* DataStoreRead: '<S264>/Data Store Read1' */
  localB->DataStoreRead1_k = *rtd_Enable;

  /* Logic: '<S264>/AND' */
  localB->AND = (localB->DataStoreRead && localB->DataStoreRead1_k);

  /* Switch: '<S264>/Switch' */
  if (localB->AND) {
    /* Switch: '<S264>/Switch' */
    localB->Switch = rtu_Speed_Ref_PU;
  } else {
    /* Switch: '<S264>/Switch' */
    localB->Switch = rtu_Speed_Meas_PU;
  }

  /* End of Switch: '<S264>/Switch' */

  /* Switch: '<S266>/Switch1' incorporates:
   *  Constant: '<S266>/FilterConstant'
   *  Constant: '<S266>/OneMinusFilterConstant'
   */
  localB->Switch1[0] = 0.1F;
  localB->Switch1[1] = 0.9F;

  /* Product: '<S323>/Product' */
  localB->Product = localB->Switch * 0.1F;

  /* UnitDelay: '<S323>/Unit Delay' */
  localB->UnitDelay = localDW->UnitDelay_DSTATE;

  /* Product: '<S323>/Product1' */
  localB->Product1 = 0.9F * localB->UnitDelay;

  /* Sum: '<S323>/Add1' */
  localB->Add1 = localB->Product + localB->Product1;

  /* Sum: '<S263>/Sum' */
  localB->Sum = localB->Add1 - rtu_Speed_Meas_PU;

  /* Product: '<S308>/PProd Out' incorporates:
   *  Constant: '<S263>/Kp1'
   */
  localB->PProdOut = localB->Sum * 0.918941498F;

  /* Logic: '<S263>/Logical Operator' */
  localB->LogicalOperator = !localB->DataStoreRead1;

  /* Constant: '<S263>/Ki2' */
  localB->Ki2 = 0.0F;

  /* DiscreteIntegrator: '<S303>/Integrator' */
  if (localB->LogicalOperator || (localDW->Integrator_PrevResetState != 0)) {
    localDW->Integrator_DSTATE = 0.0F;
  }

  /* DiscreteIntegrator: '<S303>/Integrator' */
  localB->Integrator = localDW->Integrator_DSTATE;

  /* Sum: '<S312>/Sum' */
  localB->Sum_c = localB->PProdOut + localB->Integrator;

  /* DeadZone: '<S295>/DeadZone' */
  if (localB->Sum_c > 1.0F) {
    /* DeadZone: '<S295>/DeadZone' */
    localB->DeadZone = localB->Sum_c - 1.0F;
  } else if (localB->Sum_c >= -1.0F) {
    /* DeadZone: '<S295>/DeadZone' */
    localB->DeadZone = 0.0F;
  } else {
    /* DeadZone: '<S295>/DeadZone' */
    localB->DeadZone = localB->Sum_c - -1.0F;
  }

  /* End of DeadZone: '<S295>/DeadZone' */

  /* RelationalOperator: '<S293>/Relational Operator' incorporates:
   *  Constant: '<S293>/Clamping_zero'
   */
  localB->RelationalOperator = (localB->DeadZone != 0.0F);

  /* RelationalOperator: '<S293>/fix for DT propagation issue' incorporates:
   *  Constant: '<S293>/Clamping_zero'
   */
  localB->fixforDTpropagationissue = (localB->DeadZone > 0.0F);

  /* Switch: '<S293>/Switch1' */
  if (localB->fixforDTpropagationissue) {
    /* Switch: '<S293>/Switch1' incorporates:
     *  Constant: '<S293>/Constant'
     */
    localB->Switch1_i = 1;
  } else {
    /* Switch: '<S293>/Switch1' incorporates:
     *  Constant: '<S293>/Constant2'
     */
    localB->Switch1_i = -1;
  }

  /* End of Switch: '<S293>/Switch1' */

  /* Product: '<S300>/IProd Out' incorporates:
   *  Constant: '<S263>/Ki1'
   */
  localB->IProdOut = localB->Sum * 0.0121322013F;

  /* RelationalOperator: '<S293>/fix for DT propagation issue1' incorporates:
   *  Constant: '<S293>/Clamping_zero'
   */
  localB->fixforDTpropagationissue1 = (localB->IProdOut > 0.0F);

  /* Switch: '<S293>/Switch2' */
  if (localB->fixforDTpropagationissue1) {
    /* Switch: '<S293>/Switch2' incorporates:
     *  Constant: '<S293>/Constant3'
     */
    localB->Switch2 = 1;
  } else {
    /* Switch: '<S293>/Switch2' incorporates:
     *  Constant: '<S293>/Constant4'
     */
    localB->Switch2 = -1;
  }

  /* End of Switch: '<S293>/Switch2' */

  /* RelationalOperator: '<S293>/Equal1' incorporates:
   *  Switch: '<S293>/Switch1'
   *  Switch: '<S293>/Switch2'
   */
  localB->Equal1 = (localB->Switch1_i == localB->Switch2);

  /* Logic: '<S293>/AND3' */
  localB->AND3 = (localB->RelationalOperator && localB->Equal1);

  /* Switch: '<S293>/Switch' */
  if (localB->AND3) {
    /* Switch: '<S293>/Switch' incorporates:
     *  Constant: '<S293>/Constant1'
     */
    localB->Switch_d = 0.0F;
  } else {
    /* Switch: '<S293>/Switch' */
    localB->Switch_d = localB->IProdOut;
  }

  /* End of Switch: '<S293>/Switch' */

  /* Saturate: '<S310>/Saturation' */
  u0 = localB->Sum_c;
  if (u0 > 1.0F) {
    /* Saturate: '<S310>/Saturation' */
    localB->Saturation = 1.0F;
  } else if (u0 < -1.0F) {
    /* Saturate: '<S310>/Saturation' */
    localB->Saturation = -1.0F;
  } else {
    /* Saturate: '<S310>/Saturation' */
    localB->Saturation = u0;
  }

  /* End of Saturate: '<S310>/Saturation' */

  /* Update for UnitDelay: '<S323>/Unit Delay' */
  localDW->UnitDelay_DSTATE = localB->Add1;

  /* Update for DiscreteIntegrator: '<S303>/Integrator' */
  localDW->Integrator_DSTATE += localB->Switch_d;
  localDW->Integrator_PrevResetState = (int16_T)localB->LogicalOperator;
}

/* Model step function for TID0 */
void mcb_pmsm_foc_qep_f28379d_step0(void) /* Sample time: [0.0005s, 0.0s] */
{
  {                                    /* Sample time: [0.0005s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* RateTransition: '<Root>/RT1' */
  mcb_pmsm_foc_qep_f28379d_DW.RT1_semaphoreTaken =
    mcb_pmsm_foc_qep_f28379d_DW.RT1_ActiveBufIdx;

  /* RateTransition: '<Root>/RT1' */
  mcb_pmsm_foc_qep_f28379d_B.RT1 =
    mcb_pmsm_foc_qep_f28379d_DW.RT1_Buffer[mcb_pmsm_foc_qep_f28379d_DW.RT1_semaphoreTaken];

  /* RateTransition: '<Root>/RT3' */
  mcb_pmsm_foc_qep_f28379d_B.RT3 =
    mcb_pmsm_foc_qep_f28379d_DW.RT3_Buffer[mcb_pmsm_foc_qep_f28379d_DW.RT3_ActiveBufIdx];

  /* Outputs for Atomic SubSystem: '<Root>/Speed Control' */
  mcb_pmsm_foc_q_SpeedControl(mcb_pmsm_foc_qep_f28379d_B.RT3,
    mcb_pmsm_foc_qep_f28379d_B.RT1, &mcb_pmsm_foc_qep_f28379d_DW.EnClosedLoop,
    &mcb_pmsm_foc_qep_f28379d_DW.Enable,
    &mcb_pmsm_foc_qep_f28379d_B.SpeedControl,
    &mcb_pmsm_foc_qep_f28379d_DW.SpeedControl);

  /* End of Outputs for SubSystem: '<Root>/Speed Control' */

  /* RateTransition: '<Root>/RT2' */
  mcb_pmsm_foc_qep_f28379d_DW.RT2_Buffer
    [(mcb_pmsm_foc_qep_f28379d_DW.RT2_ActiveBufIdx == 0) << 1U] =
    mcb_pmsm_foc_qep_f28379d_B.SpeedControl.Id_ref;
  mcb_pmsm_foc_qep_f28379d_DW.RT2_Buffer[1 +
    ((mcb_pmsm_foc_qep_f28379d_DW.RT2_ActiveBufIdx == 0) << 1U)] =
    mcb_pmsm_foc_qep_f28379d_B.SpeedControl.Saturation;
  mcb_pmsm_foc_qep_f28379d_DW.RT2_ActiveBufIdx =
    (mcb_pmsm_foc_qep_f28379d_DW.RT2_ActiveBufIdx == 0);
}

/* Model step function for TID1 */
void mcb_pmsm_foc_qep_f28379d_step1(void) /* Sample time: [0.5s, 0.0s] */
{
  /* Outputs for Atomic SubSystem: '<Root>/Heartbeat LED' */
  /* S-Function (c280xgpio_do): '<S255>/Digital Output' incorporates:
   *  Constant: '<S4>/RED_LED'
   */
  {
    GpioDataRegs.GPBTOGGLE.bit.GPIO34 = (uint16_T)((1U) != 0);
  }

  /* End of Outputs for SubSystem: '<Root>/Heartbeat LED' */
}

/* Model initialize function */
void mcb_pmsm_foc_qep_f28379d_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)mcb_pmsm_foc_qep_f28379d_M, 0,
                sizeof(RT_MODEL_mcb_pmsm_foc_qep_f28_T));

  /* block I/O */
  (void) memset(((void *) &mcb_pmsm_foc_qep_f28379d_B), 0,
                sizeof(B_mcb_pmsm_foc_qep_f28379d_T));

  {
    int16_T i;
    for (i = 0; i < 9; i++) {
      mcb_pmsm_foc_qep_f28379d_B.TmpSignalConversionAtSelectorIn[i] = 0.0F;
    }

    mcb_pmsm_foc_qep_f28379d_B.RT1 = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.RT3 = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.RT2[0] = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.RT2[1] = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.SCIReceive[0] = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.SCIReceive[1] = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.GetADCVoltage[0] = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.GetADCVoltage[1] = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.GetCurrents[0] = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.GetCurrents[1] = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.PU_Conversion[0] = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.PU_Conversion[1] = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.DTC = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.Product = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.Switch = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.Merge = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.Numberofpolepairs = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.Floor = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.Add_c = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.DataStoreRead = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.DTC_p = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.SpeedGain = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.Switch1[0] = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.Switch1[1] = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.Product_m = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.UnitDelay = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.Product1 = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.Add1 = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.Selector[0] = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.Selector[1] = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.DataTypeConversion = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.Switch_g = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.Switch_b[0] = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.Switch_b[1] = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.Switch_b[2] = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.One_by_Two[0] = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.One_by_Two[1] = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.One_by_Two[2] = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.PWM_Duty_Cycles[0] = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.PWM_Duty_Cycles[1] = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.PWM_Duty_Cycles[2] = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.rpm2freq = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.Eps = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.Product_k = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.Frequency = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.Vbyf = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.Correction_Factor_sinePWM = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.Amplitude = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.UnaryMinus = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.position_increment = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.scaleIn = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.UnitDelay_d = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.scaleOut = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.DataStoreRead_p = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.Eps_g = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.convert_pu = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.Merge_h = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.indexing = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.Lookup[0] = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.Lookup[1] = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.Lookup[2] = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.Lookup[3] = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.Sum3 = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.DataTypeConversion1 = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.Sum2 = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.Product_b = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.Sum4 = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.Sum5 = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.Product1_c = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.Sum6 = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.Ka = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.one_by_two = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.sqrt3_by_two = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.add_b = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.Kb = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.add_c = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.Kc = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.Divide = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.Sample_Time = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.Sum_f = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.Add_m = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.DataTypeConversion1_f = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.Add1_c = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.Input = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.Idq_ref_PU[0] = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.Idq_ref_PU[1] = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.Merge_b = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.indexing_n = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.Lookup_p[0] = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.Lookup_p[1] = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.Lookup_p[2] = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.Lookup_p[3] = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.Sum3_p = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.DataTypeConversion1_h = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.Sum2_j = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.Product_n = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.Sum4_l = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.Sum5_j = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.Product1_g = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.Sum6_a = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.Sum_o = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.PProdOut = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.Kp1 = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.Integrator = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.Sum_m = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.Saturation = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.Sum_j = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.PProdOut_g = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.Ki1 = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.Integrator_f = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.Sum_g = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.Saturation_f = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.Switch_n = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.Product_j = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.Product_f = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.Product1_gr = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.Sum1 = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.Merge_i[0] = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.Merge_i[1] = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.DeadZone = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.IProdOut = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.Switch_f = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.DeadZone_a = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.IProdOut_b = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.Switch_a = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.one_by_two_l = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.sqrt3_by_two_l = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.add_b_e = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.add_c_m = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.Max = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.Min = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.Add_n = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.one_by_two_lh = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.Add1_d = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.Add2 = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.Add3 = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.Gain[0] = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.Gain[1] = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.Gain[2] = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.acos_b = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.bsin = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.sum_Ds = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.bcos = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.asin_o = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.sum_Qs = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.Switch_h[0] = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.Switch_h[1] = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.algDD_o1 = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.algDD_o2 = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.Product_o[0] = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.Product_o[1] = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.SquareRoot = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.Switch_as = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.Switch_j[0] = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.Switch_j[1] = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.Switch2 = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.Product_bf = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.Sum_jr = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.Product2 = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.Merge_d = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.Gain_b = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.Switch_m = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.Switch1_n = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.Sqrt = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.Gain_l = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.a_plus_2b = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.one_by_sqrt3 = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.algDD_o1_e = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.algDD_o2_h = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.SpeedControl.Id_ref = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.SpeedControl.Switch = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.SpeedControl.Switch1[0] = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.SpeedControl.Switch1[1] = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.SpeedControl.Product = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.SpeedControl.UnitDelay = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.SpeedControl.Product1 = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.SpeedControl.Add1 = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.SpeedControl.Sum = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.SpeedControl.PProdOut = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.SpeedControl.Ki2 = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.SpeedControl.Integrator = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.SpeedControl.Sum_c = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.SpeedControl.DeadZone = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.SpeedControl.IProdOut = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.SpeedControl.Switch_d = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.SpeedControl.Saturation = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.IfActionSubsystem1_h.Convert_back = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.IfActionSubsystem_o.Convert_back = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.TwoinputsCRL_l.qcos = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.TwoinputsCRL_l.dsin = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.TwoinputsCRL_l.sum_beta = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.TwoinputsCRL_l.dcos = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.TwoinputsCRL_l.qsin = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.TwoinputsCRL_l.sum_alpha = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.TwoinputsCRL_l.Switch[0] = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.TwoinputsCRL_l.Switch[1] = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.TwoinputsCRL_l.algDD_o1 = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.TwoinputsCRL_l.algDD_o2 = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.IfActionSubsystem1_m.Convert_back = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.IfActionSubsystem_m.Convert_back = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.TwoinputsCRL.qcos = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.TwoinputsCRL.dsin = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.TwoinputsCRL.sum_beta = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.TwoinputsCRL.dcos = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.TwoinputsCRL.qsin = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.TwoinputsCRL.sum_alpha = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.TwoinputsCRL.Switch[0] = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.TwoinputsCRL.Switch[1] = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.TwoinputsCRL.algDD_o1 = 0.0F;
    mcb_pmsm_foc_qep_f28379d_B.TwoinputsCRL.algDD_o2 = 0.0F;
  }

  /* states (dwork) */
  (void) memset((void *)&mcb_pmsm_foc_qep_f28379d_DW, 0,
                sizeof(DW_mcb_pmsm_foc_qep_f28379d_T));
  mcb_pmsm_foc_qep_f28379d_DW.UnitDelay_DSTATE = 0.0F;
  mcb_pmsm_foc_qep_f28379d_DW.RampGenerator_DSTATE = 0.0F;
  mcb_pmsm_foc_qep_f28379d_DW.UnitDelay_DSTATE_h = 0.0F;
  mcb_pmsm_foc_qep_f28379d_DW.Integrator_DSTATE = 0.0F;
  mcb_pmsm_foc_qep_f28379d_DW.Integrator_DSTATE_o = 0.0F;
  mcb_pmsm_foc_qep_f28379d_DW.RT1_Buffer[0] = 0.0F;
  mcb_pmsm_foc_qep_f28379d_DW.RT1_Buffer[1] = 0.0F;
  mcb_pmsm_foc_qep_f28379d_DW.RT3_Buffer[0] = 0.0F;
  mcb_pmsm_foc_qep_f28379d_DW.RT3_Buffer[1] = 0.0F;
  mcb_pmsm_foc_qep_f28379d_DW.RT2_Buffer[0] = 0.0F;
  mcb_pmsm_foc_qep_f28379d_DW.RT2_Buffer[1] = 0.0F;
  mcb_pmsm_foc_qep_f28379d_DW.RT2_Buffer[2] = 0.0F;
  mcb_pmsm_foc_qep_f28379d_DW.RT2_Buffer[3] = 0.0F;
  mcb_pmsm_foc_qep_f28379d_DW.SpeedRef = 0.0F;
  mcb_pmsm_foc_qep_f28379d_DW.SpeedControl.UnitDelay_DSTATE = 0.0F;
  mcb_pmsm_foc_qep_f28379d_DW.SpeedControl.Integrator_DSTATE = 0.0F;

  {
    uint16_T s247_iter;

    /* Start for DataStoreMemory: '<Root>/Data Store Memory1' */
    mcb_pmsm_foc_qep_f28379d_DW.IaOffset = 2295U;

    /* Start for DataStoreMemory: '<Root>/Data Store Memory2' */
    mcb_pmsm_foc_qep_f28379d_DW.IbOffset = 2286U;

    /* Start for DataStoreMemory: '<Root>/Data Store Memory6' */
    mcb_pmsm_foc_qep_f28379d_DW.Debug_signals = 5U;

    /* SystemInitialize for S-Function (HardwareInterrupt_sfun): '<S239>/Hardware Interrupt' incorporates:
     *  SubSystem: '<Root>/Current Control'
     */
    mcb_pms_CurrentControl_Init();

    /* SystemInitialize for S-Function (HardwareInterrupt_sfun): '<S241>/Hardware Interrupt' incorporates:
     *  SubSystem: '<Root>/Serial Receive'
     */
    /* System initialize for function-call system: '<Root>/Serial Receive' */

    /* Start for S-Function (c28xsci_rx): '<S262>/SCI Receive' */

    /* Initialize out port */
    {
      mcb_pmsm_foc_qep_f28379d_B.SCIReceive[0] = (real32_T)0.0;
      mcb_pmsm_foc_qep_f28379d_B.SCIReceive[1] = (real32_T)0.0;
    }

    /*Configure Timer2 when blocking mode is enabled and Timeout is not inf*/
    {
      /* InitCpuTimers() - CPU Timers are also initialized in
       * MW_c28xx_board.c in the generated code.
       */
      CpuTimer2Regs.PRD.all = 0xFFFFFFFFU;/* max Period*/
      CpuTimer2Regs.TIM.all = 0xFFFFFFFFU;/* set Ctr*/
      CpuTimer2Regs.TPR.all = 0x00U;   /* no prescaler    */
      StartCpuTimer2();
    }

    /* SystemInitialize for Atomic SubSystem: '<Root>/Speed Control' */
    mcb_pmsm__SpeedControl_Init(&mcb_pmsm_foc_qep_f28379d_B.SpeedControl,
      &mcb_pmsm_foc_qep_f28379d_DW.SpeedControl);

    /* End of SystemInitialize for SubSystem: '<Root>/Speed Control' */

    /* SystemInitialize for Atomic SubSystem: '<Root>/Heartbeat LED' */
    /* Start for S-Function (c280xgpio_do): '<S255>/Digital Output' */
    EALLOW;
    GpioCtrlRegs.GPBMUX1.all &= 0xFFFFFFCFU;
    GpioCtrlRegs.GPBDIR.all |= 0x4U;
    EDIS;

    /* End of SystemInitialize for SubSystem: '<Root>/Heartbeat LED' */

    /* SystemInitialize for Atomic SubSystem: '<Root>/Hardware Init' */
    /* Start for S-Function (c280xgpio_do): '<S245>/Digital Output' */
    EALLOW;
    GpioCtrlRegs.GPDMUX2.all &= 0xFCFFFFFFU;
    GpioCtrlRegs.GPDDIR.all |= 0x10000000U;
    EDIS;

    /* Start for S-Function (c280xgpio_do): '<S245>/Digital Output1' */
    EALLOW;
    GpioCtrlRegs.GPAMUX2.all &= 0xFFFFCFFFU;
    GpioCtrlRegs.GPADIR.all |= 0x400000U;
    EDIS;

    /* SystemInitialize for Enabled SubSystem: '<S245>/ADC Gain setting' */
    mcb__SPIMasterTransfer_Init(&mcb_pmsm_foc_qep_f28379d_DW.SPIMasterTransfer);
    mcb__SPIMasterTransfer_Init(&mcb_pmsm_foc_qep_f28379d_DW.SPIMasterTransfer1);

    /* End of SystemInitialize for SubSystem: '<S245>/ADC Gain setting' */

    /* SystemInitialize for Enabled SubSystem: '<S243>/Calculate ADC Offset ' */
    /* SystemInitialize for Iterator SubSystem: '<S244>/For Iterator Subsystem' */
    /* Start for S-Function (c2802xadc): '<S247>/ADC_A_IN0' */
    if (MW_adcCInitFlag == 0U) {
      InitAdcC();
      MW_adcCInitFlag = 1U;
    }

    config_ADCC_SOC2 ();

    /* Start for S-Function (c2802xadc): '<S247>/ADC_B_IN0' */
    if (MW_adcBInitFlag == 0U) {
      InitAdcB();
      MW_adcBInitFlag = 1U;
    }

    config_ADCB_SOC2 ();

    /* End of SystemInitialize for SubSystem: '<S244>/For Iterator Subsystem' */
    /* End of SystemInitialize for SubSystem: '<S243>/Calculate ADC Offset ' */
    /* End of SystemInitialize for SubSystem: '<Root>/Hardware Init' */

    /* Outputs for Atomic SubSystem: '<Root>/Hardware Init' */
    /* Outputs for Enabled SubSystem: '<S245>/ADC Gain setting' incorporates:
     *  EnablePort: '<S253>/Enable'
     */
    /* Constant: '<S3>/6PWM_Mode' */
    mcb_pmsm__SPIMasterTransfer(14870U,
      &mcb_pmsm_foc_qep_f28379d_B.SPIMasterTransfer,
      &mcb_pmsm_foc_qep_f28379d_DW.SPIMasterTransfer);

    /* Constant: '<S3>/ADC_Gain_Setting' */
    mcb_pmsm__SPIMasterTransfer(20480U,
      &mcb_pmsm_foc_qep_f28379d_B.SPIMasterTransfer1,
      &mcb_pmsm_foc_qep_f28379d_DW.SPIMasterTransfer1);

    /* End of Outputs for SubSystem: '<S245>/ADC Gain setting' */

    /* Switch: '<S245>/Switch' incorporates:
     *  Constant: '<S245>/Inverter Enable'
     */
    mcb_pmsm_foc_qep_f28379d_B.Switch_c = 1U;

    /* S-Function (c280xgpio_do): '<S245>/Digital Output' */
    {
      if (mcb_pmsm_foc_qep_f28379d_B.Switch_c) {
        GpioDataRegs.GPDSET.bit.GPIO124 = 1U;
      } else {
        GpioDataRegs.GPDCLEAR.bit.GPIO124 = 1U;
      }
    }

    /* S-Function (c280xgpio_do): '<S245>/Digital Output1' incorporates:
     *  Constant: '<S245>/RunTimeMeasurement'
     */
    {
      if ((1U)) {
        GpioDataRegs.GPASET.bit.GPIO22 = 1U;
      } else {
        GpioDataRegs.GPACLEAR.bit.GPIO22 = 1U;
      }
    }

    /* Outputs for Enabled SubSystem: '<S243>/Calculate ADC Offset ' incorporates:
     *  EnablePort: '<S244>/Enable'
     */
    /* Outputs for Iterator SubSystem: '<S244>/For Iterator Subsystem' incorporates:
     *  ForIterator: '<S247>/For Iterator'
     */
    for (s247_iter = 1U; s247_iter < 17U; s247_iter++) {
      /* Outputs for Iterator SubSystem: '<S244>/For Iterator Subsystem' incorporates:
       *  ForIterator: '<S247>/For Iterator'
       */
      mcb_pmsm_foc_qep_f28379d_B.ForIterator = s247_iter;

      /* S-Function (c2802xadc): '<S247>/ADC_A_IN0' */
      {
        /*  Internal Reference Voltage : Fixed scale 0 to 3.3 V range.  */
        /*  External Reference Voltage : Allowable ranges of VREFHI(ADCINA0) = 3.3 and VREFLO(tied to ground) = 0  */
        AdccRegs.ADCSOCFRC1.bit.SOC2 = 1U;

        /* Wait for the period of Sampling window and EOC result to be latched after trigger */
#ifndef __TMS320C28XX_CLA__

        asm(" RPT #75|| NOP");

#endif

#ifdef __TMS320C28XX_CLA__

        real32_T wait_index;
        for (wait_index= 12; wait_index > 0; wait_index--)
          __mnop();

#endif

        mcb_pmsm_foc_qep_f28379d_B.ADC_A_IN0 = (AdccResultRegs.ADCRESULT2);
      }

      /* S-Function (c2802xadc): '<S247>/ADC_B_IN0' */
      {
        /*  Internal Reference Voltage : Fixed scale 0 to 3.3 V range.  */
        /*  External Reference Voltage : Allowable ranges of VREFHI(ADCINA0) = 3.3 and VREFLO(tied to ground) = 0  */
        AdcbRegs.ADCSOCFRC1.bit.SOC2 = 1U;

        /* Wait for the period of Sampling window and EOC result to be latched after trigger */
#ifndef __TMS320C28XX_CLA__

        asm(" RPT #75|| NOP");

#endif

#ifdef __TMS320C28XX_CLA__

        real32_T wait_index;
        for (wait_index= 12; wait_index > 0; wait_index--)
          __mnop();

#endif

        mcb_pmsm_foc_qep_f28379d_B.ADC_B_IN0 = (AdcbResultRegs.ADCRESULT2);
      }

      /* If: '<S247>/If' */
      if (mcb_pmsm_foc_qep_f28379d_B.ForIterator > 8U) {
        /* Outputs for IfAction SubSystem: '<S247>/If Action Subsystem' incorporates:
         *  ActionPort: '<S252>/Action Port'
         */
        /* Memory: '<S252>/Memory' */
        mcb_pmsm_foc_qep_f28379d_B.Memory =
          mcb_pmsm_foc_qep_f28379d_DW.Memory_PreviousInput;

        /* Sum: '<S252>/Sum' */
        mcb_pmsm_foc_qep_f28379d_B.Sum_h = mcb_pmsm_foc_qep_f28379d_B.ADC_A_IN0
          + mcb_pmsm_foc_qep_f28379d_B.Memory;

        /* Memory: '<S252>/Memory1' */
        mcb_pmsm_foc_qep_f28379d_B.Memory1 =
          mcb_pmsm_foc_qep_f28379d_DW.Memory1_PreviousInput;

        /* Sum: '<S252>/Sum1' */
        mcb_pmsm_foc_qep_f28379d_B.Sum1_j = mcb_pmsm_foc_qep_f28379d_B.ADC_B_IN0
          + mcb_pmsm_foc_qep_f28379d_B.Memory1;

        /* Update for Memory: '<S252>/Memory' */
        mcb_pmsm_foc_qep_f28379d_DW.Memory_PreviousInput =
          mcb_pmsm_foc_qep_f28379d_B.Sum_h;

        /* Update for Memory: '<S252>/Memory1' */
        mcb_pmsm_foc_qep_f28379d_DW.Memory1_PreviousInput =
          mcb_pmsm_foc_qep_f28379d_B.Sum1_j;

        /* End of Outputs for SubSystem: '<S247>/If Action Subsystem' */
      }

      /* End of If: '<S247>/If' */
    }

    /* End of Outputs for SubSystem: '<S244>/For Iterator Subsystem' */

    /* Product: '<S244>/Divide' incorporates:
     *  Constant: '<S244>/Constant'
     */
    mcb_pmsm_foc_qep_f28379d_B.Divide_o = (uint16_T)((real_T)
      mcb_pmsm_foc_qep_f28379d_B.Sum_h / 8.0);

    /* If: '<S244>/If' incorporates:
     *  Constant: '<S244>/Constant1'
     *  Constant: '<S244>/Constant2'
     */
    if ((mcb_pmsm_foc_qep_f28379d_B.Divide_o > 1500U) &&
        (mcb_pmsm_foc_qep_f28379d_B.Divide_o < 2500U)) {
      /* Outputs for IfAction SubSystem: '<S244>/If Action Subsystem' incorporates:
       *  ActionPort: '<S248>/Action Port'
       */
      /* DataStoreWrite: '<S248>/Data Store Write1' */
      mcb_pmsm_foc_qep_f28379d_DW.IaOffset = mcb_pmsm_foc_qep_f28379d_B.Divide_o;

      /* End of Outputs for SubSystem: '<S244>/If Action Subsystem' */
    } else {
      /* Outputs for IfAction SubSystem: '<S244>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S249>/Action Port'
       */
      /* DataStoreWrite: '<S249>/Data Store Write1' incorporates:
       *  Constant: '<S249>/Constant'
       */
      mcb_pmsm_foc_qep_f28379d_DW.IaOffset = 2295U;

      /* End of Outputs for SubSystem: '<S244>/If Action Subsystem1' */
    }

    /* End of If: '<S244>/If' */

    /* Product: '<S244>/Divide1' incorporates:
     *  Constant: '<S244>/Constant'
     */
    mcb_pmsm_foc_qep_f28379d_B.Divide1 = (uint16_T)((real_T)
      mcb_pmsm_foc_qep_f28379d_B.Sum1_j / 8.0);

    /* If: '<S244>/If1' incorporates:
     *  Constant: '<S244>/Constant1'
     *  Constant: '<S244>/Constant2'
     */
    if ((mcb_pmsm_foc_qep_f28379d_B.Divide1 > 1500U) &&
        (mcb_pmsm_foc_qep_f28379d_B.Divide1 < 2500U)) {
      /* Outputs for IfAction SubSystem: '<S244>/If Action Subsystem2' incorporates:
       *  ActionPort: '<S250>/Action Port'
       */
      /* DataStoreWrite: '<S250>/Data Store Write2' */
      mcb_pmsm_foc_qep_f28379d_DW.IbOffset = mcb_pmsm_foc_qep_f28379d_B.Divide1;

      /* End of Outputs for SubSystem: '<S244>/If Action Subsystem2' */
    } else {
      /* Outputs for IfAction SubSystem: '<S244>/If Action Subsystem3' incorporates:
       *  ActionPort: '<S251>/Action Port'
       */
      /* DataStoreWrite: '<S251>/Data Store Write2' incorporates:
       *  Constant: '<S251>/Constant1'
       */
      mcb_pmsm_foc_qep_f28379d_DW.IbOffset = 2286U;

      /* End of Outputs for SubSystem: '<S244>/If Action Subsystem3' */
    }

    /* End of If: '<S244>/If1' */
    /* End of Outputs for SubSystem: '<S243>/Calculate ADC Offset ' */

    /* Logic: '<S243>/NOT' incorporates:
     *  Constant: '<S243>/ADC Calib Enable'
     */
    mcb_pmsm_foc_qep_f28379d_B.NOT = false;

    /* Outputs for Enabled SubSystem: '<S243>/Default ADC Offset' incorporates:
     *  EnablePort: '<S246>/Enable'
     */
    if (mcb_pmsm_foc_qep_f28379d_B.NOT) {
      /* DataStoreWrite: '<S246>/Data Store Write1' incorporates:
       *  Constant: '<S246>/Constant'
       */
      mcb_pmsm_foc_qep_f28379d_DW.IaOffset = 2295U;

      /* DataStoreWrite: '<S246>/Data Store Write2' incorporates:
       *  Constant: '<S246>/Constant1'
       */
      mcb_pmsm_foc_qep_f28379d_DW.IbOffset = 2286U;
    }

    /* End of Outputs for SubSystem: '<S243>/Default ADC Offset' */
    /* End of Outputs for SubSystem: '<Root>/Hardware Init' */
  }
}

/* Model terminate function */
void mcb_pmsm_foc_qep_f28379d_terminate(void)
{
  /* Terminate for Atomic SubSystem: '<Root>/Hardware Init' */
  /* Terminate for Enabled SubSystem: '<S245>/ADC Gain setting' */
  mcb__SPIMasterTransfer_Term(&mcb_pmsm_foc_qep_f28379d_DW.SPIMasterTransfer);
  mcb__SPIMasterTransfer_Term(&mcb_pmsm_foc_qep_f28379d_DW.SPIMasterTransfer1);

  /* End of Terminate for SubSystem: '<S245>/ADC Gain setting' */
  /* End of Terminate for SubSystem: '<Root>/Hardware Init' */
}

void mcb_pmsm_foc_qep_f28379d_configure_interrupts(void)
{
  /* Register interrupt service routine */
  HWI_TIC28x_ConfigureIRQ(33,&ADCB1_INT,0);
  HWI_TIC28x_EnableIRQ(33);

  /* Register interrupt service routine */
  HWI_TIC28x_ConfigureIRQ(96,&SCIA_RX_INT,2);
  HWI_TIC28x_EnableIRQ(96);
}

/* Hardware Interrupt Block: '<S239>/Hardware Interrupt' */
interrupt void ADCB1_INT(void)
{
  volatile unsigned int PIEIER1_stack_save = PieCtrlRegs.PIEIER1.all;
  volatile unsigned int PIEIER9_stack_save = PieCtrlRegs.PIEIER9.all;
  PieCtrlRegs.PIEIER1.all &= ~66;
                              /*disable group1 lower/equal priority interrupts*/
  PieCtrlRegs.PIEIER9.all &= ~1;
                              /*disable group9 lower/equal priority interrupts*/
  asm(" RPT #5 || NOP");               /*wait 5 cycles        */
  IFR &= ~257;    /*eventually disable lower/equal priority pending interrupts*/
  PieCtrlRegs.PIEACK.all = 257;
                   /*ACK to allow other interrupts from the same group to fire*/
  IER |= 1;
  EINT;

  /* Event: Default Event */
  if (1 == runModel) {
    {
      int16_T tmp;

      /* RateTransition: '<Root>/RT2' */
      tmp = mcb_pmsm_foc_qep_f28379d_DW.RT2_ActiveBufIdx << 1U;
      mcb_pmsm_foc_qep_f28379d_B.RT2[0] =
        mcb_pmsm_foc_qep_f28379d_DW.RT2_Buffer[tmp];
      mcb_pmsm_foc_qep_f28379d_B.RT2[1] =
        mcb_pmsm_foc_qep_f28379d_DW.RT2_Buffer[tmp + 1];

      /* S-Function (HardwareInterrupt_sfun): '<S239>/Hardware Interrupt' */
      mcb_pmsm_foc_CurrentControl();

      /* End of Outputs for S-Function (HardwareInterrupt_sfun): '<S239>/Hardware Interrupt' */

      /* RateTransition: '<Root>/RT1' */
      mcb_pmsm_foc_qep_f28379d_DW.RT1_Buffer[mcb_pmsm_foc_qep_f28379d_DW.RT1_semaphoreTaken
        == 0] = mcb_pmsm_foc_qep_f28379d_B.Add1;
      mcb_pmsm_foc_qep_f28379d_DW.RT1_ActiveBufIdx =
        (mcb_pmsm_foc_qep_f28379d_DW.RT1_semaphoreTaken == 0);
    }
  }

  /* Clear occurred EOC event event */
  AdcbRegs.ADCINTFLGCLR.bit.ADCINT1= 1;

  /* Clear occurred Overflow event event */
  AdcbRegs.ADCINTOVFCLR.bit.ADCINT1= 1;
  DINT;
  /* disable global interrupts during context switch, CPU will enable global interrupts after exiting ISR */
  PieCtrlRegs.PIEIER1.all = PIEIER1_stack_save;
                                   /*restore PIEIER register that was modified*/
  PieCtrlRegs.PIEIER9.all = PIEIER9_stack_save;
                                   /*restore PIEIER register that was modified*/
  HWI_TIC28x_AcknowledgeIrq(33);
}

/* Hardware Interrupt Block: '<S241>/Hardware Interrupt' */
interrupt void SCIA_RX_INT(void)
{
  /* Event: Default Event */
  if (1 == runModel) {
    {
      /* S-Function (HardwareInterrupt_sfun): '<S241>/Hardware Interrupt' */

      /* Output and update for function-call system: '<Root>/Serial Receive' */

      /* S-Function (c28xsci_rx): '<S262>/SCI Receive' */
      {
        int16_T i;
        int16_T errFlg = NOERROR;
        uint16_T isHeadReceived = 1U;

        //get data as uint16 in recBuff
        uint16_T recbuff[4];
        for (i = 0; i < 4; i++) {
          recbuff[i] = 0U;
        }

        errFlg = NOERROR;

        /* Receiving data: For uint32 and uint16, rcvBuff will contain uint16 data */
        if (isHeadReceived) {
          errFlg = scia_rcv(recbuff, 8, 4);
          asm(" NOP");
          if ((errFlg == NOERROR) || (errFlg == PARTIALDATA)) {
            memcpy( &mcb_pmsm_foc_qep_f28379d_B.SCIReceive[0], recbuff,4);
          }
        }
      }

      /* DataTypeConversion: '<S260>/Data Type Conversion2' */
      mcb_pmsm_foc_qep_f28379d_B.DataTypeConversion2 = (uint16_T)
        mcb_pmsm_foc_qep_f28379d_B.SCIReceive[1];

      /* S-Function (sfix_bitop): '<S259>/Bitwise Operator' */
      mcb_pmsm_foc_qep_f28379d_B.BitwiseOperator =
        mcb_pmsm_foc_qep_f28379d_B.DataTypeConversion2 & 1U;

      /* DataTypeConversion: '<S259>/Data Type Conversion3' */
      mcb_pmsm_foc_qep_f28379d_B.DataTypeConversion3 =
        (mcb_pmsm_foc_qep_f28379d_B.BitwiseOperator != 0U);

      /* DataStoreWrite: '<S6>/Data Store Write' */
      mcb_pmsm_foc_qep_f28379d_DW.Enable =
        mcb_pmsm_foc_qep_f28379d_B.DataTypeConversion3;

      /* DataStoreWrite: '<S6>/Data Store Write1' */
      mcb_pmsm_foc_qep_f28379d_DW.SpeedRef =
        mcb_pmsm_foc_qep_f28379d_B.SCIReceive[0];

      /* S-Function (sfix_bitop): '<S259>/Bitwise Operator1' */
      mcb_pmsm_foc_qep_f28379d_B.BitwiseOperator1 =
        mcb_pmsm_foc_qep_f28379d_B.DataTypeConversion2 & 240U;

      /* ArithShift: '<S259>/Shift Arithmetic1' incorporates:
       *  S-Function (sfix_bitop): '<S259>/Bitwise Operator1'
       */
      mcb_pmsm_foc_qep_f28379d_B.ShiftArithmetic1 =
        mcb_pmsm_foc_qep_f28379d_B.BitwiseOperator1 >> 4U;

      /* DataStoreWrite: '<S6>/Data Store Write2' */
      mcb_pmsm_foc_qep_f28379d_DW.Debug_signals =
        mcb_pmsm_foc_qep_f28379d_B.ShiftArithmetic1;

      /* End of Outputs for S-Function (HardwareInterrupt_sfun): '<S241>/Hardware Interrupt' */

      /* RateTransition: '<Root>/RT3' */
      mcb_pmsm_foc_qep_f28379d_DW.RT3_Buffer[mcb_pmsm_foc_qep_f28379d_DW.RT3_ActiveBufIdx
        == 0] = mcb_pmsm_foc_qep_f28379d_B.SCIReceive[0];
      mcb_pmsm_foc_qep_f28379d_DW.RT3_ActiveBufIdx =
        (mcb_pmsm_foc_qep_f28379d_DW.RT3_ActiveBufIdx == 0);
    }
  }

  /* Clear occurred Rx FIFO complete event */
  EALLOW;
  SciaRegs.SCIFFRX.bit.RXFFINTCLR= 1;
  EDIS;

  /* Clear occurred Rx FIFO overflow event */
  EALLOW;
  SciaRegs.SCIFFRX.bit.RXFFOVRCLR= 1;
  EDIS;
  HWI_TIC28x_AcknowledgeIrq(96);
}

void mcb_pmsm_foc_qep_f28379d_unconfigure_interrupts (void)
{
  HWI_TIC28x_DisableIRQ(33);
  HWI_TIC28x_DisableIRQ(96);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
