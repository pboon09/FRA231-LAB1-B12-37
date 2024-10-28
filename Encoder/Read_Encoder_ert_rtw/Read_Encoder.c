/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Read_Encoder.c
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

#include "Read_Encoder.h"
#include "rtwtypes.h"
#include "Read_Encoder_types.h"
#include "Read_Encoder_private.h"
#include "stm_timer_ll.h"

/* Named constants for MATLAB Function: '<Root>/Change Unit' */
#define Read_Encoder_CALL_EVENT        (-1)

/* Block signals (default storage) */
B_Read_Encoder_T Read_Encoder_B;

/* Block states (default storage) */
DW_Read_Encoder_T Read_Encoder_DW;

/* Real-time model */
static RT_MODEL_Read_Encoder_T Read_Encoder_M_;
RT_MODEL_Read_Encoder_T *const Read_Encoder_M = &Read_Encoder_M_;

/* Forward declaration for local functions */
static void Read_Encoder_SystemCore_setup(stm32cube_blocks_EncoderBlock_T *obj);
static void Read_Encoder_SystemCore_setup_l(stm32cube_blocks_EncoderBlock_T *obj);
static void Read_Encode_SystemCore_setup_l2(stm32cube_blocks_EncoderBlock_T *obj);

/*
 * System initialize for atomic system:
 *    '<Root>/Change Unit'
 *    '<Root>/Change Unit1'
 *    '<Root>/Change Unit2'
 *    '<Root>/Change Unit3'
 *    '<Root>/Change Unit4'
 *    '<Root>/Change Unit5'
 */
void Read_Encoder_ChangeUnit_Init(DW_ChangeUnit_Read_Encoder_T *localDW)
{
  localDW->sfEvent = Read_Encoder_CALL_EVENT;
}

/*
 * Output and update for atomic system:
 *    '<Root>/Change Unit'
 *    '<Root>/Change Unit1'
 *    '<Root>/Change Unit2'
 *    '<Root>/Change Unit3'
 *    '<Root>/Change Unit4'
 *    '<Root>/Change Unit5'
 */
void Read_Encoder_ChangeUnit(real_T rtu_vel, real_T rtu_pos, real_T rtu_ppr,
  real_T *rty_radps, real_T *rty_rad, DW_ChangeUnit_Read_Encoder_T *localDW)
{
  localDW->sfEvent = Read_Encoder_CALL_EVENT;
  *rty_radps = rtu_vel * 2.0 * 3.1415926535897931 / rtu_ppr;
  *rty_rad = rtu_pos * 2.0 * 3.1415926535897931 / rtu_ppr;
}

static void Read_Encoder_SystemCore_setup(stm32cube_blocks_EncoderBlock_T *obj)
{
  uint8_T ChannelInfo;
  TIM_Type_T b;
  boolean_T isSlaveModeTriggerEnabled;

  /* Start for MATLABSystem: '<Root>/Encoder 1' */
  obj->isInitialized = 1;
  b.PeripheralPtr = TIM8;
  b.isCenterAlignedMode = false;

  /* Start for MATLABSystem: '<Root>/Encoder 1' */
  b.repetitionCounter = 0U;
  obj->TimerHandle = Timer_Handle_Init(&b);
  enableTimerInterrupts(obj->TimerHandle, 0);
  ChannelInfo = ENABLE_CH;

  /* Start for MATLABSystem: '<Root>/Encoder 1' */
  enableTimerChannel1(obj->TimerHandle, ChannelInfo);
  enableTimerChannel2(obj->TimerHandle, ChannelInfo);
  isSlaveModeTriggerEnabled = isSlaveTriggerModeEnabled(obj->TimerHandle);
  if (!isSlaveModeTriggerEnabled) {
    /* Start for MATLABSystem: '<Root>/Encoder 1' */
    enableCounter(obj->TimerHandle, false);
  }

  obj->isSetupComplete = true;
}

static void Read_Encoder_SystemCore_setup_l(stm32cube_blocks_EncoderBlock_T *obj)
{
  uint8_T ChannelInfo;
  TIM_Type_T b;
  boolean_T isSlaveModeTriggerEnabled;

  /* Start for MATLABSystem: '<Root>/Encoder 2' */
  obj->isInitialized = 1;
  b.PeripheralPtr = TIM4;
  b.isCenterAlignedMode = false;

  /* Start for MATLABSystem: '<Root>/Encoder 2' */
  b.repetitionCounter = 0U;
  obj->TimerHandle = Timer_Handle_Init(&b);
  enableTimerInterrupts(obj->TimerHandle, 0);
  ChannelInfo = ENABLE_CH;

  /* Start for MATLABSystem: '<Root>/Encoder 2' */
  enableTimerChannel1(obj->TimerHandle, ChannelInfo);
  enableTimerChannel2(obj->TimerHandle, ChannelInfo);
  isSlaveModeTriggerEnabled = isSlaveTriggerModeEnabled(obj->TimerHandle);
  if (!isSlaveModeTriggerEnabled) {
    /* Start for MATLABSystem: '<Root>/Encoder 2' */
    enableCounter(obj->TimerHandle, false);
  }

  obj->isSetupComplete = true;
}

static void Read_Encode_SystemCore_setup_l2(stm32cube_blocks_EncoderBlock_T *obj)
{
  uint8_T ChannelInfo;
  TIM_Type_T b;
  boolean_T isSlaveModeTriggerEnabled;

  /* Start for MATLABSystem: '<Root>/Encoder 3' */
  obj->isInitialized = 1;
  b.PeripheralPtr = TIM3;
  b.isCenterAlignedMode = false;

  /* Start for MATLABSystem: '<Root>/Encoder 3' */
  b.repetitionCounter = 0U;
  obj->TimerHandle = Timer_Handle_Init(&b);
  enableTimerInterrupts(obj->TimerHandle, 0);
  ChannelInfo = ENABLE_CH;

  /* Start for MATLABSystem: '<Root>/Encoder 3' */
  enableTimerChannel1(obj->TimerHandle, ChannelInfo);
  enableTimerChannel2(obj->TimerHandle, ChannelInfo);
  isSlaveModeTriggerEnabled = isSlaveTriggerModeEnabled(obj->TimerHandle);
  if (!isSlaveModeTriggerEnabled) {
    /* Start for MATLABSystem: '<Root>/Encoder 3' */
    enableCounter(obj->TimerHandle, false);
  }

  obj->isSetupComplete = true;
}

/* Model step function */
void Read_Encoder_step(void)
{
  real_T diff_count_h;
  uint32_T timerCounts;
  boolean_T rtb_DigitalPortRead;
  boolean_T rtb_DigitalPortRead_a;

  /* MATLABSystem: '<Root>/Encoder 1' */
  timerCounts = getTimerCounterValueForG4(Read_Encoder_DW.obj_o.TimerHandle,
    false, NULL);

  /* MATLAB Function: '<Root>/qei_x1' incorporates:
   *  DataTypeConversion: '<Root>/Cast To Double 1'
   *  MATLABSystem: '<Root>/Encoder 1'
   */
  diff_count_h = (real_T)timerCounts - Read_Encoder_DW.prev_count_o;
  if (diff_count_h > 32768.0) {
    diff_count_h -= 65536.0;
  } else if (diff_count_h < -32768.0) {
    diff_count_h += 65536.0;
  }

  Read_Encoder_DW.pulses_accum_n += diff_count_h;
  Read_Encoder_DW.prev_count_o = timerCounts;

  /* MATLAB Function: '<Root>/Change Unit' incorporates:
   *  Constant: '<Root>/Constant'
   *  Constant: '<Root>/Constant1'
   *  MATLAB Function: '<Root>/qei_x1'
   */
  Read_Encoder_ChangeUnit(diff_count_h * 100.0, Read_Encoder_DW.pulses_accum_n,
    2048.0, &Read_Encoder_B.radps_p, &Read_Encoder_B.rad_f,
    &Read_Encoder_DW.sf_ChangeUnit);

  /* MATLABSystem: '<S16>/Digital Port Read' */
  timerCounts = LL_GPIO_ReadInputPort(GPIOC);
  rtb_DigitalPortRead_a = ((timerCounts & 128U) != 0U);

  /* MATLABSystem: '<S18>/Digital Port Read' */
  timerCounts = LL_GPIO_ReadInputPort(GPIOA);
  rtb_DigitalPortRead = ((timerCounts & 512U) != 0U);

  /* MATLAB Function: '<Root>/encoder_x4' incorporates:
   *  Constant: '<Root>/Constant1'
   *  DataTypeConversion: '<Root>/Cast To Double 6'
   *  DataTypeConversion: '<Root>/Cast To Double 7'
   */
  if (rtb_DigitalPortRead_a != Read_Encoder_DW.prev_A) {
    if (rtb_DigitalPortRead_a != rtb_DigitalPortRead) {
      Read_Encoder_DW.count++;
    } else {
      Read_Encoder_DW.count--;
    }
  }

  if (rtb_DigitalPortRead != Read_Encoder_DW.prev_B) {
    if (rtb_DigitalPortRead_a == rtb_DigitalPortRead) {
      Read_Encoder_DW.count++;
    } else {
      Read_Encoder_DW.count--;
    }
  }

  diff_count_h = (Read_Encoder_DW.count - Read_Encoder_DW.prev_count_k) * 100.0;
  Read_Encoder_DW.prev_A = rtb_DigitalPortRead_a;
  Read_Encoder_DW.prev_B = rtb_DigitalPortRead;
  Read_Encoder_DW.prev_count_k = Read_Encoder_DW.count;

  /* MATLAB Function: '<Root>/Change Unit5' incorporates:
   *  Constant: '<Root>/Constant'
   *  MATLAB Function: '<Root>/encoder_x4'
   */
  Read_Encoder_ChangeUnit(diff_count_h, Read_Encoder_DW.count, 2048.0,
    &Read_Encoder_B.radps, &Read_Encoder_B.rad, &Read_Encoder_DW.sf_ChangeUnit5);

  /* MATLAB Function: '<Root>/encoder_x1' incorporates:
   *  Constant: '<Root>/Constant1'
   *  DataTypeConversion: '<Root>/Cast To Double 6'
   *  DataTypeConversion: '<Root>/Cast To Double 7'
   */
  if ((Read_Encoder_DW.prev_A_d == 0.0) && rtb_DigitalPortRead_a) {
    if (!rtb_DigitalPortRead) {
      Read_Encoder_DW.count_lf++;
    } else {
      Read_Encoder_DW.count_lf--;
    }
  }

  diff_count_h = (Read_Encoder_DW.count_lf - Read_Encoder_DW.prev_count_mm) *
    100.0;
  Read_Encoder_DW.prev_A_d = rtb_DigitalPortRead_a;
  Read_Encoder_DW.prev_count_mm = Read_Encoder_DW.count_lf;

  /* MATLAB Function: '<Root>/Change Unit3' incorporates:
   *  Constant: '<Root>/Constant'
   *  MATLAB Function: '<Root>/encoder_x1'
   */
  Read_Encoder_ChangeUnit(diff_count_h, Read_Encoder_DW.count_lf, 2048.0,
    &Read_Encoder_B.radps_d, &Read_Encoder_B.rad_e,
    &Read_Encoder_DW.sf_ChangeUnit3);

  /* MATLAB Function: '<Root>/encoder_x2' incorporates:
   *  Constant: '<Root>/Constant1'
   *  DataTypeConversion: '<Root>/Cast To Double 6'
   *  DataTypeConversion: '<Root>/Cast To Double 7'
   */
  if (rtb_DigitalPortRead_a != Read_Encoder_DW.prev_A_m) {
    if (Read_Encoder_DW.prev_A_m == rtb_DigitalPortRead) {
      Read_Encoder_DW.count_l++;
    } else {
      Read_Encoder_DW.count_l--;
    }
  }

  diff_count_h = (Read_Encoder_DW.count_l - Read_Encoder_DW.prev_count_kd) *
    100.0;
  Read_Encoder_DW.prev_A_m = rtb_DigitalPortRead_a;
  Read_Encoder_DW.prev_count_kd = Read_Encoder_DW.count_l;

  /* MATLAB Function: '<Root>/Change Unit4' incorporates:
   *  Constant: '<Root>/Constant'
   *  MATLAB Function: '<Root>/encoder_x2'
   */
  Read_Encoder_ChangeUnit(diff_count_h, Read_Encoder_DW.count_l, 2048.0,
    &Read_Encoder_B.radps_c, &Read_Encoder_B.rad_g,
    &Read_Encoder_DW.sf_ChangeUnit4);

  /* MATLABSystem: '<Root>/Encoder 2' */
  timerCounts = getTimerCounterValueForG4(Read_Encoder_DW.obj_e.TimerHandle,
    false, NULL);

  /* MATLAB Function: '<Root>/qei_x2' incorporates:
   *  DataTypeConversion: '<Root>/Cast To Double 2'
   *  MATLABSystem: '<Root>/Encoder 2'
   */
  diff_count_h = (real_T)timerCounts - Read_Encoder_DW.prev_count_m;
  if (diff_count_h > 32768.0) {
    diff_count_h -= 65536.0;
  } else if (diff_count_h < -32768.0) {
    diff_count_h += 65536.0;
  }

  Read_Encoder_DW.pulses_accum_i += diff_count_h;
  Read_Encoder_DW.prev_count_m = timerCounts;

  /* MATLAB Function: '<Root>/Change Unit1' incorporates:
   *  Constant: '<Root>/Constant'
   *  Constant: '<Root>/Constant1'
   *  MATLAB Function: '<Root>/qei_x2'
   */
  Read_Encoder_ChangeUnit(diff_count_h * 100.0, Read_Encoder_DW.pulses_accum_i,
    2048.0, &Read_Encoder_B.radps_n, &Read_Encoder_B.rad_h,
    &Read_Encoder_DW.sf_ChangeUnit1);

  /* MATLABSystem: '<Root>/Encoder 3' */
  timerCounts = getTimerCounterValueForG4(Read_Encoder_DW.obj.TimerHandle, false,
    NULL);

  /* MATLAB Function: '<Root>/qei_x4' incorporates:
   *  DataTypeConversion: '<Root>/Cast To Double 3'
   *  MATLABSystem: '<Root>/Encoder 3'
   */
  diff_count_h = (real_T)timerCounts - Read_Encoder_DW.prev_count;
  if (diff_count_h > 32768.0) {
    diff_count_h -= 65536.0;
  } else if (diff_count_h < -32768.0) {
    diff_count_h += 65536.0;
  }

  Read_Encoder_DW.pulses_accum += diff_count_h;
  Read_Encoder_DW.prev_count = timerCounts;

  /* MATLAB Function: '<Root>/Change Unit2' incorporates:
   *  Constant: '<Root>/Constant'
   *  Constant: '<Root>/Constant1'
   *  MATLAB Function: '<Root>/qei_x4'
   */
  Read_Encoder_ChangeUnit(diff_count_h * 100.0, Read_Encoder_DW.pulses_accum,
    2048.0, &Read_Encoder_B.radps_k, &Read_Encoder_B.rad_m,
    &Read_Encoder_DW.sf_ChangeUnit2);

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  Read_Encoder_M->Timing.taskTime0 =
    ((time_T)(++Read_Encoder_M->Timing.clockTick0)) *
    Read_Encoder_M->Timing.stepSize0;
}

/* Model initialize function */
void Read_Encoder_initialize(void)
{
  /* Registration code */
  rtmSetTFinal(Read_Encoder_M, 20.0);
  Read_Encoder_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  Read_Encoder_M->Sizes.checksums[0] = (2465809863U);
  Read_Encoder_M->Sizes.checksums[1] = (2780580413U);
  Read_Encoder_M->Sizes.checksums[2] = (992172977U);
  Read_Encoder_M->Sizes.checksums[3] = (3332862988U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[18];
    Read_Encoder_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    systemRan[7] = &rtAlwaysEnabled;
    systemRan[8] = &rtAlwaysEnabled;
    systemRan[9] = &rtAlwaysEnabled;
    systemRan[10] = &rtAlwaysEnabled;
    systemRan[11] = &rtAlwaysEnabled;
    systemRan[12] = &rtAlwaysEnabled;
    systemRan[13] = &rtAlwaysEnabled;
    systemRan[14] = &rtAlwaysEnabled;
    systemRan[15] = &rtAlwaysEnabled;
    systemRan[16] = &rtAlwaysEnabled;
    systemRan[17] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Read_Encoder_M->extModeInfo,
      &Read_Encoder_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Read_Encoder_M->extModeInfo,
                        Read_Encoder_M->Sizes.checksums);
    rteiSetTPtr(Read_Encoder_M->extModeInfo, rtmGetTPtr(Read_Encoder_M));
  }

  /* SystemInitialize for MATLAB Function: '<Root>/Change Unit' */
  Read_Encoder_ChangeUnit_Init(&Read_Encoder_DW.sf_ChangeUnit);

  /* SystemInitialize for MATLAB Function: '<Root>/Change Unit5' */
  Read_Encoder_ChangeUnit_Init(&Read_Encoder_DW.sf_ChangeUnit5);

  /* SystemInitialize for MATLAB Function: '<Root>/Change Unit3' */
  Read_Encoder_ChangeUnit_Init(&Read_Encoder_DW.sf_ChangeUnit3);

  /* SystemInitialize for MATLAB Function: '<Root>/Change Unit4' */
  Read_Encoder_ChangeUnit_Init(&Read_Encoder_DW.sf_ChangeUnit4);

  /* SystemInitialize for MATLAB Function: '<Root>/Change Unit1' */
  Read_Encoder_ChangeUnit_Init(&Read_Encoder_DW.sf_ChangeUnit1);

  /* SystemInitialize for MATLAB Function: '<Root>/Change Unit2' */
  Read_Encoder_ChangeUnit_Init(&Read_Encoder_DW.sf_ChangeUnit2);

  /* Start for MATLABSystem: '<Root>/Encoder 1' */
  Read_Encoder_DW.obj_o.isInitialized = 0;
  Read_Encoder_DW.obj_o.matlabCodegenIsDeleted = false;
  Read_Encoder_SystemCore_setup(&Read_Encoder_DW.obj_o);

  /* Start for MATLABSystem: '<Root>/Encoder 2' */
  Read_Encoder_DW.obj_e.isInitialized = 0;
  Read_Encoder_DW.obj_e.matlabCodegenIsDeleted = false;
  Read_Encoder_SystemCore_setup_l(&Read_Encoder_DW.obj_e);

  /* Start for MATLABSystem: '<Root>/Encoder 3' */
  Read_Encoder_DW.obj.isInitialized = 0;
  Read_Encoder_DW.obj.matlabCodegenIsDeleted = false;
  Read_Encode_SystemCore_setup_l2(&Read_Encoder_DW.obj);
}

/* Model terminate function */
void Read_Encoder_terminate(void)
{
  uint8_T ChannelInfo;

  /* Terminate for MATLABSystem: '<Root>/Encoder 1' */
  if (!Read_Encoder_DW.obj_o.matlabCodegenIsDeleted) {
    Read_Encoder_DW.obj_o.matlabCodegenIsDeleted = true;
    if ((Read_Encoder_DW.obj_o.isInitialized == 1) &&
        Read_Encoder_DW.obj_o.isSetupComplete) {
      disableCounter(Read_Encoder_DW.obj_o.TimerHandle);
      disableTimerInterrupts(Read_Encoder_DW.obj_o.TimerHandle, 0);
      ChannelInfo = ENABLE_CH;
      disableTimerChannel1(Read_Encoder_DW.obj_o.TimerHandle, ChannelInfo);
      disableTimerChannel2(Read_Encoder_DW.obj_o.TimerHandle, ChannelInfo);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Encoder 1' */
  /* Terminate for MATLABSystem: '<Root>/Encoder 2' */
  if (!Read_Encoder_DW.obj_e.matlabCodegenIsDeleted) {
    Read_Encoder_DW.obj_e.matlabCodegenIsDeleted = true;
    if ((Read_Encoder_DW.obj_e.isInitialized == 1) &&
        Read_Encoder_DW.obj_e.isSetupComplete) {
      disableCounter(Read_Encoder_DW.obj_e.TimerHandle);
      disableTimerInterrupts(Read_Encoder_DW.obj_e.TimerHandle, 0);
      ChannelInfo = ENABLE_CH;
      disableTimerChannel1(Read_Encoder_DW.obj_e.TimerHandle, ChannelInfo);
      disableTimerChannel2(Read_Encoder_DW.obj_e.TimerHandle, ChannelInfo);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Encoder 2' */
  /* Terminate for MATLABSystem: '<Root>/Encoder 3' */
  if (!Read_Encoder_DW.obj.matlabCodegenIsDeleted) {
    Read_Encoder_DW.obj.matlabCodegenIsDeleted = true;
    if ((Read_Encoder_DW.obj.isInitialized == 1) &&
        Read_Encoder_DW.obj.isSetupComplete) {
      disableCounter(Read_Encoder_DW.obj.TimerHandle);
      disableTimerInterrupts(Read_Encoder_DW.obj.TimerHandle, 0);
      ChannelInfo = ENABLE_CH;
      disableTimerChannel1(Read_Encoder_DW.obj.TimerHandle, ChannelInfo);
      disableTimerChannel2(Read_Encoder_DW.obj.TimerHandle, ChannelInfo);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Encoder 3' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
