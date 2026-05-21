#ifndef leitura_h
#define leitura_h
#include <stdlib.h>

typedef struct leitura tLeitura;

tLeitura *criaLeitura(int latitude,int longitude,float temperatura);
int retornaLatitude(tLeitura *leitura);
int retornaLongitude(tLeitura *leitura);
float retornaTemperatura(tLeitura *leitura);

#endif leitura_h