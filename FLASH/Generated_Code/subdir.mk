################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Generated_Code/AD1.c" \
"../Generated_Code/AD2.c" \
"../Generated_Code/AdcLdd1.c" \
"../Generated_Code/AdcLdd2.c" \
"../Generated_Code/BitIoLdd1.c" \
"../Generated_Code/Cpu.c" \
"../Generated_Code/INT_FTM0.c" \
"../Generated_Code/Led_Select.c" \
"../Generated_Code/PDB0.c" \
"../Generated_Code/PE_LDD.c" \
"../Generated_Code/VREF.c" \
"../Generated_Code/Vectors.c" \

C_SRCS += \
../Generated_Code/AD1.c \
../Generated_Code/AD2.c \
../Generated_Code/AdcLdd1.c \
../Generated_Code/AdcLdd2.c \
../Generated_Code/BitIoLdd1.c \
../Generated_Code/Cpu.c \
../Generated_Code/INT_FTM0.c \
../Generated_Code/Led_Select.c \
../Generated_Code/PDB0.c \
../Generated_Code/PE_LDD.c \
../Generated_Code/VREF.c \
../Generated_Code/Vectors.c \

OBJS += \
./Generated_Code/AD1.o \
./Generated_Code/AD2.o \
./Generated_Code/AdcLdd1.o \
./Generated_Code/AdcLdd2.o \
./Generated_Code/BitIoLdd1.o \
./Generated_Code/Cpu.o \
./Generated_Code/INT_FTM0.o \
./Generated_Code/Led_Select.o \
./Generated_Code/PDB0.o \
./Generated_Code/PE_LDD.o \
./Generated_Code/VREF.o \
./Generated_Code/Vectors.o \

C_DEPS += \
./Generated_Code/AD1.d \
./Generated_Code/AD2.d \
./Generated_Code/AdcLdd1.d \
./Generated_Code/AdcLdd2.d \
./Generated_Code/BitIoLdd1.d \
./Generated_Code/Cpu.d \
./Generated_Code/INT_FTM0.d \
./Generated_Code/Led_Select.d \
./Generated_Code/PDB0.d \
./Generated_Code/PE_LDD.d \
./Generated_Code/VREF.d \
./Generated_Code/Vectors.d \

OBJS_QUOTED += \
"./Generated_Code/AD1.o" \
"./Generated_Code/AD2.o" \
"./Generated_Code/AdcLdd1.o" \
"./Generated_Code/AdcLdd2.o" \
"./Generated_Code/BitIoLdd1.o" \
"./Generated_Code/Cpu.o" \
"./Generated_Code/INT_FTM0.o" \
"./Generated_Code/Led_Select.o" \
"./Generated_Code/PDB0.o" \
"./Generated_Code/PE_LDD.o" \
"./Generated_Code/VREF.o" \
"./Generated_Code/Vectors.o" \

C_DEPS_QUOTED += \
"./Generated_Code/AD1.d" \
"./Generated_Code/AD2.d" \
"./Generated_Code/AdcLdd1.d" \
"./Generated_Code/AdcLdd2.d" \
"./Generated_Code/BitIoLdd1.d" \
"./Generated_Code/Cpu.d" \
"./Generated_Code/INT_FTM0.d" \
"./Generated_Code/Led_Select.d" \
"./Generated_Code/PDB0.d" \
"./Generated_Code/PE_LDD.d" \
"./Generated_Code/VREF.d" \
"./Generated_Code/Vectors.d" \

OBJS_OS_FORMAT += \
./Generated_Code/AD1.o \
./Generated_Code/AD2.o \
./Generated_Code/AdcLdd1.o \
./Generated_Code/AdcLdd2.o \
./Generated_Code/BitIoLdd1.o \
./Generated_Code/Cpu.o \
./Generated_Code/INT_FTM0.o \
./Generated_Code/Led_Select.o \
./Generated_Code/PDB0.o \
./Generated_Code/PE_LDD.o \
./Generated_Code/VREF.o \
./Generated_Code/Vectors.o \


# Each subdirectory must supply rules for building sources it contributes
Generated_Code/AD1.o: ../Generated_Code/AD1.c
	@echo 'Building file: $<'
	@echo 'Executing target #10 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/AD1.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/AD1.o"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/AD2.o: ../Generated_Code/AD2.c
	@echo 'Building file: $<'
	@echo 'Executing target #11 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/AD2.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/AD2.o"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/AdcLdd1.o: ../Generated_Code/AdcLdd1.c
	@echo 'Building file: $<'
	@echo 'Executing target #12 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/AdcLdd1.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/AdcLdd1.o"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/AdcLdd2.o: ../Generated_Code/AdcLdd2.c
	@echo 'Building file: $<'
	@echo 'Executing target #13 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/AdcLdd2.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/AdcLdd2.o"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/BitIoLdd1.o: ../Generated_Code/BitIoLdd1.c
	@echo 'Building file: $<'
	@echo 'Executing target #14 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/BitIoLdd1.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/BitIoLdd1.o"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/Cpu.o: ../Generated_Code/Cpu.c
	@echo 'Building file: $<'
	@echo 'Executing target #15 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/Cpu.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/Cpu.o"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/INT_FTM0.o: ../Generated_Code/INT_FTM0.c
	@echo 'Building file: $<'
	@echo 'Executing target #16 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/INT_FTM0.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/INT_FTM0.o"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/Led_Select.o: ../Generated_Code/Led_Select.c
	@echo 'Building file: $<'
	@echo 'Executing target #17 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/Led_Select.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/Led_Select.o"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/PDB0.o: ../Generated_Code/PDB0.c
	@echo 'Building file: $<'
	@echo 'Executing target #18 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/PDB0.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/PDB0.o"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/PE_LDD.o: ../Generated_Code/PE_LDD.c
	@echo 'Building file: $<'
	@echo 'Executing target #19 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/PE_LDD.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/PE_LDD.o"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/VREF.o: ../Generated_Code/VREF.c
	@echo 'Building file: $<'
	@echo 'Executing target #20 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/VREF.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/VREF.o"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/Vectors.o: ../Generated_Code/Vectors.c
	@echo 'Building file: $<'
	@echo 'Executing target #21 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/Vectors.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/Vectors.o"
	@echo 'Finished building: $<'
	@echo ' '


