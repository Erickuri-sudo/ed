#include "leitura.h"
#include <stdio.h>
#include <stdlib.h>

struct leitura{
    int lat, longi;
    float temp;
};

Leitura *criaLeitura(int lat, int longi, float temp)
{
    Leitura* leitura = malloc(sizeof(Leitura));
    leitura->lat = lat;
    leitura->longi = longi;
    leitura->temp = temp;

    return leitura;
}

void imprimeLeitura(Leitura *l)
{
    printf("%d %d %.2f\n",l->lat,l->longi,l->temp);
}

void liberaLeitura(Leitura *l)
{
    free(l);
}
