#include <iostream>

// Função para realizar a ordenação por inserção em um array
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;

        // Mover os elementos de arr[0..i-1] que são maiores que a chave
        // uma posição à frente de sua posição atual
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
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
    // Exemplo de uso do Insertion Sort
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Array original: ";
    printArray(arr, n);

    insertionSort(arr, n);

    std::cout << "Array ordenado: ";
    printArray(arr, n);

    return 0;
}*/