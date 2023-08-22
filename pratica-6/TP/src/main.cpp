#include "../include/shellsort.hpp"
#include "../include/randomVet.hpp"
#include "../include/heapsort.hpp"
#include <iostream>

using namespace std;

int main(){
    //Gerando 5 vetores aleatórios

    vector<int> v1 = gerarVetorAleatorio(10, 0, 10000);
    vector<int> v2 = gerarVetorAleatorio(10, 0, 10000);
    vector<int> v3 = gerarVetorAleatorio(10, 0, 10000);
    vector<int> v4 = gerarVetorAleatorio(10, 0, 10000);
    vector<int> v5 = gerarVetorAleatorio(10, 0, 10000);
    
    //Imprimindo os vetores
    cout << "Vetor 1: \n";
    void imprimirVetor(v1);

    cout << "Vetor 2: \n";

    cout << "Vetor 3: \n";

    cout << "Vetor 4: \n";

    cout << "Vetor 5: \n";
    
    return 0;
}