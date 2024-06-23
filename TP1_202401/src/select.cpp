#include <iostream>

// Função para realizar a ordenação por seleção em um array
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

// Função para imprimir os elementos do array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

/*
int main() {
    // Exemplo de uso do Selection Sort
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Array original: ";
    printArray(arr, n);

    selectionSort(arr, n);

    std::cout << "Array ordenado: ";
    printArray(arr, n);

    return 0;
}*/