#include<stdio.h>

typedef struct {
int *v; // Vetor que contem os elementos da pilha
int N; // Tamanho de v
int topo; // Indicador do topo
} pilha;

void empilha (pilha *p, int x){

    if (p->topo == p->N)
    {
        p->N *=2;
        int *novo =realloc(p->v, p->N *sizeof(int));
        if(novo ==NULL)
            return;
        p->v=novo;
    }

    p->v[p->topo] = x;
    p->topo++;  

}

int desempilha (pilha *p, int *y){

    if (p->topo== 0)return 0;

    p->topo--;
    *y= p->v[p->topo]; 

    return 1;

}