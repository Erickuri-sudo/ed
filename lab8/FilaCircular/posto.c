#include "posto.h"
#include "fila.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

struct posto{
    char* nome;
    Fila* processamento;
    Fila* positivas;
    Fila* negativas;
};

Posto *inicPosto(char *nome)
{
    Posto* posto = malloc(sizeof(Posto));
    posto->nome = strdup(nome);
    posto->processamento = criaFila();
    posto->positivas = criaFila();
    posto->negativas = criaFila();

    return posto;
}

void imprimePosto(Posto *posto)
{
    printf("Dados do Posto: %s\n",posto->nome);
    printf("Amostras não processadas\n");
    imprimeFila(posto->processamento);
    printf("Amostras com resultados positivos\n");
    imprimeFila(posto->positivas);
    printf("Amostras com resultados negativos\n");
    imprimeFila(posto->negativas);
}

void realizaColeta(Posto *posto, char *pessoa, int idade)
{
    Amostra* a = inicAmostra(pessoa,idade);
    insereFila(posto->processamento,a);
}

void processaLoteAmostras(Posto *posto)
{
    for(int i = retornaTamanhoFila(posto->processamento);i>0;i--){
        Amostra* a = retiraFila(posto->processamento);
        if(retornaCargaViral(a) >= LIMITE_CARGA_VIRAL){
            registraResultado(a,POSITIVO);
            insereFila(posto->positivas,a);
        }
        else{
            registraResultado(a,NEGATIVO);
            insereFila(posto->negativas,a);
        }
    }

}

void liberaPosto(Posto *posto)
{
    free(posto->nome);
    liberaFila(posto->processamento);
    liberaFila(posto->positivas);
    liberaFila(posto->negativas);
    free(posto);
}
