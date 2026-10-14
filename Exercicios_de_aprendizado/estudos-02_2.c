#include <stdio.h>
#include <stdlib.h>
//acabei fazendo a aula 3 se sacanagem.
int main(){
    int idade = 0;
    float altura = 0;
    char nome []= "";
    printf("Programa Idade incializado. Aperte qualquer tecla para continuar. \n");
    getchar();
    printf("Digite qual é seu nome:\n");
    scanf("%s", &nome);
    printf("Digite qual é sua idade:\n");
    scanf("%i",&idade);
    printf("Digite qual é sua altura:\n");
    scanf("%f",&altura);
    
    printf("Seu nome é %s \n sua idade é %i\n e sua altura é %.2f \n", nome ,idade, altura);
    return  0;
}