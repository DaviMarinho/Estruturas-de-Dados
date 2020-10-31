#include <stdio.h>
#include <string.h>

int main(){
    char telefone[100];
    int i;

    scanf("%[^\n]", telefone);
    
    for(i=0;i<strlen(telefone);i++){
        if (telefone[i] == 'A' || telefone[i] == 'B' || telefone[i] == 'C'){
            telefone[i] = '2';
        }
        else if (telefone[i] == 'D' || telefone[i] == 'E' || telefone[i] == 'F'){
            telefone[i] = '3';
        }
        else if (telefone[i] == 'G' || telefone[i] == 'H' || telefone[i] == 'I'){
            telefone[i] = '4';
        }
        else if (telefone[i] == 'J' || telefone[i] == 'K' || telefone[i] == 'L'){
            telefone[i] = '5';
        }
        else if (telefone[i] == 'M' || telefone[i] == 'N' || telefone[i] == 'O'){
            telefone[i] = '6';
        }
        else if (telefone[i] == 'P' || telefone[i] == 'Q' || telefone[i] == 'R' || telefone[i] == 'S'){
            telefone[i] = '7';
        }
        else if (telefone[i] == 'T' || telefone[i] == 'U' || telefone[i] == 'V'){
            telefone[i] = '8';
        }
        else if (telefone[i] == 'W' || telefone[i] == 'X' || telefone[i] == 'Y' || telefone[i] == 'Z'){
            telefone[i] = '9';
        }
    }
    printf("%s\n", telefone);
}