#include "../include/graham.hpp"
#include "../include/mergeSort.hpp"

// Função para encontrar o próximo ponto em relação ao topo da pilha
Point nextToTop(Point* pointsStack, int& top) {
    return pointsStack[top - 1];
}

// Função para calcular a orientação de três pontos (p, q, r)
int orientation(Point p, Point q, Point r) {
    int value = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);

    if (value == 0) {
        return 0;  // colinear
    } else if (value > 0) {
        return 1;  // sentido horário
    } else {
        return 2;  // sentido anti-horário
    }
}

// Função para encontrar o fecho convexo de um conjunto de pontos
void convexHull(Point* points, int n) {
    // Verificar se há pontos suficientes para construir um fecho convexo
    if (n < 3) {
        cout << "Não há pontos suficientes para construir um fecho convexo." << endl;
        return;
    }

    // Ordenar os pontos pelo ângulo polar em relação ao ponto mais baixo (menor y)
    mergeSort(points, 0, n - 1);

    int m = 1; // tamanho do fecho convexo
    for (int i = 1; i < n; i++) {
        while (i < n - 1 && orientation(points[0], points[i], points[i + 1]) == 0) {
            i++;
        }
        points[m] = points[i];
        m++;
    }

    if (m < 3) {
        cout << "Não há pontos suficientes para construir um fecho convexo." << endl;
        return;
    }

    int top = 2; // topo da pilha
    for (int i = 3; i < m; i++) {
        while (orientation(nextToTop(points, top), points[top], points[i]) != 2) {
            top--;
        }
        top++;
        points[top] = points[i];
    }

    // Imprimir os pontos do fecho convexo
    for (int i = 0; i <= top; i++) {
        cout << "(" << points[i].x << ", " << points[i].y << ")" << endl;
    }
}
