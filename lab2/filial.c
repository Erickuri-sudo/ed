#include "filial.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct filial{
    char* nome;
    Estoque* estoque;
    int qtdItens;
};

Filial *criaFilial(char *nome, int qtdItens)
{
    Filial* filial = malloc(sizeof(Filial));
    filial->nome = strdup(nome);
    filial->estoque = criaEstoque(qtdItens);
    filial->qtdItens = 0;
    return filial;
}

void adicionaItemFilial(Filial *f, Item *i)
{
    adicionaItemEstoque(f->estoque,i);
    f->qtdItens++;
}

void imprimeFilial(Filial *f)
{
    printf("Filial: %s\n",f->nome);
    imprimeCatalogoEstoque(f->estoque);
}

void liberaFilial(Filial *f)
{
    liberaEstoque(f->estoque);
    free(f->nome);
}
