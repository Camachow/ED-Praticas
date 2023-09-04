#include "../include/fatorial.h"

int fatorialIterativo(int n) {
    int f = 1;

    while(n > 0){
        f *= n;
        n--;
    }
    return f;
};

int fatorialRecursivo(int n) {
    if (n <= 0) {
        return 1;
    } else {
        return n * fatorialRecursivo(n-1);
    }
};