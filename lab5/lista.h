#ifndef lista_h
#define lista_h
#include "estudante.h"

typedef struct lista Lista;

Lista* criaLista();
void insereEstudante(Lista* l,Estudante* e);
void imprimeLista(Lista* l);
void retiraEstudante(Lista* l,int mat);
float calculaMediaCr(Lista* l);
void liberaLista(Lista* l);

#endif