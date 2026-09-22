#include "matriz.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct matriz{
    int lins,cols;
    char ***palavras;

};

Matriz *criaMatriz(int lins, int cols)
{
    Matriz* matriz = malloc(sizeof(Matriz));
    matriz->lins = lins;
    matriz->cols = cols;
    matriz->palavras = malloc(lins * sizeof(char**));
    for(int i = 0;i<lins;i++){
        matriz->palavras[i] = malloc(cols* sizeof(char*));
    }
    return matriz;
}

void insereElemento(Matriz *m, int i, int j, char *palavra)
{
    m->palavras[i][j] = strdup(palavra);
}

void buscaPalavra(Matriz *m, char *palavra)
{
    int encontrada = 0;
    for(int i = 0;i<m->lins;i++){
        for(int j = 0;j<m->cols;j++){
            if(!strcmp(palavra,m->palavras[i][j])){
                printf("Palavra encontrada na posicao [%d][%d] :)!\n",i,j);
                return;
            }
        }
    }
    printf("Palavra não encontrada... :(\n");
}

void imprimeMatriz(Matriz *m)
{
    for(int i = 0;i<m->lins;i++){
        for(int j = 0;j<m->cols;j++){
            printf("%s ",m->palavras[i][j]);
        }
        printf("\n");
    }
}

void liberaMatriz(Matriz *m)
{
    for(int i = 0;i<m->lins;i++){
        for(int j = 0;j<m->cols;j++){
            free(m->palavras[i][j]);
        }
        free(m->palavras[i]);
    }
    free(m->palavras);
    free(m);
}
