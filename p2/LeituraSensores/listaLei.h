#ifndef listaLei_h
#define listaLei_h
#include "leitura.h"
typedef struct listaLei ListaLei;

ListaLei* criaListaLei();
void insereLeituraLista(ListaLei* lista, Leitura* l);
void imprimeListaLei(ListaLei* l);
void calculaMedias(ListaLei* l);
void removeOutliers(ListaLei* l);
void liberaListaLei(ListaLei* l);

#endif