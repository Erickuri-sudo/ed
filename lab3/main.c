#include "matriz.h"
#include <stdio.h>

int main(int argc, char const *argv[])
{
    //redireciona a entrada e saida padrao para os arquivos
    freopen("entrada.txt","r",stdin);
    freopen("saida.txt","w",stdout);

    int lins = 0,cols = 0;

    scanf("%d %d",&lins,&cols);

    //cria e preenche a matriz
    Matriz* m = inicializaMatriz(lins,cols);
    int elem = 0;
    for(int i = 0;i<lins;i++){
        for(int j = 0;j<cols;j++){
            scanf("%d",&elem);
            modificaElemento(m,i,j,elem);
        }
    }
    //transpoe matriz e imprime as matrizes
    Matriz* trs = transposta(m);
    imprimeMatriz(m);
    printf("A matriz transposta eh: \n");
    imprimeMatriz(trs);

    destroiMatriz(m);
    destroiMatriz(trs);
    return 0;
}
