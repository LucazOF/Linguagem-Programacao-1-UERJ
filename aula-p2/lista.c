#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void inserir_lista(No **lista){
    No *nova = malloc(sizeof(No));
    if (nova == NULL){
                printf("\n ERRO NA ALOCAÇÂO DE MEMORIA.");
                return;
            }
    printf("Nome: \n");
    fgets(nova->nome,sizeof(nova->nome),stdin);
    nova->nome[strcspn(nova->nome, "\n")] = '\0';
    printf("Quantidade: \n");
    scanf("%d", &nova -> quantidade);
    nova->proximo = *lista;
    *lista = nova;
    printf("PRODUTO ADICIONADA COM SUCESSO.");
}
void imprimir_lista(const No *lista){
    if(lista == NULL){
        printf("NAO TEM NGM\n");
        return ;
    }

    const No *atual = lista;


    while(atual != NULL){
        printf("Nome: %s\n", atual->nome);
        printf("Quantidade: %d\n", atual->quantidade);  
        atual = atual -> proximo;
    }

    return;
}
