#ifndef fila_h
#define fila_h
#include "amostra.h"

typedef struct fila Fila;

Fila* criaFila();
void insereFila(Fila* f,Amostra* a);
Amostra* retiraFila(Fila* f);
void imprimeFila(Fila* f);
int retornaTamanhoFila(Fila* f);
void liberaFila(Fila* f);
#endif