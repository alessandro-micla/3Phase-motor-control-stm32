/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: mcb_open_loop_control_nucleo_f401re.c
 *
 * Code generated for Simulink model 'mcb_open_loop_control_nucleo_f401re'.
 *
 * Model version                  : 9.0
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Wed Feb  5 17:10:38 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "mcb_open_loop_control_nucleo_f401re.h"
#include "mcb_open_loop_control_nucleo_f401re_types.h"
#include "mcb_open_loop_control_nucleo_f401re_private.h"
#include <math.h>
#include "arm_math.h"
#include "rtwtypes.h"
#include "stm_adc_ll.h"
#include <stddef.h>
#include "stm_timer_ll.h"
#include <string.h>

/* Block signals (default storage) */
B_mcb_open_loop_control_nucle_T mcb_open_loop_control_nucleo__B;

/* Block states (default storage) */
DW_mcb_open_loop_control_nucl_T mcb_open_loop_control_nucleo_DW;

/* Real-time model */
static RT_MODEL_mcb_open_loop_contro_T mcb_open_loop_control_nucleo_M_;
RT_MODEL_mcb_open_loop_contro_T *const mcb_open_loop_control_nucleo_M =
  &mcb_open_loop_control_nucleo_M_;

/* Forward declaration for local functions */
static void mcb_open_lo_PWMOutput_setupImpl(stm32cube_blocks_PWMOutput_mc_T *obj);
static void mcb_open_loop__SystemCore_setup(stm32cube_blocks_AnalogInput__T *obj);
static void mcb_open_lo_PWMOutput_setupImpl(stm32cube_blocks_PWMOutput_mc_T *obj)
{
  TIM_Type_T b;
  boolean_T isSlaveModeTriggerEnabled;

  /* Start for MATLABSystem: '<S26>/PWM Output' */
  b.PeripheralPtr = TIM1;
  b.isCenterAlignedMode = false;

  /* Start for MATLABSystem: '<S26>/PWM Output' */
  b.repetitionCounter = 0U;
  obj->TimerHandle = Timer_Handle_Init(&b);
  enableTimerInterrupts(obj->TimerHandle, 0);
  enableTimerChannel1(obj->TimerHandle, ENABLE_CH);
  enableTimerChannel2(obj->TimerHandle, ENABLE_CH);
  enableTimerChannel3(obj->TimerHandle, ENABLE_CH);
  isSlaveModeTriggerEnabled = isSlaveTriggerModeEnabled(obj->TimerHandle);
  if (!isSlaveModeTriggerEnabled) {
    /* Start for MATLABSystem: '<S26>/PWM Output' */
    enableCounter(obj->TimerHandle, false);
  }
}

static void mcb_open_loop__SystemCore_setup(stm32cube_blocks_AnalogInput__T *obj)
{
  ADC_Type_T adcStructLoc;
  obj->isSetupComplete = false;

  /* Start for MATLABSystem: '<S18>/Analog to Digital Converter' */
  obj->isInitialized = 1;
  adcStructLoc.InternalBufferPtr = (void *)(NULL);

  /* Start for MATLABSystem: '<S18>/Analog to Digital Converter' */
  adcStructLoc.RegularNoOfConversion = 0U;
  adcStructLoc.peripheralPtr = ADC1;
  adcStructLoc.dmaPeripheralPtr = NULL;
  adcStructLoc.dmastream = 0;
  adcStructLoc.DataTransferMode = ADC_DR_TRANSFER;
  adcStructLoc.DmaTransferMode = ADC_DMA_TRANSFER_LIMITED;
  adcStructLoc.InternalBufferSize = 2U;
  adcStructLoc.InjectedNoOfConversion = 2U;
  obj->ADCHandle = ADC_Handle_Init(&adcStructLoc, ADC_INTERRUPT_MODE, 0,
    ADC_READ, LL_ADC_INJ_SEQ_SCAN_ENABLE_2RANKS);
  enableADC(obj->ADCHandle);
  startADCConversionForExternalTrigger(obj->ADCHandle, 0);
  obj->isSetupComplete = true;
}

real_T rt_urand_Upu32_Yd_f_pw_snf(uint32_T *u)
{
  uint32_T hi;
  uint32_T lo;

  /* Uniform random number generator (random number between 0 and 1)

     #define IA      16807                      magic multiplier = 7^5
     #define IM      2147483647                 modulus = 2^31-1
     #define IQ      127773                     IM div IA
     #define IR      2836                       IM modulo IA
     #define S       4.656612875245797e-10      reciprocal of 2^31-1
     test = IA * (seed % IQ) - IR * (seed/IQ)
     seed = test < 0 ? (test + IM) : test
     return (seed*S)
   */
  lo = *u % 127773U * 16807U;
  hi = *u / 127773U * 2836U;
  if (lo < hi) {
    *u = 2147483647U - (hi - lo);
  } else {
    *u = lo - hi;
  }

  return (real_T)*u * 4.6566128752457969E-10;
}

/* Model step function */
void mcb_open_loop_control_nucleo_f401re_step(void)
{
  uint32_T fifoLevel;
  int16_T rtb_Switch_a;
  uint8_T rtb_TmpSignalConversionAtCANWri[4];
  uint8_T rtb_ByteUnpack;
  uint8_T rtb_ByteUnpack1;
  uint8_T rtb_ByteUnpack2;
  uint8_T rtb_ByteUnpack3;
  boolean_T rtb_DataTypeConversion1_d;

  /* MATLABSystem: '<S1>/CAN Read' */
  MW_CAN_ReceiveMessage(mcb_open_loop_control_nucleo_DW.obj.MW_CAN_HANDLE, 0,
                        &mcb_open_loop_control_nucleo__B.CANRead.Data[0],
                        &mcb_open_loop_control_nucleo__B.CANRead.ID,
                        &mcb_open_loop_control_nucleo__B.CANRead.Extended,
                        &mcb_open_loop_control_nucleo__B.CANRead.Remote,
                        &mcb_open_loop_control_nucleo__B.CANRead.Length, 1U,
                        &fifoLevel);
  mcb_open_loop_control_nucleo__B.CANRead.Error = 0U;
  mcb_open_loop_control_nucleo__B.CANRead.Timestamp = 0.0;

  /* S-Function (scanunpack): '<S1>/CAN Unpack' */
  {
    /* S-Function (scanunpack): '<S1>/CAN Unpack' */
    if ((4 == mcb_open_loop_control_nucleo__B.CANRead.Length) &&
        (mcb_open_loop_control_nucleo__B.CANRead.ID != INVALID_CAN_ID) ) {
      if ((544 == mcb_open_loop_control_nucleo__B.CANRead.ID) && (0U ==
           mcb_open_loop_control_nucleo__B.CANRead.Extended) ) {
        (void) memcpy(&mcb_open_loop_control_nucleo__B.CANUnpack[0],
                      mcb_open_loop_control_nucleo__B.CANRead.Data,
                      4 * sizeof(uint8_T));
      }
    }
  }

  /* S-Function (byte2any_svd): '<S1>/Byte Unpack1' */

  /* Unpack: <S1>/Byte Unpack1 */
  {
    uint32_T MW_inputPortOffset = 0U;
    uint16_T MW_outputPortWidth = 0U;

    /* Packed input data type - uint8_T */
    void* unpackData = &mcb_open_loop_control_nucleo__B.CANUnpack[1];

    /* Unpacking the values to output 1 */
    /* Output data type - uint8_T, size - 1 */
    {
      MW_outputPortWidth = sizeof(uint8_T);
      memcpy((void*)&rtb_ByteUnpack1, (void *)&(((uint8_T *)unpackData)
              [MW_inputPortOffset]), MW_outputPortWidth);
    }
  }

  /* S-Function (byte2any_svd): '<S1>/Byte Unpack3' */

  /* Unpack: <S1>/Byte Unpack3 */
  {
    uint32_T MW_inputPortOffset = 0U;
    uint16_T MW_outputPortWidth = 0U;

    /* Packed input data type - uint8_T */
    void* unpackData = &mcb_open_loop_control_nucleo__B.CANUnpack[2];

    /* Unpacking the values to output 1 */
    /* Output data type - uint8_T, size - 1 */
    {
      MW_outputPortWidth = sizeof(uint8_T);
      memcpy((void*)&rtb_ByteUnpack3, (void *)&(((uint8_T *)unpackData)
              [MW_inputPortOffset]), MW_outputPortWidth);
    }
  }

  /* S-Function (byte2any_svd): '<S1>/Byte Unpack' */

  /* Unpack: <S1>/Byte Unpack */
  {
    uint32_T MW_inputPortOffset = 0U;
    uint16_T MW_outputPortWidth = 0U;

    /* Packed input data type - uint8_T */
    void* unpackData = &mcb_open_loop_control_nucleo__B.CANUnpack[0];

    /* Unpacking the values to output 1 */
    /* Output data type - uint8_T, size - 1 */
    {
      MW_outputPortWidth = sizeof(uint8_T);
      memcpy((void*)&rtb_ByteUnpack, (void *)&(((uint8_T *)unpackData)
              [MW_inputPortOffset]), MW_outputPortWidth);
    }
  }

  /* S-Function (byte2any_svd): '<S1>/Byte Unpack2' */

  /* Unpack: <S1>/Byte Unpack2 */
  {
    uint32_T MW_inputPortOffset = 0U;
    uint16_T MW_outputPortWidth = 0U;

    /* Packed input data type - uint8_T */
    void* unpackData = &mcb_open_loop_control_nucleo__B.CANUnpack[3];

    /* Unpacking the values to output 1 */
    /* Output data type - uint8_T, size - 1 */
    {
      MW_outputPortWidth = sizeof(uint8_T);
      memcpy((void*)&rtb_ByteUnpack2, (void *)&(((uint8_T *)unpackData)
              [MW_inputPortOffset]), MW_outputPortWidth);
    }
  }

  /* SignalConversion generated from: '<S2>/CAN Write' incorporates:
   *  Constant: '<Root>/Number ID ECU'
   *  Constant: '<S6>/Constant'
   *  DataTypeConversion: '<S2>/Data Type Conversion'
   *  DataTypeConversion: '<S2>/Data Type Conversion1'
   *  DataTypeConversion: '<S6>/Data Type Conversion'
   *  S-Function (sfix_bitop): '<S2>/Bitwise OR'
   *  S-Function (sfix_bitop): '<S2>/Bitwise OR1'
   *  Sum: '<S6>/Sum'
   */
  rtb_TmpSignalConversionAtCANWri[0] = (uint8_T)((uint32_T)
    mcb_open_loop_control_nucleo__P.NumberIDECU_Value &
    mcb_open_loop_control_nucleo__P.BitwiseOR1_BitMask);
  rtb_TmpSignalConversionAtCANWri[1] = (uint8_T)((uint32_T)
    mcb_open_loop_control_nucleo__P.NumberIDECU_Value &
    mcb_open_loop_control_nucleo__P.BitwiseOR_BitMask);
  rtb_TmpSignalConversionAtCANWri[2] = (uint8_T)
    mcb_open_loop_control_nucleo__B.UniformRandomNumber;
  rtb_TmpSignalConversionAtCANWri[3] = (uint8_T)((uint8_T)
    mcb_open_loop_control_nucleo__B.UniformRandomNumber +
    mcb_open_loop_control_nucleo__P.Constant_Value_hv);

  /* MATLABSystem: '<S2>/CAN Write' */
  MW_CAN_TransmitMessage(mcb_open_loop_control_nucleo_DW.obj_h.MW_CAN_HANDLE,
    &rtb_TmpSignalConversionAtCANWri[0], 545U, 0, 0, 4, 100U, &fifoLevel);

  /* DataTypeConversion: '<S1>/Data Type Conversion1' incorporates:
   *  DataTypeConversion: '<S8>/Extract Desired Bits'
   */
  rtb_DataTypeConversion1_d = ((rtb_ByteUnpack & 1U) != 0U);

  /* RateTransition generated from: '<S1>/Data Type Conversion1' */
  mcb_open_loop_control_nucleo_DW.TmpRTBAtDataTypeConversion1Outp =
    rtb_DataTypeConversion1_d;

  /* Switch: '<S3>/Switch' incorporates:
   *  BitConcat: '<S7>/BitConcat2'
   *  DataTypeConversion: '<S1>/Data Type Conversion2'
   *  DataTypeConversion: '<S9>/Extract Desired Bits'
   *  Gain: '<S3>/Gain'
   */
  if ((rtb_ByteUnpack2 & 1U) != 0U) {
    rtb_Switch_a = (int16_T)(rtb_ByteUnpack1 << 8 | rtb_ByteUnpack3);
  } else {
    rtb_Switch_a = (int16_T)((uint16_T)(rtb_ByteUnpack1 << 8 | rtb_ByteUnpack3) *
      mcb_open_loop_control_nucleo__P.Gain_Gain_m);
  }

  /* End of Switch: '<S3>/Switch' */

  /* RateTransition generated from: '<Root>/Open Loop Control' */
  mcb_open_loop_control_nucleo_DW.TmpRTBAtOpenLoopControlInport2_ = rtb_Switch_a;
}

/* Model initialize function */
void mcb_open_loop_control_nucleo_f401re_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(mcb_open_loop_control_nucleo_M, (NULL));

  /* block I/O */
  (void) memset(((void *) &mcb_open_loop_control_nucleo__B), 0,
                sizeof(B_mcb_open_loop_control_nucle_T));

  /* states (dwork) */
  (void) memset((void *)&mcb_open_loop_control_nucleo_DW, 0,
                sizeof(DW_mcb_open_loop_control_nucl_T));

  {
    int32_T r;
    int32_T t;
    uint32_T RandSeed;

    /* Start for S-Function (scanunpack): '<S1>/CAN Unpack' */

    /*-----------S-Function Block: <S1>/CAN Unpack -----------------*/

    /* InitializeConditions for RateTransition generated from: '<S1>/Data Type Conversion1' */
    mcb_open_loop_control_nucleo_DW.TmpRTBAtDataTypeConversion1Outp =
      mcb_open_loop_control_nucleo__P.TmpRTBAtDataTypeConversion1Outp;

    /* InitializeConditions for RateTransition generated from: '<Root>/Open Loop Control' */
    mcb_open_loop_control_nucleo_DW.TmpRTBAtOpenLoopControlInport2_ =
      mcb_open_loop_control_nucleo__P.TmpRTBAtOpenLoopControlInport2_;

    /* SystemInitialize for S-Function (HardwareInterrupt_sfun): '<S11>/Hardware Interrupt' incorporates:
     *  SubSystem: '<Root>/Open Loop Control'
     */
    /* System initialize for function-call system: '<Root>/Open Loop Control' */

    /* InitializeConditions for DiscreteIntegrator: '<S29>/Ramp Generator' */
    mcb_open_loop_control_nucleo_DW.RampGenerator_DSTATE =
      mcb_open_loop_control_nucleo__P.RampGenerator_IC;

    /* SystemInitialize for Enabled SubSystem: '<S31>/Accumulate' */
    /* InitializeConditions for Delay: '<S47>/Delay' */
    mcb_open_loop_control_nucleo_DW.Delay_DSTATE =
      mcb_open_loop_control_nucleo__P.Delay_InitialCondition;

    /* SystemInitialize for Enabled SubSystem: '<S47>/Subsystem' */
    /* SystemInitialize for SignalConversion generated from: '<S48>/Input' incorporates:
     *  Outport: '<S48>/Out1'
     */
    mcb_open_loop_control_nucleo__B.Input =
      mcb_open_loop_control_nucleo__P.Out1_Y0;

    /* End of SystemInitialize for SubSystem: '<S47>/Subsystem' */

    /* SystemInitialize for Outport: '<S47>/theta_e' incorporates:
     *  Sum: '<S47>/Add1'
     *  UnitDelay: '<S31>/Unit Delay'
     */
    mcb_open_loop_control_nucleo_DW.UnitDelay_DSTATE =
      mcb_open_loop_control_nucleo__P.theta_e_Y0;

    /* End of SystemInitialize for SubSystem: '<S31>/Accumulate' */

    /* Start for MATLABSystem: '<S26>/PWM Output' */
    mcb_open_loop_control_nucleo_DW.obj_f.matlabCodegenIsDeleted = false;
    mcb_open_loop_control_nucleo_DW.obj_f.isSetupComplete = false;
    mcb_open_loop_control_nucleo_DW.obj_f.isInitialized = 1;
    mcb_open_lo_PWMOutput_setupImpl(&mcb_open_loop_control_nucleo_DW.obj_f);
    mcb_open_loop_control_nucleo_DW.obj_f.isSetupComplete = true;

    /* Start for MATLABSystem: '<S18>/Analog to Digital Converter' */
    mcb_open_loop_control_nucleo_DW.obj_k.isInitialized = 0;
    mcb_open_loop_control_nucleo_DW.obj_k.matlabCodegenIsDeleted = false;
    mcb_open_loop__SystemCore_setup(&mcb_open_loop_control_nucleo_DW.obj_k);

    /* SystemInitialize for Atomic SubSystem: '<S6>/Initialize Function' */
    /* InitializeConditions for UniformRandomNumber: '<S49>/Uniform Random Number' */
    r = (int32_T)((uint32_T)
                  mcb_open_loop_control_nucleo__P.UniformRandomNumber_Seed >>
                  16U);
    t = (int32_T)((uint32_T)
                  mcb_open_loop_control_nucleo__P.UniformRandomNumber_Seed &
                  32768U);
    RandSeed = (((((uint32_T)
                   mcb_open_loop_control_nucleo__P.UniformRandomNumber_Seed -
                   ((uint32_T)r << 16U)) + (uint32_T)t) << 16U) + (uint32_T)t) +
      (uint32_T)r;
    if (RandSeed < 1U) {
      RandSeed = 1144108930U;
    } else if (RandSeed > 2147483646U) {
      RandSeed = 2147483646U;
    }

    /* UniformRandomNumber: '<S49>/Uniform Random Number' */
    mcb_open_loop_control_nucleo__B.UniformRandomNumber =
      (mcb_open_loop_control_nucleo__P.UniformRandomNumber_Maximum -
       mcb_open_loop_control_nucleo__P.UniformRandomNumber_Minimum) *
      rt_urand_Upu32_Yd_f_pw_snf(&RandSeed) +
      mcb_open_loop_control_nucleo__P.UniformRandomNumber_Minimum;

    /* End of SystemInitialize for SubSystem: '<S6>/Initialize Function' */

    /* Start for MATLABSystem: '<S1>/CAN Read' */
    mcb_open_loop_control_nucleo_DW.obj.matlabCodegenIsDeleted = false;
    mcb_open_loop_control_nucleo_DW.obj.isInitialized = 1;
    mcb_open_loop_control_nucleo_DW.obj.MW_CAN_HANDLE = MW_CAN_Initialize(0);
    MW_configureCANFilter(mcb_open_loop_control_nucleo_DW.obj.MW_CAN_HANDLE, 0,
                          0, 0, 0, 0, 0, 0, 0, 1, 1);
    mcb_open_loop_control_nucleo_DW.obj.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/CAN Write' */
    mcb_open_loop_control_nucleo_DW.obj_h.matlabCodegenIsDeleted = false;
    mcb_open_loop_control_nucleo_DW.obj_h.isInitialized = 1;
    mcb_open_loop_control_nucleo_DW.obj_h.MW_CAN_HANDLE = MW_CAN_Initialize(0);
    MW_configureCANFilter(mcb_open_loop_control_nucleo_DW.obj_h.MW_CAN_HANDLE, 0,
                          0, 0, 0, 0, 0, 0, 0, 1, 1);
    mcb_open_loop_control_nucleo_DW.obj_h.isSetupComplete = true;

    /* Outputs for Atomic SubSystem: '<S6>/Initialize Function' */
    /* Update for UniformRandomNumber: '<S49>/Uniform Random Number' */
    rt_urand_Upu32_Yd_f_pw_snf(&RandSeed);

    /* End of Outputs for SubSystem: '<S6>/Initialize Function' */
  }
}

/* Model terminate function */
void mcb_open_loop_control_nucleo_f401re_terminate(void)
{
  /* Terminate for MATLABSystem: '<S1>/CAN Read' */
  if (!mcb_open_loop_control_nucleo_DW.obj.matlabCodegenIsDeleted) {
    mcb_open_loop_control_nucleo_DW.obj.matlabCodegenIsDeleted = true;
    if ((mcb_open_loop_control_nucleo_DW.obj.isInitialized == 1) &&
        mcb_open_loop_control_nucleo_DW.obj.isSetupComplete) {
      MW_CAN_Close(mcb_open_loop_control_nucleo_DW.obj.MW_CAN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/CAN Read' */
  /* End of Terminate for S-Function (HardwareInterrupt_sfun): '<S11>/Hardware Interrupt' */

  /* Terminate for S-Function (HardwareInterrupt_sfun): '<S11>/Hardware Interrupt' incorporates:
   *  SubSystem: '<Root>/Open Loop Control'
   */
  /* Termination for function-call system: '<Root>/Open Loop Control' */

  /* Terminate for MATLABSystem: '<S26>/PWM Output' */
  if (!mcb_open_loop_control_nucleo_DW.obj_f.matlabCodegenIsDeleted) {
    mcb_open_loop_control_nucleo_DW.obj_f.matlabCodegenIsDeleted = true;
    if ((mcb_open_loop_control_nucleo_DW.obj_f.isInitialized == 1) &&
        mcb_open_loop_control_nucleo_DW.obj_f.isSetupComplete) {
      disableCounter(mcb_open_loop_control_nucleo_DW.obj_f.TimerHandle);
      disableTimerInterrupts(mcb_open_loop_control_nucleo_DW.obj_f.TimerHandle,
        0);
      disableTimerChannel1(mcb_open_loop_control_nucleo_DW.obj_f.TimerHandle,
                           ENABLE_CH);
      disableTimerChannel2(mcb_open_loop_control_nucleo_DW.obj_f.TimerHandle,
                           ENABLE_CH);
      disableTimerChannel3(mcb_open_loop_control_nucleo_DW.obj_f.TimerHandle,
                           ENABLE_CH);
    }
  }

  /* End of Terminate for MATLABSystem: '<S26>/PWM Output' */

  /* Terminate for MATLABSystem: '<S18>/Analog to Digital Converter' */
  if (!mcb_open_loop_control_nucleo_DW.obj_k.matlabCodegenIsDeleted) {
    mcb_open_loop_control_nucleo_DW.obj_k.matlabCodegenIsDeleted = true;
    if ((mcb_open_loop_control_nucleo_DW.obj_k.isInitialized == 1) &&
        mcb_open_loop_control_nucleo_DW.obj_k.isSetupComplete) {
      ADC_Handle_Deinit(mcb_open_loop_control_nucleo_DW.obj_k.ADCHandle,
                        ADC_INTERRUPT_MODE, 0);
    }
  }

  /* End of Terminate for MATLABSystem: '<S18>/Analog to Digital Converter' */

  /* End of Terminate for S-Function (HardwareInterrupt_sfun): '<S11>/Hardware Interrupt' */

  /* Terminate for MATLABSystem: '<S2>/CAN Write' */
  if (!mcb_open_loop_control_nucleo_DW.obj_h.matlabCodegenIsDeleted) {
    mcb_open_loop_control_nucleo_DW.obj_h.matlabCodegenIsDeleted = true;
    if ((mcb_open_loop_control_nucleo_DW.obj_h.isInitialized == 1) &&
        mcb_open_loop_control_nucleo_DW.obj_h.isSetupComplete) {
      MW_CAN_Close(mcb_open_loop_control_nucleo_DW.obj_h.MW_CAN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/CAN Write' */
}

void mcb_open_loop_control_nucleo_f401re_configure_interrupts(void)
{
  /* Register interrupt service routine */
  MW_NVIC_ConfigureIRQ(33,&ADC_IRQHandler,2);
  MW_NVIC_EnableIRQ(33);
}

/* Hardware Interrupt Block: '<S11>/Hardware Interrupt' */
void ADC_IRQHandler(void)
{
  /* Event: ADC1 Inj EoCS */
  /* Check event ADC1 Inj EoCS occurred */
  if (0 != (
#if defined(MW_ADC1_ENABLED) && (defined(MW_ADC1_INJ_IRQ_ENABLED) && (MW_ADC1_INJ_IRQ_ENABLED==1))
            (0 != LL_ADC_IsEnabledIT_JEOS(ADC1)) && (0 != ADC_IsActiveFlagJEOS
        (&(MW_ADC1_VAR)))
#else
            (0 != LL_ADC_IsEnabledIT_JEOS(ADC1)) && (0 !=
        LL_ADC_IsActiveFlag_JEOS(ADC1))
#endif
            )) {
    /* Clear occurred ADC1 Inj EoCS event */
    LL_ADC_ClearFlag_JEOS(ADC1);
    if (1 == runModel) {
      {
        /* RateTransition generated from: '<S1>/Data Type Conversion1' */
        mcb_open_loop_control_nucleo__B.TmpRTBAtDataTypeConversion1Outp =
          mcb_open_loop_control_nucleo_DW.TmpRTBAtDataTypeConversion1Outp;

        /* RateTransition generated from: '<Root>/Open Loop Control' */
        mcb_open_loop_control_nucleo__B.TmpRTBAtOpenLoopControlInport2 =
          mcb_open_loop_control_nucleo_DW.TmpRTBAtOpenLoopControlInport2_;

        /* S-Function (HardwareInterrupt_sfun): '<S11>/Hardware Interrupt' */

        /* Output and update for function-call system: '<Root>/Open Loop Control' */
        {
          GPIO_TypeDef * portNameLoc;
          int32_T pinWriteLoc;
          int32_T tmp_e;
          int32_T tmp_p;
          real32_T rtb_Product1;
          real32_T rtb_Product1_d;
          real32_T rtb_Product_h;
          real32_T rtb_Switch4_idx_2;
          real32_T rtb_algDD_o2;
          real32_T rtb_sum_beta;
          real32_T tmp_m;
          uint16_T tmp[2];
          boolean_T tmp_i;

          /* MATLABSystem: '<S23>/Digital Port Write' */
          portNameLoc = GPIOC;

          /* Switch: '<S19>/Switch' incorporates:
           *  Constant: '<S19>/Constant1'
           *  Logic: '<S19>/NOT'
           */
          if (mcb_open_loop_control_nucleo__P.Constant1_Value_a >
              mcb_open_loop_control_nucleo__P.Switch_Threshold_g) {
            tmp_i =
              mcb_open_loop_control_nucleo__B.TmpRTBAtDataTypeConversion1Outp;
          } else {
            tmp_i =
              !mcb_open_loop_control_nucleo__B.TmpRTBAtDataTypeConversion1Outp;
          }

          /* MATLABSystem: '<S23>/Digital Port Write' incorporates:
           *  Switch: '<S19>/Switch'
           */
          if (tmp_i) {
            pinWriteLoc = 1024;
            tmp_p = 2048;
            tmp_e = 4096;
          } else {
            pinWriteLoc = 0;
            tmp_p = 0;
            tmp_e = 0;
          }

          pinWriteLoc = (int32_T)((uint32_T)pinWriteLoc | (uint32_T)tmp_p |
            (uint32_T)tmp_e);
          LL_GPIO_SetOutputPin(portNameLoc, (uint32_T)pinWriteLoc);
          LL_GPIO_ResetOutputPin(portNameLoc, ~(uint32_T)pinWriteLoc & 7168U);

          /* DiscreteIntegrator: '<S29>/Ramp Generator' incorporates:
           *  Logic: '<S29>/NOT'
           */
          if (!mcb_open_loop_control_nucleo__B.TmpRTBAtDataTypeConversion1Outp)
          {
            mcb_open_loop_control_nucleo_DW.RampGenerator_DSTATE =
              mcb_open_loop_control_nucleo__P.RampGenerator_IC;
          }

          /* Product: '<S27>/Product' incorporates:
           *  DiscreteIntegrator: '<S29>/Ramp Generator'
           *  Gain: '<S27>/rpm2freq'
           */
          rtb_Product_h = (real32_T)
            mcb_open_loop_control_nucleo__P.rpm2freq_Gain * 3.81469727E-6F *
            (real32_T)
            mcb_open_loop_control_nucleo__B.TmpRTBAtOpenLoopControlInport2 *
            mcb_open_loop_control_nucleo_DW.RampGenerator_DSTATE;

          /* Gain: '<S28>/Correction_Factor_sinePWM' incorporates:
           *  Abs: '<S28>/Abs'
           *  Gain: '<S28>/V-by-f'
           */
          rtb_Product1 = mcb_open_loop_control_nucleo__P.Vbyf_Gain * fabsf
            (rtb_Product_h) *
            mcb_open_loop_control_nucleo__P.Correction_Factor_sinePWM_Gain;

          /* Switch: '<S32>/Switch' incorporates:
           *  Constant: '<S5>/Boost Voltage'
           *  RelationalOperator: '<S32>/Relational Operator'
           */
          if (rtb_Product1 > mcb_open_loop_control_nucleo__P.BoostVoltage_Value)
          {
            rtb_Product1_d = rtb_Product1;
          } else {
            rtb_Product1_d = mcb_open_loop_control_nucleo__P.BoostVoltage_Value;
          }

          /* End of Switch: '<S32>/Switch' */

          /* Outputs for Enabled SubSystem: '<S31>/Accumulate' incorporates:
           *  EnablePort: '<S47>/Enable'
           */
          /* Logic: '<S31>/NOT' incorporates:
           *  Constant: '<S31>/Constant_Reset'
           *  Delay: '<S47>/Delay'
           */
          if (!mcb_open_loop_control_nucleo__P.Constant_Reset_Value) {
            /* Outputs for Enabled SubSystem: '<S47>/Subsystem' incorporates:
             *  EnablePort: '<S48>/Enable'
             */
            if (mcb_open_loop_control_nucleo_DW.Delay_DSTATE) {
              /* SignalConversion generated from: '<S48>/Input' incorporates:
               *  Gain: '<S28>/position_increment'
               *  Gain: '<S31>/scaleIn'
               */
              mcb_open_loop_control_nucleo__B.Input =
                mcb_open_loop_control_nucleo__P.position_increment_Gain *
                rtb_Product_h * mcb_open_loop_control_nucleo__P.scaleIn_Gain;
            }

            /* End of Outputs for SubSystem: '<S47>/Subsystem' */

            /* Sum: '<S47>/Add' incorporates:
             *  Delay: '<S47>/Delay'
             *  UnitDelay: '<S31>/Unit Delay'
             */
            rtb_Product_h = mcb_open_loop_control_nucleo__B.Input +
              mcb_open_loop_control_nucleo_DW.UnitDelay_DSTATE;

            /* Sum: '<S47>/Add1' incorporates:
             *  DataTypeConversion: '<S47>/Data Type Conversion'
             *  DataTypeConversion: '<S47>/Data Type Conversion1'
             *  UnitDelay: '<S31>/Unit Delay'
             */
            mcb_open_loop_control_nucleo_DW.UnitDelay_DSTATE = rtb_Product_h -
              (real32_T)(int16_T)floorf(rtb_Product_h);

            /* Update for Delay: '<S47>/Delay' incorporates:
             *  Constant: '<S47>/Constant'
             */
            mcb_open_loop_control_nucleo_DW.Delay_DSTATE =
              mcb_open_loop_control_nucleo__P.Constant_Value_a;
          }

          /* End of Logic: '<S31>/NOT' */
          /* End of Outputs for SubSystem: '<S31>/Accumulate' */

          /* Gain: '<S41>/convert_pu' incorporates:
           *  Gain: '<S31>/scaleOut'
           *  UnitDelay: '<S31>/Unit Delay'
           */
          rtb_Product_h = mcb_open_loop_control_nucleo__P.scaleOut_Gain *
            mcb_open_loop_control_nucleo_DW.UnitDelay_DSTATE *
            mcb_open_loop_control_nucleo__P.convert_pu_Gain;

          /* If: '<S41>/If' incorporates:
           *  Constant: '<S43>/Constant'
           *  DataTypeConversion: '<S44>/Convert_back'
           *  DataTypeConversion: '<S44>/Convert_uint16'
           *  DataTypeConversion: '<S45>/Convert_back'
           *  DataTypeConversion: '<S45>/Convert_uint16'
           *  Gain: '<S39>/indexing'
           *  RelationalOperator: '<S43>/Compare'
           *  Sum: '<S44>/Sum'
           *  Sum: '<S45>/Sum'
           */
          if (rtb_Product_h < mcb_open_loop_control_nucleo__P.Constant_Value_h)
          {
            /* Outputs for IfAction SubSystem: '<S41>/If Action Subsystem' incorporates:
             *  ActionPort: '<S44>/Action Port'
             */
            rtb_Switch4_idx_2 = rtb_Product_h - (real32_T)(int16_T)floorf
              (rtb_Product_h);

            /* End of Outputs for SubSystem: '<S41>/If Action Subsystem' */
          } else {
            /* Outputs for IfAction SubSystem: '<S41>/If Action Subsystem1' incorporates:
             *  ActionPort: '<S45>/Action Port'
             */
            rtb_Switch4_idx_2 = rtb_Product_h - (real32_T)(int16_T)rtb_Product_h;

            /* End of Outputs for SubSystem: '<S41>/If Action Subsystem1' */
          }

          rtb_Product1 = mcb_open_loop_control_nucleo__P.indexing_Gain *
            rtb_Switch4_idx_2;

          /* End of If: '<S41>/If' */

          /* Sum: '<S39>/Sum2' incorporates:
           *  DataTypeConversion: '<S39>/Data Type Conversion1'
           *  DataTypeConversion: '<S39>/Get_Integer'
           */
          rtb_sum_beta = rtb_Product1 - (real32_T)(uint16_T)rtb_Product1;

          /* Saturate: '<S32>/Saturation' */
          if (rtb_Product1_d >
              mcb_open_loop_control_nucleo__P.Saturation_UpperSat) {
            rtb_Product1_d = mcb_open_loop_control_nucleo__P.Saturation_UpperSat;
          } else if (rtb_Product1_d <
                     mcb_open_loop_control_nucleo__P.Saturation_LowerSat) {
            rtb_Product1_d = mcb_open_loop_control_nucleo__P.Saturation_LowerSat;
          }

          /* Selector: '<S39>/Lookup' incorporates:
           *  Constant: '<S39>/offset'
           *  Constant: '<S39>/sine_table_values'
           *  DataTypeConversion: '<S39>/Get_Integer'
           *  Sum: '<S39>/Sum'
           *  Sum: '<S40>/Sum3'
           *  Sum: '<S40>/Sum5'
           */
          rtb_Switch4_idx_2 =
            mcb_open_loop_control_nucleo__P.sine_table_values_Value[(int32_T)
            ((uint32_T)mcb_open_loop_control_nucleo__P.offset_Value[1] +
             (uint16_T)rtb_Product1)];
          tmp_m = mcb_open_loop_control_nucleo__P.sine_table_values_Value
            [(int32_T)((uint32_T)mcb_open_loop_control_nucleo__P.offset_Value[3]
                       + (uint16_T)rtb_Product1)];

          /* Outputs for Atomic SubSystem: '<S34>/Two inputs CRL' */
          /* AlgorithmDescriptorDelegate generated from: '<S37>/a16' incorporates:
           *  Constant: '<S30>/Constant'
           *  Constant: '<S39>/offset'
           *  Constant: '<S39>/sine_table_values'
           *  DataTypeConversion: '<S39>/Get_Integer'
           *  Product: '<S40>/Product'
           *  Product: '<S40>/Product1'
           *  Saturate: '<S32>/Saturation'
           *  Selector: '<S39>/Lookup'
           *  Sum: '<S39>/Sum'
           *  Sum: '<S40>/Sum3'
           *  Sum: '<S40>/Sum4'
           *  Sum: '<S40>/Sum5'
           *  Sum: '<S40>/Sum6'
           *  UnaryMinus: '<S30>/Unary Minus'
           */
          arm_inv_park_f32(mcb_open_loop_control_nucleo__P.Constant_Value_g,
                           -rtb_Product1_d, &rtb_Product_h, &rtb_algDD_o2,
                           (mcb_open_loop_control_nucleo__P.sine_table_values_Value
                            [(int32_T)((uint32_T)
            mcb_open_loop_control_nucleo__P.offset_Value[0] + (uint16_T)
            rtb_Product1)] - rtb_Switch4_idx_2) * rtb_sum_beta +
                           rtb_Switch4_idx_2,
                           (mcb_open_loop_control_nucleo__P.sine_table_values_Value
                            [(int32_T)((uint32_T)
            mcb_open_loop_control_nucleo__P.offset_Value[2] + (uint16_T)
            rtb_Product1)] - tmp_m) * rtb_sum_beta + tmp_m);

          /* End of Outputs for SubSystem: '<S34>/Two inputs CRL' */

          /* Switch: '<S20>/Switch4' incorporates:
           *  Constant: '<S15>/Constant'
           *  Constant: '<S15>/Constant1'
           *  Constant: '<S20>/stop'
           *  Gain: '<S15>/Gain'
           *  Gain: '<S36>/Ka'
           *  Gain: '<S36>/Kb'
           *  Gain: '<S36>/Kc'
           *  Product: '<S15>/Product'
           *  Sum: '<S15>/Sum'
           *  Sum: '<S36>/add_b'
           *  Sum: '<S36>/add_c'
           */
          if (mcb_open_loop_control_nucleo__B.TmpRTBAtDataTypeConversion1Outp) {
            /* Gain: '<S36>/sqrt3_by_two' */
            rtb_Switch4_idx_2 =
              mcb_open_loop_control_nucleo__P.sqrt3_by_two_Gain * rtb_algDD_o2;

            /* Gain: '<S36>/one_by_two' */
            rtb_Product1 = mcb_open_loop_control_nucleo__P.one_by_two_Gain *
              rtb_Product_h;
            rtb_Product1_d = (mcb_open_loop_control_nucleo__P.Ka_Gain *
                              rtb_Product_h +
                              mcb_open_loop_control_nucleo__P.Constant_Value) *
              mcb_open_loop_control_nucleo__P.Gain_Gain *
              mcb_open_loop_control_nucleo__P.Constant1_Value;
            rtb_Product_h = ((rtb_Switch4_idx_2 - rtb_Product1) *
                             mcb_open_loop_control_nucleo__P.Kb_Gain +
                             mcb_open_loop_control_nucleo__P.Constant_Value) *
              mcb_open_loop_control_nucleo__P.Gain_Gain *
              mcb_open_loop_control_nucleo__P.Constant1_Value;
            rtb_Switch4_idx_2 = (((0.0F - rtb_Product1) - rtb_Switch4_idx_2) *
                                 mcb_open_loop_control_nucleo__P.Kc_Gain +
                                 mcb_open_loop_control_nucleo__P.Constant_Value)
              * mcb_open_loop_control_nucleo__P.Gain_Gain *
              mcb_open_loop_control_nucleo__P.Constant1_Value;
          } else {
            rtb_Product1_d = mcb_open_loop_control_nucleo__P.stop_Value;
            rtb_Product_h = mcb_open_loop_control_nucleo__P.stop_Value;
            rtb_Switch4_idx_2 = mcb_open_loop_control_nucleo__P.stop_Value;
          }

          /* End of Switch: '<S20>/Switch4' */

          /* MATLABSystem: '<S26>/PWM Output' */
          setDutyCycleInPercentageChannel1
            (mcb_open_loop_control_nucleo_DW.obj_f.TimerHandle, rtb_Product1_d);
          setDutyCycleInPercentageChannel2
            (mcb_open_loop_control_nucleo_DW.obj_f.TimerHandle, rtb_Product_h);
          setDutyCycleInPercentageChannel3
            (mcb_open_loop_control_nucleo_DW.obj_f.TimerHandle,
             rtb_Switch4_idx_2);

          /* MATLABSystem: '<S18>/Analog to Digital Converter' */
          injectedReadADCIntr(mcb_open_loop_control_nucleo_DW.obj_k.ADCHandle,
                              ADC_READ, &tmp[0]);

          /* Update for DiscreteIntegrator: '<S29>/Ramp Generator' incorporates:
           *  Constant: '<S27>/Ramp_Time (sec)'
           *  Constant: '<S29>/One'
           *  Gain: '<S29>/Sample_Time'
           *  Product: '<S29>/Divide'
           */
          mcb_open_loop_control_nucleo_DW.RampGenerator_DSTATE +=
            mcb_open_loop_control_nucleo__P.One_Value /
            mcb_open_loop_control_nucleo__P.Ramp_Timesec_Value *
            mcb_open_loop_control_nucleo__P.Ts *
            mcb_open_loop_control_nucleo__P.RampGenerator_gainval;
          if (mcb_open_loop_control_nucleo_DW.RampGenerator_DSTATE >
              mcb_open_loop_control_nucleo__P.RampGenerator_UpperSat) {
            mcb_open_loop_control_nucleo_DW.RampGenerator_DSTATE =
              mcb_open_loop_control_nucleo__P.RampGenerator_UpperSat;
          } else if (mcb_open_loop_control_nucleo_DW.RampGenerator_DSTATE <
                     mcb_open_loop_control_nucleo__P.RampGenerator_LowerSat) {
            mcb_open_loop_control_nucleo_DW.RampGenerator_DSTATE =
              mcb_open_loop_control_nucleo__P.RampGenerator_LowerSat;
          }

          /* End of Update for DiscreteIntegrator: '<S29>/Ramp Generator' */
        }

        /* End of Outputs for S-Function (HardwareInterrupt_sfun): '<S11>/Hardware Interrupt' */
      }
    }
  }

  __ISB();
  __DSB();
}

void mcb_open_loop_control_nucleo_f401re_unconfigure_interrupts (void)
{
  MW_NVIC_DisableIRQ(33);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
