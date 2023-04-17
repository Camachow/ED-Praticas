#include <iostream>
using namespace std;

//Fibonacci Recursivo

int fibonacciRecursivo(int n) {
    if (n <= 1) {
        return n;
    } else {
        return fibonacciRecursivo(n-1) + fibonacciRecursivo(n-2);
    }
}

//Fibonacci Iterativo

int fibonacciIterativo(int n) {
    int fib1 = 0, fib2 = 1, fib = 0;
    for (int i = 2; i <= n; i++) {
        fib = fib1 + fib2;
        fib1 = fib2;
        fib2 = fib;
    }
    return (n == 0) ? fib1 : fib;
}

//Fatorial Recursivo

int fatorialRecursivo(int n) {
    if (n <= 1) {
        return n;
    } else {
        return n * fatorialRecursivo(n-1);
    }
}

//Fatorial Iterativo

int fatorialIterativo(int n) {
    int fat = 1;
    for (int i = 2; i <= n; i++) {
        fat *= i;
    }
    return fat;
}

int main() {
    int n;
    cout << "Qual operacao deseja realizar? (1 - Fibonacci, 2 - Fatorial): ";
    cin >> n;
    if (n == 1) {
        n = 5;
        cout << "Fibonacci(" << n << ") = " << fibonacciRecursivo(n) << endl;
        cout << "Fibonacci(" << n << ") = " << fibonacciIterativo(n) << endl;
    } else if (n == 2) {
        n = 5;
        cout << "Fatorial(" << n << ") = " << fatorialRecursivo(n) << endl;
        cout << "Fatorial(" << n << ") = " << fatorialIterativo(n) << endl;
    } else {
        cout << "Operacao invalida!" << endl;
    }
    return 0;
}
