#ifndef lista_h
#define lista_h

#include "estudante.h"

typedef struct lista Lista;

Lista* criaLista();
void insereEstudanteLista(Lista* l,Estudante* e);
void imprimeLista(Lista* l);
void liberaLista(Lista* l);
void retiraEstudantePorMatricula(Lista* l, int mat);
#endif