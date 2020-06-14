#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# Makefile to perform a native or cross-compilation as per requested platform 
# target. The default PLATFORM is MSP432
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <FILE>.o - Builds <FILE>.o object file
#      <FILE>.i - Builds <FILE>.i preprocessed file
#      <FILE>.asm - Builds <FILE>.asm assembly file
#      build - Builds and links all source files
#      all - same as build
#      compile-all - Compile all object files  
#      clean - removes all generated files
#
# Platform Overrides:
#      PLATFORM - Can choose between HOST and MSP432
#
#------------------------------------------------------------------------------

# including the sources makefile
include sources.mk

# Platform Overrides
PLATFORM = MSP432 #default

# Final Target
TARGET = c1m2


ifeq ($(PLATFORM),HOST)
  
  #For HOST PLATFORM  
  # Compiler Flags and Defines
  CC = gcc 
  LD = ld
  LDFLAGS = -Wl,-Map=$(TARGET).map
  CFLAGS =  -Wall -Werror -g -O0 -std=c99
  CPPFLAGS = $(INCLUDES)
  DEPFLAGS = -MM
  SIZETOOL = size #To produce the size of code
  DUMPTOOL = objdump

else

  # Architectures Specific Flags
  LINKER_FILE = ../msp432p401r.lds
  CPU = cortex-m4
  ARCH = thumb
  SPECS = nosys.specs

   
  # Compiler Flags and Defines
  CC = arm-none-eabi-gcc 
  LD = arm-none-eabi-ld
  LDFLAGS = -Wl,-Map=$(TARGET).map -T $(LINKER_FILE)
  CFLAGS =  -Wall -Werror -g -O0 -std=c99 -mcpu=$(CPU) -m$(ARCH) \
	    -march=armv7e-m -mfloat-abi=hard -mfpu=fpv4-sp-d16 \
	    --specs=$(SPECS)

  CPPFLAGS = $(INCLUDES)
  DEPFLAGS = -MM
  SIZETOOL = arm-none-eabi-size #To produce the size of code
  DUMPTOOL = arm-none-eabi-objdump # -marmv7e

endif


# Creating object file variable
OBJS = $(SOURCES:.c=.o)
# Creating the dependency file for correspoding objects
DEPFILES = $(OBJS:.o=.d)

# Generating Object and correponding dependency files
#%.o : %.c
#	$(CC) $(CPPFLAGS) $(CFLAGS) -D$(PLATFORM) -c -o $@ $<
#	$(CC) $(CPPFLAGS) $(CFLAGS) -D$(PLATFORM) $(DEPFLAGS) $< > $(@:.o=.d)	


# Creating Preprocessed file variable
PRES = $(SOURCES:.c=.i)

# Generating Preprocessed files
%.i : %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -D$(PLATFORM) -E -o $@ $<
	

# Creating assembly file variables
ASMS = $(SOURCES:.c=.asm)

# Generating Preprocessed files
%.asm : %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -D$(PLATFORM) -S -o $@ $<


# build Phony - same as all
.PHONY: build 
build: all

# Building and linking to obtain the final target
.PHONY: all
all:$(TARGET).out 

$(TARGET).out: $(OBJS)
	$(CC) $(OBJS) $(CPPFLAGS) $(CFLAGS) $(LDFLAGS) -D$(PLATFORM) -o $@ 	
	$(SIZETOOL) -Bx $@	#displaying Size
	$(DUMPTOOL) -S $(TARGET).out 1> $(TARGET).asm	
	
# Cleaning all non-source files and executables
.PHONY: clean
clean:
	rm -f $(OBJS) $(DEPFILES) $(PRES) $(ASMS) $(TARGET).out $(TARGET).map $(TARGET).asm

# Compiling all the source files to obtain oject files
.PHONY: compile-all
compile-all:$(OBJS)

# Generating Object and correponding dependency files
%.o : %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -D$(PLATFORM) -c -o $@ $<
	$(CC) $(CPPFLAGS) $(CFLAGS) -D$(PLATFORM) $(DEPFLAGS) $< > $(@:.o=.d)	




