#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//USANDO FUNÇÕES EM C


void imprimi1 (int v[],int n){
    int i;
    for ( i = 0; i < n; i++)
    {
        printf("%d | ",v[i]);
    }
}


void imprimi2 (int v[5]){
    int i;
    for ( i = 0; i < 5; i++)
    {
        printf("%d | ",v[i]);
    }
}

void imprimi3 (int *v,int n){
    int i;
    for ( i = 0; i < n; i++)
    {
        printf("%d | ",v[i]);
    }
}

int main(){
int t;
printf("Qual tamanho tera seu vetor ? \n");
scanf("%i",&t);
int vet[t];
for (int i = 0; i < t; i++)
{
    printf("Digite o registre o [%d] do vetor",i+1);
    scanf("%i",&vet[i]);
}
puts("\n1° imprimi: ");
imprimi1(vet,t);
printf("\n");
puts("\n2° imprimi: ");
imprimi2(vet);
printf("\n");
puts("\n3° imprimi: ");
imprimi3(vet,t);
printf("\n");
}
