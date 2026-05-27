#ifndef aluno_h
#define aluno_h

#include <stdlib.h>
#include <string.h>
typedef struct aluno Aluno;

Aluno *criaAluno(char *nome, int mat);
char *retornaNome(Aluno *a);
int retornaMatricula(Aluno *a);
#endif