#include "abb.h"
#include <stdio.h>

int main(int argc, char const *argv[])
{
    freopen("entrada.txt","r",stdin);
    freopen("saida1.txt","w",stdout);

    int qtd = 0;
    scanf("%d",&qtd);
    Abb* raiz = criaAbb();
    for(int i = 0;i<qtd;i++){
        char buffer[10];
        int mat = 0;

        scanf("%d %9s",&mat,buffer);
        raiz = insereAbb(raiz,mat,buffer);
    }
    int alt = alturaAbb(raiz);
    printf("Árvore Inicial (altura %d)\n",alt);
    imprimeAbb(raiz);

    char buffer[10];
    scanf("%9s",buffer);
    retiraAbb(raiz,buffer);
    scanf("%9s",buffer);
    retiraAbb(raiz,buffer);
    
    alt = alturaAbb(raiz);
    printf("\n");
    printf("Árvore Final (altura %d)\n",alt);
    imprimeAbb(raiz);

    return 0;
}
