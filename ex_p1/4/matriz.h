#ifndef matriz_h
#define matriz_h

typedef struct matriz Matriz;

Matriz* criaMatriz(int lins, int cols);
void insereElemento(Matriz* m,int i,int j,char* palavra);
void buscaPalavra(Matriz* m,char* palavra);
void imprimeMatriz(Matriz* m);
void liberaMatriz(Matriz* m);
#endif