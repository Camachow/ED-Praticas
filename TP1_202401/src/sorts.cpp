#include "../include/sorts.h"
#include <iostream>
#include <cstring>

//BubbleSort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                // Trocar arr[j] e arr[j + 1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// InsertionSort
void insertionSort(float arr[], int n) {
    for (int i = 1; i < n; i++) {
        float key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// SelectionSort
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        // Encontrar o menor elemento no array não ordenado
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        // Trocar o menor elemento encontrado com o primeiro elemento
        if (minIndex != i) {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

// MergeSort
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Ordenar a primeira e a segunda metade
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Mesclar as metades ordenadas
        merge(arr, left, mid, right);
    }
}

// QuickSort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // pi é o índice de partição, arr[pi] está no lugar correto
        int pi = partition(arr, low, high);

        // Ordenar os elementos separadamente antes e depois da partição
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// ShellSort
void shellSort(int arr[], int n) {
    // Começa com um grande intervalo, depois reduz o intervalo
    for (int gap = n / 2; gap > 0; gap /= 2) {
        // Faz uma ordenação por inserção para este intervalo
        for (int i = gap; i < n; ++i) {
            // Adiciona arr[i] aos elementos que foram ordenados pelo intervalo atual
            int temp = arr[i];

            // Move os elementos do intervalo arr[0..i-gap] que são maiores que temp
            // uma posição à frente de sua posição atual
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }

            // Coloca temp em sua posição correta
            arr[j] = temp;
        }
    }
}

// CountingSort
void countingSort(int arr[], int size) {
    // Encontra o maior elemento no array
    int max = findMax(arr, size);

    // Cria um array de contagem com tamanho suficiente para armazenar contagens de todos os elementos até o maior valor
    int* count = new int[max + 1]();

    // Conta a ocorrência de cada elemento no array original
    for (int i = 0; i < size; i++) {
        count[arr[i]]++;
    }

    // Atualiza o array original com os elementos ordenados
    int index = 0;
    for (int i = 0; i <= max; i++) {
        while (count[i] > 0) {
            arr[index++] = i;
            count[i]--;
        }
    }

    // Libera a memória alocada para o array de contagem
    delete[] count;
}

// BucketSort
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

// CountSort
void countSortRadix(int arr[], int size, int exp) {
    int output[size]; // Array de saída
    int count[10]; // Array de contagem para os dígitos de 0 a 9
    memset(count, 0, sizeof(count)); // Inicializa o array count com zeros

    // Armazena a contagem de ocorrências em count[]
    for (int i = 0; i < size; i++) {
        count[(arr[i] / exp) % 10]++;
    }

    // Modifica count[] para que ele contenha a posição atual de cada dígito em output[]
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Constrói o array de saída
    for (int i = size - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copia o array de saída para arr[], de modo que arr[] agora contenha os números ordenados pelo dígito atual
    for (int i = 0; i < size; i++) {
        arr[i] = output[i];
    }
}

// Radix
void radixSort(int arr[], int size) {
    // Encontra o maior número para saber o número de dígitos
    int max = getMax(arr, size);

    // Faz a ordenação para cada dígito, passando de unidade para dezena, centena, etc.
    for (int exp = 1; max / exp > 0; exp *= 10) {
        countSortRadix(arr, size, exp);
    }
}

