#include "estoque.h"
#include <stdio.h>
#include <stdlib.h>
struct estoque{
    float valorEstoque;
    int qtdItens;
    Item** catalogoEstoque;
};

Estoque *criaEstoque(int qtdItens)
{
    Estoque* estoque = malloc(sizeof(Estoque));
    estoque->catalogoEstoque = malloc(qtdItens*sizeof(Item*));
    estoque->qtdItens = 0;
    estoque->valorEstoque = 0.0;
    return estoque;
}

void adicionaItemEstoque(Estoque *e, Item *i)
{
    e->catalogoEstoque[e->qtdItens] = i;
    e->qtdItens++;
    e->valorEstoque += retornaValorItem(i);
}

float retornaValorEstoque(Estoque *e)
{
    return e->valorEstoque;
}

void imprimeCatalogoEstoque(Estoque *e)
{
    printf("Estoque: %.2f\n",e->valorEstoque);
    for(int i = 0;i<e->qtdItens;i++){
        imprimeItem(e->catalogoEstoque[i]);
    }
}

void liberaEstoque(Estoque *e)
{
    for(int i = 0;i<e->qtdItens;i++){
        liberaItem(e->catalogoEstoque[i]);
    }
    free(e->catalogoEstoque);
    free(e);
}
