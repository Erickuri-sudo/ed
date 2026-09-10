#include "matriz.h"
#include <stdio.h>
#include <stdlib.h>
struct matriz{
    int lins,cols;
    int **dado;
};

Matriz *criaMatriz(int lins, int cols)
{
    Matriz* matriz = malloc(sizeof(Matriz));
    matriz->dado = malloc(lins*sizeof(int*));
    for(int i = 0;i<lins;i++){
        matriz->dado[i] = malloc(cols*sizeof(int));
    }
    matriz->lins = lins;
    matriz->cols = cols;


    return matriz;
}

void insereDado(Matriz *m, int i, int j, int dado)
{
    m->dado[i][j] = dado;
}

Matriz* criaSubMatriz(Matriz *m, int linha_ini, int linha_fim, int col_ini, int col_fim)
{
    int slins = linha_fim - linha_ini + 1;
    int scols = col_fim - col_ini +1;

    Matriz* sub = malloc(sizeof(Matriz));
    sub->lins = slins;
    sub->cols = scols;
    sub->dado = malloc(slins*sizeof(int*));

    for(int i = 0;i<slins;i++){
            sub->dado[i] = &m->dado[linha_ini + i][col_ini];
    }

    return sub;
}

void imprimeMatriz(Matriz *m)
{
    for(int i = 0;i<m->lins;i++){
        for(int j = 0;j<m->cols;j++){
            printf("%d ",m->dado[i][j]);
        }
        printf("\n");
    }
}

void liberaMatriz(Matriz *m)
{
    for(int i = 0;i<m->lins;i++){
        free(m->dado[i]);
    }
    free(m->dado);
    free(m);
}
