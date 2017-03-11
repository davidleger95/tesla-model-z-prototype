################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Sources/components/cli.c \
../Sources/components/drive.c \
../Sources/components/selectMode.c \
../Sources/components/setLightRange.c 

OBJS += \
./Sources/components/cli.o \
./Sources/components/drive.o \
./Sources/components/selectMode.o \
./Sources/components/setLightRange.o 

C_DEPS += \
./Sources/components/cli.d \
./Sources/components/drive.d \
./Sources/components/selectMode.d \
./Sources/components/setLightRange.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/components/%.o: ../Sources/components/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall  -g3 -D"CPU_MK64FN1M0VMD12" -I"../Sources" -I"../Project_Settings/Startup_Code" -I"../SDK/platform/CMSIS/Include" -I"../SDK/platform/devices" -I"../SDK/platform/devices/MK64F12/include" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


