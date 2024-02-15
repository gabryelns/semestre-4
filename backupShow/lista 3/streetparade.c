#include <stdio.h>
#include <stdlib.h>

int street_parade(int *order, int n){
    int aux= 1;
    int *pilha =malloc(sizeof(int) * n);
    int topo =0;
    int marca = 0;

    for (int i=0; i < n; i++) {

        if (order[i] ==aux) aux++;

        else if (topo > 0 && pilha[topo -1] == aux) {
            topo--;
            aux++;
            i--;
        }
        else pilha[topo++] =order[i];
    }

    while (topo >0) {
        if(pilha[topo- 1]== aux) {
            topo--;
            aux++;
        }
        else return 0;
    }
    return 1;
}

int main() {
    int n;

    while (scanf("%d",&n) !=0) {

        if(n ==0) break;

        int *order =malloc(sizeof(int) *(n + 1));

        for (int i = 0; i < n; i++) scanf("%d", &order[i]);

        int possible = street_parade(order, n);

        if (possible) printf("yes\n");

        else printf("no\n");
    }

    return 0;
}