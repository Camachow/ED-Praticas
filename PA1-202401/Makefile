# Definindo o compilador
CC = gcc

# Flags do compilador
CFLAGS = -Wall -Wextra -O2

# Diretórios
SRCDIR = .
BINDIR = ./bin

# Arquivos de origem e destino
SRC = $(SRCDIR)/main.c
OBJ = $(SRC:.c=.o)
TARGET = $(BINDIR)/pa1.out

# Regra principal
all: $(TARGET)

# Regra para criar o executável
$(TARGET): $(OBJ)
	@mkdir -p $(BINDIR)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

# Regra para compilar os arquivos .c
$(OBJ): $(SRC)
	$(CC) $(CFLAGS) -c $(SRC) -o $(OBJ)

# Limpar os arquivos gerados
clean:
	rm -f $(OBJ) $(TARGET)
	rm -rf $(BINDIR)

.PHONY: all clean
