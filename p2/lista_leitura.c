#include "lista_leitura.h"

typedef struct cel_leitura tCel_leitura;

struct cel_leitura{
    tCel_leitura *prox;
    tLeitura *leitura;
};

struct lista_leitura{
    tCel_leitura *ini;
    tCel_leitura *fim;
};

tLista_leitura *criaListaLeitura()
{
    tLista_leitura *leituras = malloc(sizeof(tLista_leitura));


    return leituras;
}