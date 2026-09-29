#include "lista.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct cel Cel;

struct cel{
    Questao* q;
    Cel* prox;
};

struct lista{
    char* nome;
    int n;
    Cel* prim;
    Cel* ult;
};

Lista *criaLista(char* nome, int n)
{
    Lista* l = malloc(sizeof(Lista));
    l->nome = strdup(nome);
    l->prim = l->ult = NULL;
    l->n = n;
    return l;
}

void insereQuestao(Lista *l, Questao *q)
{
    if(!l || !q){
        return;
    }
    Cel* nova = malloc(sizeof(Cel));
    nova->q = q;
    nova->prox = NULL;
    // primeiro elemento
    if(l->prim == NULL && l->ult == NULL){
        l->prim = l->ult = nova;
    }
    // caso comum
    else{
        nova->prox = l->prim;
        l->prim = nova;
    }
}

void imprimeLista(Lista *l)
{
    Cel* p = l->prim;
    printf("Prova: %s\n",l->nome);
    while(p){
        imprimeQuestao(p->q);
        p = p->prox;
    }
}

void insereQuestaoDoBancoNaProva(Lista *banco, Lista *prova, char* id)
{
    Cel* aux = banco->prim;
    while(aux && strcmp(retornaIdQuestao(aux->q),id)){
        aux = aux->prox;
    }
    // nao encontrou a questao
    if(!aux){
        return;
    }
    insereQuestao(prova,aux->q);

}
