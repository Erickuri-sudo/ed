#include "fila.h"
#include "amostra.h"
#include <stdio.h>
#include <stdlib.h>
#define MAX_TAM 10

struct fila{
    int n;
    int ini;
    Amostra* amostras[MAX_TAM];
};

Fila *criaFila()
{
    Fila* fila = malloc(sizeof(Fila));
    fila->ini = 0;
    fila->n = 0;
    return fila;
}

void insereFila(Fila *f, Amostra *a)
{
    int fim = 0;

    if(f->n == MAX_TAM){
        printf("Fila cheia\n");
    }
    if(retornaIdade(a)>=60){
        f->ini = (f->ini - 1+MAX_TAM)%MAX_TAM;
        f->amostras[f->ini] = a;
    }
    else{
        fim = (f->ini+f->n)%MAX_TAM;
        f->amostras[fim] = a;
    }
    f->n++;
}

Amostra *retiraFila(Fila *f)
{
    Amostra* a;
    if(f->n == 0){
        printf("fila vazia\n");
        return NULL;
    }
    a = f->amostras[f->ini];
    f->ini = (f->ini + 1)%MAX_TAM;
    f->n--;
    return a;
}

void imprimeFila(Fila *f)
{
    int fim = (f->ini+f->n)%MAX_TAM;
    if(f->ini <= fim){
        for(int i = f->ini;i<fim;i++){
            imprimeAmostra(f->amostras[i]);
        }
    }
    else{
        for(int i = f->ini;i<MAX_TAM;i++){
            imprimeAmostra(f->amostras[i]);
        }
        for(int i = 0;i<fim;i++){
            imprimeAmostra(f->amostras[i]);
        }
    }
    printf("\n");
}

int retornaTamanhoFila(Fila *f)
{
    return f->n;
}

void liberaFila(Fila *f)
{
    int pos = 0;
    for(int i = 0;i<f->n;i++){
        pos = (f->ini + i)%MAX_TAM;
        liberaAmostra(f->amostras[pos]);
    }
    free(f);
}
