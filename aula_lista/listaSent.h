#ifndef listaSent_h
#define listaSent_h
#include "aluno.h"
typedef struct lista Lista;

Lista* criaLista();
void insereAluno(Lista* l,Aluno* a);
void retiraAluno(Lista* l, int mat);
void imprimeLista(Lista* l);
void liberaLista(Lista* l);

#endif