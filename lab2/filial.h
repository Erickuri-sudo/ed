#ifndef filial_h
#define filial_h

#include "estoque.h"

typedef struct filial Filial;

Filial* criaFilial(char* nome, int qtdItens);
void adicionaItemFilial(Filial* f,Item* i);
void imprimeFilial(Filial* f);
void liberaFilial(Filial* f);
#endif