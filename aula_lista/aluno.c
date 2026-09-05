#include "aluno.h"

struct aluno{
    int mat;
    float cr;
};

Aluno *criaAluno(int mat, float cr)
{
    Aluno* aluno = malloc(sizeof(Aluno));
    aluno->mat = mat;
    aluno->cr = cr;
    return aluno;
}

int retornaMatricula(Aluno *a)
{
    return a->mat;
}

void imprimeAluno(Aluno *a)
{
    printf("Aluno matricula: %d - CR: %.2f\n",a->mat,a->cr);
}
