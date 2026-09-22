#ifndef matriz_h
#define matriz_h

typedef struct matriz Matriz;

Matriz* criaMatriz(int lins,int cols);
void inserePalavra(Matriz* m,int i,int j,char* palavra);
Matriz* ordena(Matriz* m);
void imprimeMatriz(Matriz* m);
void liberaMatriz(Matriz* m);

#endif