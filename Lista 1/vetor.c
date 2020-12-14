#include <stdio.h>

int main(){
    int num, procura, i, j, k=0;

    scanf("%d", &num);
    int vetor[num];

    for(i = 0; i < num;i++){
        scanf("%d", &vetor[i]);
    }
    
    scanf("%d", &procura);

    for(i = 0; i<num;i++){
        if(vetor[i]==procura){
            k=1;
        }
    }

    if(k==1){
        printf("pertence\n");
        }
    else{
        printf("nao pertence\n");
    }
}