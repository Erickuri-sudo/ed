#include "estudante.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct estudante{
    int mat;
    char* nome;
    float cr;
};

Estudante *criaEstudante(int mat, char *nome, float cr)
{
    Estudante* e = malloc(sizeof(Estudante));

    e->mat = mat;
    e->cr = cr;
    // malloc implicito que precisa ser liberado
    e->nome = strdup(nome);
    return e;
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

float retornaCr(Estudante *e)
{
    return e->cr;
}

int retornaMatricula(Estudante *e)
{
    return e->mat;
}
