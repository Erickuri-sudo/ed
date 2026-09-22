#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void calc_esfera (float r, float* area, float* volume);
int raizes (float a, float b, float c, float* x1, float* x2);
int pares (int n, int* vet);
void inverte (int n, int* vet);
double avalia (double* poli, int grau, double x);

int main(int argc, char const *argv[])
{
    // // uso da funcao calc_esfera
    // float *area = malloc(sizeof(float));
    // float *volume = malloc(sizeof(float));
    // float r = 0.0;

    // printf("Insira o valor do raio:\n");
    // scanf("%f",&r);
    // calc_esfera(r,area,volume);
    // printf("area: %f, volume: %f\n",*area,*volume);

    // free(area);
    // free(volume);

    // // uso da funcao raizes
    // float *x1 = malloc(sizeof(float));
    // float *x2 = malloc(sizeof(float));
    // float a = 0.0,b = 0.0,c = 0.0;

    // printf("Insira o valor dos coeficientes a, b e c:\n");
    // scanf("%f %f %f",&a,&b,&c);
    // int qtd = raizes(a,b,c,x1,x2);
    // if(qtd == 0){
    //     printf("Nao existem raizes reais para essa equacao");
    // }
    // else if(qtd == 1){
    //     printf("As duas raizes sao iguais: %f %f\n",*x1,*x2);
    //     free(x1);
    //     free(x2);
    // }
    // else
    // printf("As duas raizes sao: %f %f\n",*x1,*x2);
    // free(x1);
    // free(x2);

    // // uso da funcao pares
    // int n = 0;
    // printf("Insira o numero de posicoes do vetor:\n");
    // scanf("%d",&n);
    // int vet[n];
    // for(int i = 0;i<n;i++){
    //     printf("Insira a nesima posicao do vetor\n",i+1);
    //     scanf("%d",&vet[i]);
    // }
    // int nPares = pares(n,vet);
    // printf("Numero de pares: %d\n",nPares);

    // // uso da funcao inverte
    // int vet[5] = {1,2,3,4,5};

    // inverte(5,vet);

    // for(int i = 0;i<5;i++){
    //     printf("%d ",vet[i]);
    // }

    int grau = 0;

    printf("insira o grau do polinomio: ");
    scanf("%d",&grau);
    double poli[grau+1];
    double x = 0.0;
    printf("insira o valor de x: ");
    scanf("%lf",&x);
    printf("insira os coeficientes: ");
    for(int i = 0; i < (grau+1);i++){
        scanf("%lf", &poli[i]);
    }
    double resultado = 0.0;
    resultado = avalia(poli,grau,x);
    printf("%.2lf\n",resultado);
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

int pares (int n, int* vet){
    int nPares = 0;

    for(int i = 0;i<n;i++){
        if(vet[i]%2==0){
            nPares++;
        }
    }
    return nPares;
}

void inverte (int n, int* vet){

    int aux = 0;

    for(int i = 0;i<n/2;i++){
        aux = vet[n-i-1];
        printf("aux: %d\n",aux);
        vet[n-i-1] = vet[i];
        printf("vet[n-i]: %d\n",vet[n-i-1]);
        vet[i] = aux;
        printf("vet[i]: %d\n",vet[i]);
    }
}

double avalia (double* poli, int grau, double x){
    double result = 0.0;

    for(int i = 0;i<(grau+1);i++){
        result += pow(x,grau - i)*poli[i];
    }
    return result;
}