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
#              File:  E2EXf_defs.mak
#            Config:  last364.dpa
#       ECU-Project:  last364
# 
#         Generator:  MICROSAR E2EXf Generator Version 1.16.0
#                     RTE Core Version 1.29.0
#           License:  CBD2200508
# 
#       Description:  GNU MAKEFILE (defines)
# *********************************************************************************************************************


E2EXF_CORE_PATH        = E2EXf$(BSW_SRC_DIR)\
E2EXF_OUTPUT_PATH      = $(GENDATA_DIR)

#----------------------------------------------------------------------------------------------------------------------
# MakeSupport usually includes all header-files which were in the same
# directory as the source-files automatically, but to ensure that the
# Asr-Makefiles will also work with other Basic-Make-Packages,
# it is necessary to define all include directories for this Module
#----------------------------------------------------------------------------------------------------------------------
CC_INCLUDE_PATH     += E2EXf$(BSW_SRC_DIR) $(GENDATA_DIR)
