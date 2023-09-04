#include <iostream>
#include "../include/fibonacci.h"
#include "../include/fatorial.h"
using namespace std;

int main() {
    int n;
    cout << "Qual o valor de n? ";
    cin >> n;
    cout << "Qual operacao deseja realizar?: " << endl;
    cout << "(1 - Fibonacci Iterativo, 2 - Fibonacci Recursivo, 3 - Fatorial Iterativo, 4 - Fatorial Recursivo)" << endl;
    int op;
    cin >> op;
    switch (op) {
        case 1:
            cout << "Fibonacci Iterativo: " << fibonacciIterativo(n) << endl;
            break;
        case 2:
            cout << "Fibonacci Recursivo: " << fibonacciRecursivo(n) << endl;
            break;
        case 3:
            cout << "Fatorial Iterativo: " << fatorialIterativo(n) << endl;
            break;
        case 4:
            cout << "Fatorial Recursivo: " << fatorialRecursivo(n) << endl;
            break;
        default:
            cout << "Opcao invalida!" << endl;
            break;
    }
    return 0;
}
