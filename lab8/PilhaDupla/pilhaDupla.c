#include "pilhaDupla.h"
#include <stdlib.h>
#include <stdio.h>

#define MAX_TAM 6

typedef struct idxPil IdxPil;
struct idxPil{
    int base;
    int topo;
};

struct pilha{
    IdxPil pil1,pil2;
    int itens[MAX_TAM];
};

Pilha *criaPilha()
{
    Pilha* pilha = malloc(sizeof(Pilha));
    pilha->pil1.base = 0;
    pilha->pil1.topo = -1;
    pilha->pil2.base = MAX_TAM-1;
    pilha->pil2.topo = MAX_TAM;
    return pilha;
}

void inserePilha1(Pilha *p, int num)
{
    // se vetor cheio
    if(p->pil1.topo == p->pil2.topo-1){
        printf("Lista cheia, inteiro nao inserido\n");
        return;
    }
    p->pil1.topo++;
    p->itens[p->pil1.topo] = num;

}

void inserePilha2(Pilha *p, int num)
{
    // se vetor cheio
    if(p->pil2.topo-1 == p->pil1.topo){
        printf("Lista cheia, inteiro nao inserido\n");
        return;
    }
    p->pil2.topo--;
    p->itens[p->pil2.topo] = num;
}

void imprimePilha1(Pilha *p)
{
    for(int i = p->pil1.base;i<=p->pil1.topo;i++){
        printf("%d ",p->itens[i]);
    }
    printf("\n");
}

void imprimePilha2(Pilha *p)
{
    for(int i = p->pil2.base;i>=p->pil2.topo;i--){
        printf("%d ",p->itens[i]);
    }
    printf("\n");
}

void imprimePilhas(Pilha *p)
{
    printf("Pilha 1:\n");
    imprimePilha1(p);
    printf("Pilha 2:\n");
    imprimePilha2(p);

}

void liberaPilha(Pilha *p)
{
    free(p);
}
