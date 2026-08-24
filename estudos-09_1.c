#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//USANDO FUNÇÕES EM C

float maior (float num1, float num2){
        num1 += num1 * 10;
        num2 += num2 * 10;
        if (num1 > num2)
                return num1;
        else
                return num2;
}


int main (){
        float n1 , n2, m;

        printf("Qual é o 1° numero ? ");
        scanf("%f",&n1);
        printf("Qual é o 2° numero ? ");
        scanf("%f",&n2);

        m = maior(n1,n2);
        printf("Maior: %.2f\n",m);
}