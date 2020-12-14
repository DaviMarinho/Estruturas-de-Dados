#include <stdio.h>

int somaDigitos(long int num, long int soma){
    long int resto = 0;
    if(num > 0){
        resto = num % 10;
        soma += resto;
        return somaDigitos(num = (num - resto) / 10, soma);
    }

    return soma;

}

int main(){
    long int numero;
    long int soma = 0;

    scanf("%ld", &numero);

    soma = somaDigitos(numero, soma);

    printf("%ld\n", soma);

    return 0;
}