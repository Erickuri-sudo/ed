#ifndef matriz_h
#define matriz_h

typedef struct matriz Matriz;

Matriz* criaMatriz(int lins, int cols);
void insereValor(Matriz* mat,int i, int j, int pixel);
Matriz* suaviza(Matriz* m);
void imprimeMatriz(Matriz* m);
void liberaMatriz(Matriz* m);

#endif