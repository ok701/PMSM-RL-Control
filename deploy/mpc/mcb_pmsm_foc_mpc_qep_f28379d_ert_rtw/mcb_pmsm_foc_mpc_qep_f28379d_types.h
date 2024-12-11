/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: mcb_pmsm_foc_mpc_qep_f28379d_types.h
 *
 * Code generated for Simulink model 'mcb_pmsm_foc_mpc_qep_f28379d'.
 *
 * Model version                  : 9.0
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Tue Dec 10 12:39:38 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef mcb_pmsm_foc_mpc_qep_f28379d_types_h_
#define mcb_pmsm_foc_mpc_qep_f28379d_types_h_
#include "rtwtypes.h"
#include "MW_c2000SPI.h"

/* Custom Type definition for MATLABSystem: '<S147>/SPI Master Transfer' */
#include "MW_c2000SPI.h"
#ifndef struct_tag_X3nhL3sVVdEpin6phQ7ajF
#define struct_tag_X3nhL3sVVdEpin6phQ7ajF

struct tag_X3nhL3sVVdEpin6phQ7ajF
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  MW_Handle_Type MW_SPI_HANDLE;
};

#endif                                 /* struct_tag_X3nhL3sVVdEpin6phQ7ajF */

#ifndef typedef_codertarget_tic2000_blocks_SP_T
#define typedef_codertarget_tic2000_blocks_SP_T

typedef struct tag_X3nhL3sVVdEpin6phQ7ajF codertarget_tic2000_blocks_SP_T;

#endif                             /* typedef_codertarget_tic2000_blocks_SP_T */

/* Forward declaration for rtModel */
typedef struct tag_RTM_mcb_pmsm_foc_mpc_qep__T RT_MODEL_mcb_pmsm_foc_mpc_qep_T;

#endif                               /* mcb_pmsm_foc_mpc_qep_f28379d_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
