/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Read_Encoder_private.h
 *
 * Code generated for Simulink model 'Read_Encoder'.
 *
 * Model version                  : 1.52
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Thu Oct 17 01:07:38 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef Read_Encoder_private_h_
#define Read_Encoder_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "Read_Encoder.h"
#include "Read_Encoder_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmSetTFinal
#define rtmSetTFinal(rtm, val)         ((rtm)->Timing.tFinal = (val))
#endif

extern void Read_Encoder_ChangeUnit_Init(DW_ChangeUnit_Read_Encoder_T *localDW);
extern void Read_Encoder_ChangeUnit(real_T rtu_vel, real_T rtu_pos, real_T
  rtu_ppr, real_T *rty_radps, real_T *rty_rad, DW_ChangeUnit_Read_Encoder_T
  *localDW);

#endif                                 /* Read_Encoder_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
