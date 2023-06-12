#ifndef GRAHAM_HPP
#define GRAHAM_HPP

#include <iostream>
using namespace std;

struct Point {
    int x, y;
};

// Função para encontrar o próximo ponto em relação ao topo da pilha
Point nextToTop(Point* pointsStack, int& top);

// Função para calcular a orientação de três pontos (p, q, r)
int orientation(Point p, Point q, Point r);

// Função de intercalação do Merge Sort
void merge(Point* points, int low, int mid, int high);

// Função de ordenação Merge Sort
void mergeSort(Point* points, int low, int high);

// Função para encontrar o fecho convexo de um conjunto de pontos
void convexHull(Point* points, int n);

#endif  // GRAHAM_HPP
