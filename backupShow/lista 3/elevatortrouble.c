#include <stdio.h>
#include <stdlib.h>

int min_apertar(int f, int s, int g, int u, int d) {
    int *passados = malloc(sizeof(int) *(f+ 1));

    for (int i =1; i <=f; i++) passados[i]= 0;

    int *fila =malloc(sizeof(int) * (f + 1));
    int comeco = 0;
    int final= 0;

    fila[final++]= s;
    passados[s] = 1;

    int clicks =0;
    int qtd = 1;

    while (comeco <final) {
        int newqtd= 0;

        for (int i =0; i <qtd; i++){
            int atual =fila[comeco++];

            if (atual== g) {
                free(passados);
                free(fila);
                return clicks;
            }

            int emcima= atual +u;
            int embaixo = atual- d;

            if (emcima <=f && passados[emcima] ==0){

                passados[emcima] =1;
                fila[final++]= emcima;
                newqtd++;
            }
            if (embaixo >=1 && passados[embaixo] == 0) {
                passados[embaixo]= 1;
                fila[final++] = embaixo;
                newqtd++;
            }

        }
        clicks++;
        qtd =newqtd;
    }

    free(passados);
    free(fila);

    return -1;
}

int main() {

    int f, s, g, u, d;
    scanf("%d %d %d %d %d", &f, &s, &g, &u, &d);

    int clicks = min_apertar(f, s, g, u, d);

    if(clicks== -1) printf("use the stairs\n");
    else printf("%d\n", clicks);

    return 0;
}