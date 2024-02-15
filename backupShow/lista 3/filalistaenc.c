#include<stdio.h>

typedef struct celula {
int dado;
struct celula *prox;
} celula;

void enfileira (celula **f, int x){

    celula *new = malloc(sizeof(celula));
    new->prox = (*f)->prox;
    (*f)->prox = new;
    (*f)->dado = x;
    (*f) = new;

}

int desenfileira (celula *f, int *y){

    celula *remove =f->prox;
    *y = remove->dado;

    if (f->prox ==f)
        return 0;
    else
        f->prox = remove->prox;

    return 1;

}