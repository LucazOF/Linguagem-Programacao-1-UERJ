#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Estruturas
typedef struct{
    int matricula;
    char nome [100];
    float nota1,nota2,media;
} Alunos;
//
int buscarAluno(Alunos *aluno,int totalalunos,int mat){
    for (int i = 0; i < totalalunos; i++){
        if (aluno[i].matricula == mat){
            return i;
        }
    }
    return -1;
}
float calcularmedia(float n1,float n2){
    return (n1+n2)/2;
}
void CadastrarAluno(Alunos *aluno,int *totalalunos){
    int mat_b;
    float n1 , n2;
    printf("\nCADASTRO ALUNO INICIADO.\n");
    int encontrado = 0;
    while (!encontrado){
        printf("\nDIGITE A MATRICULA DO ALUNO A SER CADASTRADO: ");
        scanf("%i",&mat_b);
        if (buscarAluno(aluno,*totalalunos,mat_b)==-1)
        {
            encontrado = 1;
        }else{
            printf("\nERRO! MATRICULA: %i JA CADASTRADA, TENTE NOVAMENTE.\n",mat_b);
        }
    }
    aluno[*totalalunos].matricula = mat_b;
    printf("\nDIGITE O NOME DO ALUNO: ");
    getchar();
    fgets(aluno[*totalalunos].nome,sizeof(aluno[*totalalunos].nome),stdin);
    aluno[*totalalunos].nome[strcspn(aluno[*totalalunos].nome, "\n")] = '\0';
    do{
        printf("\nDIGITE A 1° NOTA: ");
        scanf("%f",&n1);
        if(n1 < 0 || n1 > 10){
            printf("\nValor invalido");
        }   
    }while (n1 < 0 || n1 > 10);
    do{
        printf("\nDIGITE A 2° NOTA: ");
        scanf("%f",&n2);
         if(n2 < 0 || n2 > 10){
            printf("\nValor invalido");
        }   
    }while (n2 < 0 || n2 > 10);
    aluno[*totalalunos].nota1 = n1;
    aluno[*totalalunos].nota2 = n2;
    (*totalalunos)++;
    printf("\nCadastro Realizado com Sucesso.");
}
void BuscarAluno_void(Alunos *alunos, int total){
    if (total ==0)
    {
        printf("\nNão tem alunos cadastrados.");
        return;
    }
    int mat_b;
    int indice;
    printf ("\nDIGITE A MATRICULA DO ALUNO: ");
    scanf("%i",&mat_b);
    indice = buscarAluno(alunos,total,mat_b);
    if(indice == -1){
        printf("Aluno não encontrado");
    return;
    printf("\nMATRICULA %i | Nome %s | 1° NOTA %.2f| 2° NOTA %.2f | MEDIA %.2f",alunos[indice].matricula,alunos[indice].nome,alunos[indice].nota1,alunos[indice].nota2);
    printf("MEDIA: %.2f",calcularmedia(alunos[indice].nota1,alunos[indice].nota2));

}
void ExibirAlunos(Alunos *alunos, int total){
    if (total ==0)
    {
        printf("\nNão tem alunos cadastrados.");
        return;
    }
    printf("\nLISTA ALUNOS\n");

    for (int i = 0; i < total; i++)
    {
    float media = calcularmedia(alunos[i].nota1,alunos[i].nota2);
    printf("\nMATRICULA %i | Nome %s | 1° NOTA %.2f| 2° NOTA %.2f | ",alunos[i].matricula,alunos[i].nome,alunos[i].nota1,alunos[i].nota2);
    //printf("MEDIA: %.2f",calcularmedia(alunos[i].nota1,alunos[i].nota2));
    if (media >= 7)
    {
        printf("MEDIA: %.2f | SITUCAO: APROVADO",calcularmedia(alunos[i].nota1,alunos[i].nota2));
    }else if (media >= 4)
    {
       printf("MEDIA: %.2f | SITUCAO: RECUPERACAO",calcularmedia(alunos[i].nota1,alunos[i].nota2));
    }else
    {
        printf("MEDIA: %.2f | SITUCAO: REPROVADO",calcularmedia(alunos[i].nota1,alunos[i].nota2));
    }
    
    
    
    }
    
}
//MENU
int menu(){
    int opcao;
    printf("\n ---MENU SISTEMA--- \n");
    printf("\n1- Registrar Alunos");
    printf("\n2- Buscar Aluno");
    printf("\n3- Exibir Nota e Media dos Alunos");
    printf("\n0- Sair");
    printf("\nDigite a opção: ");
    scanf("%i",&opcao);
    return opcao;

}

int main(){
    int totalalunos = 0 ,escolha;
    Alunos aluno[100];
    do{
        escolha = menu();
        switch (escolha){
            case 1:
                CadastrarAluno(aluno,&totalalunos);
            break;
            case 2:
                BuscarAluno_void(aluno,totalalunos);
            break;
            case 3:
                ExibirAlunos(aluno,totalalunos);
            break;
            case 0:
                printf("\nSaindo do programa...");
            break;
            default:
                printf("\n Valor insirido invalido.");
            break;
        }
    }while(escolha!=0);
}