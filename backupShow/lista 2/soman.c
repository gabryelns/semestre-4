#include <stdio.h>

int soman(unsigned long int n, unsigned int saida){

    if(n == 0) return saida;
    saida += n%10;
    n/=10;
    return soman(n,saida);
}

int main() {

    unsigned long int n,saida=0;

    scanf("%ld", &n);
    printf("%d\n", soman(n,saida));

    return 0;
}