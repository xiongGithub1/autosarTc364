#ifndef MOTORFOC_CURRENTLOOP_H
#define MOTORFOC_CURRENTLOOP_H

#include "MotorFoc_Types.h"

/* ---------------------------------------------------------------------------
 * Protection observation object  (UDE: watch "MotorFoc_ProtObs")
 *   cfg      : thresholds / debounce settings (runtime tunable)
 *   cnt      : debounce / blanking counters (running state)
 *   fault    : latched fault flag + snapshot at fault time
 *   peak     : running peak phase currents
 *   runCount : 10 kHz protection run counter
 * ------------------------------------------------------------------------- */

typedef struct
{
  float32 instantTripCurrentA;       /* OC1 hard trip threshold            */
  float32 maxCurrentA;               /* OC2 confirmed trip threshold       */
  float32 overCurrentTripSec;        /* OC2 sustained trip time (s)         */
  float32 overCurrentRecoverSec;     /* OC auto-recover hold time (s)       */
  float32 overCurrentRecoverHystA;   /* OC recover when |I| <= max - hyst   */
  uint8   overCurrentAutoRecover;    /* 1 = auto-clear OC faults            */
  float32 minVdcRunV;                /* UV trip threshold                  */
  float32 vdcHysteresisV;            /* UV recovery hysteresis             */
  uint16  undervoltConfirmCount;     /* UV debounce (loops)                */
  uint16  undervoltRecoverCount;     /* UV stable-bus loops before clear   */
  uint8   uvAutoRecover;             /* 1 = auto-clear UV fault            */
  uint16  startupBlankingCount;      /* startup blanking length (loops)    */
} MotorFoc_ProtCfgType;

typedef struct
{
  uint16 startupBlankingLeft;        /* remaining blanking loops           */
  uint16 undervoltCounter;           /* UV debounce counter (trip)         */
  uint16 uvRecoverCounter;           /* UV recovery counter                */
  uint32 overCurrentCounter;         /* OC2 sustained trip counter (beats)  */
  uint32 overCurrentRecoverCounter;  /* OC auto-recover counter (beats)     */
  uint8  state;                      /* CURRENTLOOP_STATE_*                */
} MotorFoc_ProtCntType;

typedef struct
{
  uint8   active;                    /* latched fault flag                 */
  uint8   reason;                    /* CURRENT_FAULT_*                    */
  uint8   clearRequest;              /* explicit clear request             */
  uint32  runCount;                  /* protection run counter at fault    */
  float32 iuA;                       /* fault snapshot                     */
  float32 ivA;
  float32 iwA;
  float32 vdcV;
  float32 idA;
  float32 iqA;
  float32 vdV;
  float32 vqV;
  uint32  pwmU;
  uint32  pwmV;
  uint32  pwmW;
} MotorFoc_ProtFaultType;

typedef struct
{
  float32 iuA;                       /* running peak phase currents        */
  float32 ivA;
  float32 iwA;
} MotorFoc_ProtPeakType;

typedef struct
{
  MotorFoc_ProtCfgType   cfg;
  MotorFoc_ProtCntType   cnt;
  MotorFoc_ProtFaultType fault;
  MotorFoc_ProtPeakType  peak;
  uint32 runCount;
} MotorFoc_ProtObsType;

extern volatile MotorFoc_ProtObsType MotorFoc_ProtObs;
/* SVPWM sector N (1..6). Low-speed Tcmp spikes often align with sector edges. */
extern volatile uint8 MotorFoc_SvpwmSector;

#define MOTORFOC_CURRENT_FAULT_NONE          (0U)
#define MOTORFOC_CURRENT_FAULT_UNDERVOLT     (1U)
#define MOTORFOC_CURRENT_FAULT_OVERCURRENT   (2U)  /* confirmed overcurrent (OC2) */
#define MOTORFOC_CURRENT_FAULT_OVERCURRENT_INST (3U) /* instantaneous overcurrent (OC1) */

#define MOTORFOC_CURRENTLOOP_STATE_IDLE      (0U)
#define MOTORFOC_CURRENTLOOP_STATE_RUN       (1U)
#define MOTORFOC_CURRENTLOOP_STATE_BLANKING  (2U)
#define MOTORFOC_CURRENTLOOP_STATE_FAULT     (3U)

void MotorFoc_CurrentLoopInit(MotorFoc_ContextType* ctx);
void MotorFoc_SetIdRef(MotorFoc_ContextType* ctx, float32 idRef);
void MotorFoc_SetIqRef(MotorFoc_ContextType* ctx, float32 iqRef);
void MotorFoc_SetAngleFromTle5012(MotorFoc_ContextType* ctx,
                                  float32 angleRaw,
                                  float32 electricalAngleRad);
void MotorFoc_UpdateCurrentFromAdc(MotorFoc_ContextType* ctx,
                                   float32 iu,
                                   float32 iv,
                                   float32 iw,
                                   float32 vdc);
void MotorFoc_UpdateRawCurrentForProtection(float32 iu,
                                             float32 iv,
                                             float32 iw);
void MotorFoc_RunCurrentLoop(MotorFoc_ContextType* ctx);
void MotorFoc_RunVoltageOpenLoop(MotorFoc_ContextType* ctx,
                                 float32 vdRef,
                                 float32 vqRef);
void MotorFoc_CurrentLoopStop(MotorFoc_ContextType* ctx);
void MotorFoc_CurrentLoopPreparePwmNeutral(MotorFoc_ContextType* ctx);
void MotorFoc_CurrentLoopClearFault(void);
void MotorFoc_CurrentLoopArmStartupBlanking(void);

#endif /* MOTORFOC_CURRENTLOOP_H */
