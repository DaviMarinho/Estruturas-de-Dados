#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

void divide_lista (celula *l, celula *l1, celula *l2){
    while(l -> prox != NULL){
        if(l -> prox -> dado % 2 != 0){
            l1 -> prox = l -> prox;
            l1 = l1 -> prox;
        }
        if(l -> prox -> dado % 2 == 0){
            l2 -> prox = l -> prox;
            l2 = l2 -> prox;
        }
        l = l -> prox;
    }
    l1->prox = NULL;
    l2->prox = NULL;
}

/*void imprime (celula *le) {
    for (celula *ptr = le -> prox; ptr != NULL; ptr = ptr->prox){
        printf("%d -> ", ptr->dado);
    }
    printf("NULL\n");
}

int main () {

celula *cabeca = malloc(sizeof(celula));
celula *l1 = malloc(sizeof(celula));
celula *l2 = malloc(sizeof(celula));
celula *a = malloc(sizeof(celula));
celula *b = malloc(sizeof(celula));
celula *c = malloc(sizeof(celula));
celula *d = malloc(sizeof(celula));
celula *e = malloc(sizeof(celula));

cabeca -> prox = a;
a -> dado = 2;
a -> prox = b;
b -> dado = 3;
b -> prox = c;
c -> dado = 4;
c -> prox = d;
d -> dado = 5;
d -> prox = e;
e -> dado = 6;
e -> prox = NULL;

imprime(cabeca);

divide_lista(cabeca, l1, l2);

imprime(l1);
imprime(l2);
}*/