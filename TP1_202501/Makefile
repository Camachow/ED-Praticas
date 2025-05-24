# Makefile

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -O2 -D_XOPEN_SOURCE=700 -Iinclude

# Source and object files
SRCS := $(wildcard src/*.c)
OBJS := $(patsubst src/%.c,obj/%.o,$(SRCS))

.PHONY: all clean

# Default target
all: tp1

# Link executable
tp1: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Compile source to object
obj/%.o: src/%.c
	@mkdir -p obj
	$(CC) $(CFLAGS) -c $< -o $@

# Clean build artifacts
clean:
	rm -rf obj tp1
	rm -rf obj tp1
