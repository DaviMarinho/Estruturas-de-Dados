#include <stdio.h>

int main(){
    int aeroportos, voos, aeroX, aeroY;
    int i=0, teste=1, maior, j;
    int quantidades[101];

    scanf("%d %d", &aeroportos, &voos);

    //for(i=0; i<aeroportos;i++)
        //quantidades[i]=0;

    while(aeroportos!=0 && voos!=0){

        for(i=0; i<=aeroportos;i++){
            quantidades[i]=0;
        }

        for(j=0;j<voos;j++){
            scanf("%d %d", &aeroX, &aeroY);
            quantidades[aeroX] += 1;
            quantidades[aeroY] += 1;
        }

        maior = 0;
        for(i=1; i<=aeroportos;i++){
            //if(i==1)
                //maior=quantidades[i];
            if(quantidades[i]>=maior)
                maior=quantidades[i];
        }

        printf("Teste %d\n", teste);
        for(i=1; i<=aeroportos;i++){
            if(quantidades[i]==maior)
                printf("%d ", i);
        }
        printf("\n\n");

        teste++;
        scanf("%d %d", &aeroportos, &voos);
    }

    return 0;
}