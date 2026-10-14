#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 50
//Programa para cadastrar pessoas usando o struct 
struct tipo_pessoa
   {
     int idade;
     float peso;
     char nome[TAM];
   };
typedef struct tipo_pessoa tipo_pessoa;

int main(){
    int n =0 ;
    printf("Quantas pessoas você quer registrar ?");
    scanf("%i",&n);
    tipo_pessoa pes[n];
    for (int i = 0; i < n; i++)
    {
        printf("Registre a Pessoa: \n");
        printf("idade: \n");
        scanf("%i",&pes[i].idade);
        printf("peso: \n");
        scanf("%f",&pes[i].peso);
        getchar();//limpar enter
        printf("Nome: ");
        fgets(pes[i].nome, TAM, stdin); //registrar string sempre assim
    // remover \n do fgets
        pes[i].nome[strcspn(pes[i].nome, "\n")] = '\0';
    }
    printf("\nPessoas Cadastradas no Sitema\n");

    for (int i = 0; i < n; i++)
    {
        printf("\n");
        printf("pes.idade: %d \n",pes[i].idade);
        printf("pes.peso: %.2f \n",pes[i].peso);
        printf("pes.nome: %s \n",pes[i].nome);    
        printf("\n");
    }
    
    

}