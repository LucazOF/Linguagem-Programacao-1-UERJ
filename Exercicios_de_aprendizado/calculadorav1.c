#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int funcao;
    float x,resultado;
}calculo;
void um(calculo *calculo,int *total){
    printf("\nf(x) = x");
    printf("\nDigite um valor para X:");
    scanf("%f",&calculo[*total].x);
    calculo[*total].resultado = calculo[*total].x; 
    printf("\nf(%.2f) = %.2f", calculo[*total].x, calculo[*total].resultado);
    calculo[*total].funcao =1;
    (*total)++;
}
void dois(calculo *calculo,int *total){
    float x;
    printf("\nf(x) = x²");
    printf("\nDigite um valor para X:");
    scanf("%f",&x);
    calculo[*total].x = x;
    calculo[*total].resultado = x*x;
    printf("\nf(%.2f) = %.2f ", x , calculo[*total].resultado);
    calculo[*total].funcao = 2;
    (*total)++;
}
void tres(calculo *calculo,int *total){
    float x;
    printf("\nf(x) = x³");
    printf("\nDigite um valor para X:");
    scanf("%f",&x);
    calculo[*total].x = x;
    calculo[*total].resultado = x*x*x;
    printf("\nf(%.2f) = %.2f ", x , calculo[*total].resultado);
    calculo[*total].funcao = 3;
    (*total)++;
}
void quatro(calculo *calculo,int *total){
    float x;
    printf("\nf(x) = 2x + 5");
    printf("\nDigite um valor para X:");
    scanf("%f",&x);
    calculo[*total].resultado = 2*x+5;
    printf("\nf(%.2f) = %.2f ", x , calculo[*total].resultado);
    calculo[*total].funcao = 4;
    (*total)++;
}
void cinco(calculo *calculo,int *total){
    float x;
    printf("\nf(x) = 2x + 5");
    printf("\nDigite um valor para X:");
    scanf("%f",&x);
    calculo[*total].resultado = x*x +2*x+1;
    printf("\nf(%.2f) = %.2f ", x , calculo[*total].resultado);
    calculo[*total].funcao = 5;
    (*total)++;  
}
void exibir(calculo *calculo,int total){
    for (int i = 0; i < total; i++)
    {
        //if(calculo[i].funcao ==1 ){
        //    printf("\nFunção: f(x) = x");
        //    printf("\n Resultado: %.2f | Valor de X: %.2f ",calculo[i].resultado,calculo[i].x);
        //}else if (calculo[i].funcao ==1 )
        //{
            /* code */
        //}
        switch (calculo[i].funcao)
        {
        case 1:
            printf("\nFunção: f(x) = x");
            printf("\n Resultado: %.2f | Valor de X: %.2f ",calculo[i].resultado,calculo[i].x);
            break;
        case 2:
            printf("\nFunção: f(x) = x²");
            printf("\n Resultado: %.2f | Valor de X: %.2f ",calculo[i].resultado,calculo[i].x);
            break;
        case 3:
            printf("\nFunção: f(x) = x³");
            printf("\n Resultado: %.2f | Valor de X: %.2f ",calculo[i].resultado,calculo[i].x);
            break;
        case 4:
            printf("\nFunção: 2x + 5");
            printf("\n Resultado: %.2f | Valor de X: %.2f ",calculo[i].resultado,calculo[i].x);
            break;
        case 5:
            printf("\nFunção: f(x) = x² + 2x + 1");
            printf("\n Resultado: %.2f | Valor de X: %.2f ",calculo[i].resultado,calculo[i].x);
            break;
        }
    }
    
}
int menu(){
    int opcao;
    printf ("\n===== CALCULADORA===\n");
    printf("\n1- f(x) = x");
    printf("\n2 - f(x) = x²");
    printf("\n3 - f(x) = x³");
    printf("\n4 - f(x) = 2x + 5");
    printf("\n5 - f(x) = x² + 2x + 1");
    printf ("\n6- historico");
    scanf("%i",&opcao);
    return opcao;
}
int main (){
    calculo calculo[100];
    int opcao, total;
    do{
        opcao = menu();
        switch(opcao)
        {
            case 1:
                um(calculo,&total);
                break;
            case 2:
                dois(calculo,&total);
                break;
            case 3:
                tres(calculo,&total);
                break;
            case 4:
                quatro(calculo,&total);
                break;
            case 5:
                cinco(calculo,&total);
                break;
            case 6:
                exibir(calculo,total);
                break;
            case 0:
                printf("\nSaindo");
                break;
        }
    }while(opcao !=0);
}