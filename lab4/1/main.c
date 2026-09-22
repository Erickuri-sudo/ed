#include <stdio.h>
#include "mapa.h"

int main(int argc, char const *argv[])
{
    freopen("entrada.txt","r",stdin);
    freopen("saida.txt","w",stdout);
    int lins = 0,cols = 0;

    scanf("%d %d",&lins,&cols);

    Mapa* mapa = criaMapa(lins,cols);
    for(int i = 0;i<lins;i++){
        for(int j = 0; j < cols;j++){
            char buffer[15];
            scanf("%14s",buffer);
            insereNomeMapa(mapa,buffer,i,j);
        }
    }
    Mapa* trs = transpoe(mapa);
    Mapa* ord = ordena(mapa);
    imprimeMapa(mapa);
    printf("\n");
    printf("== Primeiro experimento:\n");
    imprimeMapa(trs);
    printf("\n");
    printf("== Segundo experimento:\n");
    imprimeMapa(ord);
    liberaMapa(mapa);
    liberaMapa(trs);
    liberaMapa(ord);
    return 0;
}
