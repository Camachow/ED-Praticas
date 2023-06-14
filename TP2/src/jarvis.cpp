#include "../include/jarvis.hpp"
#include "../include/point.hpp"
#include <iostream>

int mostLeftPoint(Point points[], int n){
    int l = 0;
    for (int i = 1; i < n; i++)
        if (points[i].getX() < points[l].getX())
            l = i;
    return l;
}

Stack convexHullJarvis(Point points[], int n){
   if (n<3) {
        throw "Erro: Número de pontos insuficiente";
    }

    if(Point::isCollinear(points, n)){
        Stack stack = Stack();
        stack.push(points[0]);
        stack.push(points[n-1]);
        return stack;
    }

    Stack stackJarvis = Stack();

    int l = mostLeftPoint(points, n);

    int p = l;

    int q = 0;

    do {
        stackJarvis.push(points[p]);
        q = (p+1)%n;
        for (int i = 0; i < n; i++){
            if (Point::orientation(points[p], points[i], points[q]) == 2)
                q = i;
        }
        p = q;
    } while (p != l);

    return stackJarvis; 
}