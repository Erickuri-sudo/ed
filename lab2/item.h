#ifndef item_h
#define item_h

#include "produto.h"

typedef struct item Item;

Item* criaItem(Produto* p,int qtd);
float retornaValorItem(Item* i);
void imprimeItem(Item* i);
void liberaItem(Item* i);

#endif