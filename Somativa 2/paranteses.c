#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

celula *cria_pilha(){
    celula *topo = malloc(sizeof(celula));
    topo->prox = NULL;
    return topo;
}

void empilha (celula *p, int x){
    celula *ponteiro = malloc(sizeof(celula));
    ponteiro->dado = x;
    ponteiro->prox = p->prox;
    p->prox = ponteiro;
}

int desempilha (celula *p){
    char desempilhado;
    celula *lixo = p->prox;
    if(lixo==NULL)
        return 0;
    desempilhado = lixo->dado;
    p->prox = lixo->prox;
    return desempilhado;
    free(lixo);
}

int main(){
    int i = 0, balanceado = 0, abre = 0, objeto = 0, fecha = 0;
    char expressao[500];
    celula *ponteiro = cria_pilha();
    
    scanf("%[^\n]", expressao);

    for(i = 0; i < strlen(expressao); i++){
        if(expressao[i] == '('){
            empilha(ponteiro, expressao[i]);
            abre++;
        }
        if(expressao[i] == '['){
            empilha(ponteiro, expressao[i]);
            abre++;
        }
        if(expressao[i] == '{'){
            empilha(ponteiro, expressao[i]);
            abre++;
        }
        if(expressao[i] == ')'){
            fecha++;
            objeto = desempilha(ponteiro);
            if(objeto == 0)
                balanceado++;
            if(objeto == 40)
                balanceado++;
        }       
        if(expressao[i] == ']'){
            fecha++;
            objeto = desempilha(ponteiro);
            if(objeto == 0)
                balanceado++;
            if(objeto == 91)
                balanceado++;
        }
        if(expressao[i] == '}'){
            fecha++;
            objeto = desempilha(ponteiro);
            if(objeto == 0)
                balanceado++;
            if(objeto == 123)
                balanceado++;
        }
    }

    if(balanceado == abre && fecha == abre)
        printf("sim\n");
    else
        printf("nao\n");

    return 0;
}