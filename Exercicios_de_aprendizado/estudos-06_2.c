#include <stdio.h>
#include <stdlib.h>

//REGISTRO DE NOMES
int main(){
    int n = 0;
    printf("Quantas pessoas você quer registrar ?");
    scanf("%i",&n);
    char nomes[n][70]; //Aqui eu defino [n] qntd de nomes [n] qntd de caracteres
    for (int i = 0; i < n; i++)
    {
        printf("Registre o %i° nome: ",i+1);
        scanf(" %69[^\n]", nomes[i]); // Ele registra os 69 caraceteres pq o ultimo em C é /0 
        fflush(stdin);
        /* code */
    }
    printf("Lista de nomes\n");
    for (int i = 0; i < n; i++){
        printf("%i° %s\n",i+1,nomes[i]);
    }


}