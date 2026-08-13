#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void calc_esfera (float r, float* area, float* volume);

int raizes (float a, float b, float c, float* x1, float* x2);

int main(int argc, char const *argv[])
{
    // uso da funcao calc_esfera
    float *area = malloc(sizeof(float));
    float *volume = malloc(sizeof(float));
    float r = 0.0;

    printf("Insira o valor do raio:\n");
    scanf("%f",&r);
    calc_esfera(r,area,volume);
    printf("area: %f, volume: %f\n",*area,*volume);

    free(area);
    free(volume);

    // uso da funcao raizes
    float *x1 = malloc(sizeof(float));
    float *x2 = malloc(sizeof(float));
    float a = 0.0,b = 0.0,c = 0.0;

    printf("Insira o valor dos coeficientes a, b e c:\n");
    scanf("%f %f %f",&a,&b,&c);
    int qtd = raizes(a,b,c,x1,x2);
    if(qtd == 0){
        printf("Nao existem raizes reais para essa equacao");
    }
    else if(qtd == 1){
        printf("As duas raizes sao iguais: %f %f\n",*x1,*x2);
        free(x1);
        free(x2);
    }
    else
    printf("As duas raizes sao: %f %f\n",*x1,*x2);
    free(x1);
    free(x2);

    return 0;
}

void calc_esfera (float r, float* area, float* volume){
    *area = 4.0*r*r*3.14159265358979323846;
    *volume = 4.0*r*r*r*3.14159265358979323846/3;
}

int raizes (float a, float b, float c, float* x1, float* x2){
    float delta = 0.0;

    delta = b*b - 4*a*c;
    printf("delta: %f\n",delta);
    if(delta < 0){
        x1 = NULL;
        x2 = NULL;
        return 0;
    }

    *x1 = (-b + sqrt(delta))/(2*a);
    *x2 = (-b - sqrt(delta))/(2*a);

    if(delta == 0){
        return 1;
    }
    return 2;
    
}