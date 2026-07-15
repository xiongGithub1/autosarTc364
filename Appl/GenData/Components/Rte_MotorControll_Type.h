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
 *             File:  Rte_MotorControll_Type.h
 *           Config:  last364.dpa
 *      ECU-Project:  last364
 *
 *        Generator:  MICROSAR RTE Generator Version 4.29.0
 *                    RTE Core Version 1.29.0
 *          License:  CBD2200508
 *
 *      Description:  Application types header file for SW-C <MotorControll>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_MOTORCONTROLL_TYPE_H
# define RTE_MOTORCONTROLL_TYPE_H

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

# include "Rte_Type.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * DataType Symbol Redefinitions
 *********************************************************************************************************************/

#  define Tle9180_ov_Fault boolean

#  define Iv_A float32

#  define OriginAngle uint16

#  define MotorMd uint8

# endif /* RTE_CORE */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_MOTORCONTROLL_TYPE_H */
