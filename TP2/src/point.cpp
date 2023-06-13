#include "../include/point.hpp"

Point::Point(int x, int y) {
    this->x = x;
    this->y = y;
}

Point::Point() {}

Point::~Point() {}

void Point::swap(Point* a, Point* b) {
    Point t = *a;
    *a = *b;
    *b = t;
}

int Point::distSq(Point p1, Point p2) {
    return (p1.x - p2.x) * (p1.x - p2.x) +
           (p1.y - p2.y) * (p1.y - p2.y);
}

int Point::orientation(Point p, Point q, Point r) {
    int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);

    if (val == 0)   return 0; // Collinear
    return (val > 0) ? 1 : 2; // Clock or counterclock wise
}

int Point::isCollinear(Point *points, int n){
    for(int i = 0; i < n; i++)
        if(points[i].getX() != points[i].getY())
            return 0;
    return 1;
}

double getAngle(Point p1){
    return atan2(p1.getY(), p1.getX());
}

int Point::getX() {
    return x;
}

int Point::getY() {
    return y;
}

void Point::setX(int x) {
    this->x = x;
}

void Point::setY(int y) {
    this->y = y;
}
