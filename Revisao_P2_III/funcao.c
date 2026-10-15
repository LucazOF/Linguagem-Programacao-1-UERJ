#include "funcao.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void insert(No **inicio){
    No *novo = malloc(sizeof(No));
    if (novo == NULL){
        printf("\n ERRO NA ALOCAÇÂO DE MEMORIA.");
        return;
    }
    printf("\n==============");
    printf("\nREGISTRAR VEICULO");
    printf("\n==============");
    int id;
    do{
        printf("\nDIGITE O ID DO CARRO: ");
        scanf("%d",&id);
        if(search(*inicio,id)!=NULL){
            printf("\nERRO | JA EXISTE CARRP COM ESSE NUMERO");
        }
    }while(search(*inicio,id)!=NULL);
    novo->id = id;
    getchar();
    printf("\nPLACA DO VEICULO: ");
    fgets(novo
        ->placa,sizeof(novo->placa),stdin);
    novo->placa[strcspn(novo->placa, "\n")] = '\0';
    novo->status = AGUARDANDO;
    novo->proximo = *inicio;
    *inicio = novo;
    printf("\nCARRO REGISTRADO.");
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
void atualizarstatus(No **inicio){
    if(*inicio == NULL){
        printf("\nERRO | Não há Veiculos cadastrados.\n");
        return;
    }    
    int id;
    Evento evento;
    printf("\n==============");
    printf("\nMUDAR STAUS VEICULO");
    printf("\n==============");
    No *encontrado = NULL;
    do{
        printf("\nDIGITE O NUMERO DE IDENTIFICACAO DO VEICULO: ");
        scanf("%d",&id);
        encontrado = search(*inicio,id);
        if(encontrado == NULL){
            printf("\nERRO | NAO EXISTE VEICULO COM ESSE NUMERO %d",id);
        }
    }while(encontrado == NULL);
    int opcao;
    printf("\nALTERAR STATUS DO VEICULO\n");
    printf("1 ---- ENTRAR ----\n");
    printf("2 ---- PAGAR ----\n");
    printf("3 ---- SAIR ----\n");
    scanf("%d", &opcao);
    switch(opcao){
        case 1:
            evento = ENTRAR;
            break;
        case 2:
            evento = PAGAR;
            break;
        case 3:
            evento = SAIR;
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
        printf("\nERRO | O VEICULO NAO ESTA APTO A ESSA MUDANÇA\n");
        return;
    }
}
int processar_evento(No *encontrado,Evento evento){
    if(encontrado == NULL){
        return 0;
}  
switch(evento){
        case ENTRAR:
            if(encontrado->status == AGUARDANDO){
                encontrado->status = ESTACIONADO;
                return 1;
            }else{
                return 0;
            }
            break;
        case PAGAR:
            if(encontrado->status == ESTACIONADO){
                encontrado->status = PAGO;
                return 1;
            }else{
                return 0;
            }
            break;
        case SAIR:
            if(encontrado->status == PAGO){
                    encontrado->status = SAIU;
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
void excluir(No **inicio){
    if (*inicio == NULL){
        printf("\nNÃO HÁ VEICULOS CADASTRADAS.");
        return;
    }
    int id;
    printf("\n================");
    printf("\n EXCLUIR VEICULO");
    printf("\n================");
    No *encontrado = NULL;
    do
    {
        printf("\nDIGITE O NUMERO DE IDENTIFICACAO DO VEICULO: ");
        scanf("%d",&id);
        encontrado = search(*inicio,id);
        if (encontrado == NULL)
        {
            printf("\nERRO | NAO EXISTE VEICULO COM ESSE NUMERO %d",id);
        }
    } while (encontrado == NULL);
    No *atual = *inicio;
    No *anterior = NULL;
    while (atual!= NULL && atual->id!=id)
        {
            anterior = atual;
            atual=atual->proximo;
        }

        if(atual == NULL){
            printf("\nVEICULO NAO ENCONTRADO.");
            return;
        }
        if (atual->status != SAIU){
            printf("\nERRO | CARRO NÃO FOI SAIU AINDA.");
            return;
        }
        if (anterior == NULL){
            *inicio=atual->proximo;
        }else{
            anterior->proximo=atual->proximo;
        }
        free(atual);
        printf("\nVEICULO EXCLUIDO COM SUCESSO.");
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
    *inicio=NULL;
}
void imprimir(const No *inicio){
    if(inicio == NULL){
        printf("\nERRO | Não a Veiculos cadastrados no sistema.");
        return;
    }
    const No *atual = inicio;
    while(atual !=NULL){
    printf("\nN°:%d |PLACA %s",atual->id,atual->placa);
        switch(atual->status){
            case AGUARDANDO:
                printf("| STATUS: AGUARDANDO\n");
            break;
            case ESTACIONADO:
                printf("| STATUS: ESTACIONADO\n");
            break;
            case PAGO:
                printf("| STATUS: PAGO\n");
            break;
            case SAIU:
                printf("| STATUS: SAIU\n");
            break;
        }
    atual= atual->proximo;        
    }    
}