#include <stdio.h>
#include <string.h>

void trocaxy(char *nomex, int posicao, char *nomey) {
    if (nomex[posicao] == '\0') return;

    if (nomex[posicao] == 'x') nomey[posicao] = 'y';
    else nomey[posicao] = nomex[posicao];
    
    trocaxy(nomex, posicao+1, nomey);
}

int main() {
    char entradax[1001];
    char saiday[1001];
    int posicao =0;

    scanf("%s", entradax);
    trocaxy(entradax, posicao, saiday);
    printf("%s\n", saiday);
    return 0;
}