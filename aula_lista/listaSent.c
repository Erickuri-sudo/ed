#include "listaSent.h"
#include <stdlib.h>

typedef struct cel{
    Cel* prox;
    Aluno* a;
}Cel;

struct lista{
    Cel* prim;
    Cel* ult;
};

Lista *criaLista()
{
    Lista* l = malloc(sizeof(Lista));
    l->ult = NULL;
    l->prim = NULL;
    return l;
}

void insereAluno(Lista *l, Aluno *a)
{
    if(l == NULL || a == NULL){
        return;
    }
    Cel* nova = malloc(sizeof(Cel));
    nova->a = a;
    nova->prox = l->prim;
    l->prim = nova;

    if(!l->ult)
        l->ult = nova;
}

void retiraAluno(Lista *l, int mat)
{
    Cel* aux = NULL;
    Cel* aluno = l->prim;

    while(aluno && retornaMatricula(aluno->a) != mat){
        aux = aluno;
        aluno = aluno->prox;
    }

    if(!aluno){ //lista vazia ou aluno nao encontrado
        return;
    }
    if(l->prim == l->ult == aluno){
        l->prim == l->ult == NULL;
        free(aluno);
    }
    if(aluno == l->prim){
        l->prim = aluno->prox;
        free(aluno);
    }
    if(aluno == l->ult){
        aux->prox = NULL;
        l->ult = aux;
        free(aluno);
    }

    aux->prox = aluno->prox; //caso comum
    free(aluno);

}

void imprimeLista(Lista *l)
{
    Cel* p;
    for(p = l->prim;p!=NULL;p=p ){
        imprimeAluno(p->a);
    }
}

void liberaLista(Lista *l)
{
    Cel* p = l->prim;
    Cel* t = NULL;

    while(p){
        t=p->prox;
        free(p);
        p=t;
    }
    free(l);
}
