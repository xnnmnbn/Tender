################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/game/scene_example.cpp 

CPP_DEPS += \
./src/game/scene_example.d 

OBJS += \
./src/game/scene_example.o 


# Each subdirectory must supply rules for building sources it contributes
src/game/%.o: ../src/game/%.cpp src/game/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/include -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src-2f-game

clean-src-2f-game:
	-$(RM) ./src/game/scene_example.d ./src/game/scene_example.o

.PHONY: clean-src-2f-game

