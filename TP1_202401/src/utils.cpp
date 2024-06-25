#include "../include/utils.h"
#include <iostream>
#include <sys/time.h>
#include <cstdlib>
#include <iomanip>

double getExecutionTime(void (*sortFunc)(int[], int), int arr[], int size) {
    struct timeval start, end;
    gettimeofday(&start, NULL);
    sortFunc(arr, size);
    gettimeofday(&end, NULL);
    double executionTime = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1e6;
    return executionTime;
}

// Funções para gerar vetores
void generateRandomArray(int arr[], int size, int max) {
    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % max; // Valores aleatórios
    }
}

void generateSortedArray(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        arr[i] = i;
    }
}

void generateReverseSortedArray(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        arr[i] = size - i;
    }
}

// Função para imprimir os elementos do array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " "; // Use std::cout for output
    }
    std::cout << std::endl; // Use std::endl for line break
}

int getMax(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Pivô
    int i = (low - 1); // Índice do menor elemento

    for (int j = low; j <= high - 1; ++j) {
        // Se o elemento atual for menor que ou igual ao pivô
        if (arr[j] <= pivot) {
            i++; // Incrementa o índice do menor elemento
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Arrays temporários
    int* leftArray = new int[n1];
    int* rightArray = new int[n2];

    // Copiar dados para os arrays temporários
    for (int i = 0; i < n1; ++i)
        leftArray[i] = arr[left + i];
    for (int j = 0; j < n2; ++j)
        rightArray[j] = arr[mid + 1 + j];

    // Mesclar os arrays temporários de volta em arr[left..right]
    int i = 0;
    int j = 0;
    int k = left;

    while (i < n1 && j < n2) {
        if (leftArray[i] <= rightArray[j]) {
            arr[k] = leftArray[i];
            i++;
        } else {
            arr[k] = rightArray[j];
            j++;
        }
        k++;
    }

    // Copiar os elementos restantes de leftArray[], se houver
    while (i < n1) {
        arr[k] = leftArray[i];
        i++;
        k++;
    }

    // Copiar os elementos restantes de rightArray[], se houver
    while (j < n2) {
        arr[k] = rightArray[j];
        j++;
        k++;
    }

    // Liberar memória alocada
    delete[] leftArray;
    delete[] rightArray;
}