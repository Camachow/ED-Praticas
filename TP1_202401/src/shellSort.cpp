#include <iostream>

// Função para realizar a ordenação Shell Sort em um array
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

// Função para imprimir os elementos do array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    // Exemplo de uso do Shell Sort
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Array original: ";
    printArray(arr, n);

    shellSort(arr, n);

    std::cout << "Array ordenado: ";
    printArray(arr, n);

    return 0;
}
