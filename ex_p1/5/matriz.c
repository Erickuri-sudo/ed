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

void imprimeSubVisoesQuadradas(Matriz *m)
{
/* Para cada índice i de 0 até o número de linhas da matriz origem
Para cada índice j de 0 até o número de colunas da matriz origem
Max_tam: Determinar o maior tamanho possível de submatriz quadrada, a partir de (i,j)
Para cada x de 0 até o Max_tam:
sub = criaSubMatriz (origem, i, i+k, j, j+k);
imprime(sub);
libera(sub); */

    for(int i = 0;i<m->lins;i++){
        for(int j = 0;j<m->cols;j++){
            int max_tam = 0;
            int dLins = m->lins - i;
            int dCols = m->cols - j;
            if(dLins >= dCols){
                max_tam = dCols;
            }
            else
                max_tam = m->lins - i;

            for(int x = 0;x<max_tam;x++){
                Matriz* sub = criaSubMatriz(m,i,i+x,j,j+x);
                printf("Submatriz quadrada %dx%d em (%d,%d):\n",x+1,x+1,i,j);
                imprimeMatriz(sub);
                printf("\n");
                free(sub->dado);
                free(sub);
            }
            
        }
    }
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
