#include "../include/fibonacci.h"

int fibonacciRecursivo(int n) {
    if (n < 3) {
        return 1;
    } else {
        return fibonacciRecursivo(n-1) + fibonacciRecursivo(n-2);
    }
}

int fibonacciIterativo(int n) {
    int fib1 = 0, fib2 = 1, fib = 0;
    for (int i = 2; i <= n; i++) {
        fib = fib1 + fib2;
        fib1 = fib2;
        fib2 = fib;
    }
    return (n == 0) ? fib1 : fib;
}