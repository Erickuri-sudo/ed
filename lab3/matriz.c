#include "matriz.h"
#include <stdlib.h>

struct matriz{
    int nLinhas;
    int nColunas;
    int **mat;
};

Matriz *inicializaMatriz(int nlinhas, int ncolunas)
{
    Matriz* m = malloc(sizeof(Matriz));
    m->nColunas = ncolunas;
    m->nLinhas = nlinhas;
    m->mat = malloc(nlinhas * sizeof(int*));
    for(int i = 0;i<nlinhas;i++){
        m->mat[i] = malloc(ncolunas * sizeof(int));
    }

    return m;
}

void modificaElemento(Matriz *mat, int linha, int coluna, int elem)
{
    if(mat == NULL){
        return;
    }
    if(linha > mat->nLinhas || coluna > mat->nColunas){
        return;
    }

    mat->mat[linha][coluna] = elem;
}

int recuperaElemento(Matriz *mat, int linha, int coluna)
{   

    return mat->mat[linha][coluna];
}

int recuperaNColunas(Matriz *mat)
{
    return mat->nColunas;
}

int recuperaNLinhas(Matriz *mat)
{
    return mat->nLinhas;
}

Matriz *transposta(Matriz *mat)
{
    Matriz* trs = inicializaMatriz(mat->nColunas,mat->nLinhas);
    for(int i = 0;i<mat->nLinhas;i++){
        for(int j = 0;j<mat->nColunas;j++){
            trs->mat[j][i] = mat->mat[i][j];
        }
    }
    return trs;
}

void imprimeMatriz(Matriz *mat)
{
    for(int i = 0;i<mat->nLinhas;i++){
        for(int j = 0;j<mat->nColunas;j++){
            printf("%d ",mat->mat[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void imprimeLinha(Matriz *mat, int indice)
{
    for(int i = 0;i<mat->nColunas;i++){
        printf("%d ",mat->mat[indice][i]);
    }
    printf("\n");
}

void destroiMatriz(Matriz *mat)
{
    if(mat == NULL){
        return;
    }
    for(int i = 0;i<mat->nLinhas;i++){
      free(mat->mat[i]);
    }
    free(mat);
}
