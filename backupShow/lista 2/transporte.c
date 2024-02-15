#include<stdio.h>

#include <stdio.h>

int main (){

    int a,b,c,x,y,z,res;
    scanf("%d%d%d%d%d%d", &a,&b,&c,&x,&y,&z);

    if(c > z) printf("0\n");
    else
    {
        x /= a;
        y /= b;
        z /= c;
        res = a * b * c;
        printf("%d\n", res);

    }
    return 0;
}
