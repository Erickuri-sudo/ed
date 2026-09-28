#include <stdio.h>
#include "lista.h"
#include <string.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    freopen("entrada.txt","r",stdin);
    freopen("saida.txt","w",stdout);

    int qtd = 0;
    scanf("%d",&qtd);
    Lista* l = criaLista();

    for(int i = 0;i<qtd;i++){
        char nome[11];
        int mat;
        float cr;

        scanf("%d %s %f",&mat,nome,&cr);
        Estudante* e = criaEstudante(mat,nome,cr);
        insereEstudanteLista(l,e);
    }
    imprimeLista(l);

    int mat = 0;
    while(scanf("%d",&mat)==1){
        printf("================\n");
        retiraEstudantePorMatricula(l,mat);
        imprimeLista(l);
    }
    
    return 0;
}
