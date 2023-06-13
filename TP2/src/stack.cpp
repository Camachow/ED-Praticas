#include "stack.hpp"

Stack::Stack() {
    top = -1; // Inicializar o topo da pilha como -1 (vazia)
    size = 0; // Inicializar o tamanho da pilha como 0
}

Stack::~Stack() {
    // Destrutor
}

int Stack::getSize() {
    return size;
}

Point Stack::getTop() {
    return data[top];
}

Point Stack::getPoint(int index) {
    return data[index];
}

void Stack::push(Point value) {
    if (top < MAX_SIZE - 1) {
        size++;
        data[++top] = value;
    } else {
        // Pilha cheia, não é possível inserir
        // Você pode escolher lidar com esse caso de acordo com suas necessidades
    }
}

Point Stack::pop() {
    if (!isEmpty()) {
        size--;
        return data[top--];
    }
    throw "Pilha vazia!";
}

bool Stack::isEmpty() {
    return (top == -1);
}

void Stack::clear() {
    top = -1;
    size = 0;
}