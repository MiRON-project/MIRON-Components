################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../smartsoft/src/BatteryPushServiceInHandlerBatteryCharging.cc \
../smartsoft/src/BatteryPushServiceInHandlerBatteryLevel.cc \
../smartsoft/src/BumperEventServiceInHandlerRobotBump.cc \
../smartsoft/src/CompHandler.cc \
../smartsoft/src/EstimateActivity.cc \
../smartsoft/src/EstimateListener.cc \
../smartsoft/src/ObjectEventBumpInHandlerObjectBump.cc \
../smartsoft/src/ParameterStateStruct.cc \
../smartsoft/src/PeopleEventBumpInHandlerPersonBump.cc \
../smartsoft/src/PeopleEventServiceInHandlerPeopleInRoom.cc \
../smartsoft/src/QoSMetricProviderCore.cc \
../smartsoft/src/SmartStateChangeHandler.cc \
../smartsoft/src/WantedPersonEventInHandlerWantedPersonFound.cc 

CC_DEPS += \
./smartsoft/src/BatteryPushServiceInHandlerBatteryCharging.d \
./smartsoft/src/BatteryPushServiceInHandlerBatteryLevel.d \
./smartsoft/src/BumperEventServiceInHandlerRobotBump.d \
./smartsoft/src/CompHandler.d \
./smartsoft/src/EstimateActivity.d \
./smartsoft/src/EstimateListener.d \
./smartsoft/src/ObjectEventBumpInHandlerObjectBump.d \
./smartsoft/src/ParameterStateStruct.d \
./smartsoft/src/PeopleEventBumpInHandlerPersonBump.d \
./smartsoft/src/PeopleEventServiceInHandlerPeopleInRoom.d \
./smartsoft/src/QoSMetricProviderCore.d \
./smartsoft/src/SmartStateChangeHandler.d \
./smartsoft/src/WantedPersonEventInHandlerWantedPersonFound.d 

OBJS += \
./smartsoft/src/BatteryPushServiceInHandlerBatteryCharging.o \
./smartsoft/src/BatteryPushServiceInHandlerBatteryLevel.o \
./smartsoft/src/BumperEventServiceInHandlerRobotBump.o \
./smartsoft/src/CompHandler.o \
./smartsoft/src/EstimateActivity.o \
./smartsoft/src/EstimateListener.o \
./smartsoft/src/ObjectEventBumpInHandlerObjectBump.o \
./smartsoft/src/ParameterStateStruct.o \
./smartsoft/src/PeopleEventBumpInHandlerPersonBump.o \
./smartsoft/src/PeopleEventServiceInHandlerPeopleInRoom.o \
./smartsoft/src/QoSMetricProviderCore.o \
./smartsoft/src/SmartStateChangeHandler.o \
./smartsoft/src/WantedPersonEventInHandlerWantedPersonFound.o 


# Each subdirectory must supply rules for building sources it contributes
smartsoft/src/%.o: ../smartsoft/src/%.cc
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/include/boost -I../ -I"/opt/ACE_wrappers" -I"/home/renan/SOFTWARE/smartsoft/include" -I"/home/renan/SOFTWARE/smartsoft/include/SmartSoft_CD_API" -I"/home/renan/SOFTWARE/smartsoft/include/AceSmartSoftKernel" -I"/home/renan/SOFTWARE/SmartMDSD-Toolchain-v3.12/QoSMetricProvider/smartsoft/src" -I"/home/renan/SOFTWARE/SmartMDSD-Toolchain-v3.12/QoSMetricProvider/smartsoft/src-gen" -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


