#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PROF 0
#define ALUN 1

typedef struct cel Cel;
struct cel{

    Cel* prox;
    Cel* ant;
    void* dado; // lista het
    int tipo; // necessario para fazer o casting correto

};

struct lista{
    Cel* prim;
    Cel* ult;
};

struct aluno{
    char* nome;
    int cpf;
    float cr;
};

struct professor{
    char* nome;
    int cpf;
    float salario;
};

Lista *criaLista()
{
    Lista* lista = malloc(sizeof(Lista));
    lista->prim = lista->ult = NULL;
    return lista;
}

Aluno *criaAluno(char *nome, int cpf, float cr)
{
    Aluno* a = malloc(sizeof(Aluno));
    a->nome = strdup(nome);
    a->cpf = cpf;
    a->cr = cr;
    return a;
}

Prof *criaProf(char *nome, int cpf, float salario)
{
    Prof* p = malloc(sizeof(Prof));
    p->nome = strdup(nome);
    p->cpf = cpf;
    p->salario = salario;
    return p;
}

void insereAluno(Lista *l, Aluno *a)
{
    Cel* nova = malloc(sizeof(Cel));
    nova->dado = (void*)a;
    nova->tipo = ALUN;
    nova->prox = NULL;
    // lista vazia
    if(l->prim == NULL){
        nova->ant = NULL;
        l->prim = nova;
    }
    else{
        nova->ant = l->ult;
        l->ult->prox = nova;
    }
    l->ult = nova;
}

void insereProfessor(Lista *l, Prof *p)
{
    Cel* nova = malloc(sizeof(Cel));
    nova->dado = (void*)p;
    nova->tipo = PROF;
    nova->prox = NULL;

    if(l->prim == NULL){
        nova->ant = NULL;
        l->prim = nova;
    }
    else{
        nova->ant = l->ult;
        l->ult->prox = nova;
    }
    l->ult = nova;
}
/*
    funcoes auxiliares para o codigo
    retornaSalario para retornar o salario dos professores mesmo que
    o tipo seja um void* (atraves de downcasting na chamada de funcao)
    retornaCr funciona de maneira semelhante e calculaMedia (auto explicativa)
*/
static float retornaSalario(Prof* p){
    return p->salario;
}
static float retornaCr(Aluno* a){
    return a->cr;
}
static float calculaMedia(float soma,int qtd){
    return soma/(float)qtd;
}

void imprimeProfessor(Prof *p)
{
    printf("%s, CPF: %d e Salario: %.2f\n",p->nome,p->cpf,p->salario);
}

void imprimeAluno(Aluno *a)
{
    printf("%s, CPF: %d e CR: %.2f\n",a->nome,a->cpf,a->cr);
}

void imprimeLista(Lista *l)
{
    Cel* p;
    // loop professores
    printf("PROFESSORES\n");
    float soma = 0.0;
    int qtd = 0;
    for(p = l->prim;p!=NULL;p = p->prox){
        if(p->tipo == PROF){
            imprimeProfessor((Prof*)p->dado);
            soma += retornaSalario((Prof*)p->dado);
            qtd++;
        }
    }
    printf("\n");
    float media = calculaMedia(soma,qtd);
    printf("Media de salario dos %d professores: %.2f\n",qtd,media);
    printf("\n");

    // loop alunos
    soma = 0.0;
    qtd = 0;
    for(p = l->prim;p!=NULL;p = p->prox){
        if(p->tipo == ALUN){
            imprimeAluno((Aluno*)p->dado);
            soma += retornaCr((Aluno*)p->dado);
            qtd++;
        }
    }
    printf("\n");
    media = calculaMedia(soma,qtd);
    printf("Media de CR dos %d alunos: %.2f\n",qtd,media);
}

void liberaAluno(Aluno *a)
{
    free(a->nome);
    free(a);
}

void liberaProfessor(Prof *p)
{
    free(p->nome);
    free(p);
}

void liberaLista(Lista *l)
{
    Cel* p = l->prim;
    Cel* aux = NULL;

    while(p){
        aux = p->prox;
        if(p->tipo == ALUN){
            liberaAluno((Aluno*)p->dado);
        }
        else{
            liberaProfessor((Prof*)p->dado);
        }
        free(p);
        p = aux;
    }
    free(l);
}
