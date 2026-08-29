#include "produto.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct produto{
    int id;
    char* nome;
    float preco;
};

Produto *criaProduto(int id, char *nome, float preco)
{
    Produto* produto = malloc(sizeof(Produto));
    produto->id = id;
    produto->nome = strdup(nome);
    produto->preco = preco;

    return produto;
}

float retornaPrecoProduto(Produto *p)
{
    return p->preco;
}

char *retornaNomeProduto(Produto *p)
{
    return p->nome;
}

int retornaIdProduto(Produto *p)
{
    return p->id;
}

void liberaProduto(Produto *p)
{
    free(p->nome);
    free(p);
}
