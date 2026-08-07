/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *             File:  Os_Cfg.h
 *           Config:  last364.dpa
 *      ECU-Project:  last364
 *
 *        Generator:  MICROSAR RTE Generator Version 4.29.0
 *                    RTE Core Version 1.29.0
 *          License:  CBD2200508
 *
 *      Description:  Os definitions
 *********************************************************************************************************************/

#ifndef _OS_CFG_H_
# define _OS_CFG_H_

/* Os definitions */

/* Tasks */
# define BswCore1Task (0U)
# define Default_Appl_Init_Task (1U)
# define Default_Appl_Task (2U)
# define Default_BSW_ASync_Task_10ms (3U)
# define Default_MotorInitTask (4U)
# define MotorTask (5U)

/* Counters */
# define SystemTimer (0U)
# define SystemTimer1 (1U)

/* Alarms */
# define Rte_Al_TE2_EcuM_EcuM_MainFunction (0U)
# define Rte_Al_TE_StartApp_StartApp_Cyclic1000ms (1U)
# define Rte_Al_TE_StartApp_StartApp_Cyclic10ms (2U)
# define Rte_Al_TE_StartApp_StartApp_Cyclic1ms (3U)
# define Rte_Al_TE_StartApp_StartApp_Cyclic250ms (4U)
# define Rte_Al_TE2_Default_BSW_ASync_Task_10ms_0_10ms (5U)
# define Rte_Al_TE2_Default_BSW_ASync_Task_10ms_0_20ms (6U)
# define Rte_Al_TE2_Default_BSW_ASync_Task_10ms_0_5ms (7U)
# define Rte_Al_TE_MotorTask_0_1ms (8U)

/* Events */
# define Rte_Ev_Cyclic2_Default_BSW_ASync_Task_10ms_0_10ms (0x01ULL)
# define Rte_Ev_Cyclic2_Default_BSW_ASync_Task_10ms_0_20ms (0x02ULL)
# define Rte_Ev_Cyclic2_Default_BSW_ASync_Task_10ms_0_5ms (0x04ULL)
# define Rte_Ev_Cyclic_MotorTask_0_1ms (0x01ULL)
# define Rte_Ev_Run_MotorCdd_AdcSampleReady_Rp_AdcSampleReady_AdcSampleReady (0x02ULL)
# define Rte_Ev_Run_StartApp_StartApp_Cyclic1000ms (0x01ULL)
# define Rte_Ev_Run_StartApp_StartApp_Cyclic10ms (0x02ULL)
# define Rte_Ev_Run_StartApp_StartApp_Cyclic1ms (0x04ULL)
# define Rte_Ev_Run_StartApp_StartApp_Cyclic250ms (0x08ULL)

/* Spinlocks */

/* Resources */

/* ScheduleTables */

/* Cores */
# define OS_CORE_ID_0 (0U)
# define OS_CORE_ID_1 (1U)
# include "usrostyp.h"

/* Trusted Functions */


#endif /* _OS_CFG_H_ */
