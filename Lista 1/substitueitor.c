#include <stdio.h>
#include <string.h>

int main(){
    char frase[10500];
    char palavra1[41];
    char palavra2[41];
    int cont=0, procura=0;

    scanf("%[^\n]", frase);
    scanf("%s", palavra1);
    scanf("%s", palavra2);

    for(cont = 0; frase[cont] != '\0'; cont++){
        if(frase[cont] == palavra1[procura])
            procura++;
        else{
            if(procura > 0){
                if(palavra1[procura] == '\0'){
                    printf("%s", palavra2);
                    procura = 0;
                }
                else{
                    while(procura > 0){
                        printf("%c", frase[cont-procura]);
                        procura--;
                    }
                }
            }
            printf("%c", frase[cont]);
        }
    }

    if(palavra1[procura] == '\0' && procura > 0){
        printf("%s", palavra2);
        procura = 0;
    } 

    printf("\n");
}