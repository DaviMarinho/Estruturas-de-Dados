#include <stdio.h>

int main(){
    int idadeMonica=0, idadeFilhos[3], idadeFMaior=0, i=0;

    scanf("%d", &idadeMonica);
    while(i<2){
        scanf("%d", &idadeFilhos[i]);
        i++;
    }
    idadeFilhos[2] = 0;
    idadeFilhos[2] = idadeMonica - (idadeFilhos[0] + idadeFilhos[1]);

    for(i=0;i<3;i++){
        if(idadeFilhos[i]>idadeFMaior){
            idadeFMaior = idadeFilhos[i];
        }
    }

    printf("%d\n", idadeFMaior);


    return 0;
}
