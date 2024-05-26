#include<stdio.h>

typedef struct celula {
int dado;
struct celula *prox;
} celula;

int desenfileira (celula *f, int *y){

    if (f== NULL) return 0;
        
    celula *newcel = f->prox;
    *y= newcel->dado;
    f->prox =newcel->prox;
    
    free(newcel);

    return 0;

}