#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

void divide_lista (celula *l, celula *l1, celula *l2){

    celula *atual = l->prox;
    celula *atual1= l1;
    celula *atual2 =l2;

    while (atual !=NULL) {
        if (atual->dado%2== 0) {
            atual2->prox = atual;
            atual2= atual2->prox;
        }
        else {
            atual1->prox= atual;
            atual1 =atual1->prox;
        }
        atual = atual->prox;
    }

    atual1->prox = NULL;
    atual2->prox = NULL;
    l->prox = NULL;
}
