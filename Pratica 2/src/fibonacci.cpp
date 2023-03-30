#include <iostream>
using namespace std;

//Recursivo

int fibonacciRecursivo(int n) {
    if (n <= 1) {
        return n;
    } else {
        return fibonacciRecursivo(n-1) + fibonacciRecursivo(n-2);
    }
}

//Iterativo

int fibonacciIterativo(int n) {
    int fib1 = 0, fib2 = 1, fib = 0;
    for (int i = 2; i <= n; i++) {
        fib = fib1 + fib2;
        fib1 = fib2;
        fib2 = fib;
    }
    return (n == 0) ? fib1 : fib;
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    cout << "Fibonacci(" << n << ") = " << fibonacciIterativo(n) << endl;
    return 0;
}
