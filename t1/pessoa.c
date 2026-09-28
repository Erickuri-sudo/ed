#include "pessoa.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct pessoa{
    char* nome;
    // ainda nao entendi a estrutura, deixo sem nada ate criar o arquivo
    void* listaDeAmizade;
    void* listaDeMusica;
};

Pessoa *criaPessoa(char* nome)
{
    Pessoa* p = malloc(sizeof(Pessoa));
    // alocacao implicita! lembrar de desalocar depois
    p->nome = strdup(nome);
    return p;
}