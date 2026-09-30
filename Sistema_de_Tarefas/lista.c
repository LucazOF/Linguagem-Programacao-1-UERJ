#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include <string.h>

void cadastro(No **inicio){
    int id;
    No *novo = malloc(sizeof(No));
    if (novo == NULL)
    {
        printf("\nERRO | ALOCAÇÃO DE MEMORIA FALHOU!");
        return;
    }
    printf("\n=================");
    printf("\nCADASTRO INICIADO");
    printf("\n=================");
    while (1)
    {
        printf("\nDIGITE O ID A SER CADASTRADO: ");
        scanf("%d",&id);
        if (search(*inicio,id)==NULL)
        {

            break;
        }else{
            printf("\nERRO | ID: %d JÁ CADASTRADO ");
        }
        
    }
    novo->id = id;
    getchar();
    printf("\nDIGITE A DESCRIÇÃO DA TAREFA: ");
    fgets(novo->descricao,sizeof(novo->descricao),stdin);
    novo->descricao[strcspn(novo->descricao,"\n")] = '\0';
    printf("\nDIGITE 1 - PARA TAREFA CONCLUIDA E 0 PARA NÃO CONCLUIDA");
    scanf("%d",&novo->concluido);
    novo->prox = *inicio;
    *inicio = novo;
    printf("\nTAREFA CADASTRADA NO SISTEMA");
}
No *search(const No **inicio,const int id){
    No *atual = *inicio;
    while (atual != NULL)
    {
        if (atual->id == id)
        {
            return atual;
        }
        
        atual = atual->prox;
    }
    return NULL;
}