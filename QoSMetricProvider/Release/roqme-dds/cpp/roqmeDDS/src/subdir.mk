################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../roqme-dds/cpp/roqmeDDS/src/RoqmeDDSException.cpp \
../roqme-dds/cpp/roqmeDDS/src/RoqmeDDSManager.cpp \
../roqme-dds/cpp/roqmeDDS/src/RoqmeDataReader.cpp \
../roqme-dds/cpp/roqmeDDS/src/RoqmeDataWriter.cpp \
../roqme-dds/cpp/roqmeDDS/src/RoqmeReaderImpl.cpp \
../roqme-dds/cpp/roqmeDDS/src/RoqmeTemplateImpl.cpp \
../roqme-dds/cpp/roqmeDDS/src/RoqmeWriterImpl.cpp 

OBJS += \
./roqme-dds/cpp/roqmeDDS/src/RoqmeDDSException.o \
./roqme-dds/cpp/roqmeDDS/src/RoqmeDDSManager.o \
./roqme-dds/cpp/roqmeDDS/src/RoqmeDataReader.o \
./roqme-dds/cpp/roqmeDDS/src/RoqmeDataWriter.o \
./roqme-dds/cpp/roqmeDDS/src/RoqmeReaderImpl.o \
./roqme-dds/cpp/roqmeDDS/src/RoqmeTemplateImpl.o \
./roqme-dds/cpp/roqmeDDS/src/RoqmeWriterImpl.o 

CPP_DEPS += \
./roqme-dds/cpp/roqmeDDS/src/RoqmeDDSException.d \
./roqme-dds/cpp/roqmeDDS/src/RoqmeDDSManager.d \
./roqme-dds/cpp/roqmeDDS/src/RoqmeDataReader.d \
./roqme-dds/cpp/roqmeDDS/src/RoqmeDataWriter.d \
./roqme-dds/cpp/roqmeDDS/src/RoqmeReaderImpl.d \
./roqme-dds/cpp/roqmeDDS/src/RoqmeTemplateImpl.d \
./roqme-dds/cpp/roqmeDDS/src/RoqmeWriterImpl.d 


# Each subdirectory must supply rules for building sources it contributes
roqme-dds/cpp/roqmeDDS/src/%.o: ../roqme-dds/cpp/roqmeDDS/src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/include/boost -I../ -I"/opt/ACE_wrappers" -I"/home/renan/SOFTWARE/smartsoft/include" -I"/home/renan/SOFTWARE/smartsoft/include/SmartSoft_CD_API" -I"/home/renan/SOFTWARE/smartsoft/include/AceSmartSoftKernel" -I"/home/renan/SOFTWARE/SmartMDSD-Toolchain-v3.12/QoSMetricProvider/smartsoft/src" -I"/home/renan/SOFTWARE/SmartMDSD-Toolchain-v3.12/QoSMetricProvider/smartsoft/src-gen" -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


