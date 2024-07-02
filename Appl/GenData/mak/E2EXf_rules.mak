# *********************************************************************************************************************
#   COPYRIGHT
#   -------------------------------------------------------------------------------------------------------------------
#   \verbatim
# 
#                 This software is copyright protected and proprietary to Vector Informatik GmbH.
#                 Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
#                 All other rights remain with Vector Informatik GmbH.
#   \endverbatim
#   -------------------------------------------------------------------------------------------------------------------
#   FILE DESCRIPTION
#   -------------------------------------------------------------------------------------------------------------------
#              File:  E2EXf_rules.mak
#            Config:  last364.dpa
#       ECU-Project:  last364
# 
#         Generator:  MICROSAR E2EXf Generator Version 1.16.0
#                     RTE Core Version 1.29.0
#           License:  CBD2200508
# 
#       Description:  GNU MAKEFILE (rules)
# *********************************************************************************************************************


LIBRARIES_TO_BUILD           += E2EXf
E2EXf_FILES                  += E2EXf$(BSW_SRC_DIR)\E2EXf.c

CC_FILES_TO_BUILD            += E2EXf$(BSW_SRC_DIR)\E2EXf.c

GENERATED_SOURCE_FILES       += $(GENDATA_DIR)\E2EXf_LCfg.c
