#ifndef CIRCULARQUEUE_H
#define CIRCULARQUEUE_H

class CircularQueue {
private:
    int *buffer;
    int front, rear, capacity;
public:
    CircularQueue(int size);
    ~CircularQueue();
    bool isEmpty();
    bool isFull();
    void enqueue(int data);
    int dequeue();
    void print();
    int getCapacity();
};

#endif