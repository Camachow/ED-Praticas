#include <iostream>

// Função para mesclar dois subarrays de arr[]
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

// Função principal que implementa o Merge Sort
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
/* 
// Função para imprimir os elementos do array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    // Exemplo de uso do Merge Sort
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Array original: ";
    printArray(arr, n);

    mergeSort(arr, 0, n - 1);

    std::cout << "Array ordenado: ";
    printArray(arr, n);

    return 0;
} */