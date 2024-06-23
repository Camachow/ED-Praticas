#include <iostream>

// Função de ordenação Insertion Sort para ordenar os buckets
void insertionSort(float arr[], int size) {
    for (int i = 1; i < size; i++) {
        float key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Função de ordenação Bucket Sort
void bucketSort(float arr[], int size) {
    // Número de buckets
    const int bucketCount = 10;
    float buckets[bucketCount][size];
    int bucketSizes[bucketCount];

    // Inicializar o tamanho dos buckets como zero
    for (int i = 0; i < bucketCount; i++) {
        bucketSizes[i] = 0;
    }

    // Distribuir os elementos nos buckets
    for (int i = 0; i < size; i++) {
        int bucketIndex = static_cast<int>(arr[i] * bucketCount); // Multiplicando por 10 para colocar no bucket correto
        buckets[bucketIndex][bucketSizes[bucketIndex]++] = arr[i];
    }

    // Ordenar cada bucket usando Insertion Sort
    for (int i = 0; i < bucketCount; i++) {
        insertionSort(buckets[i], bucketSizes[i]);
    }

    // Concatenar todos os buckets no array original
    int index = 0;
    for (int i = 0; i < bucketCount; i++) {
        for (int j = 0; j < bucketSizes[i]; j++) {
            arr[index++] = buckets[i][j];
        }
    }
}
