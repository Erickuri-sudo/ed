#ifndef pilhaDupla_h
#define pilhaDupla_h

typedef struct pilha Pilha;

Pilha* criaPilha();
void inserePilha1(Pilha* p, int num);
void inserePilha2(Pilha* p,int num);
void imprimePilha1(Pilha* p);
void imprimePilha2(Pilha* p);
void imprimePilhas(Pilha* p);
void liberaPilha(Pilha* p);
#endif