#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

int main(){
    int m = 0,n = 0;
    FILE *arq = fopen("entrada.txt","r");

    fscanf(arq,"%d %d",&m,&n);

    Matriz *mat = inicializaMatriz(m,n);

    int elem = 0;

    //preenche os elementos da matriz
    for(int i = 0;i < m;i++){
        for(int j = 0;j < n;j++){
            fscanf(arq,"%d",&elem);
            modificaElemento(mat,i,j,elem);
        }
    }
    
    Matriz *t = transposta(mat);
    Matriz *mult = multiplicacao(mat,t);

    //imprime a matriz original, a transposta e a multiplicacao entre as matrizes no arquivo saida.txt

    FILE *saida = freopen("saida.txt","w",stdout);

    imprimeMatriz(mat);
    fprintf(saida,"\n");
    fprintf(saida,"A matriz transposta eh: \n");
    imprimeMatriz(t);
    fprintf(saida,"\n");
    fprintf(saida, "A matriz multiplicacao eh: \n");
    imprimeMatriz(mult);
    fprintf(saida,"\n");

    //libera as matrizes
    destroiMatriz(mat);
    destroiMatriz(t);
    destroiMatriz(mult);

    //fecha os arquivos
    fclose(arq);
    fclose(saida);

    return 0;
}