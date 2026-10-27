#include "arvore.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct aluno{
    char* nome;
    int mat;
};
struct arv{
    Aluno* aluno;
    Arv* esq;
    Arv* dir;
};
Arv *arv_criavazia(void)
{
    return NULL;
}

Arv *arv_cria(Aluno *c, Arv *e, Arv *d)
{
    Arv* a = malloc(sizeof(Arv));
    a->aluno = c;
    a->esq = e;
    a->dir = d;

    return a;
}

Arv *arv_libera(Arv *a)
{
    if(!(arv_vazia(a))){
        arv_libera(a->esq);
        arv_libera(a->dir);
        free(a);
    }
    return NULL;
}

int arv_vazia(Arv *a)
{
    if(a==NULL){
        return 1;
    }
    return 0;
}

int arv_pertence(Arv *a, int mat)
{
    if((arv_vazia(a))){
        return 0;
    }
    if(retornaMatriculaAluno(a->aluno) == mat)
        return 1;

    return arv_pertence(a->esq,mat) || arv_pertence(a->dir,mat);
}

void arv_imprime(Arv *a)
{
    printf("<");
    if(!(arv_vazia(a))){
        imprimeAluno(a->aluno);
        arv_imprime(a->esq);
        arv_imprime(a->dir);
    }
    printf(">");
}

Arv *arv_pai(Arv *a, int mat)
{
    Arv* temp = NULL;

    if(arv_vazia(a))
        return NULL;
    if(((a->esq!=NULL) && retornaMatriculaAluno(a->dir->aluno) == mat)||
    (a->dir!=NULL &&retornaMatriculaAluno(a->esq->aluno)==mat)){
        return a;
    }
    else{
        temp = arv_pai(a->esq,mat);
        if (!temp)
            temp = arv_pai(a->dir,mat);
    }
    return temp;
}

int folhas(Arv *a)
{
    if(arv_vazia(a)){
        return 0;
    }
    if(a->esq == NULL && a->dir == NULL){
        return 1;
    }
    return folhas(a->esq) + folhas(a->dir);
}

int ocorrencias(Arv *a, int mat)
{
    if(arv_vazia(a)){ // caso base
        return 0;
    }
    if(retornaMatriculaAluno(a->aluno) == mat){ // caso base (desejado)
        return 1;
    }
    return ocorrencias(a->esq,mat)+ocorrencias(a->dir,mat);
}
