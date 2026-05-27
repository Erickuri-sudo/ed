#include "aluno.h"

struct aluno{
    char *nome;
    int mat;
};

Aluno *criaAluno(char *nome, int mat)
{
    Aluno *aluno = malloc(sizeof(Aluno));

    aluno->nome = strdup(nome);
    aluno->mat = mat;

    return aluno;
}

char *retornaNome(Aluno *a)
{
    return a->nome;
}

int retornaMatricula(Aluno *a)
{
    return a->mat;
}
