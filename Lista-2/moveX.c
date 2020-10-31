#include <stdio.h>

    int conta7(unsigned long int num, unsigned long int quantidade){
        int resto = 0;
        if(num > 0 ){
            resto = num % 10;
            if(resto==7)
                quantidade++;
            return conta7(num = (num - resto) / 10, quantidade);
        }
        return quantidade;
    }

int main(){
    unsigned long int numero = 0;
    unsigned long int quantidade = 0;

    scanf("%ld", &numero);

    quantidade = conta7(numero, quantidade);

    printf("%ld\n", quantidade);

    return 0;
}
