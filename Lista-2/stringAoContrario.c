#include <stdio.h>
#include <string.h>

void contrario(char palavra[]) {

    if (palavra[0] != '\0'){
        contrario(&palavra[1]);
        printf("%c",palavra[0]);
    }

}

int main(void) {
    char palavra[500];

    scanf("%[^\n]", palavra);

    contrario(palavra);
    printf("\n"); 

    return 0;
    }