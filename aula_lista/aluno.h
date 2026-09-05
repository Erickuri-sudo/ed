#ifndef aluno_h
#define aluno_h

typedef struct aluno Aluno;

Aluno* criaAluno(int mat, float cr);
int retornaMatricula(Aluno* a);
void imprimeAluno(Aluno* a);
#endif