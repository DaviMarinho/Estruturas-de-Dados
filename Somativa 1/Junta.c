#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

void mescla_listas (celula *l1, celula *l2, celula *l3){
    l1 = l1 -> prox;
    l2 = l2 -> prox;
    while(l1 && l2){
        if(l1 -> dado < l2 -> dado){
            l3 -> prox = l1;
            l3 = l1;
            l1 = l1 -> prox;
        }
        else{
            l3 -> prox = l2;
            l3 = l2;
            l2 = l2 -> prox;
        }
    }

    if(l1)
        l3->prox = l1;
    else
        l3->prox = l2;
}


/*void imprime (celula *le) {
    for (celula *ptr = le -> prox; ptr != NULL; ptr = ptr->prox){
        printf("%d -> ", ptr->dado);
    }
    printf("NULL\n");
}

int main () {

celula *l1 = malloc(sizeof(celula));
celula *l2 = malloc(sizeof(celula));
celula *l3 = malloc(sizeof(celula));
celula *a = malloc(sizeof(celula));
celula *b = malloc(sizeof(celula));
celula *c = malloc(sizeof(celula));
celula *d = malloc(sizeof(celula));
celula *e = malloc(sizeof(celula));
celula *f = malloc(sizeof(celula));

l1 -> prox = a;
a -> dado = 1;
a -> prox = b;
b -> dado = 7;
b -> prox = c;
c -> dado = 9;
c -> prox = NULL;
l2 -> prox = d;
d -> dado = 2;
d -> prox = e;
e -> dado = 3;
e -> prox = f;
f -> dado = 8;
f -> prox = NULL;


imprime(l1);
imprime(l2);

mescla_listas(l1, l2, l3);

imprime(l3);
}*/