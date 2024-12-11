/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: mcb_pmsm_qep_offset_f28379d.h
 *
 * Code generated for Simulink model 'mcb_pmsm_qep_offset_f28379d'.
 *
 * Model version                  : 9.3
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Tue Dec 10 11:18:23 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef mcb_pmsm_qep_offset_f28379d_h_
#define mcb_pmsm_qep_offset_f28379d_h_
#ifndef mcb_pmsm_qep_offset_f28379d_COMMON_INCLUDES_
#define mcb_pmsm_qep_offset_f28379d_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "c2000BoardSupport.h"
#include "MW_f2837xD_includes.h"
#include "string.h"
#include "DSP28xx_SciUtil.h"
#include "IQmathLib.h"
#endif                        /* mcb_pmsm_qep_offset_f28379d_COMMON_INCLUDES_ */

#include "MW_c2000ISR.h"
#include "mcb_pmsm_qep_offset_f28379d_types.h"
#include <stddef.h>
#include <string.h>
#include "rt_nonfinite.h"
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

extern void init_SCI(void);
extern void init_SCI_GPIO(void);
extern void config_ePWMSyncSource(void);
extern void config_ePWM_GPIO (void);
extern void config_ePWM_TBSync (void);
extern void config_ePWM_XBAR(void);

/* Block signals (default storage) */
typedef struct {
  uint32_T BytePack[2];                /* '<S52>/Byte Pack' */
  uint32_T SCI_Tx_Data[3];             /* '<S50>/Merge' */
  uint32_T SCI_Tx_Iteration;           /* '<S50>/Merge1' */
  uint32_T Sum[4];                     /* '<S34>/Sum' */
  uint32_T IndexVector;                /* '<S51>/Index Vector' */
  uint32_T Add;                        /* '<S51>/Add' */
  uint32_T Data[2];                    /* '<S54>/Data' */
  uint32_T Data_f[2];                  /* '<S55>/Data' */
  uint32_T Data_fw[2];                 /* '<S56>/Data' */
  uint32_T Delay;                      /* '<S26>/Delay' */
  uint32_T Add1;                       /* '<S26>/Add1' */
  real32_T SCIReceive;                 /* '<S80>/SCI Receive' */
  real32_T DTC;                        /* '<S74>/DTC' */
  real32_T Product;                    /* '<S61>/Product' */
  real32_T Switch;                     /* '<S63>/Switch' */
  real32_T Merge;                      /* '<S64>/Merge' */
  real32_T Numberofpolepairs;          /* '<S69>/Number of pole pairs' */
  real32_T Floor;                      /* '<S65>/Floor' */
  real32_T Add_c;                      /* '<S65>/Add' */
  real32_T Switch_k;                   /* '<S3>/Switch' */
  real32_T TmpSignalConversionAtBytePackIn[2];
  real32_T Merge_f;                    /* '<S36>/Merge' */
  real32_T indexing;                   /* '<S34>/indexing' */
  real32_T Lookup[4];                  /* '<S34>/Lookup' */
  real32_T Sum3;                       /* '<S35>/Sum3' */
  real32_T DataTypeConversion1;        /* '<S34>/Data Type Conversion1' */
  real32_T Sum2;                       /* '<S34>/Sum2' */
  real32_T Product_j;                  /* '<S35>/Product' */
  real32_T Sum4;                       /* '<S35>/Sum4' */
  real32_T Sum5;                       /* '<S35>/Sum5' */
  real32_T Product1;                   /* '<S35>/Product1' */
  real32_T Sum6;                       /* '<S35>/Sum6' */
  real32_T Switch4[3];                 /* '<S14>/Switch4' */
  real32_T sqrt3_by_two;               /* '<S48>/sqrt3_by_two' */
  real32_T one_by_two;                 /* '<S48>/one_by_two' */
  real32_T add_c;                      /* '<S48>/add_c' */
  real32_T add_b;                      /* '<S48>/add_b' */
  real32_T Min;                        /* '<S45>/Min' */
  real32_T Max;                        /* '<S45>/Max' */
  real32_T Add_i;                      /* '<S45>/Add' */
  real32_T one_by_two_b;               /* '<S45>/one_by_two' */
  real32_T Add2;                       /* '<S44>/Add2' */
  real32_T Add1_m;                     /* '<S44>/Add1' */
  real32_T Add3;                       /* '<S44>/Add3' */
  real32_T Gain[3];                    /* '<S44>/Gain' */
  real32_T Sum_d[3];                   /* '<S14>/Sum' */
  real32_T Gain_h[3];                  /* '<S14>/Gain' */
  real32_T Convert_back;               /* '<S40>/Convert_back' */
  real32_T Convert_back_g;             /* '<S39>/Convert_back' */
  real32_T Merge_g;                    /* '<S25>/Merge' */
  real32_T UnitDelay;                  /* '<S30>/Unit Delay' */
  real32_T Switch_b;                   /* '<S25>/Switch' */
  real32_T Multiply;                   /* '<S31>/Multiply' */
  real32_T Add_d;                      /* '<S32>/Add' */
  real32_T DataTypeConversion1_c;      /* '<S32>/Data Type Conversion1' */
  real32_T Add1_j;                     /* '<S32>/Add1' */
  real32_T Input;                      /* '<S33>/Input' */
  real32_T Delay_f;                    /* '<S29>/Delay' */
  real32_T Add1_a;                     /* '<S29>/Add1' */
  real32_T SaturatetomotorcalibSpeedRPM;
                                /* '<S29>/Saturate to 'motor.calibSpeed' RPM' */
  real32_T qcos;                       /* '<S21>/qcos' */
  real32_T dsin;                       /* '<S21>/dsin' */
  real32_T sum_beta;                   /* '<S21>/sum_beta' */
  real32_T dcos;                       /* '<S21>/dcos' */
  real32_T qsin;                       /* '<S21>/qsin' */
  real32_T sum_alpha;                  /* '<S21>/sum_alpha' */
  real32_T Switch_k5[2];               /* '<S22>/Switch' */
  real32_T algDD_o1;
  real32_T algDD_o2;
  uint16_T Output;                     /* '<S53>/Output' */
  uint16_T eQEP_o1;                    /* '<S3>/eQEP' */
  uint16_T eQEP_o2;                    /* '<S3>/eQEP' */
  uint16_T Merge_j;                    /* '<S61>/Merge' */
  uint16_T FixPtSum1;                  /* '<S57>/FixPt Sum1' */
  uint16_T FixPtSwitch;                /* '<S58>/FixPt Switch' */
  uint16_T DataTypeConversion;         /* '<S36>/Data Type Conversion' */
  uint16_T Get_Integer;                /* '<S34>/Get_Integer' */
  uint16_T ADC_B_IN2;                  /* '<S3>/ADC_B_IN2' */
  uint16_T ADC_C_IN2;                  /* '<S3>/ADC_C_IN2' */
  uint16_T Scale_to_PWM_Counter_PRD[3];/* '<S14>/Scale_to_PWM_Counter_PRD' */
  uint16_T Sum3_n;                     /* '<S71>/Sum3' */
  uint16_T Sum7;                       /* '<S71>/Sum7' */
  int16_T WhileIterator;               /* '<S51>/While Iterator' */
  int16_T Convert_uint16;              /* '<S40>/Convert_uint16' */
  int16_T Convert_uint16_c;            /* '<S39>/Convert_uint16' */
  int16_T DataTypeConversion_i;        /* '<S32>/Data Type Conversion' */
  boolean_T DataTypeConversion_o;      /* '<S4>/Data Type Conversion' */
  boolean_T DataStoreRead;             /* '<S11>/Data Store Read' */
  boolean_T Compare;                   /* '<S38>/Compare' */
  boolean_T Switch_j;                  /* '<S15>/Switch' */
  boolean_T NOT;                       /* '<S15>/NOT' */
  boolean_T Compare_b;                 /* '<S23>/Compare' */
  boolean_T NOT_p;                     /* '<S18>/NOT' */
  boolean_T Compare_p;                 /* '<S27>/Compare' */
  boolean_T NOT_j;                     /* '<S30>/NOT' */
  boolean_T Delay_i;                   /* '<S32>/Delay' */
} BlockIO_mcb_pmsm_qep_offset_f28;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  uint64_T Add1_DWORK1;                /* '<S26>/Add1' */
  real32_T UnitDelay_DSTATE;           /* '<S30>/Unit Delay' */
  real32_T Delay_DSTATE;               /* '<S29>/Delay' */
  uint32_T Delay_DSTATE_n;             /* '<S26>/Delay' */
  int32_T DigitalOutput2_FRAC_LEN;     /* '<S2>/Digital Output2' */
  int32_T DRV830xEnable_FRAC_LEN;      /* '<S15>/DRV830x Enable' */
  uint32_T Sum_DWORK1[4];              /* '<S34>/Sum' */
  uint32_T Add_DWORK1;                 /* '<S51>/Add' */
  uint16_T Output_DSTATE;              /* '<S53>/Output' */
  boolean_T Delay_DSTATE_o;            /* '<S32>/Delay' */
  boolean_T Enable;                    /* '<Root>/Data Store Memory29' */
  boolean_T PosGen_MODE;               /* '<S11>/PosGen' */
  boolean_T UpCounter_MODE;            /* '<S18>/Up Counter' */
  boolean_T Subsystem_MODE;            /* '<S25>/Subsystem' */
} D_Work_mcb_pmsm_qep_offset_f283;

/* Invariant block signals (default storage) */
typedef struct {
  const uint32_T Width;                /* '<S50>/Width' */
} ConstBlockIO_mcb_pmsm_qep_offse;

/* Constant parameters (default storage) */
typedef struct {
  /* Computed Parameter: sine_table_values_Value
   * Referenced by: '<S34>/sine_table_values'
   */
  real32_T sine_table_values_Value[1002];
} ConstParam_mcb_pmsm_qep_offset_;

/* Real-time Model Data Structure */
struct tag_RTM_mcb_pmsm_qep_offset_f28 {
  const char_T * volatile errorStatus;
};

/* Block signals (default storage) */
extern BlockIO_mcb_pmsm_qep_offset_f28 mcb_pmsm_qep_offset_f28379d_B;

/* Block states (default storage) */
extern D_Work_mcb_pmsm_qep_offset_f283 mcb_pmsm_qep_offset_f2837_DWork;
extern const ConstBlockIO_mcb_pmsm_qep_offse mcb_pmsm_qep_offset_f283_ConstB;/* constant block i/o */

/* Constant parameters (default storage) */
extern const ConstParam_mcb_pmsm_qep_offset_ mcb_pmsm_qep_offset_f283_ConstP;

/* Model entry point functions */
extern void mcb_pmsm_qep_offset_f28379d_initialize(void);
extern void mcb_pmsm_qep_offset_f28379d_step(void);
extern void mcb_pmsm_qep_offset_f28379d_terminate(void);

/* Real-time Model object */
extern RT_MODEL_mcb_pmsm_qep_offset_f2 *const mcb_pmsm_qep_offset_f28379d_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

#ifdef __cpluscplus

extern "C"
{

#endif

  interrupt void ADCB1_INT(void);
  interrupt void SCIA_RX_INT(void);
  void mcb_pmsm_qep_offset_f28379d_configure_interrupts (void);
  void mcb_pmsm_qep_offset_f28379d_unconfigure_interrupts (void);

#ifdef __cpluscplus

}

#endif

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'mcb_pmsm_qep_offset_f28379d'
 * '<S1>'   : 'mcb_pmsm_qep_offset_f28379d/HW Interrupt'
 * '<S2>'   : 'mcb_pmsm_qep_offset_f28379d/Heartbeat LED'
 * '<S3>'   : 'mcb_pmsm_qep_offset_f28379d/Offset Calculation'
 * '<S4>'   : 'mcb_pmsm_qep_offset_f28379d/Serial Receive'
 * '<S5>'   : 'mcb_pmsm_qep_offset_f28379d/HW Interrupt/HWI_ADCB1_INT'
 * '<S6>'   : 'mcb_pmsm_qep_offset_f28379d/HW Interrupt/HWI_SCIA_RX_INT'
 * '<S7>'   : 'mcb_pmsm_qep_offset_f28379d/HW Interrupt/HWI_ADCB1_INT/ECSoC'
 * '<S8>'   : 'mcb_pmsm_qep_offset_f28379d/HW Interrupt/HWI_ADCB1_INT/ECSoC/ECSimCodegen'
 * '<S9>'   : 'mcb_pmsm_qep_offset_f28379d/HW Interrupt/HWI_SCIA_RX_INT/ECSoC'
 * '<S10>'  : 'mcb_pmsm_qep_offset_f28379d/HW Interrupt/HWI_SCIA_RX_INT/ECSoC/ECSimCodegen'
 * '<S11>'  : 'mcb_pmsm_qep_offset_f28379d/Offset Calculation/Control_System'
 * '<S12>'  : 'mcb_pmsm_qep_offset_f28379d/Offset Calculation/Data Serial Output'
 * '<S13>'  : 'mcb_pmsm_qep_offset_f28379d/Offset Calculation/Input Scaling'
 * '<S14>'  : 'mcb_pmsm_qep_offset_f28379d/Offset Calculation/Output Scaling'
 * '<S15>'  : 'mcb_pmsm_qep_offset_f28379d/Offset Calculation/PWM Output'
 * '<S16>'  : 'mcb_pmsm_qep_offset_f28379d/Offset Calculation/Parameters'
 * '<S17>'  : 'mcb_pmsm_qep_offset_f28379d/Offset Calculation/Control_System/Inverse Park Transform'
 * '<S18>'  : 'mcb_pmsm_qep_offset_f28379d/Offset Calculation/Control_System/PosGen'
 * '<S19>'  : 'mcb_pmsm_qep_offset_f28379d/Offset Calculation/Control_System/Sine-Cosine Lookup'
 * '<S20>'  : 'mcb_pmsm_qep_offset_f28379d/Offset Calculation/Control_System/Space Vector Generator'
 * '<S21>'  : 'mcb_pmsm_qep_offset_f28379d/Offset Calculation/Control_System/Inverse Park Transform/Two inputs CRL'
 * '<S22>'  : 'mcb_pmsm_qep_offset_f28379d/Offset Calculation/Control_System/Inverse Park Transform/Two inputs CRL/Switch_Axis'
 * '<S23>'  : 'mcb_pmsm_qep_offset_f28379d/Offset Calculation/Control_System/PosGen/Enable PWM for 15 seconds'
 * '<S24>'  : 'mcb_pmsm_qep_offset_f28379d/Offset Calculation/Control_System/PosGen/Subsystem'
 * '<S25>'  : 'mcb_pmsm_qep_offset_f28379d/Offset Calculation/Control_System/PosGen/Subsystem1'
 * '<S26>'  : 'mcb_pmsm_qep_offset_f28379d/Offset Calculation/Control_System/PosGen/Up Counter'
 * '<S27>'  : 'mcb_pmsm_qep_offset_f28379d/Offset Calculation/Control_System/PosGen/Subsystem1/Compare To Constant'
 * '<S28>'  : 'mcb_pmsm_qep_offset_f28379d/Offset Calculation/Control_System/PosGen/Subsystem1/If Action Subsystem'
 * '<S29>'  : 'mcb_pmsm_qep_offset_f28379d/Offset Calculation/Control_System/PosGen/Subsystem1/If Action Subsystem2'
 * '<S30>'  : 'mcb_pmsm_qep_offset_f28379d/Offset Calculation/Control_System/PosGen/Subsystem1/Position Generator'
 * '<S31>'  : 'mcb_pmsm_qep_offset_f28379d/Offset Calculation/Control_System/PosGen/Subsystem1/Subsystem'
 * '<S32>'  : 'mcb_pmsm_qep_offset_f28379d/Offset Calculation/Control_System/PosGen/Subsystem1/Position Generator/Accumulate'
 * '<S33>'  : 'mcb_pmsm_qep_offset_f28379d/Offset Calculation/Control_System/PosGen/Subsystem1/Position Generator/Accumulate/Subsystem'
 * '<S34>'  : 'mcb_pmsm_qep_offset_f28379d/Offset Calculation/Control_System/Sine-Cosine Lookup/Sine-Cosine Lookup'
 * '<S35>'  : 'mcb_pmsm_qep_offset_f28379d/Offset Calculation/Control_System/Sine-Cosine Lookup/Sine-Cosine Lookup/Interpolation'
 * '<S36>'  : 'mcb_pmsm_qep_offset_f28379d/Offset Calculation/Control_System/Sine-Cosine Lookup/Sine-Cosine Lookup/WrapUp'
 * '<S37>'  : 'mcb_pmsm_qep_offset_f28379d/Offset Calculation/Control_System/Sine-Cosine Lookup/Sine-Cosine Lookup/datatype'
 * '<S38>'  : 'mcb_pmsm_qep_offset_f28379d/Offset Calculation/Control_System/Sine-Cosine Lookup/Sine-Cosine Lookup/WrapUp/Compare To Zero'
 * '<S39>'  : 'mcb_pmsm_qep_offset_f28379d/Offset Calculation/Control_System/Sine-Cosine Lookup/Sine-Cosine Lookup/WrapUp/If Action Subsystem'
 * '<S40>'  : 'mcb_pmsm_qep_offset_f28379d/Offset Calculation/Control_System/Sine-Cosine Lookup/Sine-Cosine Lookup/WrapUp/If Action Subsystem1'
 * '<S41>'  : 'mcb_pmsm_qep_offset_f28379d/Offset Calculation/Control_System/Sine-Cosine Lookup/Sine-Cosine Lookup/datatype/datatype no change'
 * '<S42>'  : 'mcb_pmsm_qep_offset_f28379d/Offset Calculation/Control_System/Space Vector Generator/Modulation method'
 * '<S43>'  : 'mcb_pmsm_qep_offset_f28379d/Offset Calculation/Control_System/Space Vector Generator/Voltage Input'
 * '<S44>'  : 'mcb_pmsm_qep_offset_f28379d/Offset Calculation/Control_System/Space Vector Generator/Modulation method/SVPWM'
 * '<S45>'  : 'mcb_pmsm_qep_offset_f28379d/Offset Calculation/Control_System/Space Vector Generator/Modulation method/SVPWM/Half(Vmin+Vmax)'
 * '<S46>'  : 'mcb_pmsm_qep_offset_f28379d/Offset Calculation/Control_System/Space Vector Generator/Voltage Input/Valphabeta'
 * '<S47>'  : 'mcb_pmsm_qep_offset_f28379d/Offset Calculation/Control_System/Space Vector Generator/Voltage Input/Valphabeta/Inverse Clarke Transform'
 * '<S48>'  : 'mcb_pmsm_qep_offset_f28379d/Offset Calculation/Control_System/Space Vector Generator/Voltage Input/Valphabeta/Inverse Clarke Transform/Two phase input'
 * '<S49>'  : 'mcb_pmsm_qep_offset_f28379d/Offset Calculation/Data Serial Output/Data_Conditioning_Tx'
 * '<S50>'  : 'mcb_pmsm_qep_offset_f28379d/Offset Calculation/Data Serial Output/Data_Logging'
 * '<S51>'  : 'mcb_pmsm_qep_offset_f28379d/Offset Calculation/Data Serial Output/While Iterator Subsystem'
 * '<S52>'  : 'mcb_pmsm_qep_offset_f28379d/Offset Calculation/Data Serial Output/Data_Conditioning_Tx/Data_Type_Float'
 * '<S53>'  : 'mcb_pmsm_qep_offset_f28379d/Offset Calculation/Data Serial Output/Data_Logging/Counter Limited'
 * '<S54>'  : 'mcb_pmsm_qep_offset_f28379d/Offset Calculation/Data Serial Output/Data_Logging/Data'
 * '<S55>'  : 'mcb_pmsm_qep_offset_f28379d/Offset Calculation/Data Serial Output/Data_Logging/End'
 * '<S56>'  : 'mcb_pmsm_qep_offset_f28379d/Offset Calculation/Data Serial Output/Data_Logging/Start'
 * '<S57>'  : 'mcb_pmsm_qep_offset_f28379d/Offset Calculation/Data Serial Output/Data_Logging/Counter Limited/Increment Real World'
 * '<S58>'  : 'mcb_pmsm_qep_offset_f28379d/Offset Calculation/Data Serial Output/Data_Logging/Counter Limited/Wrap To Zero'
 * '<S59>'  : 'mcb_pmsm_qep_offset_f28379d/Offset Calculation/Input Scaling/eQEP_Decoder'
 * '<S60>'  : 'mcb_pmsm_qep_offset_f28379d/Offset Calculation/Input Scaling/eQEP_Decoder/Mechanical to Electrical Position'
 * '<S61>'  : 'mcb_pmsm_qep_offset_f28379d/Offset Calculation/Input Scaling/eQEP_Decoder/Quadrature Decoder'
 * '<S62>'  : 'mcb_pmsm_qep_offset_f28379d/Offset Calculation/Input Scaling/eQEP_Decoder/Mechanical to Electrical Position/MechToElec'
 * '<S63>'  : 'mcb_pmsm_qep_offset_f28379d/Offset Calculation/Input Scaling/eQEP_Decoder/Mechanical to Electrical Position/MechToElec/floating-point'
 * '<S64>'  : 'mcb_pmsm_qep_offset_f28379d/Offset Calculation/Input Scaling/eQEP_Decoder/Mechanical to Electrical Position/MechToElec/floating-point/Compensate Offset'
 * '<S65>'  : 'mcb_pmsm_qep_offset_f28379d/Offset Calculation/Input Scaling/eQEP_Decoder/Mechanical to Electrical Position/MechToElec/floating-point/Mech To Elec'
 * '<S66>'  : 'mcb_pmsm_qep_offset_f28379d/Offset Calculation/Input Scaling/eQEP_Decoder/Mechanical to Electrical Position/MechToElec/floating-point/Compensate Offset/If Action Subsystem'
 * '<S67>'  : 'mcb_pmsm_qep_offset_f28379d/Offset Calculation/Input Scaling/eQEP_Decoder/Mechanical to Electrical Position/MechToElec/floating-point/Compensate Offset/If Action Subsystem1'
 * '<S68>'  : 'mcb_pmsm_qep_offset_f28379d/Offset Calculation/Input Scaling/eQEP_Decoder/Mechanical to Electrical Position/MechToElec/floating-point/Mech To Elec/Variant Subsystem'
 * '<S69>'  : 'mcb_pmsm_qep_offset_f28379d/Offset Calculation/Input Scaling/eQEP_Decoder/Mechanical to Electrical Position/MechToElec/floating-point/Mech To Elec/Variant Subsystem/Dialog'
 * '<S70>'  : 'mcb_pmsm_qep_offset_f28379d/Offset Calculation/Input Scaling/eQEP_Decoder/Quadrature Decoder/DT_Handle'
 * '<S71>'  : 'mcb_pmsm_qep_offset_f28379d/Offset Calculation/Input Scaling/eQEP_Decoder/Quadrature Decoder/PositionNoReset'
 * '<S72>'  : 'mcb_pmsm_qep_offset_f28379d/Offset Calculation/Input Scaling/eQEP_Decoder/Quadrature Decoder/PositionResetAtIndex'
 * '<S73>'  : 'mcb_pmsm_qep_offset_f28379d/Offset Calculation/Input Scaling/eQEP_Decoder/Quadrature Decoder/Variant Subsystem'
 * '<S74>'  : 'mcb_pmsm_qep_offset_f28379d/Offset Calculation/Input Scaling/eQEP_Decoder/Quadrature Decoder/DT_Handle/floating-point'
 * '<S75>'  : 'mcb_pmsm_qep_offset_f28379d/Offset Calculation/Input Scaling/eQEP_Decoder/Quadrature Decoder/PositionNoReset/Variant Subsystem'
 * '<S76>'  : 'mcb_pmsm_qep_offset_f28379d/Offset Calculation/Input Scaling/eQEP_Decoder/Quadrature Decoder/PositionNoReset/Variant Subsystem/Dialog'
 * '<S77>'  : 'mcb_pmsm_qep_offset_f28379d/Offset Calculation/Input Scaling/eQEP_Decoder/Quadrature Decoder/Variant Subsystem/Dialog'
 * '<S78>'  : 'mcb_pmsm_qep_offset_f28379d/Serial Receive/Code Generation'
 * '<S79>'  : 'mcb_pmsm_qep_offset_f28379d/Serial Receive/Data_Conditioning_Rx'
 * '<S80>'  : 'mcb_pmsm_qep_offset_f28379d/Serial Receive/Code Generation/Data_Type_Float'
 * '<S81>'  : 'mcb_pmsm_qep_offset_f28379d/Serial Receive/Data_Conditioning_Rx/Data_Type_Float'
 */
#endif                                 /* mcb_pmsm_qep_offset_f28379d_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
