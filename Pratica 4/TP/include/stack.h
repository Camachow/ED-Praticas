#ifndef STACK_H
#define STACK_H
#include <iostream>
#include "../include/circularqueue.h"

class Stack {
    private:
        CircularQueue q;

    public:
        Stack(int size);
        bool isEmpty();
        bool isFull();
        void push(int data);
        int pop();    
        void print();   
};

#endif