#include "../include/insertionSort.hpp"

void insertionSort(Point* points, int n) {
    int i, j;
    Point key;

    for (i = 1; i < n; i++) {
        key = points[i];
        j = i - 1;

        while (j >= 0 && getAngle(points[j]) > getAngle(key)) {
            points[j + 1] = points[j];
            j--;
        }

        points[j + 1] = key;
    }
}