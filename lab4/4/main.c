#include <stdio.h>
#include <string.h>
#include "matriz.h"

int main(int argc, char const *argv[])
{
    freopen("entrada.txt","r",stdin);
    freopen("saida.txt","w",stdout);

    int cols = 0,lins = 0;

    scanf("%d %d",&lins,&cols);

    Matriz* m = criaMatriz(lins,cols);

    for(int i = 0;i<lins;i++){
        for(int j = 0;j<cols;j++){
            char buffer[16];
            scanf("%s",buffer);
            insereElemento(m,i,j,buffer);
        }
    }

    imprimeMatriz(m);
    printf("\n============================\n\n");

    char busca[16];
    while(strcmp(busca,"0")){
        printf("==> Digite a palavra para o caça-palavras ou 0, caso queira sair:\n");
        scanf("%s",busca);
        // verifica se o ultimo scanf recebeu 0 e termina caso positivo
        if(!strcmp(busca, "0")){
            break;
        }
        buscaPalavra(m,busca); 
        printf("\n");
    }

    liberaMatriz(m);
    return 0;
}
