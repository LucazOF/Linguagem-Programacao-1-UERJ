#include "aula.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void inserir_lista(No **lista){
    int id;
    No *nova = malloc(sizeof(No));
    if (nova == NULL){
                printf("\n ERRO NA ALOCAÇÂO DE MEMORIA.");
                return;
            }
    getchar();
    printf("\nTitulo: ");
    fgets(nova->titulo,sizeof(nova->titulo),stdin);
    nova->titulo[strcspn(nova->titulo, "\n")] = '\0';
    do{
        printf("\nID: ");
        scanf("%d", &id);
        if(search(*lista,id)!= NULL){
            printf("\nERRO: ID JA EXISTE.");
        }
    }while(search(*lista,id)!= NULL);
    nova->id = id;
    nova->estado = DISPONIVEL;
    nova->proximo = *lista;
    *lista = nova;
    printf("LIVRO ADICIONADO COM SUCESSO.");
}

No *search(No *inicio, int id){
    No *atual = inicio;
    while (atual != NULL)
    {
        if (atual->id == id)
        {
            return atual;
        }
        atual = atual->proximo;
    }
    return NULL;
}
void Buscar_livro(No **inicio){
    if(inicio == NULL){
        printf("\nERRO | Não há livros cadastrados.\n");
        return;
    }
    int id;
    No *encontrado = NULL;
    printf("\n======================");
    printf("\nALTERAR STATUS INCIADO");
    printf("\n======================");
    do{
        printf("\nDigite o ID do livro que você deseja alterar o status: ");
        scanf("%d",&id);
        encontrado = search(*inicio,id);
        if(encontrado == NULL){
            printf("\nERRO | Livro não encontrado tente novamente.");
        }
    }while(encontrado == NULL);
    int opcao;
    printf("\nO que alterar no livro?\n");
    printf("1 ---- RETIRAR ----\n");
    printf("2 ---- RESERVAR ----\n");
    printf("3 ---- CANCELAR RESERVA ----\n");
    printf("4 ---- DEVOLVER ---- \n");
    scanf("%d", &opcao);
    EventoLivro evento;
    switch(opcao){
        case 1:
            evento = RETIRAR;
            break;
        case 2:
            evento = RESERVAR;
            break;
        case 3:
            evento = CANCELAR_RESERVA;
            break;
        case 4:
            evento = DEVOLVER;
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
        printf("\nERRO | O LIVRO ESTA APTO A ESSA MUDANÇA\n");
        return;
    }
}

int processar_evento(No *encontrado,EventoLivro evento){
    switch(evento){
        case RETIRAR:
            if(encontrado->estado == RESERVADO){
                encontrado->estado = EMPRESTADO;
                return 1;
            }else{
                return 0;
            }
            break;
        case RESERVAR:
            if(encontrado->estado == DISPONIVEL){
                encontrado->estado = RESERVADO;
                return 1;
            }else{
                return 0;
            }
            break;
        case CANCELAR_RESERVA:
            if(encontrado->estado == RESERVADO){
                    encontrado->estado = DISPONIVEL;
                    return 1;
                }else{
                    return 0;
                }
                break;
        case DEVOLVER:
            if(encontrado->estado == EMPRESTADO){
                    encontrado->estado = DISPONIVEL;
                    return 1;
                }else{
                    return 0;
                }
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

void imprimir(const No *inicio){
    if(inicio == NULL){
        printf("\nERRO | Não a livros cadastrados.");
        return;
    }
    const No *atual = inicio;
    while(atual != NULL){
        printf("\nID:%d |Titulo %s",atual->id,atual->titulo);
        switch(atual->estado){
            case DISPONIVEL:
                printf("| STATUS: DISPONIVEL\n");
            break;
            case RESERVADO:
                printf("| STATUS: RESERVADO\n");
            break;
            case EMPRESTADO:
                printf("| STATUS: EMPRESTADO\n");
            break;
        }
        atual = atual ->proximo;
    }
    
}