#include<stdio.h>

int pares(char *palavra, int posicao,int contapares){

    if (palavra[posicao] == '\0' ||palavra[posicao+1] == '\0') return contapares;
    if(palavra[posicao] == palavra[posicao +2]) return pares(palavra, posicao+1, contapares+1);

    return pares(palavra, posicao+1, contapares);
}

int main(){

    char entrada[201];
    int contapares = 0, posicao =0;

    scanf("%s", entrada);

    printf("%d\n", pares(entrada, posicao, contapares));

    return 0;
}