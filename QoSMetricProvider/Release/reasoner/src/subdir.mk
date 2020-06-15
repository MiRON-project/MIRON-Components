################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../reasoner/src/ConfigurationParams.cpp \
../reasoner/src/DDSConnRoqmeReasoner.cpp \
../reasoner/src/FilteringVarElimination.cpp \
../reasoner/src/InferenceEngineFactory.cpp \
../reasoner/src/RoqmeReasoner.cpp \
../reasoner/src/domain.cpp \
../reasoner/src/factor.cpp \
../reasoner/src/io.cpp \
../reasoner/src/main.cpp \
../reasoner/src/variable.cpp 

OBJS += \
./reasoner/src/ConfigurationParams.o \
./reasoner/src/DDSConnRoqmeReasoner.o \
./reasoner/src/FilteringVarElimination.o \
./reasoner/src/InferenceEngineFactory.o \
./reasoner/src/RoqmeReasoner.o \
./reasoner/src/domain.o \
./reasoner/src/factor.o \
./reasoner/src/io.o \
./reasoner/src/main.o \
./reasoner/src/variable.o 

CPP_DEPS += \
./reasoner/src/ConfigurationParams.d \
./reasoner/src/DDSConnRoqmeReasoner.d \
./reasoner/src/FilteringVarElimination.d \
./reasoner/src/InferenceEngineFactory.d \
./reasoner/src/RoqmeReasoner.d \
./reasoner/src/domain.d \
./reasoner/src/factor.d \
./reasoner/src/io.d \
./reasoner/src/main.d \
./reasoner/src/variable.d 


# Each subdirectory must supply rules for building sources it contributes
reasoner/src/%.o: ../reasoner/src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/include/boost -I../ -I"/opt/ACE_wrappers" -I"/home/renan/SOFTWARE/smartsoft/include" -I"/home/renan/SOFTWARE/smartsoft/include/SmartSoft_CD_API" -I"/home/renan/SOFTWARE/smartsoft/include/AceSmartSoftKernel" -I"/home/renan/SOFTWARE/SmartMDSD-Toolchain-v3.12/QoSMetricProvider/smartsoft/src" -I"/home/renan/SOFTWARE/SmartMDSD-Toolchain-v3.12/QoSMetricProvider/smartsoft/src-gen" -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


