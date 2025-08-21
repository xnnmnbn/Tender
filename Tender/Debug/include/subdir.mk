################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../include/assetmanager.cpp \
../include/game.cpp \
../include/scene.cpp 

CPP_DEPS += \
./include/assetmanager.d \
./include/game.d \
./include/scene.d 

OBJS += \
./include/assetmanager.o \
./include/game.o \
./include/scene.o 


# Each subdirectory must supply rules for building sources it contributes
include/%.o: ../include/%.cpp include/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/include -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-include

clean-include:
	-$(RM) ./include/assetmanager.d ./include/assetmanager.o ./include/game.d ./include/game.o ./include/scene.d ./include/scene.o

.PHONY: clean-include

