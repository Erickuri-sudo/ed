#ifndef estudante_h
#define estudante_h

typedef struct estudante Estudante;

Estudante* criaEstudante(int mat,char* nome, float cr);
void imprimeEstudante(Estudante* e);
void liberaEstudante(Estudante* e);
float retornaCr(Estudante* e);
int retornaMatricula(Estudante* e);

#endif