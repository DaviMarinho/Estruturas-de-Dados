#include <stdio.h>
#include <stdlib.h>

#define nextStartIndex(FILA) (((FILA)->inicio + 1) % ((FILA)->N)) //(f->inicio+1) % f->N
#define nextEndIndex(FILA) (((FILA)->fim + 1) % ((FILA)->N)) //(f->fim+1) % f->N
#define isBufferEmpty(FILA) ((FILA)->fim == (FILA)->inicio) //f->fim == f->inicio
#define isBufferFull(FILA) (nextEndIndex(FILA) == (FILA)->inicio) //(f->fim+1) % f->N == f->inicio
#define bufferDestroy(FILA) free((FILA)->v); //free(f->v)

typedef struct {
    int *v;
    int N;
    int inicio, fim;
} fila;

int enfileira(fila *f, int x) {
    if(isBufferFull(f))
        return 0;
    f->v[f->fim] = x;
    f->fim = nextEndIndex(f);
    if(isBufferEmpty(f))
        f->inicio = nextStartIndex(f);
    return 1;
}

int desenfileira(fila *f, int *y) {
    if(isBufferEmpty(f))
        return 0;
    *y = f->v[f->inicio];
    f->inicio = nextStartIndex(f);
    return 1;
}

void imprime(fila *f) {
    printf("Q -> ");
    for(int i = 0; i < f->N; i++)
        printf("%d -> ", f->v[i]);
    printf("Q\n");
}

int main(int argc, char *argv[]) {
    int d, y;
    fila *f = malloc(sizeof(fila));
    f->N = 4;
    f->inicio = 0; f->fim = 0;
    f->v = calloc(f->N, sizeof(fila));

    int t[] = {1, 2, 3};
    for(int i = 0; i < 3; i++) {
        d = enfileira(f, t[i]);
        if(d) printf("Inserido %d!\n", t[i]); else printf(":(\n");
    }
    d = enfileira(f, 666);
    if(d) printf("Inserido!\n"); else printf(":(\n");
    d = enfileira(f, 666);
    if(d) printf("Inserido!\n"); else printf(":(\n");
    imprime(f);

    d = 1;
    while(d) {
        d = desenfileira(f, &y);
        if(d) printf("Saiu %d!\n", y); else printf(":(\n");
    }
    imprime(f);

    bufferDestroy(f);
    return 0;
}

// vim:set et sw=4 ts=4 tw=100:
