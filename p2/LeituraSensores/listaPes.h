#ifndef listaPes_h
#define listaPes_h

#include "pessoa.h"

typedef struct listaPes ListaPes;

ListaPes* criaListaPes();
void inserePessoaLista(ListaPes* l,Pessoa* p);
Pessoa* buscaPessoa(ListaPes* l,char* nome);
void imprimeListaPes(ListaPes* lista);
void liberaListaPes(ListaPes* l);

#endif