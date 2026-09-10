#ifndef matriz_h
#define matriz_h

typedef struct matriz Matriz;

Matriz* criaMatriz(int lins,int cols);
void insereDado(Matriz* m,int i, int j,int dado);
Matriz* criaSubMatriz (Matriz* m, int linha_ini, int linha_fim, int col_ini, int col_fim);
void imprimeMatriz(Matriz* m);
void liberaMatriz(Matriz* m);

#endif