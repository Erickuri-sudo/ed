#ifndef aluno_h
#define aluno_h

typedef struct aluno Aluno;

// criacao
Aluno* criaAluno(int mat,char* nome);

// getters
int retornaMatriculaAluno(Aluno* e);
char* retornaNomeAluno(Aluno* e);

void imprimeAluno(Aluno* e);

// liberacao
void liberaAluno(Aluno* e);

#endif