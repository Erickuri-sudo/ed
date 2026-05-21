#ifndef lista_leitura_h
#define lista_leitura_h
#include "leitura.h"
typedef struct lista_leitura tLista_leitura;

tLista_leitura *criaListaLeitura();
void insereListaLeitura(tLista_leitura *lista,tLeitura *leitura);
#endif