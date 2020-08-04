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

######################################
##  Please do not modify this file  ##
######################################

### Webot's controller libraries importation into SmartMDSD
export WEBOTS_LIBRARY=$(realpath --relative-to=$SMART_ROOT_ACE/lib $WEBOTS_HOME/lib/controller)
DEPLOY_LIBRARIES="
$WEBOTS_LIBRARY/libController.so
$WEBOTS_LIBRARY/libCppController.so
"
