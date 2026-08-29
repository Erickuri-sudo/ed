#include <stdio.h>
#include <stdlib.h>
#include "supermercado.h"

typedef struct catalogo{
    int nProdutos;
    Produto** produtos;
}Catalogo;

Catalogo criaCatalogo(int nProdutos);
Catalogo insereProdutoCatalogo(Produto* p,Catalogo c,int pos);
Produto* retornaProdutoPorId(Catalogo c,int id);
void imprimeCatalogo(Catalogo c);
int main(int argc, char const *argv[])
{ 
    int nProdutos = 0;
    scanf("%d",&nProdutos);
    int id = 0;
    char nome[16];
    float preco = 0.0;
    Catalogo c = criaCatalogo(nProdutos);

    for(int i = 0;i<nProdutos;i++){
        scanf("%d %s %f",&id,nome,&preco);
        Produto* p = criaProduto(id,nome,preco);
        c = insereProdutoCatalogo(p,c,i);
    }
    
    int qtdFiliais = 0;
    char nomeSuper[11];
    scanf("%s",nomeSuper);
    scanf("%d",&qtdFiliais);
    Supermercado* s = criaSupermercado(nomeSuper,qtdFiliais);

    for(int j = 0;j<qtdFiliais;j++){
        char nomeFilial[25];
        int qtdItens = 0;
        scanf("%s",nomeFilial);
        scanf("%d",&qtdItens);
        Filial* f = criaFilial(nomeFilial,qtdItens);
        for(int m = 0;m<qtdItens;m++){
            int idItem = 0;
            int qtdItem = 0;
            scanf("%d %d",&idItem,&qtdItem);
            Item* i = criaItem(retornaProdutoPorId(c,idItem),qtdItem);
            adicionaItemFilial(f,i);
        }
        adicionaFilial(s,f);
    }
    imprimeSupermercado(s);
    //imprimeCatalogo(c);
    return 0;
}
Catalogo criaCatalogo(int nProdutos){
    Catalogo c;
    c.produtos = malloc(nProdutos*sizeof(Produto*));
    c.nProdutos = nProdutos;
    return c;
}
Catalogo insereProdutoCatalogo(Produto* p,Catalogo c,int pos){
    c.produtos[pos] = p;
    return c;
}
Produto* retornaProdutoPorId(Catalogo c,int id){
    for(int i = 0;i<c.nProdutos;i++){
        if(retornaIdProduto(c.produtos[i]) == id){
            return c.produtos[i];
        }
    }
    return NULL;
}
void imprimeCatalogo(Catalogo c){
    for(int i = 0;i<c.nProdutos;i++){
        printf("nome: %s,valor: %.2f, id: %d\n",retornaNomeProduto(c.produtos[i]),
        retornaPrecoProduto(c.produtos[i]),retornaIdProduto(c.produtos[i]));
    }
}