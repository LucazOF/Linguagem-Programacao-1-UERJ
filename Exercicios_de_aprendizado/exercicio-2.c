#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Criando o aluno
#define TAM 80
struct a_alunos
   {
     char nome[TAM];
     float n1 , n2 , n3, media;
   };
typedef struct a_alunos a_alunos;

float mediaNotas (a_alunos * aluno_atual){ // ele ja está recebendo o aluno i então so preciso calcular a media e registrar na memoria e não usar for novamente.
    //para acessar a memoria precisa usar '->'
    float m = (aluno_atual -> n1 + aluno_atual->n2 + aluno_atual->n3) / 3;
    return m;

}

void mostraMelhorNota(a_alunos*aluno_atual, int total){ //acessar o aluno na memoria a_alunos*aluno_atual
    int indicemelhor = 0;
    for (int i = 0; i < total; i++)
    {
        if (aluno_atual[i].media >aluno_atual[indicemelhor].media){
            indicemelhor=i;
        }
    }
    printf("O melhor aluno foi %s com media %.2f\n",aluno_atual[indicemelhor].nome, aluno_atual[indicemelhor].media);

}
void MostrarPiorNota(a_alunos*atual, int total){
    int indicepior = 0;
    for (int i = 0; i < total; i++)
    {
        if (atual[i].media < atual[indicepior].media){
            indicepior=i;
        }
    }
    printf("O pior aluno foi %s com media %.2f\n",atual[indicepior].nome, atual[indicepior].media);


}
int main(){
    int n =0 ;
    printf("Quantas Alunos você quer registrar ?");
    scanf("%i",&n);
    getchar();
    a_alunos alun[n]; //criando varios alunos
    for (int i = 0; i < n; i++)
    {
        
        printf("Registre o %i Aluno: \n",i+1);
        printf("Nome do aluno: ");
        fgets(alun[i].nome, TAM, stdin);
        alun[i].nome[strcspn(alun[i].nome, "\n")] = '\0';

        do{
            printf("Nota da 1° prova: \n");
            scanf("%f",&alun[i].n1);
            if (alun[i].n1 > 10 || alun[i].n1 < 0){
                printf("Insira uma nota valida , valor 0 a 10\n");
            }
        }while (alun[i].n1 > 10 || alun[i].n1 < 0);
        do{
            printf("Nota da 2° prova: \n");
            scanf("%f",&alun[i].n2);
            if (alun[i].n2 >10 || alun[i].n2 <0){
                printf("Insira uma nota valida , valor 0 a 10\n");
            }
        }while (alun[i].n2 > 10 || alun[i].n2 < 0);
        do
        {
            printf("Nota da 3° prova: \n");
            scanf("%f",&alun[i].n3);
            if (alun[i].n3 >10 || alun[i].n3 < 0){
                printf("Insira uma nota valida , valor 0 a 10\n");
            }

        } while (alun[i].n3 >10 || alun[i].n3 < 0);
        getchar();
    }
    for (int i = 0; i < n; i++)
    {
        alun[i].media = mediaNotas(&alun[i]);
    }
    
    for (int i = 0; i < n; i++)
    {
        printf("Aluno: %s\n",alun[i].nome);  
        printf("Media: %.2f\n",alun[i].media);
        if (alun[i].media >= 7)
        {
            printf("Situação do aluno: Aprovado\n");
        }
        else if (alun[i].media < 7 && alun[i].media >= 5)
        {
            printf("Situação do aluno: Recuperação\n");
        }
        else{
            printf("Situação do aluno: Reprovado\n");
        }
        
        printf("----------------\n");

    }
    mostraMelhorNota(alun, n);
    MostrarPiorNota(alun, n);
}


