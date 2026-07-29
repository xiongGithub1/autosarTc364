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
# define Default_Appl_Init_Task (0U)
# define Default_Appl_Task (1U)
# define Default_BSW_ASync_Task (2U)
# define MotorTask (3U)

/* Counters */
# define SystemTimer (0U)

/* Alarms */
# define Rte_Al_TE_StartApp_StartApp_Cyclic1000ms (0U)
# define Rte_Al_TE_StartApp_StartApp_Cyclic10ms (1U)
# define Rte_Al_TE_StartApp_StartApp_Cyclic1ms (2U)
# define Rte_Al_TE_StartApp_StartApp_Cyclic250ms (3U)
# define Rte_Al_TE2_Default_BSW_ASync_Task_0_10ms (4U)
# define Rte_Al_TE2_Default_BSW_ASync_Task_0_20ms (5U)
# define Rte_Al_TE_Com_Com_MainFunctionTx_ComMainFunctionTx (6U)
# define Rte_Al_TE_MotorCdd_MotorCDDMainFunction (7U)
# define Rte_Al_TE_MotorControll_MotorControll_MainFunction (8U)

/* Events */
# define Rte_Ev_Cyclic2_Default_BSW_ASync_Task_0_10ms (0x01ULL)
# define Rte_Ev_Cyclic2_Default_BSW_ASync_Task_0_20ms (0x02ULL)
# define Rte_Ev_Run_Com_Com_MainFunctionTx_ComMainFunctionTx (0x04ULL)
# define Rte_Ev_Run_MotorCdd_AdcSampleReady_Rp_AdcSampleReady_AdcSampleReady (0x01ULL)
# define Rte_Ev_Run_MotorCdd_MotorCDDMainFunction (0x02ULL)
# define Rte_Ev_Run_MotorControll_MotorControll_MainFunction (0x04ULL)
# define Rte_Ev_Run_StartApp_StartApp_Cyclic1000ms (0x01ULL)
# define Rte_Ev_Run_StartApp_StartApp_Cyclic10ms (0x02ULL)
# define Rte_Ev_Run_StartApp_StartApp_Cyclic1ms (0x04ULL)
# define Rte_Ev_Run_StartApp_StartApp_Cyclic250ms (0x08ULL)

/* Spinlocks */

/* Resources */

/* ScheduleTables */

/* Cores */

/* Trusted Functions */


#endif /* _OS_CFG_H_ */
