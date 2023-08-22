#include "../include/randomVet.hpp"

std::vector<int> gerarVetorAleatorio(int tamanho, int valorMinimo, int valorMaximo) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(valorMinimo, valorMaximo);

    std::vector<int> vetor;

    for (int i = 0; i < tamanho; ++i) {
        int valor = dis(gen);
        vetor.push_back(valor);
    }

    return vetor;
}

void imprimirVetor(std::vector<int> vetor) {
    for (int valor : vetor) {
        std::cout << valor << " ";
    }
    std::cout << std::endl;
}