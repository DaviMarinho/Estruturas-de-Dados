#include <stdio.h>
#include <stdlib.h>

void printaX(int quantidadeX){
    
    if(quantidadeX == 0)
        return;
    else{
        printf("x");
        quantidadeX--;
    }   
    printaX(quantidadeX);
}

void moveX(char palavra[], char *palavra2, int j, int k, int quantidadeX){

        if(palavra[j] != '\0'){
            if(palavra[j] != 'x'){
                palavra2[k] = palavra[j];
                k++;
            }
            if(palavra[j] == 'x')
                quantidadeX++;
            j++;
            moveX(palavra, palavra2, j, k, quantidadeX);
        }else{
            printf("%s", palavra2);
            printaX(quantidadeX);
        }
}

int main(){
    char palavra[101];
    char *palavra2;
    int j = 0, k = 0;
    int quantidadeX = 0;

    scanf("%[^\n]", palavra);

    palavra2 = malloc(sizeof(char)*101);
    
    moveX(palavra, palavra2, j, k, quantidadeX);

    printf("\n");

    return 0;
}