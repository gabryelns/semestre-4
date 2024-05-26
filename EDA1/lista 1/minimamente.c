#include <stdio.h>

int main() {
    int v[1000];
    int max, n,soma =0, i=0, saida[1000]={0};

    do {
        scanf("%d", &n);
        if (n == 0) break;
        v[i] = n;
        i++;
    } while (i < 1000);

    scanf("%d", &max);
    int conta = i;

    for (int j = 0; j < i; j++) {
        soma += v[j];
        if (soma > max)
        {
            saida[conta] = v[j];
            conta--;
            soma = 0;
        }
        
    }

    for (int j = 0; j < i+1; j++) {
        if (saida[j] != 0) printf("%d\n", saida[j]);    
    }

    return 0;
}
