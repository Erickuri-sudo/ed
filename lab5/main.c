#include <stdio.h>
#include "lista.h"
#include "estudante.h"
#include <stdlib.h>
#include <string.h>
int main(int argc, char const *argv[])
{
    freopen("entrada.txt","r",stdin);
    freopen("saida.txt","w",stdout);

    int qtd = 0;
    Lista* l = criaLista();
    scanf("%d",&qtd);

    for(int i = 0;i<qtd;i++){
        int mat = 0;
        char nome[11];
        float cr = 0.0;
        scanf("%d",&mat);
        scanf("%10s",nome);
        scanf("%f",&cr);
        Estudante* e = criaEstudante(mat,cr,nome);
        insereEstudante(l,e);
    }

    imprimeLista(l);

    int mat = 0;
    while(scanf("%d",&mat)==1){
        retiraEstudante(l,mat);
        imprimeLista(l);
    }
    liberaLista(l);
    return 0;
}
