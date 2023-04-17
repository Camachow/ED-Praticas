#include "../include/stack.h"
#include "../include/circularqueue.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

int main() {
    unsigned int seed = time(0);
    srand(seed);

    Stack s(10);
    s.push(0);
    s.print();
    s.push(1);
    s.print();
    s.push(2);
    s.print();
    s.push(3);
    s.print();
    s.push(4);
    s.print();
    s.push(5);
    s.print();
    s.push(6);
    s.print();
    s.push(7);
    s.print();
    s.push(8);
    s.print();
    s.push(9);
    s.print();
    s.pop();
    s.print();
    s.pop();
    s.print();
    s.pop();
    s.print();
    s.pop();
    s.print();
    s.pop();
    s.print();
    s.pop();
    s.print();
    s.pop();
    s.print();
    s.pop();
    s.print();
    s.pop();
    s.print();
    s.pop();
    s.print();

/*
    if(rand() % 2 == 1){
        cout<<"Empilhando 1 \n";
        s.push(1);
    }else{
        cout<<"Desempilhando \n";
        s.pop();
    }
    if(rand() % 2 == 1){
        cout<<"Empilhando 2 \n";
        s.push(2);
    }else{
        cout<<"Desempilhando \n";
        s.pop();
    }
    if(rand() % 2 == 1){
        cout<<"Empilhando 3 \n";
        s.push(3);
    }else{
        cout<<"Desempilhando \n";
        s.pop();
    }
    if(rand() % 2 == 1){
        cout<<"Empilhando 4 \n";
        s.push(4);
    }else{
        cout<<"Desempilhando \n";
        s.pop();
    }
    if(rand() % 2 == 1){
        cout<<"Empilhando 5 \n";
        s.push(5);
    }else{
        cout<<"Desempilhando \n";
        s.pop();
    }
    if(rand() % 2 == 1){
        cout<<"Empilhando 6 \n";
        s.push(6);
    }else{
        cout<<"Desempilhando \n";
        s.pop();
    }
    if(rand() % 2 == 1){
        cout<<"Empilhando 7 \n";
        s.push(7);
    }else{
        cout<<"Desempilhando \n";
        s.pop();
    }
    if(rand() % 2 == 1){
        cout<<"Empilhando 8 \n";
        s.push(8);
    }else{
        cout<<"Desempilhando \n";
        s.pop();
    }
    if(rand() % 2 == 1){
        cout<<"Empilhando 9 \n";
        s.push(9);
    }else{
        cout<<"Desempilhando \n";
        s.pop();
    }
    */
   return 0;
}