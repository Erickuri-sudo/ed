#ifndef pessoa_h
#define pessoa_h

#include "leitura.h"

typedef struct pessoa Pessoa;

Pessoa* criaPessoa(char* nome);
char* retornaNomePessoa(Pessoa* p);
void insereLeituraPessoa(Pessoa* p, Leitura* l);
void imprimePessoa(Pessoa* p);
void liberaPessoa(Pessoa* p);

#endif