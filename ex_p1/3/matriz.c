#include "matriz.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct matriz{
    int lins,cols;
    char*** palavras;
};

Matriz *criaMatriz(int lins, int cols)
{
    Matriz* matriz = malloc(sizeof(Matriz));
    matriz->lins = lins;
    matriz->cols = cols;
    matriz->palavras = malloc(lins*sizeof(char**));
    for(int i = 0;i<lins;i++){
        matriz->palavras[i] = calloc(cols,sizeof(char*));
    }

    return matriz;
}

void inserePalavra(Matriz *m, int i, int j, char *palavra)
{
    m->palavras[i][j] = strdup(palavra);
}

Matriz *ordena(Matriz *m)
{
    Matriz* ord = criaMatriz(m->lins,m->cols);
    int tam = m->lins*m->cols;
    char** vet = malloc(tam*sizeof(char*));
    int k = 0;

    // copia os enderecos da matriz original para um vetor auxiliar
    for(int i = 0;i<m->lins;i++){
        for(int j = 0;j<m->cols;j++){
            vet[k] = m->palavras[i][j];
            k++;
        }
    }

    for(int i = 0;i<tam-1;i++){
        for(int j = 0;j<tam-1;j++){
            if(strcmp(vet[j],vet[j+1])>0){
                char *aux = vet[j];
                vet[j] = vet[j+1];
                vet[j+1] = aux;
            }
        }
    }
    k = 0;

    for(int i = 0;i<ord->lins;i++){
        for(int j = 0;j<ord->cols;j++){
            ord->palavras[i][j] = strdup(vet[k]);
            k++;
        }
    }
    free(vet);
    return ord;
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
