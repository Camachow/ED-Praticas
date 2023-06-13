#ifndef GRAHAM_HPP
#define GRAHAM_HPP

#include <iostream>
#include "point.hpp"
#include "stack.hpp"
using namespace std;

// Função para encontrar o próximo ponto em relação ao topo da pilha
Point nextToTop(Stack* pointsStack);

// Função para encontrar o fecho convexo de um conjunto de pontos
Stack convexHullMergesort(Point* points, int n);

Stack convexHullInsertionSort(Point* points, int n);

Stack convexHullBucketSort(Point* points, int n);

#endif  // GRAHAM_HPP
