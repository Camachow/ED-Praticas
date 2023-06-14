#include "../include/mergeSort.hpp"
#include <math.h>

// Função de intercalação do Merge Sort
void merge(Point* points, int low, int mid, int high) {
    int n1 = mid - low + 1;
    int n2 = high - mid;

    Point* left = new Point[n1];
    Point* right = new Point[n2];

    int auxleft = 0;
    int auxright = 0;

    int indexToMerge = low;

    for (int i = 0; i < n1; i++) {
        left[i] = points[low + i];
    }

    for (int i = 0; i < n2; i++) {
        right[i] = points[mid + 1 + i];
    }

    while (auxleft < n1 && auxright < n2) {
        if (left[auxleft].getY() < right[auxright].getY()) {
            points[indexToMerge] = left[auxleft];
            auxleft++;
        } else if (left[auxleft].getY() == right[auxright].getY()) {
            if (left[auxleft].getX() < right[auxright].getX()) {
                points[indexToMerge] = left[auxleft];
                auxleft++;
            } else {
                points[indexToMerge] = right[auxright];
                auxright++;
            }
        }
        else {
            points[indexToMerge] = right[auxright];
            auxright++;
        }
        indexToMerge++;   
    }

    while (auxleft < n1) {
        points[indexToMerge] = left[auxleft];
        auxleft++;
        indexToMerge++;
    }

    while (auxright < n2) {
        points[indexToMerge] = right[auxright];
        auxright++;
        indexToMerge++;
    }

    for(int i = low + 1; i <= high; i++){
        for(int j = i + 1; j <= high; j++){
            double angle1 = getAngle(points[i]);
            double angle2 = getAngle(points[j]);

            if(angle1 > angle2){
                Point aux = points[i];
                points[i] = points[j];
                points[j] = aux;
            }
        }
    }
    
    delete[] left;
    delete[] right;

}

// Função de ordenação Merge Sort
void mergeSort(Point* points, int low, int high) {
    if (low < high) {
        int mid = floor((low + high) / 2);

        mergeSort(points, low, mid);
        mergeSort(points, mid + 1, high);

        merge(points, low, mid, high);
    }
}

