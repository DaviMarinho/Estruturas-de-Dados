#include <stdio.h>
#include <stdlib.h>

typedef struct bota{
      int  tamanho;
      char pe;
      struct bota *proxima;
} BOTA;

typedef struct botas{
    BOTA* primeira;
    BOTA * ultima;
} BOTAS;

BOTA * enfileira(int tamanho, char pe, BOTA * primeira) {
        BOTA *novo     = (BOTA*) malloc(sizeof(BOTA));
        novo->tamanho  = tamanho;
        novo->pe       = pe;
        if (primeira == NULL) {
            novo->proxima = NULL;
        } else {
            novo->proxima = primeira;
        }
         return novo;
}

BOTA * lerBotas() {
    int  tamanho = 0;
    BOTA * primeira = NULL;
    char pe = ' ';
    while (scanf("%2d %c",&tamanho, &pe) != EOF) {
        if (tamanho < 30 || tamanho > 60) {
            exit (1);
        }
        if (pe != 'D' && pe != 'E') {
            exit (1);
        }
        // Acresenta uma bota no inicio da lista
        primeira  = enfileira(tamanho, pe, primeira);
    }
    return primeira;
}

int contarPares(BOTA * primeira) {
    int pares = 0;
    BOTA * base = primeira;
    while (base != NULL) {
        BOTA * candidata = base->proxima;
        BOTA * anterior  = base;
        while (candidata != NULL) {
            if (base->tamanho == candidata->tamanho && base->pe != candidata->pe) {
                pares++;
                // Remove a bota da lista
                anterior->proxima = candidata->proxima;
                free(candidata);
                break;
            }
            anterior  = candidata;
            candidata = candidata->proxima;
        }
        base = base->proxima;
    }
    return pares;
}


int main() {

    int qtCartas = 0;
    BOTA * primeira;

    primeira = lerBotas();

    printf("%d\n", contarPares(primeira));

  }

