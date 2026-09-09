#include "mapa.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct mapa
{
    char ***nomes;
    int lins, cols;
};

Mapa *criaMapa(int lins, int cols)
{
    Mapa *mapa = malloc(sizeof(Mapa));
    mapa->nomes = malloc(lins * sizeof(char **));

    for (int i = 0; i < lins; i++)
    {
        mapa->nomes[i] = calloc(cols, sizeof(char *));
    }
    mapa->cols = cols;
    mapa->lins = lins;

    return mapa;
}

void insereNomeMapa(Mapa *m, char *nome, int i, int j)
{
    m->nomes[i][j] = strdup(nome);
}

Mapa *transpoe(Mapa *m)
{
    Mapa *trs = criaMapa(m->cols, m->lins);
    for (int i = 0; i < m->lins; i++)
    {
        for (int j = 0; j < m->cols; j++)
        {
            trs->nomes[j][i] = strdup(m->nomes[i][j]);
        }
    }
    return trs;
}

Mapa *ordena(Mapa *m)
{
    Mapa *ord = criaMapa(m->lins, m->cols);
    char bufferMaior[15];
    // primeira estrategia: gravar toda a matriz em um vetor e ordenar o vetor
    int tam = m->lins * m->cols;
    char **vet = malloc(tam * sizeof(char*));
    int k = 0;
    for (int i = 0; i < m->lins; i++)
    {
        for (int j = 0; j < m->cols; j++)
        {
            vet[k] = m->nomes[i][j];
            k++;
        }
    }
    for (int j = 0; j < k - 1; j++)
    {
        for (int i = 0; i < k - 1; i++)
        {
            if (strcmp(vet[i], vet[i + 1]) > 0)
            {
                char *temp = vet[i];
                vet[i] = vet[i + 1];
                vet[i + 1] = temp;
            }
        }
    }

    k = 0;

    for (int i = 0; i < ord->lins; i++)
    {
        for (int j = 0; j < ord->cols; j++)
        {
            ord->nomes[i][j] = strdup(vet[k]);
            k++;
        }
    }
    free(vet);
    return ord;
}

void imprimeMapa(Mapa *m)
{
    for (int i = 0; i < m->lins; i++)
    {
        for (int j = 0; j < m->cols; j++)
        {
            printf("%s ", m->nomes[i][j]);
        }
        printf("\n");
    }
}

void liberaMapa(Mapa *m)
{
    for (int i = 0; i < m->lins; i++)
    {
        for (int j = 0; j < m->cols; j++)
        {
            free(m->nomes[i][j]);
        }
        free(m->nomes[i]);
    }
    free(m->nomes);
    free(m);
}
