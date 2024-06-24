#include <iostream>
#include "../include/sorts.h"

int main() {
    // Exemplo de uso do Merge Sort
    float arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Array original: ";
    printFloatArray(arr, n);

    insertionSort(arr, n);

    std::cout << "Array ordenado: ";
    printFloatArray(arr, n);

    return 0;
}