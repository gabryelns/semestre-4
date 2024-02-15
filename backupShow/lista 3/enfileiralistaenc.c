#include<stdio.h>

typedef struct celula {
int dado;
struct celula *prox;
} celula;

celula *enfileira (celula *f, int x){

   celula *newcel= malloc(sizeof(celula));
    if(newcel ==NULL || f== NULL)
        return NULL;
    newcel->prox = f->prox;
    f->prox= newcel;
    f->dado =x;
    f =newcel;
    return newcel;

}