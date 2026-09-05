#include "matriz.h"
#include <stdio.h>
#include <stdlib.h>

struct matriz{
    int lins,cols;
    int** pixels;
};
Matriz *criaMatriz(int lins, int cols)
{
    Matriz* mat = malloc(sizeof(Matriz));

    mat->lins = lins;
    mat->cols = cols;
    mat->pixels = malloc(lins*sizeof(int*));
    for(int i = 0;i<lins;i++){
        mat->pixels[i] = malloc(cols*sizeof(int));
    }

    return mat;
}

void insereValor(Matriz* mat,int i, int j, int pixel)
{
    mat->pixels[i][j] = pixel;
}

Matriz *suaviza(Matriz *m)
{
    Matriz* suavizada = criaMatriz(m->lins,m->cols);

    for(int i = 0;i<m->lins;i++){
        for(int j = 0;j<m->cols;j++){
            if(i == 0 || i == m->lins - 1 || j == 0 || j == m->cols - 1){
                suavizada->pixels[i][j] = m->pixels[i][j];
            }
            else{
                int soma = 0;
                int contador = 0;
                for(int x = i - 1;x<=i+1;x++){
                    for(int y = j - 1;y<=j+1;y++){
                        soma+= m->pixels[x][y];
                        contador++;
                    }
                }
                suavizada->pixels[i][j] = soma/contador;
            }
        }
    }
    return suavizada;
}

void imprimeMatriz(Matriz *m)
{
    for(int i = 0;i<m->lins;i++){
        for(int j = 0;j<m->cols;j++){
            printf("%d ",m->pixels[i][j]);
        }
        printf("\n");
    }
}

void liberaMatriz(Matriz *m)
{
    for(int i = 0;i<m->lins;i++){
        free(m->pixels[i]);
    }
    free(m->pixels);
    free(m);
}
