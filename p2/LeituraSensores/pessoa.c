#include "pessoa.h"
#include "leitura.h"
#include "listaLei.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct pessoa{
    char* nome;
    ListaLei* leituras;
};

Pessoa *criaPessoa(char *nome)
{
    Pessoa* pessoa = malloc(sizeof(Pessoa));
    pessoa->nome = strdup(nome);
    pessoa->leituras = criaListaLei();
    return pessoa;
}

char *retornaNomePessoa(Pessoa *p)
{
    return p->nome;
}

void insereLeituraPessoa(Pessoa *p, Leitura *l)
{
    insereLeituraLista(p->leituras,l);
}

void imprimePessoa(Pessoa *p)
{
    printf("Pessoa: %s\n",retornaNomePessoa(p));
    imprimeListaLei(p->leituras);
}

void liberaPessoa(Pessoa *p)
{
    free(p->nome);
    //liberaListaLei
    free(p);
}
