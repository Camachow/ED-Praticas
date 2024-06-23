#include <iostream>

// Função para trocar dois elementos
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Função para encontrar a posição de partição e colocar o pivô no lugar correto
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

// Função principal que implementa o Quick Sort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // pi é o índice de partição, arr[pi] está no lugar correto
        int pi = partition(arr, low, high);

        // Ordenar os elementos separadamente antes e depois da partição
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
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
    // Exemplo de uso do Quick Sort
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Array original: ";
    printArray(arr, n);

    quickSort(arr, 0, n - 1);

    std::cout << "Array ordenado: ";
    printArray(arr, n);

    return 0;
}
