#include "arvore.h"

struct arv{
    Aluno *aluno;
    Arv *e;
    Arv *d;
};

Arv *arv_criavazia(void)
{
    return NULL;
}

Arv *arv_cria(Aluno *c, Arv *e, Arv *d)
{
    Arv *arvore = malloc(sizeof(Arv));
    arvore->aluno = c;
    arvore->d = d;
    arvore->e = e;
    return arvore;
}

Arv *arv_libera(Arv *a)
{
    if(!arv_vazia(a)){
        arv_libera(a->e);
        arv_libera(a->d);
        free(a);
    }
    return NULL;
}

int arv_vazia(Arv *a)
{
    return a == NULL;
}

int arv_pertence(Arv *a, int mat)
{
    if(arv_vazia(a)){
        return 0; 
    }
    else if(retornaMatricula(a->aluno) == mat){
        return 1;
    }
    else{
        return arv_pertence(a->e,mat)||arv_pertence(a->d,mat);
    }
    
}

void arv_imprime(Arv *a)
{
    if(!arv_vazia(a)){
        printf("Aluno/folha:%d - %s\n",retornaMatricula(a->aluno),retornaNome(a->aluno));
        arv_imprime(a->e);
        arv_imprime(a->d);
       
    }
}

Arv *arv_pai(Arv *a, int mat)
{
    if(!arv_vazia(a)){
        if(retornaMatricula(a->e->aluno) == mat || retornaMatricula(a->d->aluno) == mat){
            return a;
        }
        return arv_pai(a->e,mat) || arv_pai(a->d,mat);
    }
}

int folhas(Arv *a)
{
    if(arv_vazia(a)){
        return 0;
    }
    else if(a->d == NULL && a->e == NULL){
        return 1;
    }
    else{
        return folhas(a->e) + folhas(a->d);
    }
}

int ocorrencias(Arv *a, int mat)
{
    int contador = 0;
    if(arv_vazia(a)){
        return 0;
    }
    else if(!arv_vazia(a)){
        contador += folhas(a->e);
        contador += folhas(a->d);
        contador++;
    }
    
    return contador;
}
