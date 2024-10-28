/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Homing.c
 *
 * Code generated for Simulink model 'Homing'.
 *
 * Model version                  : 1.57
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Thu Oct 17 03:21:10 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Homing.h"
#include "Homing_types.h"
#include "rtwtypes.h"
#include "stm_timer_ll.h"
#include "Homing_private.h"

/* Block signals (default storage) */
B_Homing_T Homing_B;

/* Block states (default storage) */
DW_Homing_T Homing_DW;

/* Real-time model */
static RT_MODEL_Homing_T Homing_M_;
RT_MODEL_Homing_T *const Homing_M = &Homing_M_;

/* Forward declaration for local functions */
static void Homing_SystemCore_setup(stm32cube_blocks_EncoderBlock_T *obj);
static void Homing_SystemCore_setup(stm32cube_blocks_EncoderBlock_T *obj)
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
void Homing_step(void)
{
  real_T diff_count;
  uint32_T pinReadLoc;
  uint32_T timerCounts;

  /* MATLABSystem: '<S5>/Digital Port Read' */
  pinReadLoc = LL_GPIO_ReadInputPort(GPIOC);

  /* MATLABSystem: '<Root>/Encoder 3' */
  timerCounts = getTimerCounterValueForG4(Homing_DW.obj.TimerHandle, false, NULL);

  /* MATLAB Function: '<Root>/qei_x4' incorporates:
   *  DataTypeConversion: '<Root>/Cast To Double'
   *  MATLABSystem: '<Root>/Encoder 3'
   *  MATLABSystem: '<S5>/Digital Port Read'
   * */
  if ((pinReadLoc & 8192U) != 0U) {
    Homing_DW.pulses_accum = 0.0;
  }

  diff_count = (real_T)timerCounts - Homing_DW.prev_count;
  if (diff_count > 32768.0) {
    diff_count -= 65536.0;
  } else if (diff_count < -32768.0) {
    diff_count += 65536.0;
  }

  Homing_DW.pulses_accum += diff_count;
  Homing_DW.prev_count = timerCounts;

  /* MATLAB Function: '<Root>/Change Unit' incorporates:
   *  Constant: '<Root>/Constant'
   *  Constant: '<Root>/Constant1'
   *  MATLAB Function: '<Root>/qei_x4'
   */
  Homing_B.radps = diff_count * 100.0 * 2.0 * 3.1415926535897931 / 2048.0;
  Homing_B.rad = Homing_DW.pulses_accum * 2.0 * 3.1415926535897931 / 2048.0;

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  Homing_M->Timing.taskTime0 =
    ((time_T)(++Homing_M->Timing.clockTick0)) * Homing_M->Timing.stepSize0;
}

/* Model initialize function */
void Homing_initialize(void)
{
  /* Registration code */
  rtmSetTFinal(Homing_M, 30.0);
  Homing_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  Homing_M->Sizes.checksums[0] = (278090211U);
  Homing_M->Sizes.checksums[1] = (2885651613U);
  Homing_M->Sizes.checksums[2] = (1255940845U);
  Homing_M->Sizes.checksums[3] = (2910290472U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[5];
    Homing_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Homing_M->extModeInfo,
      &Homing_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Homing_M->extModeInfo, Homing_M->Sizes.checksums);
    rteiSetTPtr(Homing_M->extModeInfo, rtmGetTPtr(Homing_M));
  }

  /* Start for MATLABSystem: '<Root>/Encoder 3' */
  Homing_DW.obj.isInitialized = 0;
  Homing_DW.obj.matlabCodegenIsDeleted = false;
  Homing_SystemCore_setup(&Homing_DW.obj);
}

/* Model terminate function */
void Homing_terminate(void)
{
  uint8_T ChannelInfo;

  /* Terminate for MATLABSystem: '<Root>/Encoder 3' */
  if (!Homing_DW.obj.matlabCodegenIsDeleted) {
    Homing_DW.obj.matlabCodegenIsDeleted = true;
    if ((Homing_DW.obj.isInitialized == 1) && Homing_DW.obj.isSetupComplete) {
      disableCounter(Homing_DW.obj.TimerHandle);
      disableTimerInterrupts(Homing_DW.obj.TimerHandle, 0);
      ChannelInfo = ENABLE_CH;
      disableTimerChannel1(Homing_DW.obj.TimerHandle, ChannelInfo);
      disableTimerChannel2(Homing_DW.obj.TimerHandle, ChannelInfo);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Encoder 3' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
