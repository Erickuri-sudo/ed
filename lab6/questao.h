#ifndef questao_h
#define questao_h

typedef struct questao Questao;

Questao* criaQuestao(char* id,char* enunciado);
void imprimeQuestao(Questao* q);
void liberaQuestao(Questao* q);
char* retornaIdQuestao(Questao* q);
#endif