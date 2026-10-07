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

    Lista* l = criaLista();

    for(int i = 0;i<qtd;i++){
        char tipo;
        char nome[10];
        int cpf = 0;
        float dado = 0.0;
        scanf(" %c %9s %d %f",&tipo,nome,&cpf,&dado);

        if(tipo == 'A'){
            Aluno* a = criaAluno(nome, cpf, dado);
            insereAluno(l,a);
        }
        else{
            Prof* p = criaProf(nome, cpf, dado);
            insereProfessor(l,p);
        }
    }

    imprimeLista(l);
    liberaLista(l);
    return 0;
}
