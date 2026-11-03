#include "abb.h"
#include <stdio.h>

int main(int argc, char const *argv[])
{
    freopen("entrada.txt","r",stdin);

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
    printf("Arvore inicial (altura %d):\n",alt);
    imprimeAbb(raiz);
    
    return 0;
}
