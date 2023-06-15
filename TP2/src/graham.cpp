#include "../include/graham.hpp"
#include "../include/mergeSort.hpp"
#include "../include/stack.hpp"
#include "../include/point.hpp"
#include "../include/bucketSort.hpp"
#include "../include/insertionSort.hpp"

// Função para encontrar o próximo ponto em relação ao topo da pilha
Point nextToTop(Stack* stack) {
    Point p = stack->getTop();
    stack->pop();
    Point result = stack->getTop();
    stack->push(p);
    return result;
}

int getLowerIndex(Point *points, int size){
    int lowerIndex = 0;
    for(int i = 1; i < size; i++){
        if(points[i].getY() < points[lowerIndex].getY() || (points[i].getY() == points[lowerIndex].getY() && points[i].getX() < points[lowerIndex].getX())){
            lowerIndex = i;
        }
    }
    return lowerIndex;
}

Stack grahamScan(Point* points, int n, Point p0){
    
    //Verifica se os pontos são colineares
    if(Point::isCollinear(points, n)){
        Stack stack = Stack();
        stack.push(points[0]);
        stack.push(points[n-1]);
        return stack;
    }

    // Se dois ou mais pontos tiverem o mesmo ângulo polar com p0,
    // então remover todos os pontos exceto o que estiver mais distante de p0
    // Lembre-se que, em ordem polar, o ponto mais distante aparece por último
    int m = 1; // Inicializar o tamanho do vetor de pontos ordenados
    for (int i = 1; i < n; i++) {
        // Manter removendo pontos enquanto o ângulo formado por pontos[i-1],
        // pontos[i] e p0 for colinear no sentido horário ou o ângulo for reto
        while (i < n - 1 && Point::orientation(p0, points[i], points[i + 1]) == 0) {
            i++;
        }
        points[m++] = points[i];
    }

    // Se o tamanho do vetor de pontos ordenados for menor que 3,
    // então não é possível construir um fecho convexo
    if (m < 3) {
        throw "Não é possível construir um fecho convexo.";
    }

    // Criar uma pilha e colocar os três primeiros pontos nele
    Stack stack = Stack();
    stack.push(points[0]);
    stack.push(points[1]);
    stack.push(points[2]);

    // Processar os pontos restantes
    for (int i = 3; i < m; i++) {
        // Manter removendo pontos enquanto o ângulo formado por
        // pontos[i-1], pontos[i] e o topo da pilha for colinear no sentido horário
        while (stack.getSize() > 1 && Point::orientation(nextToTop(&stack), stack.getTop(), points[i]) != 2)
            stack.pop();
        
        stack.push(points[i]);
    }
    return stack;
}

// Função para encontrar o fecho convexo de um conjunto de pontos
Stack convexHullMergesort(Point* points, int n) {
    Stack stack = Stack();
    // Verificar se há pontos suficientes para construir um fecho convexo
    if (n < 3) {
        throw "Não é possível construir um fecho convexo.";
    }

    // Encontrar o ponto com menor coordenada y
    // Se houver mais de um ponto com a menor coordenada y,
    // então o ponto com menor coordenada x será escolhido
    int min = getLowerIndex(points, n);

    // Colocar o ponto com menor coordenada y na primeira posição
    swap(points[0], points[min]);

    // Ordenar os pontos restantes com relação ao primeiro ponto
    // em ordem polar no sentido anti-horário
    Point p0 = points[0];
    mergeSort(points, 0, n - 1);
    stack = grahamScan(points, n, p0);

    return stack;
}

Stack convexHullInsertionSort(Point *points, int size){
    Stack stack = Stack();

    int min = getLowerIndex(points, size);

    swap(points[0], points[min]);
    Point p0 = points[0];
    insertionSort(points, size);
    stack = grahamScan(points, size, p0);

    return stack;
}

Stack convexHullBucketSort(Point *points, int size){
    Stack stack = Stack();

    int min = getLowerIndex(points, size);

    swap(points[0], points[min]);
    Point p0 = points[0];
    bucketSort(points, size);
    stack = grahamScan(points, size, p0);

    return stack;
}
