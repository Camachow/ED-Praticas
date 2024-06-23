#include <iostream>
#include <cstring> // Para usar a função memset

// Função para obter o maior valor no array
int getMax(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Função para realizar a ordenação de contagem para um dígito específico
void countSort(int arr[], int size, int exp) {
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

// Função principal para implementar o Radix Sort
void radixSort(int arr[], int size) {
    // Encontra o maior número para saber o número de dígitos
    int max = getMax(arr, size);

    // Faz a ordenação para cada dígito, passando de unidade para dezena, centena, etc.
    for (int exp = 1; max / exp > 0; exp *= 10) {
        countSort(arr, size, exp);
    }
}
