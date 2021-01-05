#include <stdio.h>

int main(){
    int numeros[1001];
    int total=0, aux = 0;

    while(scanf("%d", &numeros[total])!= EOF){
        total++;
    }

for (int contador = 1; contador < total; contador++) {
    for (int i = 0; i < total - 1; i++) {
        if (numeros[i] > numeros[i + 1]) {
            aux = numeros[i];
            numeros[i] = numeros[i + 1];
            numeros[i + 1] = aux;
        }
    }
}

    for(int i = 0; i < total; i++){
        if(i == total-1)
            printf("%d\n", numeros[i]);
        else
            printf("%d ", numeros[i]);
    }
    
    return 0;
}