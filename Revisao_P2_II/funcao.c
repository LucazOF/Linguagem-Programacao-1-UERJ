#include "funcao.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void insert(No **inicio){
    int id;
    No *nova = malloc(sizeof(No));
    if (nova == NULL){
        printf("\n ERRO NA ALOCAÇÂO DE MEMORIA.");
        return;
    }
    printf("\n==============");
    printf("\nCRIAR CHAMADO");
    printf("\n==============");

    do{
        printf("\nDIGITE O NUMERO DO CHAMADO: ");
        scanf("%d",&id);
        if(search(*inicio,id)!=NULL){
            printf("\nERRO | JA EXISTE CHAMADO COM ESSE NUMERO");
        }
    }while(search(*inicio,id)!=NULL);
    nova->numero = id;
    getchar();
    printf("\nDescricao: ");
    fgets(nova->desc,sizeof(nova->desc),stdin);
    nova->desc[strcspn(nova->desc, "\n")] = '\0';
    nova->status = ABERTO;
    nova->proximo = *inicio;
    *inicio = nova;
}
No *search(No *inicio, int id){
    No *atual = inicio;
    while (atual != NULL)
    {
        if (atual->numero == id)
        {
            return atual;
        }
        atual = atual->proximo;
    }
    return NULL;
}
void atualizarstatus(No **inicio){
    if(*inicio == NULL){
        printf("\nERRO | Não há livros cadastrados.\n");
        return;
    }    
    int id;
    Evento evento;
    printf("\n==============");
    printf("\nATUALIZAR CHAMADO");
    printf("\n==============");
    No *encontrado = NULL;
    do{
        printf("\nDIGITE O NUMERO DO CHAMADO: ");
        scanf("%d",&id);
        encontrado = search(*inicio,id);
        if(encontrado == NULL){
            printf("\nERRO | NAO EXISTE CHAMADO COM ESSE NUMERO");
        }
    }while(encontrado == NULL);
    int opcao;
    printf("\nO que alterar no chamado?\n");
    printf("1 ---- INCIAR ----\n");
    printf("2 ---- CANCELAR ----\n");
    printf("3 ---- FINALIZAR ----\n");
    scanf("%d", &opcao);
    switch(opcao){
        case 1:
            evento = INICIAR;
            break;
        case 2:
            evento = CANCELAR;
            break;
        case 3:
            evento = FINALIZAR;
            break;
        default:
            printf("\nValor invalido.");
            return;
        break;
    }
    int resultado = processar_evento (encontrado,evento);
    if(resultado == 1){
        printf("\nALTERACAO FEITA COM SUCESSO.");
        return;
    }else{
        printf("\nERRO | O CHAMADO NAO ESTA APTO A ESSA MUDANÇA\n");
        return;
    }
}
int processar_evento(No *encontrado,Evento evento){
    if(encontrado == NULL){
        return 0;
}  
switch(evento){
        case INICIAR:
            if(encontrado->status == ABERTO){
                encontrado->status = EM_ATENDIMENTO;
                return 1;
            }else{
                return 0;
            }
            break;
        case CANCELAR:
            if(encontrado->status == ABERTO || encontrado->status == EM_ATENDIMENTO){
                encontrado->status = CANCELADO;
                return 1;
            }else{
                return 0;
            }
            break;
        case FINALIZAR:
            if(encontrado->status == EM_ATENDIMENTO){
                    encontrado->status = RESOLVIDO;
                    return 1;
                }else{
                    return 0;
                }
                break;
        default:
                return 0;
            break;
    }
}
void liberar(No **inicio){
    No *atual = *inicio;
    No *proximo;
    while (atual!=NULL)
    {
        proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
    *inicio= NULL;
}
void buscarchamado(No *inicio){
    if(inicio == NULL){
        printf("\nERRO | Não a chamados cadastrados no sistema.");
        return;
    }
    printf("\n======================");
    printf("\nBUSCAR CHAMADO");
    printf("\n======================");
    No *encontrado = NULL;
    int id;
    do{
        printf("\nDigite o ID do livro que você deseja alterar o status: ");
        scanf("%d",&id);
        encontrado = search(inicio,id);
        if(encontrado == NULL){
            printf("\nERRO | Livro não encontrado tente novamente.");
        }
    }while(encontrado == NULL);
    printf("\nN°:%d |Decrição %s",encontrado->numero,encontrado->desc);
        switch(encontrado->status){
            case ABERTO:
                printf("| STATUS: ABERTO\n");
            break;
            case EM_ATENDIMENTO:
                printf("| STATUS: EM ATENDIMENTO\n");
            break;
            case CANCELADO:
                printf("| STATUS: CANCELADO\n");
            break;
            case RESOLVIDO:
                printf("| STATUS: RESOLVIDO\n");
            break;
        }
}
void imprimir(const No *inicio){
    if(inicio == NULL){
        printf("\nERRO | Não a chamados cadastrados no sistema.");
        return;
    }
    const No *atual = inicio;
    while(atual !=NULL){
    printf("\nN°:%d |Decrição %s",atual->numero,atual->desc);
        switch(atual->status){
            case ABERTO:
                printf("| STATUS: ABERTO\n");
            break;
            case EM_ATENDIMENTO:
                printf("| STATUS: EM ATENDIMENTO\n");
            break;
            case CANCELADO:
                printf("| STATUS: CANCELADO\n");
            break;
            case RESOLVIDO:
                printf("| STATUS: RESOLVIDO\n");
            break;
        }
    atual= atual->proximo;        
    }    
}