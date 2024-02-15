#include <stdio.h>
#include <string.h>

int grau9(char *num) {
    int tamanho = strlen(num);
    int soma = 0;

    for (int i = 0; i < tamanho; i++) {
        soma += num[i] - '0';
    }

    if (soma % 9 != 0) {
        return 0;
    }

    if (soma == 9) {
        return 1;
    }

    char novon[1001];
    sprintf(novon, "%d", soma);

    return 1 + grau9(novon);
}

int main() {
    char num[1001];

    while (1) {
        scanf("%s", num);
        if (num[0] == '0') break;

        int grau = grau9(num);

        if (grau > 0) {
            printf("%s is a multiple of 9 and has 9-degree %d.\n", num, grau);
        } else {
            printf("%s is not a multiple of 9.\n", num);
        }
    }

    return 0;
}