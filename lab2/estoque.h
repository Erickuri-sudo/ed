#ifndef estoque_h
#define estoque_h

#include "item.h"

typedef struct estoque Estoque;

Estoque* criaEstoque(int qtdItens);
void adicionaItemEstoque(Estoque* e, Item* i);
float retornaValorEstoque(Estoque* e);
void imprimeCatalogoEstoque(Estoque* e);
void liberaEstoque(Estoque *e);

#endif