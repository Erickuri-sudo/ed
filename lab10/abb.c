#include "abb.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct abb{
    int mat;
    char* nome;
    Abb* dir;
    Abb* esq;
};

Abb *criaAbb()
{
    return NULL;
}

Abb *insereAbb(Abb *a, int mat, char *nome)
{
    if(a == NULL){
        a = malloc(sizeof(Abb));
        a->mat = mat;
        a->nome = strdup(nome);
        a->dir = a->esq = NULL;
    }
    else if(strcmp(nome,a->nome)<0){
        a->esq = insereAbb(a->esq,mat,nome);
    }
    else{
        a->dir = insereAbb(a->dir,mat,nome);
    }
    return a;

}

Abb *retiraAbb(Abb *a, char *nome)
{
    if(a == NULL){ // no vazio
        return NULL;
    }
    else if(strcmp(nome,a->nome)<0){ // nome esta a esquerda do no atual
        a->esq = retiraAbb(a->esq,nome);
    }
    else if(strcmp(nome,a->nome)>0){ // nome esta a direita do no atual
        a->dir = retiraAbb(a->dir,nome);
    }
    else{ // encontrou o no
        if(a->dir == NULL && a->esq == NULL){ // no folha
            free(a->nome);
            free(a);
            a = NULL;
        }
        else if(a->dir == NULL){

        }
    }
    return a;
}

int alturaAbb(Abb *a)
{
    if(a == NULL){
        return -1;
    }

    int altEsq = alturaAbb(a->esq);
    int altDir = alturaAbb(a->dir);
    
    if(altEsq > altDir){
        return (altEsq+1);
    }
    else
    return (altDir+1);
}

void imprimeAbb(Abb *a)
{
    printf("<");
    if(a!=NULL){
        printf("%s",a->nome);
        imprimeAbb(a->esq);
        imprimeAbb(a->dir);
    }
    printf(">");
}
