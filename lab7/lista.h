#ifndef lista_h
#define lista_h

typedef struct lista Lista;
typedef struct aluno Aluno;
typedef struct professor Prof;

Lista* criaLista();
Aluno* criaAluno(char* nome,int cpf,float cr);
Prof* criaProf(char* nome,int cpf,float salario);
void insereAluno(Lista* l,Aluno* a);
void insereProfessor(Lista* l, Prof* p);
void imprimeProfessor(Prof* p);
void imprimeAluno(Aluno* a);
void imprimeLista(Lista* l);
void liberaAluno(Aluno* a);
void liberaProfessor(Prof* p);
void liberaLista(Lista* l);
#endif