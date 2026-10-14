#include "pilhaDupla.h"
#include <stdio.h>

int main(int argc, char const *argv[])
{
    Pilha* p = criaPilha();
    // preenche a pilha 1, max_tam(do vetor inteiro) = 6
    inserePilha1(p,1);
    inserePilha1(p,2);
    inserePilha1(p,3);
    // preenche a pilha 2, max_tam(do vetor inteiro) = 6
    inserePilha2(p,4);
    inserePilha2(p,5);
    inserePilha2(p,6);
    inserePilha2(p,7);

    imprimePilhas(p);
    liberaPilha(p);
    
    return 0;
}
