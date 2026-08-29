#include "item.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct item{
    Produto* p;
    int qtd;
};

Item *criaItem(Produto *p, int qtd)
{
    Item* item = malloc(sizeof(Item));

    item->p = p;
    item->qtd = qtd; 
    
    return item;
}

float retornaValorItem(Item *i)
{
    return retornaPrecoProduto(i->p)*(float)i->qtd;
}

void imprimeItem(Item *i)
{
    printf("Item: %s, valor unitario: %.2f, quantidade: %d\n",retornaNomeProduto(i->p),
    retornaPrecoProduto(i->p),i->qtd);
}

void liberaItem(Item *i)
{
    free(i);
}
