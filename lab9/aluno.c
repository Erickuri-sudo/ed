#include "aluno.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct aluno{
    char* nome;
    int mat;
};

Aluno *criaAluno(int mat, char *nome)
{
    Aluno* aluno= malloc(sizeof(aluno));
    aluno->mat = mat;
    aluno->nome = strdup(nome);
    return aluno;
}

int retornaMatriculaAluno(Aluno *e)
{
    return e->mat;
}

char *retornaNomeAluno(Aluno *e)
{
    return e->nome;
}

void imprimeAluno(Aluno *e)
{
    printf("%s",e->nome);
}

void liberaAluno(Aluno *e)
{
    free(e->nome);
    free(e);
}
