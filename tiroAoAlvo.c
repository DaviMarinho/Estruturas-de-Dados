#include <stdio.h>
#include <stdlib.h>

int buscaPontos(long long int valor, int circulos, long long int *raio){
	int inicio = 1;
    int fim = circulos;
    int meio = 0;
	
	if(valor>raio[circulos])
    	return 0;
	while(inicio<fim){
		meio = (inicio+fim)/2;
		if(raio[meio] >= valor)
			fim = meio;
		else
			inicio = meio+1;
	}
	return circulos+1-fim;
}

int main(){
    int circulos, tiros;
    long long int raio[500000];
    long long int x, y, pontos = 0;

    scanf("%d %d", &circulos, &tiros);

    for(int i = 1; i <= circulos; i++){
        scanf("%lld", &raio[i]);
        raio[i] = raio[i]*raio[i]; 
    }

    for(int i = 1; i <= tiros; i++){
        scanf("%lld %lld", &x, &y);
        pontos += buscaPontos((x*x+y*y), circulos, raio);
    }

    printf("%lld\n", pontos);

    return 0;
}