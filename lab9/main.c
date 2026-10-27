#include "arvore.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    Aluno* a = criaAluno(1,"A");
    Aluno* b = criaAluno(2,"B");
    Aluno* c = criaAluno(3,"C");

    Arv* a1 = arv_cria(a,arv_criavazia(),arv_criavazia());
    //arv_imprime(a1);
    Arv* a2 = arv_cria(b, arv_criavazia(),arv_criavazia());
    Arv* a3 = arv_cria(c,a1,a2);

    arv_imprime(a3);

    printf("\n");
    int mat = 4;
    int pert = arv_pertence(a3,mat);
    if(pert){
        printf("A matricula %d pertence a arvore\n",mat);
    }
    else{
        printf("A matricula %d nao pertence a arvore\n",mat);
    }
    mat = 2;
    pert = arv_pertence(a3,mat);
    if(pert){
        printf("A matricula %d pertence a arvore\n",mat);
    }
    else{
        printf("A matricula %d nao pertence a arvore\n",mat);
    }

    int qtd = folhas(a3);
    printf("Quantidade de nos folha: %d\n",qtd);

    Arv* pai = arv_pai(a3,mat);
    if(pai){
        printf("Arvore pai da matricula %d:",mat);
        arv_imprime(pai);
        printf("\n");
    }
    qtd = ocorrencias(a3,1);
    printf("%d\n",qtd);
    return 0;
}