################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Buch.cpp \
../Buecherei.cpp \
../DVD.cpp \
../Datum.cpp \
../Magazin.cpp \
../Medium.cpp \
../Person.cpp 

CPP_DEPS += \
./Buch.d \
./Buecherei.d \
./DVD.d \
./Datum.d \
./Magazin.d \
./Medium.d \
./Person.d 

OBJS += \
./Buch.o \
./Buecherei.o \
./DVD.o \
./Datum.o \
./Magazin.o \
./Medium.o \
./Person.o 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean--2e-

clean--2e-:
	-$(RM) ./Buch.d ./Buch.o ./Buecherei.d ./Buecherei.o ./DVD.d ./DVD.o ./Datum.d ./Datum.o ./Magazin.d ./Magazin.o ./Medium.d ./Medium.o ./Person.d ./Person.o

.PHONY: clean--2e-

