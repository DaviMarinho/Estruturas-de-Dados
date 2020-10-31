#include <stdio.h>

int potenciacao(double num, double pot){
    if(pot == 0)
        return 1;
    if(pot < 0)
        return num*potenciacao(num, pot+1);
    else
        return num*potenciacao(num, pot-1);
}

int main(){
    double numero=0, potencia=0, final=0;

    scanf("%lf", &numero);
    scanf("%lf", &potencia);

    if(numero == 0 && potencia == 0){
        printf("indefinido\n");
        return 0;
    }

    final = potenciacao(numero, potencia);

    if(potencia<0){
        if(final==0){
            printf("indefinido\n");
            return 0;
        }
        else
            final = 1/final;
    }

    printf("%lf\n", final);

    return 0;
}