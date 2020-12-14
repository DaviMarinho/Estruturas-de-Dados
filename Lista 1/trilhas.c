#include <stdio.h>

int main(){
    int numTrilhas;
    int i, j, numPontos, pontos=0, pontosP[1000];
    int melhorCaminho, melhorTrilha, subidaIda, subidaVolta, subida;

    scanf("%d", &numTrilhas);

    for(i=0; i<numTrilhas;i++){
        scanf("%d", &numPontos);
        for(j=0;j<numPontos;j++){
            scanf("%d", &pontosP[j]);
        }
        for(j=1;j<numPontos;j++){
            if(pontosP[j]>pontosP[j-1]){
                subidaIda += pontosP[j]-pontosP[j-1];
            }   
        }
        for(j=numPontos-1;j>-1;j--){
            if(pontosP[j]<pontosP[j-1]){
                subidaVolta += pontosP[j-1]-pontosP[j];
            }
        }  
        if(subidaIda>subidaVolta){
            subida=subidaVolta;
        }else{
            subida=subidaIda;
        }
        if(i==0){
            melhorCaminho=subida;
            melhorTrilha=i+1;
        }
        if(subida<melhorCaminho){
            melhorTrilha=i+1;
            melhorCaminho=subida;
        }
        subidaIda=0;
        subidaVolta=0;
        subida=0;
        }

    printf("%d\n", melhorTrilha);

    return 0;
}