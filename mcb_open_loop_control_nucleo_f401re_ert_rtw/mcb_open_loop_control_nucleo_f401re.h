/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: mcb_open_loop_control_nucleo_f401re.h
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

#ifndef mcb_open_loop_control_nucleo_f401re_h_
#define mcb_open_loop_control_nucleo_f401re_h_
#ifndef mcb_open_loop_control_nucleo_f401re_COMMON_INCLUDES_
#define mcb_open_loop_control_nucleo_f401re_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "math.h"
#include "string.h"
#include "stm_can_hal.h"
#include "main.h"
#endif                /* mcb_open_loop_control_nucleo_f401re_COMMON_INCLUDES_ */

#include "mw_stm32_nvic.h"
#include "mcb_open_loop_control_nucleo_f401re_types.h"
#include <string.h>
#include <stddef.h>
#include "can_message.h"
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#define mcb_open_loop_control_nucleo_f401re_M (mcb_open_loop_control_nucleo_M)

/* Block signals (default storage) */
typedef struct {
  CANMsg CANRead;                      /* '<S1>/CAN Read' */
  real_T UniformRandomNumber;          /* '<S49>/Uniform Random Number' */
  real32_T Input;                      /* '<S48>/Input' */
  int16_T TmpRTBAtOpenLoopControlInport2;/* '<Root>/CONTROL RPM AND DIRECTION' */
  uint8_T CANUnpack[4];                /* '<S1>/CAN Unpack' */
  boolean_T TmpRTBAtDataTypeConversion1Outp;/* '<S1>/Data Type Conversion1' */
} B_mcb_open_loop_control_nucle_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  stm32cube_blocks_CANRead_mcb__T obj; /* '<S1>/CAN Read' */
  stm32cube_blocks_CANWrite_mcb_T obj_h;/* '<S2>/CAN Write' */
  stm32cube_blocks_AnalogInput__T obj_k;/* '<S18>/Analog to Digital Converter' */
  stm32cube_blocks_PWMOutput_mc_T obj_f;/* '<S26>/PWM Output' */
  real32_T RampGenerator_DSTATE;       /* '<S29>/Ramp Generator' */
  real32_T UnitDelay_DSTATE;           /* '<S31>/Unit Delay' */
  int_T CANUnpack_ModeSignalID;        /* '<S1>/CAN Unpack' */
  int_T CANUnpack_StatusPortID;        /* '<S1>/CAN Unpack' */
  volatile int16_T TmpRTBAtOpenLoopControlInport2_;/* synthesized block */
  boolean_T Delay_DSTATE;              /* '<S47>/Delay' */
  volatile boolean_T TmpRTBAtDataTypeConversion1Outp;/* synthesized block */
} DW_mcb_open_loop_control_nucl_T;

/* Parameters (default storage) */
struct P_mcb_open_loop_control_nucle_T_ {
  real32_T Ts;                         /* Variable: Ts
                                        * Referenced by: '<S29>/Sample_Time'
                                        */
  uint16_T BitwiseOR1_BitMask;         /* Mask Parameter: BitwiseOR1_BitMask
                                        * Referenced by: '<S2>/Bitwise OR1'
                                        */
  uint16_T BitwiseOR_BitMask;          /* Mask Parameter: BitwiseOR_BitMask
                                        * Referenced by: '<S2>/Bitwise OR'
                                        */
  real_T UniformRandomNumber_Minimum;  /* Expression: 0
                                        * Referenced by: '<S49>/Uniform Random Number'
                                        */
  real_T UniformRandomNumber_Maximum;  /* Expression: 200
                                        * Referenced by: '<S49>/Uniform Random Number'
                                        */
  real_T UniformRandomNumber_Seed;     /* Expression: 0
                                        * Referenced by: '<S49>/Uniform Random Number'
                                        */
  real32_T Constant1_Value;            /* Expression: single(100)
                                        * Referenced by: '<S15>/Constant1'
                                        */
  real32_T Constant_Value;             /* Computed Parameter: Constant_Value
                                        * Referenced by: '<S15>/Constant'
                                        */
  real32_T sqrt3_by_two_Gain;          /* Computed Parameter: sqrt3_by_two_Gain
                                        * Referenced by: '<S36>/sqrt3_by_two'
                                        */
  real32_T one_by_two_Gain;            /* Computed Parameter: one_by_two_Gain
                                        * Referenced by: '<S36>/one_by_two'
                                        */
  real32_T Kc_Gain;                    /* Computed Parameter: Kc_Gain
                                        * Referenced by: '<S36>/Kc'
                                        */
  real32_T Kb_Gain;                    /* Computed Parameter: Kb_Gain
                                        * Referenced by: '<S36>/Kb'
                                        */
  real32_T Ka_Gain;                    /* Computed Parameter: Ka_Gain
                                        * Referenced by: '<S36>/Ka'
                                        */
  real32_T Gain_Gain;                  /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<S15>/Gain'
                                        */
  real32_T stop_Value;                 /* Computed Parameter: stop_Value
                                        * Referenced by: '<S20>/stop'
                                        */
  real32_T Out1_Y0;                    /* Computed Parameter: Out1_Y0
                                        * Referenced by: '<S48>/Out1'
                                        */
  real32_T theta_e_Y0;                 /* Computed Parameter: theta_e_Y0
                                        * Referenced by: '<S47>/theta_e'
                                        */
  real32_T Vabc_PU_Y0;                 /* Computed Parameter: Vabc_PU_Y0
                                        * Referenced by: '<S5>/Vabc_PU'
                                        */
  real32_T Constant_Value_h;           /* Computed Parameter: Constant_Value_h
                                        * Referenced by: '<S43>/Constant'
                                        */
  real32_T Constant_Value_g;           /* Computed Parameter: Constant_Value_g
                                        * Referenced by: '<S30>/Constant'
                                        */
  real32_T RampGenerator_gainval;   /* Computed Parameter: RampGenerator_gainval
                                     * Referenced by: '<S29>/Ramp Generator'
                                     */
  real32_T RampGenerator_IC;           /* Computed Parameter: RampGenerator_IC
                                        * Referenced by: '<S29>/Ramp Generator'
                                        */
  real32_T RampGenerator_UpperSat; /* Computed Parameter: RampGenerator_UpperSat
                                    * Referenced by: '<S29>/Ramp Generator'
                                    */
  real32_T RampGenerator_LowerSat; /* Computed Parameter: RampGenerator_LowerSat
                                    * Referenced by: '<S29>/Ramp Generator'
                                    */
  real32_T Vbyf_Gain;                  /* Computed Parameter: Vbyf_Gain
                                        * Referenced by: '<S28>/V-by-f'
                                        */
  real32_T Correction_Factor_sinePWM_Gain;
                           /* Computed Parameter: Correction_Factor_sinePWM_Gain
                            * Referenced by: '<S28>/Correction_Factor_sinePWM'
                            */
  real32_T BoostVoltage_Value;         /* Computed Parameter: BoostVoltage_Value
                                        * Referenced by: '<S5>/Boost Voltage'
                                        */
  real32_T Saturation_UpperSat;       /* Computed Parameter: Saturation_UpperSat
                                       * Referenced by: '<S32>/Saturation'
                                       */
  real32_T Saturation_LowerSat;       /* Computed Parameter: Saturation_LowerSat
                                       * Referenced by: '<S32>/Saturation'
                                       */
  real32_T sine_table_values_Value[1002];
                                  /* Computed Parameter: sine_table_values_Value
                                   * Referenced by: '<S39>/sine_table_values'
                                   */
  real32_T position_increment_Gain;
                                  /* Computed Parameter: position_increment_Gain
                                   * Referenced by: '<S28>/position_increment'
                                   */
  real32_T scaleIn_Gain;               /* Computed Parameter: scaleIn_Gain
                                        * Referenced by: '<S31>/scaleIn'
                                        */
  real32_T UnitDelay_InitialCondition;
                               /* Computed Parameter: UnitDelay_InitialCondition
                                * Referenced by: '<S31>/Unit Delay'
                                */
  real32_T scaleOut_Gain;              /* Computed Parameter: scaleOut_Gain
                                        * Referenced by: '<S31>/scaleOut'
                                        */
  real32_T convert_pu_Gain;            /* Computed Parameter: convert_pu_Gain
                                        * Referenced by: '<S41>/convert_pu'
                                        */
  real32_T indexing_Gain;              /* Computed Parameter: indexing_Gain
                                        * Referenced by: '<S39>/indexing'
                                        */
  real32_T One_Value;                  /* Computed Parameter: One_Value
                                        * Referenced by: '<S29>/One'
                                        */
  real32_T Ramp_Timesec_Value;         /* Computed Parameter: Ramp_Timesec_Value
                                        * Referenced by: '<S27>/Ramp_Time (sec)'
                                        */
  int16_T Gain_Gain_m;                 /* Computed Parameter: Gain_Gain_m
                                        * Referenced by: '<S3>/Gain'
                                        */
  int16_T offset_Value[4];             /* Computed Parameter: offset_Value
                                        * Referenced by: '<S39>/offset'
                                        */
  int16_T TmpRTBAtOpenLoopControlInport2_;
                          /* Computed Parameter: TmpRTBAtOpenLoopControlInport2_
                           * Referenced by:
                           */
  int16_T rpm2freq_Gain;               /* Computed Parameter: rpm2freq_Gain
                                        * Referenced by: '<S27>/rpm2freq'
                                        */
  uint16_T Offset_Value;               /* Computed Parameter: Offset_Value
                                        * Referenced by: '<S38>/Offset'
                                        */
  uint16_T Switch_Threshold;           /* Computed Parameter: Switch_Threshold
                                        * Referenced by: '<S38>/Switch'
                                        */
  uint16_T Constant1_Value_a;          /* Expression: inverter.EnableLogic
                                        * Referenced by: '<S19>/Constant1'
                                        */
  uint16_T Switch_Threshold_g;         /* Computed Parameter: Switch_Threshold_g
                                        * Referenced by: '<S19>/Switch'
                                        */
  uint16_T NumberIDECU_Value;          /* Computed Parameter: NumberIDECU_Value
                                        * Referenced by: '<Root>/Number ID ECU'
                                        */
  boolean_T Delay_InitialCondition;/* Computed Parameter: Delay_InitialCondition
                                    * Referenced by: '<S47>/Delay'
                                    */
  boolean_T Constant_Value_a;          /* Computed Parameter: Constant_Value_a
                                        * Referenced by: '<S47>/Constant'
                                        */
  boolean_T Constant_Reset_Value;    /* Computed Parameter: Constant_Reset_Value
                                      * Referenced by: '<S31>/Constant_Reset'
                                      */
  boolean_T TmpRTBAtDataTypeConversion1Outp;
                          /* Computed Parameter: TmpRTBAtDataTypeConversion1Outp
                           * Referenced by:
                           */
  uint8_T Constant_Value_hv;           /* Computed Parameter: Constant_Value_hv
                                        * Referenced by: '<S6>/Constant'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_mcb_open_loop_control_T {
  const char_T * volatile errorStatus;
};

extern CAN_DATATYPE CAN_DATATYPE_GROUND;

/* Block parameters (default storage) */
extern P_mcb_open_loop_control_nucle_T mcb_open_loop_control_nucleo__P;

/* Block signals (default storage) */
extern B_mcb_open_loop_control_nucle_T mcb_open_loop_control_nucleo__B;

/* Block states (default storage) */
extern DW_mcb_open_loop_control_nucl_T mcb_open_loop_control_nucleo_DW;

/* Model entry point functions */
extern void mcb_open_loop_control_nucleo_f401re_initialize(void);
extern void mcb_open_loop_control_nucleo_f401re_step(void);
extern void mcb_open_loop_control_nucleo_f401re_terminate(void);

/* Real-time Model object */
extern RT_MODEL_mcb_open_loop_contro_T *const mcb_open_loop_control_nucleo_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

#ifdef __cpluscplus

extern "C"
{

#endif

  void ADC_IRQHandler(void);
  void mcb_open_loop_control_nucleo_f401re_configure_interrupts (void);
  void mcb_open_loop_control_nucleo_f401re_unconfigure_interrupts (void);

#ifdef __cpluscplus

}

#endif

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S8>/DTProp1' : Unused code path elimination
 * Block '<S8>/DTProp2' : Unused code path elimination
 * Block '<S9>/DTProp1' : Unused code path elimination
 * Block '<S9>/DTProp2' : Unused code path elimination
 * Block '<S30>/Data Type Duplicate' : Unused code path elimination
 * Block '<S36>/Data Type Duplicate' : Unused code path elimination
 * Block '<S37>/Data Type Duplicate' : Unused code path elimination
 * Block '<S37>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S39>/Data Type Duplicate' : Unused code path elimination
 * Block '<S39>/Data Type Propagation' : Unused code path elimination
 * Block '<S44>/Data Type Duplicate' : Unused code path elimination
 * Block '<S45>/Data Type Duplicate' : Unused code path elimination
 * Block '<S31>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S5>/Data Type Conversion' : Unused code path elimination
 * Block '<S16>/Base Speed' : Unused code path elimination
 * Block '<S16>/Data Type' : Unused code path elimination
 * Block '<S16>/Inverter' : Unused code path elimination
 * Block '<S16>/Number of pole pairs' : Unused code path elimination
 * Block '<S16>/PWM Frequency' : Unused code path elimination
 * Block '<S8>/Modify Scaling Only' : Eliminate redundant data type conversion
 * Block '<S9>/Modify Scaling Only' : Eliminate redundant data type conversion
 * Block '<S39>/Get_FractionVal' : Eliminate redundant data type conversion
 */

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
 * '<Root>' : 'mcb_open_loop_control_nucleo_f401re'
 * '<S1>'   : 'mcb_open_loop_control_nucleo_f401re/CAN-BUS READ'
 * '<S2>'   : 'mcb_open_loop_control_nucleo_f401re/CAN-BUS WRITE'
 * '<S3>'   : 'mcb_open_loop_control_nucleo_f401re/CONTROL RPM AND DIRECTION'
 * '<S4>'   : 'mcb_open_loop_control_nucleo_f401re/Hardware Interrupt'
 * '<S5>'   : 'mcb_open_loop_control_nucleo_f401re/Open Loop Control'
 * '<S6>'   : 'mcb_open_loop_control_nucleo_f401re/Safety code generator'
 * '<S7>'   : 'mcb_open_loop_control_nucleo_f401re/CAN-BUS READ/Bit Concat'
 * '<S8>'   : 'mcb_open_loop_control_nucleo_f401re/CAN-BUS READ/Extract Bits'
 * '<S9>'   : 'mcb_open_loop_control_nucleo_f401re/CAN-BUS READ/Extract Bits1'
 * '<S10>'  : 'mcb_open_loop_control_nucleo_f401re/Hardware Interrupt/ECSoC'
 * '<S11>'  : 'mcb_open_loop_control_nucleo_f401re/Hardware Interrupt/ECSoC/ECSimCodegen'
 * '<S12>'  : 'mcb_open_loop_control_nucleo_f401re/Open Loop Control/Analog to Digital Converter'
 * '<S13>'  : 'mcb_open_loop_control_nucleo_f401re/Open Loop Control/Codegen'
 * '<S14>'  : 'mcb_open_loop_control_nucleo_f401re/Open Loop Control/Control_System'
 * '<S15>'  : 'mcb_open_loop_control_nucleo_f401re/Open Loop Control/Output Scaling'
 * '<S16>'  : 'mcb_open_loop_control_nucleo_f401re/Open Loop Control/Parameters'
 * '<S17>'  : 'mcb_open_loop_control_nucleo_f401re/Open Loop Control/Analog to Digital Converter/ECSoC'
 * '<S18>'  : 'mcb_open_loop_control_nucleo_f401re/Open Loop Control/Analog to Digital Converter/ECSoC/ECSimCodegen'
 * '<S19>'  : 'mcb_open_loop_control_nucleo_f401re/Open Loop Control/Codegen/Hardware Initialization'
 * '<S20>'  : 'mcb_open_loop_control_nucleo_f401re/Open Loop Control/Codegen/PWM Output'
 * '<S21>'  : 'mcb_open_loop_control_nucleo_f401re/Open Loop Control/Codegen/Hardware Initialization/Digital Port Write'
 * '<S22>'  : 'mcb_open_loop_control_nucleo_f401re/Open Loop Control/Codegen/Hardware Initialization/Digital Port Write/ECSoC'
 * '<S23>'  : 'mcb_open_loop_control_nucleo_f401re/Open Loop Control/Codegen/Hardware Initialization/Digital Port Write/ECSoC/ECSimCodegen'
 * '<S24>'  : 'mcb_open_loop_control_nucleo_f401re/Open Loop Control/Codegen/PWM Output/PWM Output1'
 * '<S25>'  : 'mcb_open_loop_control_nucleo_f401re/Open Loop Control/Codegen/PWM Output/PWM Output1/ECSoC'
 * '<S26>'  : 'mcb_open_loop_control_nucleo_f401re/Open Loop Control/Codegen/PWM Output/PWM Output1/ECSoC/ECSimCodegen'
 * '<S27>'  : 'mcb_open_loop_control_nucleo_f401re/Open Loop Control/Control_System/SpeedRefToFreq'
 * '<S28>'  : 'mcb_open_loop_control_nucleo_f401re/Open Loop Control/Control_System/VabcCalc'
 * '<S29>'  : 'mcb_open_loop_control_nucleo_f401re/Open Loop Control/Control_System/SpeedRefToFreq/Ramp Generator'
 * '<S30>'  : 'mcb_open_loop_control_nucleo_f401re/Open Loop Control/Control_System/VabcCalc/3-Phase Sine Voltage Generator'
 * '<S31>'  : 'mcb_open_loop_control_nucleo_f401re/Open Loop Control/Control_System/VabcCalc/Position Generator'
 * '<S32>'  : 'mcb_open_loop_control_nucleo_f401re/Open Loop Control/Control_System/VabcCalc/Saturate output to limits'
 * '<S33>'  : 'mcb_open_loop_control_nucleo_f401re/Open Loop Control/Control_System/VabcCalc/3-Phase Sine Voltage Generator/Inverse Clarke Transform'
 * '<S34>'  : 'mcb_open_loop_control_nucleo_f401re/Open Loop Control/Control_System/VabcCalc/3-Phase Sine Voltage Generator/Inverse Park Transform'
 * '<S35>'  : 'mcb_open_loop_control_nucleo_f401re/Open Loop Control/Control_System/VabcCalc/3-Phase Sine Voltage Generator/Sine-Cosine Lookup'
 * '<S36>'  : 'mcb_open_loop_control_nucleo_f401re/Open Loop Control/Control_System/VabcCalc/3-Phase Sine Voltage Generator/Inverse Clarke Transform/Two phase input'
 * '<S37>'  : 'mcb_open_loop_control_nucleo_f401re/Open Loop Control/Control_System/VabcCalc/3-Phase Sine Voltage Generator/Inverse Park Transform/Two inputs CRL'
 * '<S38>'  : 'mcb_open_loop_control_nucleo_f401re/Open Loop Control/Control_System/VabcCalc/3-Phase Sine Voltage Generator/Inverse Park Transform/Two inputs CRL/Switch_Axis'
 * '<S39>'  : 'mcb_open_loop_control_nucleo_f401re/Open Loop Control/Control_System/VabcCalc/3-Phase Sine Voltage Generator/Sine-Cosine Lookup/Sine-Cosine Lookup'
 * '<S40>'  : 'mcb_open_loop_control_nucleo_f401re/Open Loop Control/Control_System/VabcCalc/3-Phase Sine Voltage Generator/Sine-Cosine Lookup/Sine-Cosine Lookup/Interpolation'
 * '<S41>'  : 'mcb_open_loop_control_nucleo_f401re/Open Loop Control/Control_System/VabcCalc/3-Phase Sine Voltage Generator/Sine-Cosine Lookup/Sine-Cosine Lookup/WrapUp'
 * '<S42>'  : 'mcb_open_loop_control_nucleo_f401re/Open Loop Control/Control_System/VabcCalc/3-Phase Sine Voltage Generator/Sine-Cosine Lookup/Sine-Cosine Lookup/datatype'
 * '<S43>'  : 'mcb_open_loop_control_nucleo_f401re/Open Loop Control/Control_System/VabcCalc/3-Phase Sine Voltage Generator/Sine-Cosine Lookup/Sine-Cosine Lookup/WrapUp/Compare To Zero'
 * '<S44>'  : 'mcb_open_loop_control_nucleo_f401re/Open Loop Control/Control_System/VabcCalc/3-Phase Sine Voltage Generator/Sine-Cosine Lookup/Sine-Cosine Lookup/WrapUp/If Action Subsystem'
 * '<S45>'  : 'mcb_open_loop_control_nucleo_f401re/Open Loop Control/Control_System/VabcCalc/3-Phase Sine Voltage Generator/Sine-Cosine Lookup/Sine-Cosine Lookup/WrapUp/If Action Subsystem1'
 * '<S46>'  : 'mcb_open_loop_control_nucleo_f401re/Open Loop Control/Control_System/VabcCalc/3-Phase Sine Voltage Generator/Sine-Cosine Lookup/Sine-Cosine Lookup/datatype/datatype no change'
 * '<S47>'  : 'mcb_open_loop_control_nucleo_f401re/Open Loop Control/Control_System/VabcCalc/Position Generator/Accumulate'
 * '<S48>'  : 'mcb_open_loop_control_nucleo_f401re/Open Loop Control/Control_System/VabcCalc/Position Generator/Accumulate/Subsystem'
 * '<S49>'  : 'mcb_open_loop_control_nucleo_f401re/Safety code generator/Initialize Function'
 */
#endif                              /* mcb_open_loop_control_nucleo_f401re_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
