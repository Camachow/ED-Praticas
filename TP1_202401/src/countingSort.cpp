// Função para encontrar o maior elemento no array
int findMax(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Função de ordenação Counting Sort
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

