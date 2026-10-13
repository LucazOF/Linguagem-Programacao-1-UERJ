#include "aula.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int menu(){
    int opcao;
    printf("=================\n");
    printf("     BIBLIOTECA     \n");
    printf("=================\n\n");
    printf("1 - Cadastrar livro\n");
    printf("2 - Alterar Status\n");
    printf("3 - Exibir livro\n");
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
            inserir_lista(&inicio);
            break;
        case 2:
            Buscar_livro(&inicio);
            break;
        case 3:
            imprimir(inicio);
          break;
        case 0:
            printf("\nsaindo..");
            liberar(&inicio);
            break;
        }
    } while (escolha !=0);
    
}
