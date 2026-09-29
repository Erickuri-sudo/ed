#include "questao.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct questao{
    char* id;
    char* enunciado;
};

Questao *criaQuestao(char *id, char *enunciado)
{
    Questao* q = malloc(sizeof(Questao));
    // malloc implicito
    q->id = strdup(id);
    // outro malloc implicito
    q->enunciado = strdup(enunciado);

    return q;
}

void imprimeQuestao(Questao *q)
{
    printf("ID: %s, Enunciado: %s\n",q->id,q->enunciado);
}

void liberaQuestao(Questao *q)
{
    free(q->id);
    free(q->enunciado);
    free(q);
}

char *retornaIdQuestao(Questao *q)
{
    return q->id;
}
