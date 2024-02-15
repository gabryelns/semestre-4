#include<stdio.h>

typedef struct celula {
int dado;
struct celula *prox;
} celula;

void empilha (celula *p, int x){

    celula *newcel = malloc(sizeof(celula));
    newcel->dado =x;
    newcel->prox= p->prox;
    p->prox =newcel;

}

int desempilha (celula *p, int *y){

    celula *remove =p->prox;

    if(remove ==NULL) return 0;

    p->prox= remove->prox;
    *y =remove->dado;

    free(remove);
    return 1;

}