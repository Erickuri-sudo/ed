#include <stdio.h>
#include "matriz.h"

int main(int argc, char const *argv[])
{
    freopen("entrada.txt","r",stdin);
    freopen("saida.txt","w",stdout);

    int lins = 0,cols = 0;

    scanf("%d %d", &lins,&cols);    

    Matriz* m = criaMatriz(lins,cols);

    for(int i = 0;i<lins;i++){
        for(int j = 0;j<cols;j++){
            char buffer[16];
            scanf("%15s",buffer);
            inserePalavra(m,i,j,buffer);
        }
    }
    Matriz* ord = ordena(m);
    imprimeMatriz(m);
    printf("============================\n");
    imprimeMatriz(ord);

    liberaMatriz(m);
    liberaMatriz(ord);
    return 0;
}
