#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cel TCel;

struct aluno{
    char* nome;
    int mat;
};

struct cel{
    TCel* prox;
    TAluno* a;
};

struct lista{
    TCel* prim;
    TCel* ult;
};

TLista *CriaLista()
{
    TLista* lista = malloc(sizeof(TLista));
    lista->prim = lista->ult = NULL;
    return lista;
}

TAluno *InicializaAluno(char *nome, int matricula)
{
    TAluno* a = malloc(sizeof(TAluno));
    a->mat = matricula;
    a->nome = strdup(nome);
    return a;
}

void InsereAluno(TLista *lista, TAluno *aluno)
{
    if(!lista || !aluno){
        return;
    }
    TCel* nova = malloc(sizeof(TCel));
    nova->a = aluno;
    nova->prox = NULL;

    // lista vazia
    if(lista->ult == NULL){
        lista->ult = nova;
    }
    else{
        nova->prox = lista->prim;
    }
    lista->prim = nova;
}

TAluno *Retira(TLista *lista, int mat)
{
    TAluno* a;

    TCel* p = lista->prim;
    TCel* aux = NULL;
    while(p && p->a->mat!=mat){
        aux = p;
        p = p->prox;
    }

    if(!p||!a){
        return NULL;
    }

    else if(lista->prim == p){
        lista->prim = p->prox;
    }
    else if(lista->ult == p){
        lista->ult = aux;
        aux->prox = NULL;
    }
    else if(lista->ult == lista->prim){
        lista->prim = lista->ult = NULL;
    }
    else{
        aux->prox = p->prox;
    }
    a = p->a;
    free(p);
    return a;
}

void RetiraRepetidos(TLista *lista)
{
    TCel* p = lista->prim;

    while(p){
        TCel* ant = p;
        TCel* aux = p->prox;

        while(aux){
            if(p->a->mat == aux->a->mat){
                ant->prox = aux->prox; // desencadeia aux

                if(aux == lista->ult){
                    lista->ult = ant; // se for o ultimo da lista atualiza sentinela
                }

                TCel* removida = aux;
                aux = aux->prox;
                free(removida);
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

TLista *Merge(TLista *turma1, TLista *turma2)
{
    TLista* merge = CriaLista();
    TCel* c1 = turma1->prim;
    TCel* c2 = turma2->prim;
    TCel* prox = NULL;

    merge->prim = c1;
    merge->ult = c1;
    c1 = c1->prox;
    
    while(c1 && c2){
        prox = c2->prox;
        merge->ult->prox = c2;
        merge->ult = c2;
        c2 = prox;

        prox = c1->prox;
        merge->ult->prox = c1;
        merge->ult = c1;
        c1 = prox;
    }
    if(c1){
        merge->ult->prox = c1;
        merge->ult = turma1->ult;
    }
    else if(c2){
        merge->ult->prox = c2;
        merge->ult = turma2->ult;
    }
    turma1->prim = turma1->ult = NULL;
    turma2->prim = turma2->ult = NULL;

    return merge;
}

void LiberaAluno(TAluno *aluno)
{
    free(aluno->nome);
    free(aluno);
}

void Imprime(TLista *lista)
{
    TCel* p;
    for(p = lista->prim;p!=NULL;p = p->prox){
        printf("Aluno: %s Matricula: %d\n",p->a->nome,p->a->mat);
    }
}

void LiberaLista(TLista *lista)
{
    TCel* p = lista->prim;
    TCel* aux = NULL;

    while(p){
        aux = p;
        p = p->prox;
        LiberaAluno(aux->a);
        free(aux);
    }
    free(lista);
}
