#include "lista.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct cel Cel;

struct cel{
    Cel* prox;
    Estudante* e;

};

struct lista{
    Cel* prim;
    Cel* ult;
};

Lista *criaLista()

{
    Lista* lista = malloc(sizeof(Lista));
    lista->prim = NULL;
    lista->ult = NULL;

    return lista;
}

void insereEstudante(Lista *l, Estudante *e)
{
    // pre condicoes
    if(l == NULL || e == NULL){
        return;
    }

    Cel *nova = malloc(sizeof(Cel));
    nova->e = e;
    nova->prox = NULL;
    // caso seja a primeira insercao
    if(l->prim == NULL){
        l->prim = nova;
        l->ult  = nova;
    }
    // caso comum
    else{
        l->ult->prox = nova;
        l->ult = nova;
    }
   
}

void imprimeLista(Lista *l)
{
    Cel* p;
    for(p = l->prim;p!=NULL;p=p->prox){
        imprimeEstudante(p->e);
    }
    printf("Media: %.2f\n",calculaMediaCr(l));
    printf("================\n");
}

void retiraEstudante(Lista *l, int mat)
{
    Cel* p = l->prim;
    Cel* aux = NULL;
    while(p && retornaMatriculaEstudante(p->e) != mat){
        aux = p;
        p = p->prox;
    }
    if(!p){
        return;
    }
    
}

float calculaMediaCr(Lista *l)
{
    float soma = 0.0;
    int n = 0;
    Cel* p;
    for(p = l->prim;p!=NULL;p=p->prox){
        soma+=retornaCrEstudante(p->e);
        n++;
    }
    float media = soma/(float)n;
    return media;
}
