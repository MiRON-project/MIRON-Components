################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../smartsoft/src/BatteryPushServiceInHandlerBatteryCharging.cc \
../smartsoft/src/BatteryPushServiceInHandlerBatteryLevel.cc \
../smartsoft/src/CompHandler.cc \
../smartsoft/src/EstimateActivity.cc \
../smartsoft/src/EstimateListener.cc \
../smartsoft/src/ParameterStateStruct.cc \
../smartsoft/src/QoSMetricProviderCore.cc \
../smartsoft/src/SimpleBumperServiceInHandlerRobotBump.cc \
../smartsoft/src/SimpleObjectBumpPushServiceInHandlerObjectBump.cc \
../smartsoft/src/SimplePeopleBumpPushServiceInHandlerPersonBump.cc \
../smartsoft/src/SimplePeoplePushServiceInHandlerPeopleInRoom.cc \
../smartsoft/src/SimpleWantedPeoplePushServiceInHandlerWantedPersonFound.cc \
../smartsoft/src/SmartStateChangeHandler.cc 

CC_DEPS += \
./smartsoft/src/BatteryPushServiceInHandlerBatteryCharging.d \
./smartsoft/src/BatteryPushServiceInHandlerBatteryLevel.d \
./smartsoft/src/CompHandler.d \
./smartsoft/src/EstimateActivity.d \
./smartsoft/src/EstimateListener.d \
./smartsoft/src/ParameterStateStruct.d \
./smartsoft/src/QoSMetricProviderCore.d \
./smartsoft/src/SimpleBumperServiceInHandlerRobotBump.d \
./smartsoft/src/SimpleObjectBumpPushServiceInHandlerObjectBump.d \
./smartsoft/src/SimplePeopleBumpPushServiceInHandlerPersonBump.d \
./smartsoft/src/SimplePeoplePushServiceInHandlerPeopleInRoom.d \
./smartsoft/src/SimpleWantedPeoplePushServiceInHandlerWantedPersonFound.d \
./smartsoft/src/SmartStateChangeHandler.d 

OBJS += \
./smartsoft/src/BatteryPushServiceInHandlerBatteryCharging.o \
./smartsoft/src/BatteryPushServiceInHandlerBatteryLevel.o \
./smartsoft/src/CompHandler.o \
./smartsoft/src/EstimateActivity.o \
./smartsoft/src/EstimateListener.o \
./smartsoft/src/ParameterStateStruct.o \
./smartsoft/src/QoSMetricProviderCore.o \
./smartsoft/src/SimpleBumperServiceInHandlerRobotBump.o \
./smartsoft/src/SimpleObjectBumpPushServiceInHandlerObjectBump.o \
./smartsoft/src/SimplePeopleBumpPushServiceInHandlerPersonBump.o \
./smartsoft/src/SimplePeoplePushServiceInHandlerPeopleInRoom.o \
./smartsoft/src/SimpleWantedPeoplePushServiceInHandlerWantedPersonFound.o \
./smartsoft/src/SmartStateChangeHandler.o 


# Each subdirectory must supply rules for building sources it contributes
smartsoft/src/%.o: ../smartsoft/src/%.cc
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/include/boost -I../ -I"/opt/ACE_wrappers" -I"/home/renan/SOFTWARE/smartsoft/include" -I"/home/renan/SOFTWARE/smartsoft/include/SmartSoft_CD_API" -I"/home/renan/SOFTWARE/smartsoft/include/AceSmartSoftKernel" -I"/home/renan/SOFTWARE/smartsoft-ace-mdsd-v3/repos/ComponentRepository/MIRON-Components/QoSMetricProvider/smartsoft/src" -I"/home/renan/SOFTWARE/smartsoft-ace-mdsd-v3/repos/ComponentRepository/MIRON-Components/QoSMetricProvider/smartsoft/src-gen" -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


