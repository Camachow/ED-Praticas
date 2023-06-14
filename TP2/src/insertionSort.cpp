#include "../include/insertionSort.hpp"

void insertionSort(Point* points, int n) {
    for (int i = 1; i < n; i++) {
        Point key = points[i];
        int j = i - 1;

        while (j >= 0 && getAngle(points[j]) > getAngle(key)) {
            points[j + 1] = points[j];
            j--;
        }

        points[j + 1] = key;
    }
}