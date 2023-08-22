#include "../include/stack.h"
#include "../include/circularqueue.h"

using namespace std;

Stack::Stack(int size) : q(size) {}

bool Stack::isEmpty() {
    return q.isEmpty();
}

bool Stack::isFull() {
    return q.isFull();
}

void Stack::print() {
    q.print();
}

void Stack::push(int data) {
    if (isFull()) {
        cout << "Stack overflow\n";
        return;
    }
    CircularQueue temp(q.getCapacity());
    temp.enqueue(data);
    while (!q.isEmpty()) {
        temp.enqueue(q.dequeue());
    }
    while (!temp.isEmpty()) {
        q.enqueue(temp.dequeue());
    }
}

int Stack::pop() {
    if (isEmpty()) {
        cout << "Stack underflow\n";
        return -1;
    }
    CircularQueue temp(q.getCapacity());
    while (!q.isEmpty()) {
        temp.enqueue(q.dequeue());
    }
    int data = temp.dequeue();
    while (!temp.isEmpty()) {
        q.enqueue(temp.dequeue());
    }
    return data;
}
