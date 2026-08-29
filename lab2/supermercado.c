#include "supermercado.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct supermercado{
    char* nome;
    int qtdFilial;
    Filial** filiais;
};

Supermercado *criaSupermercado(char *nome, int qtdFilial)
{
    Supermercado* super = malloc(sizeof(Supermercado));
    super->nome = strdup(nome);
    super->filiais = malloc(qtdFilial*sizeof(Filial*));
    super->qtdFilial = 0;
    return super;
}

void adicionaFilial(Supermercado *s, Filial *f)
{
    s->filiais[s->qtdFilial] = f;
    s->qtdFilial++;
}

void imprimeSupermercado(Supermercado *s)
{
    printf("Nome do Supermercado: %s\n",s->nome);
    for(int i = 0;i<s->qtdFilial;i++){
        imprimeFilial(s->filiais[i]);
    }
}

void liberaSupermercado(Supermercado *s)
{
    free(s->nome);
    for(int i = 0;i<s->qtdFilial;i++){
        liberaFilial(s->filiais[i]);
    }
    free(s->filiais);
    free(s);
}
