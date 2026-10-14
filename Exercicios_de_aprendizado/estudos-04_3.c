#include <stdio.h>
#include <stdlib.h>

int main(){
    int d = 0;
    printf("Programa incializado. Aperte qualquer tecla para continuar.");
    getchar();
    printf("Qual dia da semana é hoje ? (insira valor de 1 a 7)");
    scanf("%i",&d);

    switch (d)
    {
    case 1:
        printf("Domingo\n");
        break;
    
    case 2:
        printf("Segunda-feira\n");
        break;
    
    case 3:
        printf("Terça-feira\n");
        break;
    case 4:
        printf("Quarta-feira\n");
        break;
    case 5:
        printf("Quinta-feira\n");
        break;
    case 6:
        printf("Sexta-feira\n");
        break;
    
    case 7:
        printf("Sabado\n");
        break;
    
    default:
        printf("valor invalidado\n");
        break;
    }
}