#include <stdio.h>
#include <stdlib.h>
#define texto "Entrada e saida de dados." //variavel goblal
 
int main(){
    int A , B ,soma, subtr , mult ;
    float divis;
    printf("Digite o 1° valor \n");
    scanf ("%i",&A);
    printf("Digite o 2° valor \n");
    scanf ("%i",&B);
    soma = A + B;
    subtr = A -B;
    mult = A * B;
    divis = A/B;

    printf("Resultados:\n");
    printf("soma:%i\n",soma);
    printf("sub:%i\n",subtr);
    printf("mult:%i\n",mult);
    printf("div:%.2f\n",divis);
}