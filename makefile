CC = h8300-elf-gcc
CXX = h8300-elf-g++

SRC_DIR = ./src
BUILD_DIR = ./build
TEMP_DIR = ./temp

SRCS = $(shell find $(SRC_DIR) -name "*.cpp" -or -name "*.c")
OBJS = $(addsuffix .o,$(SRCS))
DEPS = $(addsuffix .d,$(addprefix $(TEMP_DIR)/,$(basename $(notdir $(SRCS)))))

INC_DIR = ./include ./src/h8sys ./src/2022EOMMP
LIB_DIR = ./include
LIBS = add3069
CXXFLAGS = -mh -O2 -Wall $(addprefix -I,$(INC_DIR)) -std=c++17 -MMD -MP -c
CFLAGS = -mh -O2 -Wall $(addprefix -I,$(INC_DIR)) -MMD -MP -c
LDFLAGS = -mh -nostartfiles $(addprefix -L,$(LIB_DIR)) -T./include/3069F/h8rom.x $(addprefix -I,$(INC_DIR)) -Wl,-Map,$(BUILD_DIR)/$(TARGET).map
STARTUP_FILE = ./include/3069F/h8crt0.s

TARGET = program

all: $(BUILD_DIR)/$(TARGET).elf
	h8300-elf-objcopy -O srec $^ $(basename $^).mot

%.elf: $(OBJS)
	$(CXX) $(LDFLAGS) $(STARTUP_FILE) $(addprefix $(TEMP_DIR)/,$(addsuffix .o,$(basename $(basename $(notdir $^))))) $(addprefix -l,$(LIBS)) -o $(BUILD_DIR)/$(TARGET).elf

%.cpp.o: %.cpp
	$(CXX) $(CXXFLAGS) $^ -o $(addsuffix .o,$(addprefix $(TEMP_DIR)/,$(basename $(notdir $^))))

%.c.o: %.c
	$(CC) $(CFLAGS) $^ -o $(addsuffix .o,$(addprefix $(TEMP_DIR)/,$(basename $(notdir $^))))

.PHONY: clean
clean:
	rm -f $(TEMP_DIR)/*
	rm -f $(BUILD_DIR)/*

.PHONY: write
write:
	sudo chmod 666 /dev/ttyUSB0
	kz_h8write -3069 -f25 -d $(BUILD_DIR)/$(TARGET).mot /dev/ttyUSB0

-include $(DEPS)
