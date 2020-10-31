#include <stdio.h>

int main(){
    int nota=0, codigo=0, restaurantes=0, melhornota, menorcodigo, dias=0, melhorrest[1000];
    int i;
    while(scanf("%d", &restaurantes)!=EOF){
        melhornota=-1;
        menorcodigo=9999999;
        for(i=0;i<restaurantes; i++){
            scanf("%d", &codigo);
            scanf("%d", &nota);
            if(nota==melhornota){
                if(codigo<menorcodigo){
                    menorcodigo=codigo;
                    melhorrest[dias]=menorcodigo;
                }
            }
            if(nota>melhornota){
                melhornota = nota;
                
                menorcodigo = codigo;
                melhorrest[dias]=menorcodigo;
            }
        }
        dias++;
    }
    for(i=0; i<dias; i++){
        printf("Dia %d\n", i+1);
        printf("%d\n", melhorrest[i]);
        printf("\n");
    }
    return 0;
}