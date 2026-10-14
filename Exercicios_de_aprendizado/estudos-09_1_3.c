#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float maior(float num1, float num2);

int main (){
        float n1 , n2, m;

        printf("Qual é o 1° numero ? ");
        scanf("%f",&n1);
        printf("Qual é o 2° numero ? ");
        scanf("%f",&n2);

        m = maior(n1,n2);
        printf("Maior: %.2f\n",m);
}

float maior (float num1, float num2){
        if (num1 > num2)
                return num1;
        else
                return num2;
}