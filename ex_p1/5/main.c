#include <stdio.h>
#include "matriz.h"

int main(int argc, char const *argv[])
{
    freopen("entrada1.txt","r",stdin);
    freopen("saida1.txt","w",stdout);

    int lins= 0,cols = 0;
    
    scanf("%d %d",&lins,&cols);
    Matriz* m = criaMatriz(lins,cols);
    
    for(int i = 0;i<lins;i++){
        for(int j = 0;j<cols;j++){
            int dado = 0;
            scanf("%d",&dado);
            insereDado(m,i,j,dado);
        }
    }
    int slini = 0,slfim = 0,scini = 0,scfim = 0;

    scanf("%d %d %d %d",&slini,&slfim,&scini,&scfim);
    Matriz* sub = criaSubMatriz(m,slini,slfim,scini,scfim);
    printf("Matriz Original:\n");
    imprimeMatriz(m);
    printf("Visão Submatriz %d-%d %d-%d:\n",slini,slfim,scini,scfim);
    imprimeMatriz(sub);
    liberaMatriz(m);
    return 0;
}
