//Faça um programa que some 4 numeros inteiros
#include <stdio.h>
#include <stdlib.h>

float soma (float number[] ,int n ){
    float m =0;
    for (int i = 0; i < n; i++)
    {
        m += number[i];
    }
    return m;
}
int main(){
    int n;
    float somas;
    printf("Quantos numeros você quer somar ? ");
    scanf("%i",&n);
    float numeros[n];
    for (int i=0;i<n;i++){
        printf("Qual é o %i°: ",i+1);
        scanf("%f",&numeros[i]);
    }
    
    somas = soma(numeros,n);
    printf("A soma de todos os numeros é: %.2f \n",somas);
}