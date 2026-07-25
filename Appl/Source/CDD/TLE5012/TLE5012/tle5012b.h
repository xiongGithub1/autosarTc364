/*
 * tle5012b.h - TLE5012B register access API
 */
#ifndef TLE5012B_H
#define TLE5012B_H

#include "Std_Types.h"
#include "tle5012_a.h"

#define STAT    (0x00U)
#define ACSTAT  (0x01U)
#define AVAL    (0x02U)
#define ASPD    (0x03U)
#define AREV    (0x04U)
#define FSYNC   (0x05U)
#define MOD_1   (0x06U)
#define SIL     (0x07U)
#define MOD_2   (0x08U)
#define MOD_3   (0x09U)
#define OFFX    (0x0AU)
#define OFFY    (0x0BU)
#define SYNCH   (0x0CU)
#define IFAB    (0x0DU)
#define MOD_4   (0x0EU)
#define TCO_Y   (0x0FU)
#define ADC_X   (0x10U)
#define ADC_Y   (0x11U)
#define D_MAG   (0x14U)
#define T_RAW   (0x15U)
#define IIF_CNT (0x20U)
#define T25O    (0x30U)

#define clockwise        (TRUE)
#define counterclockwise (FALSE)

#define M_PI    (3.14159265358979323846F)
#define M_TWOPI (6.28318530717958647692F)

typedef struct
{
  float32 Angle;
  float32 Original_Angle;
  float32 anglePi;
  float32 AngleSpeed;
  float32 AngleSpeedFilter;
  float32 RPM;
  boolean Direction;
  uint16 ANG_BASE;
  float32 Temperature;
  float32 DisTimer;
  uint8 polePairs;
  uint16 SafetyBit;
} Tle5012;

extern unsigned char TableCRC[256];

void tle5012b_delay_us(uint32 delayUs);
void tle5012b_write_fast(uint16 address, uint16 data);
uint16 tle5012b_read_fast(uint8 address);
void tle5012b_read_AngleSpeed(Tle5012 *tle5012);
void tle5012b_read_angle(Tle5012 *tle5012);
boolean tle5012b_ChangeAngleDirection(boolean Dir);
void tle5012b_ChangeAngleBasic(Tle5012 *tle5012, uint16 angleBasic);
void tle5012b_read_all(void);
unsigned char CRC8(unsigned char *message, unsigned char Bytelength, unsigned char *TableCRC);

#endif /* TLE5012B_H */
