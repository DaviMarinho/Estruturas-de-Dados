#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int dado;
    struct no *esq, *dir;
} no;

typedef struct celula {
    no *dado;
    struct celula *prox;
} celula;


celula *cria_pilha(){
    celula *topo = malloc(sizeof(celula));
    topo->prox = NULL;
    return topo;
}

int isPilhaVazia(celula *pilha){
    if(pilha->prox == NULL)
        return 0;
    else
        return 1;
}

void empilha (celula *p, no *x){
    celula *ponteiro = malloc(sizeof(celula));
    ponteiro->dado = x;
    ponteiro->prox = p->prox;
    p->prox = ponteiro;
}

no* desempilha (celula *p){
    no* numero;
    celula *lixo = p->prox;
    numero = lixo->dado;
    p->prox = lixo->prox;
    free(lixo);
    return numero;
}

no *criar_arvore (int x, no *esq, no *dir) {
    no *raiz = malloc (sizeof (no));
    raiz->dado = x;
    raiz->esq = esq;
    raiz->dir = dir;
    return raiz;
}


    void pre_ordem (no *raiz){
    if(raiz == NULL)
        return;

    celula *pilha = cria_pilha();
    empilha(pilha, raiz);

    while(isPilhaVazia(pilha) != 0){
        raiz = desempilha(pilha);
        printf("%d ", raiz->dado);
        if(raiz->dir != NULL)
            empilha(pilha, raiz->dir);
        if(raiz->esq != NULL)
            empilha(pilha, raiz->esq);
    }
}

void em_ordem (no *raiz){
    if(raiz == NULL)
        return;

    celula *pilha = cria_pilha();
    
    while(1){
        if(raiz!=NULL) {
            empilha(pilha, raiz);
            raiz = raiz->esq;
        }else{
            if(isPilhaVazia(pilha)==0)
                break;

        raiz = desempilha(pilha);
        printf("%d ", raiz->dado);
        raiz = raiz->dir;
        }
    }
}

void pos_ordem (no *raiz){
    no* atual = raiz;
    celula* pilha = cria_pilha();

    while(atual!=NULL || isPilhaVazia(pilha)==1){
        if(atual!=NULL){
            empilha(pilha, atual);
            atual = atual->esq;
        }else{
            no* temp = pilha->prox->dado->dir;
            if(temp==NULL){
                temp = desempilha(pilha);
                printf("%d ", temp->dado);
                
                while(isPilhaVazia(pilha)==1 && temp==pilha->prox->dado->dir){
                    temp = desempilha(pilha);
                    printf("%d ", temp->dado);
                }
            }else{
                atual = temp;
            }
        }
    }
}

    no *procurar (no *raiz, int x) {
    if (raiz == NULL || raiz->dado == x) return raiz;
    no *esq = procurar (raiz->esq, x);
    if (esq != NULL) return esq;
    return procurar (raiz->dir, x);
    }

    void inserir (no *raiz, int x, int y, char L) {
    // inserir x do lado L de y
    no *procurado = procurar (raiz, y);
    if (L == 'E') {
        no *novo = criar_arvore (x, procurado->esq, NULL);
        procurado->esq = novo;
    }
    else {
        no *novo = criar_arvore (x, NULL, procurado->dir);
        procurado->dir = novo;
    }
    }

int main () {
    int elem, novo;
    char lado;
    //printf ("Digite a raiz: ");
    scanf ("%d", &novo);
    no *raiz = criar_arvore (novo, NULL, NULL);
    //printf ("Digite NOVO LADO EXISTENTE: ");
    while (scanf ("%d %c %d", &novo, &lado, &elem) != EOF) {
        inserir (raiz, novo, elem, lado);
        //printf ("Digite NOVO LADO EXISTENTE: ");
    }

    printf ("Pre-ordem: ");
    pre_ordem (raiz);
    printf ("\n");
    
    printf ("Em-ordem: ");
    em_ordem (raiz);
    printf ("\n");
    
    printf ("Pos-ordem: ");
    pos_ordem (raiz);
    printf ("\n");

    return 0;
}