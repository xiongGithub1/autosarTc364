/**********************************************************************************************************************
 * Appl_BringupCfg.h - temporary SPI bring-up switches (not DaVinci-generated)
 *
 * APPL_SPI9180_BRINGUP = 1: StartApp only runs TLE9180 SPI test; motor paths compiled out.
 * APPL_SPI9180_BRINGUP = 0: normal application (MotorCdd / MotorControll active).
 **********************************************************************************************************************/
#ifndef APPL_BRINGUPCFG_H
#define APPL_BRINGUPCFG_H

#ifndef APPL_SPI9180_BRINGUP
#define APPL_SPI9180_BRINGUP  (0)
#endif

#endif /* APPL_BRINGUPCFG_H */
