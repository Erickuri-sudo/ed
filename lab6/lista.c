#include "lista.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct cel Cel;

struct cel{
    Questao* q;
    Cel* prox;
};

struct lista{
    char* nome;
    int n;
    Cel* prim;
    Cel* ult;
};

Lista *criaLista(char* nome, int n)
{
    Lista* l = malloc(sizeof(Lista));
    l->nome = strdup(nome);
    l->prim = l->ult = NULL;
    l->n = n;
    return l;
}

void insereQuestao(Lista *l, Questao *q)
{
    if(!l || !q){
        return;
    }
    Cel* nova = malloc(sizeof(Cel));
    nova->q = q;
    nova->prox = NULL;
    // primeiro elemento
    if(l->prim == NULL && l->ult == NULL){
        l->prim = l->ult = nova;
    }
    // caso comum
    else{
        nova->prox = l->prim;
        l->prim = nova;
    }
}

void imprimeLista(Lista *l)
{
    Cel* p = l->prim;
    printf("Prova: %s\n",l->nome);
    while(p){
        imprimeQuestao(p->q);
        p = p->prox;
    }
}

void insereQuestaoDoBancoNaProva(Lista *banco, Lista *prova, char* id)
{
    Cel* aux = banco->prim;
    while(aux && strcmp(retornaIdQuestao(aux->q),id)){
        aux = aux->prox;
    }
    // nao encontrou a questao
    if(!aux){
        return;
    }
    insereQuestao(prova,aux->q);

}

Lista* mergeProvas(Lista *p1, Lista *p2)
{
    if(!p1 || !p2){
        return NULL;
    }

    Lista* merge = criaLista("merge",p1->n+p2->n);
    // ponteiros que vao caminhar nas duas listas
    Cel* p1_atual = p1->prim;
    Cel* p2_atual = p2->prim;
    // ponteiros para nao perder a referencia dos proximos
    Cel* p1_prox = NULL;
    Cel* p2_prox = NULL;
    
    // inicializando prim e ult para previnir segfault
    merge->prim = p1_atual;
    merge->ult = p2_atual;

    while(p1_atual!=NULL && p2_atual!=NULL){
        // recebe os proximos
        p1_prox = p1_atual->prox;
        p2_prox = p2_atual->prox;

        if(p1_prox){
            // prox do atual se torna o prox do p2_atual
            p1_atual->prox = p2_prox;
        }
        
        p2_atual->prox = p1_atual;
        merge->ult = p1_atual;

        p1_atual = p1_prox;
        p2_atual = p2_prox;
    }

    if(p2_atual!=NULL){
        merge->ult->prox = p2_atual;
        merge->ult = p2->ult;
    }
    else if(p1_atual!=NULL){
        merge->ult = p1->ult;

    }

    return merge;
}

void retiraQuestoesRepetidas(Lista *merge)
{
    Cel* p = merge->prim;
    // o loop exterior itera sobre cada celula da lista
    while(p){
        Cel* ant = p;
        Cel* aux = p->prox;
        // para cada p, caminha com um aux(o proximo de p) e o anterior de aux
        // assim, compara p com aux e mantem ant para remocao
        while(aux){
            if(!strcmp(retornaIdQuestao(p->q),retornaIdQuestao(aux->q))){
                // desencadeia aux
                ant->prox = aux->prox;
                // se aux for a ultima celula atualiza a sentinela
                if(aux == merge->ult){
                    merge->ult = ant;
                }
                // remove a celula e atualiza aux
                Cel* removida = aux;
                aux = aux->prox;
                free(removida);
                merge->n--;
                ant = ant->prox;
            }
            else{
                ant = aux;
                aux = aux->prox;
            }
        }
        p = p->prox;
    }
    
}

void liberaListaCompleta(Lista *l)
{
    free(l->nome);
    Cel* p = l->prim;
    Cel* aux = NULL;
    while(p){
        aux = p;
        p = p->prox;
        liberaQuestao(aux->q);
        free(aux);
    }
    free(l);
}

void liberaCelulasLista(Lista *l)
{
    free(l->nome);
    Cel* p = l->prim;
    Cel* aux = NULL;
    while(p){
        aux = p;
        p = p->prox;
        free(aux);
    }
    free(l);
}

void liberaSoSentinela(Lista *l)
{
    free(l->nome);
    free(l);
}
