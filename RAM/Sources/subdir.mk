################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/Events.c" \
"../Sources/Main_App.c" \
"../Sources/NirsConfig.c" \
"../Sources/ProcessorExpert.c" \
"../Sources/SensorMeasurement.c" \
"../Sources/SoftwareTimers.c" \
"../Sources/Timers.c" \

C_SRCS += \
../Sources/Events.c \
../Sources/Main_App.c \
../Sources/NirsConfig.c \
../Sources/ProcessorExpert.c \
../Sources/SensorMeasurement.c \
../Sources/SoftwareTimers.c \
../Sources/Timers.c \

OBJS += \
./Sources/Events.o \
./Sources/Main_App.o \
./Sources/NirsConfig.o \
./Sources/ProcessorExpert.o \
./Sources/SensorMeasurement.o \
./Sources/SoftwareTimers.o \
./Sources/Timers.o \

C_DEPS += \
./Sources/Events.d \
./Sources/Main_App.d \
./Sources/NirsConfig.d \
./Sources/ProcessorExpert.d \
./Sources/SensorMeasurement.d \
./Sources/SoftwareTimers.d \
./Sources/Timers.d \

OBJS_QUOTED += \
"./Sources/Events.o" \
"./Sources/Main_App.o" \
"./Sources/NirsConfig.o" \
"./Sources/ProcessorExpert.o" \
"./Sources/SensorMeasurement.o" \
"./Sources/SoftwareTimers.o" \
"./Sources/Timers.o" \

C_DEPS_QUOTED += \
"./Sources/Events.d" \
"./Sources/Main_App.d" \
"./Sources/NirsConfig.d" \
"./Sources/ProcessorExpert.d" \
"./Sources/SensorMeasurement.d" \
"./Sources/SoftwareTimers.d" \
"./Sources/Timers.d" \

OBJS_OS_FORMAT += \
./Sources/Events.o \
./Sources/Main_App.o \
./Sources/NirsConfig.o \
./Sources/ProcessorExpert.o \
./Sources/SensorMeasurement.o \
./Sources/SoftwareTimers.o \
./Sources/Timers.o \


# Each subdirectory must supply rules for building sources it contributes
Sources/Events.o: ../Sources/Events.c
	@echo 'Building file: $<'
	@echo 'Executing target #1 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/Events.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/Events.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/Main_App.o: ../Sources/Main_App.c
	@echo 'Building file: $<'
	@echo 'Executing target #2 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/Main_App.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/Main_App.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/NirsConfig.o: ../Sources/NirsConfig.c
	@echo 'Building file: $<'
	@echo 'Executing target #3 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/NirsConfig.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/NirsConfig.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/ProcessorExpert.o: ../Sources/ProcessorExpert.c
	@echo 'Building file: $<'
	@echo 'Executing target #4 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/ProcessorExpert.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/ProcessorExpert.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/SensorMeasurement.o: ../Sources/SensorMeasurement.c
	@echo 'Building file: $<'
	@echo 'Executing target #5 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/SensorMeasurement.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/SensorMeasurement.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/SoftwareTimers.o: ../Sources/SoftwareTimers.c
	@echo 'Building file: $<'
	@echo 'Executing target #6 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/SoftwareTimers.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/SoftwareTimers.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/Timers.o: ../Sources/Timers.c
	@echo 'Building file: $<'
	@echo 'Executing target #7 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/Timers.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/Timers.o"
	@echo 'Finished building: $<'
	@echo ' '


