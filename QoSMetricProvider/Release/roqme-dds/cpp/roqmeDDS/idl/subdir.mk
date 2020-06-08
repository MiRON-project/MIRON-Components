################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../roqme-dds/cpp/roqmeDDS/idl/RoqmeDDSTopics.cpp \
../roqme-dds/cpp/roqmeDDS/idl/RoqmeDDSTopicsSplDcps.cpp 

O_SRCS += \
../roqme-dds/cpp/roqmeDDS/idl/RoqmeDDSTopics.o \
../roqme-dds/cpp/roqmeDDS/idl/RoqmeDDSTopicsSplDcps.o 

OBJS += \
./roqme-dds/cpp/roqmeDDS/idl/RoqmeDDSTopics.o \
./roqme-dds/cpp/roqmeDDS/idl/RoqmeDDSTopicsSplDcps.o 

CPP_DEPS += \
./roqme-dds/cpp/roqmeDDS/idl/RoqmeDDSTopics.d \
./roqme-dds/cpp/roqmeDDS/idl/RoqmeDDSTopicsSplDcps.d 


# Each subdirectory must supply rules for building sources it contributes
roqme-dds/cpp/roqmeDDS/idl/%.o: ../roqme-dds/cpp/roqmeDDS/idl/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/include/boost -I../ -I"/opt/ACE_wrappers" -I"/home/renan/SOFTWARE/smartsoft/include" -I"/home/renan/SOFTWARE/smartsoft/include/SmartSoft_CD_API" -I"/home/renan/SOFTWARE/smartsoft/include/AceSmartSoftKernel" -I"/home/renan/SOFTWARE/smartsoft-ace-mdsd-v3/repos/ComponentRepository/MIRON-Components/QoSMetricProvider/smartsoft/src" -I"/home/renan/SOFTWARE/smartsoft-ace-mdsd-v3/repos/ComponentRepository/MIRON-Components/QoSMetricProvider/smartsoft/src-gen" -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


