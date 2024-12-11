/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: mcb_pmsm_qep_offset_f28379d_private.h
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

#ifndef mcb_pmsm_qep_offset_f28379d_private_h_
#define mcb_pmsm_qep_offset_f28379d_private_h_
#include "rtwtypes.h"
#include "mcb_pmsm_qep_offset_f28379d_types.h"

void config_QEP_eQEP1(uint32_T pcmaximumvalue, uint32_T pcInitialvalue, uint32_T
                      unittimerperiod, uint32_T comparevalue, uint16_T
                      watchdogtimer, uint16_T qdecctl, uint16_T qepctl, uint16_T
                      qposctl, uint16_T qcapctl, uint16_T qeint);
void InitAdcB (void);
void config_ADCB_SOC0 (void);
void InitAdcC (void);
void config_ADCC_SOC0 (void);
extern uint16_T MW_adcBInitFlag;
extern uint16_T MW_adcCInitFlag;

#endif                              /* mcb_pmsm_qep_offset_f28379d_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
