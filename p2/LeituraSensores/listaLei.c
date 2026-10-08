#include "listaLei.h"
#include "leitura.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct cel Cel;

struct cel{
    Cel* prox;
    Leitura* l;
};

struct listaLei{
    Cel* prim;
    Cel* ult;
    float somaLat,somaLongi,somaTemp;
    int qtd;
};

ListaLei *criaListaLei()
{
    ListaLei* l = malloc(sizeof(ListaLei));
    l->prim = l->ult = NULL;
    l->somaLat = l->somaLongi = l->somaTemp = 0.0;
    return l;
}
// insere ao final da lista
void insereLeituraLista(ListaLei *lista, Leitura *l)
{
    Cel* nova = malloc(sizeof(Cel));
    nova->l = l;
    nova->prox = NULL;

    if(lista->prim == NULL){
        lista->prim = nova;
    }
    else{
        lista->ult->prox = nova;
    }
    lista->somaLat += retornaLatitude(l);
    lista->somaLongi += retornaLongitude(l);
    lista->somaTemp += retornaTemperatura(l);
    lista->qtd++;
    lista->ult = nova;

}

void imprimeListaLei(ListaLei *l)
{
    Cel* p = l->prim;
    while(p){
        imprimeLeitura(p->l);
        p = p->prox;
    }
    
}
Leitura *buscaOutliers(ListaLei *l)
{
}
void removeOutliers(ListaLei *l)
{
    float mediaLat = (l->somaLat/(float)l->qtd)*1.5;
    float mediaLongi = (l->somaLongi/(float)l->qtd)*1.5;
    float mediaTemp = (l->somaTemp/(float)l->qtd)*1.5;


}

void liberaListaLei(ListaLei *l)
{
    
}
