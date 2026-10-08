#include "listaLei.h"
#include "listaPes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    freopen("entrada.txt","r",stdin);
    freopen("saida.txt","w",stdout);

    ListaPes* pessoas = criaListaPes();
    char nome[10];
    int lat = 0,longi = 0;
    float temp = 0.0;

    while(scanf("%s %d %d %f",nome,&lat,&longi,&temp)==4){
        Pessoa* pessoa = buscaPessoa(pessoas,nome);
        if(!pessoa){ // se nao existe a pessoa
            pessoa = criaPessoa(nome);
            inserePessoaLista(pessoas,pessoa);
        }
        Leitura* lei = criaLeitura(lat,longi,temp);
        insereLeituraPessoa(pessoa,lei);
    }
    imprimeListaPes(pessoas);
    return 0;
}
