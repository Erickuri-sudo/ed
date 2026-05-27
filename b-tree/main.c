#include "arvore.h"
#include "aluno.h"

int main(int argc, char const *argv[])
{
    Aluno *a = criaAluno("alunoA",1);
    Aluno *b = criaAluno("alunoB",2);
    Aluno *c = criaAluno("alunoC",3);
    Aluno *d = criaAluno("alunoD",4);
    Aluno *e = criaAluno("alunoE",5);
    Aluno *f = criaAluno("alunoF",6);
    Aluno *g = criaAluno("alunoG",7);

    //subarvore c--b--d
    Arv *nodec = arv_cria(c,arv_criavazia(),arv_criavazia());
    Arv *noded = arv_cria(d,arv_criavazia(),arv_criavazia());
    Arv *nodeb = arv_cria(b,nodec,noded);
    //subarvore f--e--g
    Arv *nodef = arv_cria(f,arv_criavazia(),arv_criavazia());
    Arv *nodeg = arv_cria(g,arv_criavazia(),arv_criavazia());
    Arv *nodee = arv_cria(e,nodef,nodeg);
    //arvore completa b--a--e
    Arv *nodea = arv_cria(a,nodeb,nodee);
    arv_imprime(nodea);

    Arv *nulo = arv_criavazia();
    int contador = 0;
    contador = folhas(nodea);
    printf("%d\n",contador);
    Arv *pai = arv_pai(nodea,3);
    arv_imprime(pai);
    arv_libera(nodea);
    return 0;
}
