#ifndef supermercado_h
#define supermercado_h
#include "filial.h"
typedef struct supermercado Supermercado;

Supermercado* criaSupermercado(char* nome,int qtdFilial);
void adicionaFilial(Supermercado* s,Filial* f);
void imprimeSupermercado(Supermercado* s);
void liberaSupermercado(Supermercado* s);
#endif