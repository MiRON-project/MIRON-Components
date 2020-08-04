#!/bin/bash

# Use this variable to name files that are to be deployed to the data
# instance directory of
# the component (<COMPONENT INSTANCE NAME>_data/) on the target host.
#
# Files can be relative to component project directory or absolute.
# Add one file or directory per line.
#
# Examples:
#
# DEPLOY_LIBRARIES="../bin/libMyLibrary.so"
#
# DEPLOY_COMPONENT_FILES="
# $SMART_ROOT_ACE/myFILE
# $SMART_ROOT_ACE/myFILE2
# "
export OMPL_LIBRARY=$(realpath --relative-to=$SMART_ROOT_ACE/lib $OMPL_BUILD/lib)
DEPLOY_LIBRARIES="
$OMPL_LIBRARY/libompl.so
$OMPL_LIBRARY/libompl.so.1.5.0
$OMPL_LIBRARY/libompl.so.16"
DEPLOY_COMPONENT_FILES=""
