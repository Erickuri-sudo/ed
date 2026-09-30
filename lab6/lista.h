#ifndef lista_h
#define lista_h

#include "questao.h"

typedef struct lista Lista;

Lista* criaLista(char* nome,int n);
void insereQuestao(Lista* l,Questao* q);
void imprimeLista(Lista* l);
void insereQuestaoDoBancoNaProva(Lista* banco,Lista* prova, char* id);
Lista* mergeProvas(Lista* p1,Lista* p2);
void retiraQuestoesRepetidas(Lista* merge);
#endif