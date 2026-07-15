/**********************************************************************************************************************
 * Appl_BringupCfg.h - temporary SPI / sensor bring-up switches (not DaVinci-generated)
 *
 * HOW TO USE
 *   APPL_SPI_BRINGUP_TEST = 1  -> StartApp runs TestFiles tests; motor FOC/Controll OFF
 *   APPL_SPI_BRINGUP_TEST = 0  -> normal motor path ON; leave TestFiles call sites unused
 *
 * Per-device (only effective when APPL_SPI_BRINGUP_TEST == 1):
 *   APPL_TLE9180_TEST_EN / APPL_TLE5012_TEST_EN
 *
 * AFTER BRING-UP DONE
 *   1) Set APPL_SPI_BRINGUP_TEST to 0
 *   2) Delete Appl/Source/TestFiles/tle9180_test.* and tle5012_test.*
 *   3) Remove #include / #if bring-up blocks from StartApp.c
 **********************************************************************************************************************/
#ifndef APPL_BRINGUPCFG_H
#define APPL_BRINGUPCFG_H

/* 1 = SPI sensor test mode (motor gated off); 0 = enable motor control */
#ifndef APPL_SPI_BRINGUP_TEST
#define APPL_SPI_BRINGUP_TEST   (1)
#endif

/* 9180 alone already OK 鈥� now isolate 5012 (QSPI2). */
#ifndef APPL_TLE9180_TEST_EN
#define APPL_TLE9180_TEST_EN    (1)
#endif

#ifndef APPL_TLE5012_TEST_EN
#define APPL_TLE5012_TEST_EN    (1)
#endif

/* Legacy alias used by MotorCdd / MotorControll / MotorCdd_Adc */
#ifndef APPL_SPI9180_BRINGUP
#define APPL_SPI9180_BRINGUP    (APPL_SPI_BRINGUP_TEST)
#endif

#endif /* APPL_BRINGUPCFG_H */
