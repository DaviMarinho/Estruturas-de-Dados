#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int somaEImprime() {
    int soma=0;
    char c;
    scanf("%c", &c);

    if(c=='0') 
        return 0;

    while(isdigit(c)){
        soma += (c - '0');
        printf("%c",c);
        scanf("%c", &c);
    }

    return soma;
}

int somaDigitos (int numero) {
    if(numero<10)
        return numero;

    else
        return(numero%10 + somaDigitos(numero/10));
}

int grauDoNumero (int numero) {
    int grau;
    if (numero<10) 
        if(numero==9)
            return 1;
        else
            return 0;
    else { 
        grau = grauDoNumero (somaDigitos(numero));

        if(grau == 0) 
            return 0;
        else
            return grau+1;
    }
}

int main() {
    int grauNumero;
    int numero;

    while(1){
        numero = somaEImprime();

        if(numero==0) 
            break;

        grauNumero = grauDoNumero(numero);

        if (grauNumero==0)
            printf(" is not a multiple of 9.\n");
        else 
            printf(" is a multiple of 9 and has 9-degree %d.\n", grauNumero);
    }
    return 0;
}