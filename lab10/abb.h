#ifndef abb_h
#define abb_h

typedef struct abb Abb;

Abb* criaAbb();
Abb* insereAbb(Abb* a, int mat, char* nome);
Abb* retiraAbb(Abb* a,char* nome);
int alturaAbb(Abb* a);
void imprimeAbb(Abb* a);
#endif