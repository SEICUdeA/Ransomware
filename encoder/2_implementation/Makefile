CC      := gcc

CFLAGS  := -Wall -Wextra -Iinclude -MMD -MP
LDFLAGS :=
LIBS    :=

NAME    := encoder

SRC_DIR := src
INC_DIR := include
BUILD   := build

SRCS := $(shell find $(SRC_DIR) -name '*.c')
OBJS := $(patsubst $(SRC_DIR)/%.c,$(BUILD)/%.o,$(SRCS))
DEPS := $(OBJS:.o=.d)

TARGET := $(BUILD)/$(NAME)

all: $(TARGET)

$(TARGET): $(OBJS)
	@mkdir -p $(BUILD)
	$(CC) $(OBJS) -o $@ $(LDFLAGS) $(LIBS)

$(BUILD)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -rf $(BUILD)

.PHONY: all run clean

-include $(DEPS)
