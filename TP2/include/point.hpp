#ifndef POINT_HPP
#define POINT_HPP
#include <math.h>

using namespace std;

class Point {
private:
    int x, y;

public:
    // Construtor e destrutor
    Point(int x, int y);
    Point();
    ~Point();
    // Função para trocar dois pontos
    static void swap(Point* a, Point* b);
    // Função para encontrar o quadrado da distância euclidiana
    static int distSq(Point p1, Point p2);
    // Função para calcular a orientação de três pontos (p, q, r)
    static int orientation(Point p, Point q, Point r);
    // Função para verificar se todos os pontos são colineares
    static int isCollinear(Point *points, int n);
    // Getters e setters
    int getX();
    int getY();
    void setX(int x);
    void setY(int y);

};

double getAngle(Point p1);

#endif  // POINT_HPP