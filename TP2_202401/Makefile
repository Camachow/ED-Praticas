# Nome do compilador
CXX = g++

# Flags de compilação
CXXFLAGS = -Wall -Wextra -std=c++17 -g

# Diretórios
INCDIR = include
SRCDIR = src
OBJDIR = obj
BINDIR = bin

# Nome do executável
TARGET = $(BINDIR)/tp2.out

# Headers
HEADERS = $(wildcard $(INCDIR)/*.h)

# Arquivos fonte
SOURCES = $(wildcard $(SRCDIR)/*.cpp)

# Arquivos objeto
OBJECTS = $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(SOURCES))

# Regras de compilação e ligação
all: $(TARGET)

$(TARGET): $(OBJECTS)
	@mkdir -p $(BINDIR)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp $(HEADERS)
	@mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) -I$(INCDIR) -o $@ -c $<

# Limpeza dos arquivos compilados
clean:
	rm -rf $(OBJDIR) $(BINDIR)

# Executa o programa
run: $(TARGET)
	$(TARGET)

# Regra para rodar o Valgrind
valgrind: $(TARGET)
	valgrind --leak-check=full $(TARGET)

# Regra de phony para evitar conflitos com arquivos de mesmo nome
.PHONY: all clean run valgrind
