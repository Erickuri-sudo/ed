#ifndef mapa_h
#define mapa_h

typedef struct mapa Mapa;

Mapa* criaMapa(int lins, int cols);
void insereNomeMapa(Mapa* m,char* nome,int i,int j);
Mapa* transpoe(Mapa* m);
Mapa* ordena(Mapa* m);
void imprimeMapa(Mapa* m);
void liberaMapa(Mapa* m);
#endif