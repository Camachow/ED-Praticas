# Makefile para o TP1 - Ordenador Universal

CC = gcc
CFLAGS = -Wall -Iinclude -O2
OBJDIR = obj
BINDIR = bin
SRCDIR = src

OBJS = $(OBJDIR)/main.o \
       $(OBJDIR)/ordenador.o \
       $(OBJDIR)/calibrador.o \
       $(OBJDIR)/shuffle.o

TARGET = $(BINDIR)/tp1.out

all: $(TARGET)

$(TARGET): $(OBJS)
	@mkdir -p $(BINDIR)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR)/*.o $(BINDIR)/tp1.out

.PHONY: all clean
