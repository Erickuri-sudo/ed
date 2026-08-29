#ifndef produto_h
#define produto_h

typedef struct produto Produto;

Produto* criaProduto(int id,char* nome,float preco);
float retornaPrecoProduto(Produto* p);
char* retornaNomeProduto(Produto* p);
int retornaIdProduto(Produto* p);
void liberaProduto(Produto* p);

#endif