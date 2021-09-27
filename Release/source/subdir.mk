################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../source/Assignment3_Blinkenlights.c \
../source/TSI.c \
../source/delay.c \
../source/led.c \
../source/mtb.c \
../source/semihost_hardfault.c 

OBJS += \
./source/Assignment3_Blinkenlights.o \
./source/TSI.o \
./source/delay.o \
./source/led.o \
./source/mtb.o \
./source/semihost_hardfault.o 

C_DEPS += \
./source/Assignment3_Blinkenlights.d \
./source/TSI.d \
./source/delay.d \
./source/led.d \
./source/mtb.d \
./source/semihost_hardfault.d 


# Each subdirectory must supply rules for building sources it contributes
source/%.o: ../source/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DCPU_MKL25Z128VLK4 -DCPU_MKL25Z128VLK4_cm0plus -DFSL_RTOS_BM -DSDK_OS_BAREMETAL -DSDK_DEBUGCONSOLE=0 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DNDEBUG -D__REDLIB__ -I"C:\Users\ujjai\Documents\MCUXpressoIDE_11.2.0_4120\workspace\Assignment3_Blinkenlights\board" -I"C:\Users\ujjai\Documents\MCUXpressoIDE_11.2.0_4120\workspace\Assignment3_Blinkenlights\source" -I"C:\Users\ujjai\Documents\MCUXpressoIDE_11.2.0_4120\workspace\Assignment3_Blinkenlights" -I"C:\Users\ujjai\Documents\MCUXpressoIDE_11.2.0_4120\workspace\Assignment3_Blinkenlights\drivers" -I"C:\Users\ujjai\Documents\MCUXpressoIDE_11.2.0_4120\workspace\Assignment3_Blinkenlights\CMSIS" -I"C:\Users\ujjai\Documents\MCUXpressoIDE_11.2.0_4120\workspace\Assignment3_Blinkenlights\utilities" -I"C:\Users\ujjai\Documents\MCUXpressoIDE_11.2.0_4120\workspace\Assignment3_Blinkenlights\startup" -Os -fno-common -g -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fmacro-prefix-map="../$(@D)/"=. -mcpu=cortex-m0plus -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


