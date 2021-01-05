#include <stdio.h>
#include <stdlib.h>

int compara(const void *a, const void *b) {
    return ( *(int*)a - *(int*)b);
}

int pesquisaBinaria (int *n, int numProcurado, int total){
    int inferior = 0;
    int superior = total-1;
    int metade = 0;

    while (inferior <= superior){
        metade = (inferior + superior)/2;
        if (n[metade] == numProcurado)
            return metade;
        if (n[metade] > numProcurado)
            superior = metade-1;
        else
            inferior = metade+1;
    }

    return -1;
}

int main() {
    int numN, numM, i = 0;
    int *n, *m, *temp,resposta;

    scanf("%d %d", &numN, &numM);

    n = malloc(numN*sizeof(int));
    temp = malloc(numN*sizeof(int));
    m = malloc(numM*sizeof(int));

    for(i = 0; i < numN; i++){
        scanf("%d", &n[i]);
    }
    for(i = 0; i < numM; i++){
        scanf("%d", &m[i]);
    }

    for(i = 0; i < numN; i++){
        temp[i] = n[i];
    }
    

    qsort(((int *)n), numN, sizeof(int), compara);

    for(i = 0; i < numM; i++){
        resposta = pesquisaBinaria(n, m[i], numN);
        if(resposta == -1)
            printf("%d\n", resposta);
        else{
            for(int j = 0; j < numN; j++){
                if(temp[j]==n[resposta]){
                    printf("%d\n", j);
                }
            }
        }
    }

    free(n);
    free(m);

    return 0;
}