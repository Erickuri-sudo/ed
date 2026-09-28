#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cel Cel;

struct cel{
    Estudante* e;
    Cel* prox;
};

struct lista{
    Cel* prim;
    Cel* ult;
};

Lista *criaLista()
{
    Lista* l = malloc(sizeof(Lista));
    // inicializa tanto a primeira como a ultima celula com NULL
    l->prim = l->ult = NULL;

    return l;
}

void insereEstudanteLista(Lista *l, Estudante *e)
{
    if(!l || !e){
         return;
    }

    Cel* nova = malloc(sizeof(Cel));
    nova->e = e;
    nova->prox = NULL;
    // lista vazia
    if(l->prim == NULL && l->ult == NULL){
        l->prim = l->ult = nova;
    }
    // caso comum
    else{
        l->ult->prox = nova;
        l->ult = nova;
    }
}
static float calculaMediaCr(Lista* l){
    float soma = 0.0;
    int n = 0;
    Cel* p = l->prim;

    while(p){
        soma += retornaCr(p->e);
        n++;
        p = p->prox;
    }
    return soma/(float)n;
}

void imprimeLista(Lista *l)
{
    Cel* p = l->prim;
    while(p){
        imprimeEstudante(p->e);
        p = p->prox;
    }
    printf("Media dos estudantes: %.2f\n",calculaMediaCr(l));
}

void retiraEstudantePorMatricula(Lista *l, int mat)
{
    if(!l){
        return;
    }

    Cel* p = l->prim;
    Cel* aux = NULL;
    // procura o estudante pela matricula
    while(p && retornaMatricula(p->e)!=mat){
            aux = p;
            p = p->prox;
    }
    // se nao encontrou o estudante (ou seja, chegou em null)
    if(!p){
        return;
    }
    // se encontrou, retira o estudante
    // unica celula da lista
    else if(l->prim == p && l->ult == p){
        l->prim = l->ult = NULL;
    }
    // primeira posicao da lista
    else if(p == l->prim){
        l->prim = p->prox;

    }
    // ultima posicao
    else if(p == l->ult){
        aux->prox = NULL;
        l->ult = aux;
    }
    // caso comum
    else{
        aux->prox = p->prox;
    }
    liberaEstudante(p->e);
    free(p);

}   
