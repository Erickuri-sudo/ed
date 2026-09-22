#include "estudante.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct estudante{
    char* nome;
    int mat;
    float cr;
};

Estudante *criaEstudante(int mat, float cr, char *nome)
{
    Estudante* estudante= malloc(sizeof(Estudante));
    estudante->mat = mat;
    estudante->nome = strdup(nome);
    estudante->cr = cr;

    return estudante;
}

int retornaMatriculaEstudante(Estudante *e)
{
    return e->mat;
}

float retornaCrEstudante(Estudante *e)
{
    return e->cr;
}

char *retornaNomeEstudante(Estudante *e)
{
    return e->nome;
}

void imprimeEstudante(Estudante *e)
{
    printf("%d %s %.2f\n",e->mat,e->nome,e->cr);
}

void liberaEstudante(Estudante *e)
{
    free(e->nome);
    free(e);
}
