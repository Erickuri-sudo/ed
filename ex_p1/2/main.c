#include "matriz.h"
#include <stdio.h>

int main(int argc, char const *argv[])
{
    freopen("entrada.txt","r",stdin);
    freopen("saida.txt","w",stdout);
    int lins = 0,cols=0;
    int pixel = 0;

    scanf("%d %d",&lins,&cols);

    Matriz* mat = criaMatriz(lins,cols);

    for(int i = 0;i<lins;i++){
        for(int j = 0;j<cols;j++){
            scanf("%d",&pixel);
            insereValor(mat,i,j,pixel);
        }
    }
    Matriz* s = suaviza(mat);

    imprimeMatriz(mat);
    printf("\n");
    printf("A matriz com filtro de suavização eh:\n");
    imprimeMatriz(s);
    liberaMatriz(mat);

    return 0;
}
