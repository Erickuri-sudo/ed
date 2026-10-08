#include "listaPes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pessoa.h"

typedef struct cel Cel;
struct cel{
    Cel* prox;
    Pessoa* p;
};

struct listaPes{
    Cel* prim;
    Cel* ult;
};

ListaPes *criaListaPes()
{
    ListaPes* lista = malloc(sizeof(ListaPes));
    lista->prim = lista->ult = NULL;

    return lista;
}

void inserePessoaLista(ListaPes *l, Pessoa *p)
{
    Cel* nova = malloc(sizeof(Cel));
    nova->p = p;
    nova->prox = NULL;

    if(l->prim == NULL){
        l->prim = nova;
    }
    else{
        l->ult->prox = nova;
    }
    l->ult = nova;
}

Pessoa *buscaPessoa(ListaPes *l, char *nome)
{
    Cel* p = l->prim;
    while(p && strcmp(nome,retornaNomePessoa(p->p))){
        p = p->prox;
    }
    if(!p){
        return NULL;
    }
    return p->p;
}

void imprimeListaPes(ListaPes *lista)
{
    Cel* p = lista->prim;
    while(p){
        imprimePessoa(p->p);
        p = p->prox;
    }
}

void liberaListaPes(ListaPes *l)
{
    Cel* p = l->prim;
    Cel* aux = NULL;

    while(p){
        aux = p;
        p = p->prox;
        liberaPessoa(aux->p);
        free(aux);
    }
    free(l);
}
