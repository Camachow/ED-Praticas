#include "../include/circularqueue.h"
#include <iostream>

using namespace std;


CircularQueue::CircularQueue(int size) {
    capacity = size + 1;  // O buffer é alocado com tamanho "size + 1" para permitir que o rear "alcance" o front
    buffer = new int[capacity];
    front = 0;
    rear = 0;
}

CircularQueue::~CircularQueue() {
    delete[] buffer;
}

int CircularQueue::getCapacity() {
    return capacity;
}

void CircularQueue::print() {
    cout << "Queue: ";
    for (int i = front; i != rear; i = (i + 1) % capacity) {
        cout << buffer[i] << " ";
    }
    cout << endl;
}

bool CircularQueue::isEmpty() {
    return front == rear;
}

bool CircularQueue::isFull() {
    return (rear + 1) % capacity == front;
}

void CircularQueue::enqueue(int data) {
    if (isFull()) {
        cout << "Queue overflow\n";
        return;
    }
    buffer[rear] = data;
    rear = (rear + 1) % capacity;
}

int CircularQueue::dequeue() {
    if (isEmpty()) {
        cout << "Queue underflow\n";
        return -1;
    }
    int data = buffer[front];
    front = (front + 1) % capacity;
    return data;
}
