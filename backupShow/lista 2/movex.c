#include <stdio.h>
#include <string.h>

void move(char *nome, int posicao, char *aux1, char *aux2,int iaux1, int iaux2) {
    if (nome[posicao] == '\0') return;

    if (nome[posicao] == 'x') {aux2[iaux2] = 'x';
    iaux2++;
    }
    else {aux1[iaux1] = nome[posicao];
    iaux1++;
    }

    move(nome, posicao+1, aux1,aux2, iaux1, iaux2);
}

int main() {
    char entrada[1001];
    char aux1[1001], aux2[1001];

    int iaux1 =0,iaux2=0;

    scanf("%s", entrada);
    move(entrada, 0, aux1, aux2, iaux1,iaux2);
    printf("%s", aux1);
    printf("%s\n", aux2);

    return 0;
}
