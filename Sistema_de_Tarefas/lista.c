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
            printf("\nERRO | ID: %d JÁ CADASTRADO ",id);
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
    return;
}
void cadastro(No **inicio){
    int id;
    No *novo = malloc(sizeof(No));
    if (novo == NULL)
    {
        printf("\nERRO | ALOCAÇÃO DE MEMORIA FALHOU!");
        return;
    }
    printf("\n=================");
    printf("\nCADASTRO FINAL");
    printf("\n=================");
    while (1)
    {
        printf("\nDIGITE O ID A SER CADASTRADO: ");
        scanf("%d",&id);
        if (search(*inicio,id)==NULL)
        {

            break;
        }else{
            printf("\nERRO | ID: %d JÁ CADASTRADO ",id);
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
    return;
}
void cadastronofinal(No **inicio){
    int id;
    No *novo = malloc(sizeof(No));
    if (novo == NULL)
    {
        printf("\nERRO | ALOCAÇÃO DE MEMORIA FALHOU!");
        return;
    }
    printf("\n=================");
    printf("\nCADASTRO FINAL");
    printf("\n=================");
    while (1)
    {
        printf("\nDIGITE O ID A SER CADASTRADO: ");
        scanf("%d",&id);
        if (search(*inicio,id)==NULL)
        {

            break;
        }else{
            printf("\nERRO | ID: %d JÁ CADASTRADO ",id);
        }
        
    }
    novo->id = id;
    getchar();
    printf("\nDIGITE A DESCRIÇÃO DA TAREFA: ");
    fgets(novo->descricao,sizeof(novo->descricao),stdin);
    novo->descricao[strcspn(novo->descricao,"\n")] = '\0';
    printf("\nDIGITE 1 - PARA TAREFA CONCLUIDA E 0 PARA NÃO CONCLUIDA");
    scanf("%d",&novo->concluido);
    if (*inicio ==NULL){
        *inicio = novo;
    }else{
        No *atual = *inicio;
        while (atual != NULL)
        {

            atual = atual->prox;
        }
        atual->prox = novo;
        novo->prox = NULL;
    }

    printf("\nTAREFA CADASTRADA NO SISTEMA");
    return;
}
No *search(No *inicio, int id){
    No *atual = inicio;
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
void BuscarTarefa( No **inicio){
    if (*inicio == NULL){
        printf("\nNÃO HÁ TAREFAS CADASTRADAS.");
        return;
    }
    int id;
    No *encontrado = NULL;
    do
    {
        printf("\nDIGITE O ID DA TAREFA: ");
        scanf("%d",&id);
        encontrado = search(*inicio,id);
        if (encontrado == NULL)
        {
            printf("\nERRO| N HA NINGUEM COM ESSE ID:%d.",id);
        }
    } while (encontrado == NULL);
    printf("\nTAREFA ENCONTRADA!");
    printf("\n---------------");
    printf("\nID: %d | Descrição: %s | Status",encontrado->id,encontrado->descricao);
    if (encontrado->concluido == 1)
    {
        printf("[X]");
    }else if (encontrado->concluido == 0)
    {
        printf("[ ]");
    }
    printf("\n---------------");
    return;
}
void imprimir(No **inicio){
    if (*inicio == NULL){
        printf("\nNÃO HÁ TAREFAS CADASTRADAS.");
        return;
    }
    No *atual = *inicio;
    printf("\n================");
    printf("\n LISTA TAREFAS  ");
    printf("\n================");
    while (atual != NULL)
    {
    printf("\nID: %d | Descrição: %s | Status",atual->id,atual->descricao);
        if (atual->concluido == 1)
        {
            printf("[X]");
        }else if (atual->concluido == 0)
        {
            printf("[ ]");
        }
        atual = atual->prox;
    }
    printf("\n================");
}

void concluirtask(No **inicio){
    if (*inicio == NULL){
        printf("\nNÃO HÁ TAREFAS CADASTRADAS.");
        return;
    }
    int id;
    printf("\n================");
    printf("\n CONCLUIR TAREFA");
    printf("\n================");
    No *encontrado = NULL;
    do
    {
        printf("\nDIGITE O ID DA TAREFA: ");
        scanf("%d",&id);
        encontrado = search(*inicio,id);
        if (encontrado == NULL)
        {
            printf("\nERRO| N HA NINGUEM COM ESSE ID %d.",id);
        }
    } while (encontrado == NULL);
    encontrado->concluido = 1;
    printf("\nTAREFA MARCADA COMO CONCLUIDA.");
    printf("\n-----------------\n");
    return;
}
void Excluir(No **inicio){
    if (*inicio == NULL){
        printf("\nNÃO HÁ TAREFAS CADASTRADAS.");
        return;
    }
    int id;
    printf("\n================");
    printf("\n EXCLUIR TAREFA");
    printf("\n================");
    No *encontrado = NULL;
    do
    {
        printf("\nDIGITE O ID DA TAREFA: ");
        scanf("%d",&id);
        encontrado = search(*inicio,id);
        if (encontrado == NULL)
        {
            printf("\nERRO| N HA NINGUEM COM ESSE ID %d.",id);
        }
    } while (encontrado == NULL);
    No *atual = *inicio;
    No *anterior = NULL;
    while (atual!= NULL || atual->id!=id)
        {
            anterior = atual;
            atual=atual->prox;
        }
        if(atual == NULL){
            printf("\nLIVRO NAO ENCONTRADO.");
            return;
        }
        if (anterior == NULL){
            *inicio=atual->prox;
        }else{
            anterior->prox=atual->prox;
        }
        free(atual);
        printf("\nTAREFA EXCLUIDA COM SUCESSO.");
}

void liberar(No **inicio){
    No *atual = *inicio;
    No *proximo;
    while (atual!=NULL)
    {
        proximo = atual->prox;
        free(atual);
        atual = proximo;
    }
    *inicio=NULL;
}