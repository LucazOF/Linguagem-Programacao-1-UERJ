#include <stdio.h>
#include "lista.h"

int menu(){
    int opcao;
    printf("=================\n");
    printf("     TAREFAS     \n");
    printf("=================\n\n");
    printf("1 - Cadastrar tarefa\n");
    printf("2 - Listar tarefas\n");
    printf("3 - Buscar tarefa por ID\n");
    printf("4 - Concluir tarefa\n");
    printf("5 - Remover tarefa\n");
    printf("0 - Sair\n\n");
    printf("Opcao: ");
    scanf("%d",&opcao);
}
int main(){
    No *inicio = NULL;
    int escolha;
    do
    {
        escolha = menu();
        switch (escolha)
        {
        case 1:
            cadastro(&inicio);
            break;
        
        default:
            break;
        }
        /* code */
    } while (escolha !=0);
    
}