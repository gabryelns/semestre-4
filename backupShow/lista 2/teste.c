#include<stdio.h>

int main(){

    int n = 12;
    printf("%d\n", n%2);
    return 0;
}


/*int main() {
    celula *celulal = (celula *)malloc(sizeof(celula));
    celulal->prox = NULL;

    for (int i = 1; i <= 5; i++) {
        celula *nova_celula = (celula *)malloc(sizeof(celula));
        nova_celula->dado = i;
        nova_celula->prox = celulal->prox;
        celulal->prox = nova_celula;
    }
    celula *celulal1 = (celula *)malloc(sizeof(celula));
    celula *celulal2 = (celula *)malloc(sizeof(celula));   

    divide_lista(celulal, celulal1, celulal2);
    
    return 0;
}*/

/*

// main para imprimir uma listA

int main() {
    celula *le = (celula *)malloc(sizeof(celula));
    le->prox = NULL;

    
    for (int i = 1; i <= 5; i++) {
        celula *nova_celula = (celula *)malloc(sizeof(celula));
        nova_celula->dado = i;
        nova_celula->prox = le->prox;
        le->prox = nova_celula;
    }

    printf("Imprimindo a lista de forma iterativa:\n");
    imprime(le);

    printf("Imprimindo a lista de forma recursiva:\n");
    imprime_rec(le);

    return 0;
}*/

/*celula *atual = le->prox;
    while (atual != NULL) {
        celula *temp = atual;
        atual = atual->prox;
        free(temp);
    }
    free(le);*/
