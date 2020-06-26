CMAKE_MINIMUM_REQUIRED(VERSION 3.0)

FIND_FILE(SMART_MACROS SmartMacros2.cmake PATHS $ENV{SMART_ROOT_ACE}/CMakeMacros /opt/smartSoftAce/CMakeMacros)
INCLUDE(${SMART_MACROS})
INCLUDE_DIRECTORIES(${WEBOTS_HOME}/src)

SMART_ADD_PACKAGE(ComponentSkillInterface)
SMART_ADD_PACKAGE(ComponentWebotsObjectRecognition)
SMART_ADD_PACKAGE(ComponentWebotsPersonRecognition)
SMART_ADD_PACKAGE(ComponentWebotsRobot)
SMART_ADD_PACKAGE(QoSMetricProvider)