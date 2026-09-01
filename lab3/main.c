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
    //transpoe matriz
    Matriz* trs = transposta(m);
    //multiplica as matrizes
    Matriz* mult = multiplicacao(m,trs);

    //imprime as matrizes
    imprimeMatriz(m);
    printf("\n");
    printf("A matriz transposta eh: \n");
    imprimeMatriz(trs);
    printf("\n");
    printf("A matriz multiplicacao eh: \n");
    imprimeMatriz(mult);

    //libera as estruturas
    destroiMatriz(m);
    destroiMatriz(trs);
    destroiMatriz(mult);
    return 0;
}
