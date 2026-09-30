#include <stdio.h>
#include "lista.h"


int main(){
    No *inicio = NULL;

    int opcao;
    do{
        printf("Digite a opcao desejada: ");
        scanf("%d", &opcao);
        getchar();
        switch(opcao){
            case 1:
            inserir_lista(&inicio);
            break;

            case 2:
            imprimir_lista(inicio);
            break;

            case 0:
            break;
        }
    }while(opcao != 0);
        
}