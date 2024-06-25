#include <iostream>
#include <cstdlib>
#include <iomanip>
#include "../include/sorts.h"

const int MAX_SIZE = 50000; // Tamanho máximo do vetor

int main() {
    // Exemplo de uso do Merge Sort
    int arr[MAX_SIZE];

    //int n = sizeof(arr) / sizeof(arr[0]);

    std::cout << std::fixed << std::setprecision(6); // Configurar precisão da saída
    
    for (int size = 50; size <= MAX_SIZE; size += 50) {
        
        //generateReverseSortedArray(arr, size);
        //generateRandomArray(arr, size, MAX_SIZE);
        generateSortedArray(arr, size); 
        
        double time = getExecutionTime(bubbleSort, arr, size);
        
        //std::cout << "Tamanho do vetor: " << size << ", Tempo de execução: " << time << " segundos" << std::endl;
        //std::cout << size << ", " << std::endl;
        std::cout << time << ", " << std::endl;
    }

    //printArray(arr, MAX_SIZE);
    return 0;
}