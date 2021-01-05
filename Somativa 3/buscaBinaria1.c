#include <stdio.h>
#include <stdlib.h>

int buscaBinaria (int *v, int x, int n) { 
    int e = -1, d = n;
    while (e < d-1) {  
        int m = (e + d)/2;
        if (v[m] < x) 
            e = m;
        else 
            d = m; 
    }
    return d;
}

int main(){
    int numN, numM, i = 0, j = 0, k = 0;
    int *n, *m, resposta;

    scanf("%d %d", &numN, &numM);

    n = malloc(numN*sizeof(int));
    m = malloc(numM*sizeof(int));

    for(i = 0; i < numN; i++){
        scanf("%d", &n[i]);
    }
    for(i = 0; i < numM; i++){
        scanf("%d", &m[i]);
    }

    for(i = 0; i < numM; i++){
        if(m[i] == 0){
            resposta = 0;
            printf("%d\n", resposta);
        }else{
            resposta = buscaBinaria(n, m[i], numN);
            printf("%d\n", resposta);
        }
    }

    free(n);
    free(m);

    return 0;
}
