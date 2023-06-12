#include "../include/mergeSort.hpp"

// Função de intercalação do Merge Sort
void merge(Point* points, int low, int mid, int high) {
    int n1 = mid - low + 1;
    int n2 = high - mid;

    Point left[n1], right[n2];

    for (int i = 0; i < n1; i++) {
        left[i] = points[low + i];
    }

    for (int j = 0; j < n2; j++) {
        right[j] = points[mid + 1 + j];
    }

    int i = 0, j = 0, k = low;

    while (i < n1 && j < n2) {
        if (left[i].x <= right[j].x) {
            points[k] = left[i];
            i++;
        } else {
            points[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        points[k] = left[i];
        i++;
        k++;
    }

    while (j < n2) {
        points[k] = right[j];
        j++;
        k++;
    }
}

// Função de ordenação Merge Sort
void mergeSort(Point* points, int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2;

        mergeSort(points, low, mid);
        mergeSort(points, mid + 1, high);

        merge(points, low, mid, high);
    }
}

