#include <stdio.h>

int main (){

    int n, v[100], atual, g=0;

    scanf("%d",&n);

    for(int i=0; i <= n; i++){
        scanf("%d", &v[i]);
    }
    for(int i=0; i <= n; i++){
        
        if(v[i] < v[i+1]) {atual = v[i];
        g = i;
        }
    }
    
    printf("%d\n", g);

    return 0;
}