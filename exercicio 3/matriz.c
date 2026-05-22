#include "matriz.h"
#include <stdlib.h>
#include <stdio.h>

struct matriz{
    int nColunas;
    int nLinhas;
    int **m;
};

Matriz * inicializaMatriz(int nlinhas, int ncolunas)
{
    Matriz *mat = malloc(sizeof(Matriz));
    mat->nColunas = ncolunas;
    mat->nLinhas = nlinhas;
    mat->m = malloc(mat->nLinhas * (sizeof(int*)));

    for(int i = 0;i < mat->nLinhas;i++){
        mat->m[i] = malloc(mat->nColunas * sizeof(int));
    }
    
return mat;
}

void destroiMatriz(Matriz *mat)
{
    for(int i = 0;i < mat->nLinhas;i++){
        free(mat->m[i]);
    }
    free(mat->m);
    free(mat);
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
    Matriz *transposta = inicializaMatriz(mat->nColunas,mat->nLinhas);

    for(int i = 0;i < mat->nColunas;i++){
        for(int j = 0;j < mat->nLinhas;j++){
            transposta->m[i][j] = mat->m[j][i];
        }
    }
    return transposta;
}

Matriz *multiplicacao(Matriz *mat1, Matriz *mat2)
{
    if(mat1 == NULL){
        return NULL;
    }
    if(mat2 == NULL){
        return NULL;
    }
    if(mat1->nColunas != mat2->nLinhas){
        return NULL;
    }

    Matriz *multiplicada = inicializaMatriz(mat1->nLinhas,mat2->nColunas);

    for(int linha = 0; linha < mat1->nLinhas;linha++){

        for(int coluna = 0; coluna < mat2->nColunas;coluna++){

            for (int k = 0; k < mat2->nLinhas; k++) { // Dimensão comum
                multiplicada->m[linha][coluna] += mat1->m[linha][k] * mat2->m[k][coluna];
            }
        }
    }
    return multiplicada;
}

void modificaElemento(Matriz *mat, int linha, int coluna, int elem)
{
    // printf("mat[%d][%d] = %d\n",linha,coluna, elem);
    mat->m[linha][coluna] = elem;
}

int recuperaElemento(Matriz *mat, int linha, int coluna)
{
    return mat->m[linha][coluna];
}

void imprimeMatriz(Matriz *mat)
{
    for(int i = 0;i < mat->nLinhas;i++){
        for(int j = 0;j<mat->nColunas;j++){
            printf("%d ",mat->m[i][j]);
        }
        printf("\n");
    }
}

void imprimeLinha(Matriz *mat, int indice)
{
    for(int j = 0;j < mat->nColunas;j++){
        printf("%d ",mat->m[indice][j]);
    }
    printf("\n");
}
