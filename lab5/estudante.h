#ifndef estudante_h
#define estudante_h

typedef struct estudante Estudante;

// criacao
Estudante* criaEstudante(int mat,float cr,char* nome);

// getters
int retornaMatriculaEstudante(Estudante* e);
float retornaCrEstudante(Estudante* e);
char* retornaNomeEstudante(Estudante* e);

void imprimeEstudante(Estudante* e);

// liberacao
void liberaEstudante(Estudante* e);


#endif