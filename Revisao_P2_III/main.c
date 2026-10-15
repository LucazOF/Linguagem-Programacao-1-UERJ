#include "funcao.h"
#include <stdio.h>

int menu(){
    int opcao;
    printf("=================\n");
    printf("     ESTACIONAMENTO     \n");
    printf("=================\n\n");
    printf("1 - Cadastrar Veiculo\n");
    printf("2 - Alterar Status\n");
    printf("3 - Exibir Veiculo\n");
    printf("4 - Excluir Veiculo\n");
    printf("0 - Sair\n");
    printf("Opcao: ");
    scanf("%d",&opcao);
    return opcao;
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
            insert(&inicio);
            break;
        case 2:
            atualizarstatus(&inicio);
            break;
        case 3:
            imprimir(inicio);
          break;
        case 4:
            excluir(&inicio);
        break;
        case 0:
            printf("\nsaindo..");
            liberar(&inicio);
            break;
        }
    } while (escolha !=0);
    
}