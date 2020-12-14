#include <stdio.h>

int main(){
    int i, j, k, soma;
    int final;

    scanf("%d %d %d", &i, &j, &k);
    scanf("%d", &final);

    soma = i+j+k;

    if(final==soma)
        printf("Acertou\n");
    else
        printf("Errou\n");
    
    return 0;
}
