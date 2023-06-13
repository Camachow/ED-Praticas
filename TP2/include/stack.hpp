#ifndef STACK_HPP
#define STACK_HPP
#include "point.hpp"

const int MAX_SIZE = 10000; // Tamanho máximo da pilha

class Stack {
private:
    int top; // Topo da pilha
    int size; // Tamanho da pilha
    Point data[MAX_SIZE]; // Array para armazenar os elementos

public:
    Stack(); // Construtor
    ~Stack(); // Destrutor
    void push(Point value); // Inserir elemento na pilha
    Point pop(); // Remover elemento da pilha
    bool isEmpty(); // Verificar se a pilha está vazia
    int getSize(); // Obter o tamanho da pilha
    Point getTop(); // Obter o elemento do topo da pilha
    Point getPoint(int index); // Obter o elemento de um índice específico da pilha
    void clear(); // Limpar a pilha

};

#endif
