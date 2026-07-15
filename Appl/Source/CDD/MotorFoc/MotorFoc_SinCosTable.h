/**********************************************************************************************************************
 * MotorFoc_SinCosTable.h
 * 13-bit (8192) sin/cos lookup — same table as TC364_IPB_EB PmsmFoc MidSys.
 * Table length = 8192 + 2048 so cos(θ) = sin(θ+π/2) without wrap.
 **********************************************************************************************************************/
#ifndef MOTORFOC_SINCOSTABLE_H
#define MOTORFOC_SINCOSTABLE_H

#include "Std_Types.h"

/* Full electrical circle resolution (matches TLE5012 ANG_VAL % 8192). */
#define MOTORFOC_SINCOS_RESOLUTION_BITS   (13U)
#define MOTORFOC_SINCOS_TABLE_SIZE        (8192U)
#define MOTORFOC_SINCOS_IDX_MASK          (MOTORFOC_SINCOS_TABLE_SIZE - 1U)
#define MOTORFOC_SINCOS_COS_OFFSET        (MOTORFOC_SINCOS_TABLE_SIZE / 4U) /* 2048 = π/2 */
#define MOTORFOC_SINCOS_STORAGE_SIZE      (MOTORFOC_SINCOS_TABLE_SIZE + MOTORFOC_SINCOS_COS_OFFSET)
/* rad → index: 8192 / (2*π) */
#define MOTORFOC_SINCOS_RAD_TO_IDX        (1303.7972938672417F)

extern const float MotorFoc_SinCosTable[MOTORFOC_SINCOS_STORAGE_SIZE];

#endif /* MOTORFOC_SINCOSTABLE_H */
