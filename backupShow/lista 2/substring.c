#include <stdio.h>

int contadorcrescente(char *string, char *subString, int posicao, int posicao_2, int tamanho1, int qtd)
{   

    if(qtd== strlen(subString)) 
    {
        return posicao;
    }
    
    if(string[posicao] == subString[posicao_2])
    {
        return contadorcrescente(string, subString, ++posicao, ++posicao_2, tamanho1, ++qtd); 
    }
    else if(string[posicao] == '\0') 
        return -1;
    else if(string[posicao] == subString[0])
        return contadorcrescente(string, subString, posicao, 0, tamanho1, 0);
    else
         return contadorcrescente(string, subString, ++posicao, 0, tamanho1, 0);
}

int contadordecrescente(char *string,char *subString, int posicao, int posicao_2, int tamanho1,int qtd)
{   

    if(qtd ==tamanho1)
    {   
        if(posicao== -1)
            return posicao + 1;
        else
            return posicao;
    }

    if(string[posicao]== subString[posicao_2])
    {
        return contadordecrescente(string, subString,--posicao, --posicao_2, tamanho1, ++qtd);
    }
    else if(posicao == -1)
        return -1;
    else if(string[posicao] == subString[tamanho1 - 1]) 
        return contadordecrescente(string, subString, posicao, tamanho1 - 1, tamanho1, 0);
    else
        return contadordecrescente(string, subString,--posicao,tamanho1 - 1,tamanho1, 0); }

int main()
{
    char string[101];
    char subString[101];
    scanf("%s",string);
    scanf("%s",subString);

    int tamanho = strlen(string);
    int tamanho1 =strlen(subString); 

    int resultado1= contadorcrescente(string, subString, 0, 0, tamanho1, 0);

    int resultado2= contadordecrescente (string, subString, (tamanho- 1), (tamanho1- 1),tamanho1, 0); 

    int resultado3 =0;

    if(resultado1 !=-1 && resultado2 != -1)
        resultado3 =resultado2 -resultado1 + (2 * strlen(subString)+ 1); 

    if(resultado3!= 0 &&resultado3 == tamanho1 + 1)
        printf("%d\n",tamanho1); 
        else
        printf("%d\n", resultado3);

    return 0;
}