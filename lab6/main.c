#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    freopen("entrada.txt","r",stdin);
    freopen("saida.txt","w",stdout);
    int qtd = 0;
    scanf("%d",&qtd);

    Lista* l = criaLista("banco",qtd);

    for(int i = 0;i<qtd;i++){
        char id[3];
        char enun[26];
        scanf("%s %[^\n]",id,enun);
        Questao* q = criaQuestao(id,enun);
        insereQuestao(l,q);
    }

    imprimeLista(l);

    char nome1[11];
    int qtdP1 = 0;
    scanf("%s",nome1);
    scanf("%d",&qtdP1);
    Lista* p1 = criaLista(nome1,qtdP1);
    for(int i = 0;i<qtdP1;i++){
        char id[3];
        scanf("%s",id);
        printf("%s ",id);
        insereQuestaoDoBancoNaProva(l,p1,id);
    }
    imprimeLista(p1);

    char nome2[11];
    int qtdP2 = 0;
    scanf("%s",nome2);
    scanf("%d",&qtdP2);
    Lista* p2 = criaLista(nome2,qtdP2);
    for(int i = 0;i<qtdP2;i++){
        char id[3];
        scanf("%s",id);
        printf("%s ",id);
        insereQuestaoDoBancoNaProva(l,p2,id);
    }
    imprimeLista(p2);
    return 0;
}
