#include "leitura.h"

struct leitura{
    int latitude;
    int longitude;
    float temperatura;
};

tLeitura *criaLeitura(int latitude,int longitude,float temperatura)
{
    tLeitura *leitura = malloc(sizeof(tLeitura));
    leitura->latitude = latitude;
    leitura->longitude = longitude;
    leitura->temperatura = temperatura;

    return leitura;
}

int retornaLatitude(tLeitura *leitura)
{
    return leitura->latitude;
}

int retornaLongitude(tLeitura *leitura)
{
    return leitura->longitude;
}

float retornaTemperatura(tLeitura *leitura)
{
    return leitura->temperatura;
}
