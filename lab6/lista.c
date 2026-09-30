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

Lista* mergeProvas(Lista *p1, Lista *p2)
{
    Lista* merge = criaLista("merge",p1->n+p2->n);

    Cel* aux = p1->prim;
    for(int i = 0;i<p1->n;i++){
        insereQuestao(merge,aux->q);
        aux = aux->prox;
    }
    aux = p2->prim;
    for(int i = 0;i<p2->n;i++){
        insereQuestao(merge,aux->q);
        aux = aux->prox;
    }
    return merge;
}

void retiraQuestoesRepetidas(Lista *merge)
{
    Cel* p = merge->prim;

    while(p){
        Cel* ant = p;
        Cel* aux = p->prox;
        while(aux){
            if(!strcmp(retornaIdQuestao(p->q),retornaIdQuestao(aux->q))){
                // desencadeia aux
                ant->prox = aux->prox;
                // se aux for a ultima celula atualiza a sentinela
                if(aux == merge->ult){
                    merge->ult = ant;
                }
                // remove a celula e atualiza aux
                Cel* removida = aux;
                aux = aux->prox;
                free(removida);
                merge->n--;
                ant = ant->prox;
            }
            else{
                ant = aux;
                aux = aux->prox;
            }
        }
        p = p->prox;
    }
    
}
