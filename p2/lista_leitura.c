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

    leituras->ini = NULL;
    leituras->fim = NULL;
    return leituras;
}

void insereListaLeitura(tLista_leitura *lista, tLeitura *leitura)
{
    tCel_leitura *nova = malloc(sizeof(tCel_leitura));
    nova->leitura = leitura;
    nova->prox = NULL;

    if(lista->ini == NULL){
        lista->ini = nova;
        lista->fim = nova;
    }
    else{
        lista->fim->prox = nova;
        lista->fim = nova;

    }

}
