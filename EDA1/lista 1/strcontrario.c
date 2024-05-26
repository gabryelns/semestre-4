#include <stdio.h>
#include <string.h>

int tamanhosub(char *string) {
    if (*string == '\0') {
        return 0;
    }
    return 1 + tamanhosub(string + 1);
}

void stringcontrario(char *palavra, int posicao, char *contrario, int tamanho) {
    if (palavra[posicao] == '\0') return;

    contrario[posicao] = palavra[tamanho];
    
    stringcontrario(palavra, posicao+1, contrario, tamanho-1);
}

int main(){

    char entrada[1002];
    char contrario[1002];
    int posicao =0;

    scanf("%s", entrada);
    int tamanho = -1;
    tamanho += tamanhosub(entrada);

    stringcontrario(entrada, posicao, contrario, tamanho);
    printf("%s\n", contrario);

    return 0;
}