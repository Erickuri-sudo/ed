#ifndef leitura_h
#define leitura_h

typedef struct leitura Leitura;

Leitura* criaLeitura(int lat,int longi, float temp);
void imprimeLeitura(Leitura* l);
int retornaLatitude(Leitura* l);
int retornaLongitude(Leitura* l);
float retornaTemperatura(Leitura* l);
void liberaLeitura(Leitura* l);

#endif