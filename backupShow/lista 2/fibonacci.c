#include<stdio.h>

long int memoria[81] = {0};

long int fibonacci(int n) {
    if (n == 2 || n==1) return 1;

    if (memoria[n] != 0) {
        return memoria[n];
    }

    memoria[n] = fibonacci(n - 1) + fibonacci(n - 2);
    return memoria[n];
}