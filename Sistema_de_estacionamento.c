#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Carro{
    char placa [8];
    float hora;
    struct Carro *proximo;
}Carro;
typedef struct 
{
    Carro *inicio;
}Lista;

// Inicialização
int len (const Lista *lista);
void insertCarro(Lista *lista);
void adicionartempo(Lista *lista);
Carro *buscar(const Lista *lista, char placa[]);
void RegistrarSaida(Lista *lista);
void imprimir(const Lista *lista);

//FUNÇÕES
int len (const Lista *lista){

    int quantidade= 0;
    Carro *atual = lista->inicio;
    while (atual != NULL)
    {
        quantidade++;
        atual = atual->proximo;
    }
    return quantidade;
}

void insertCarro(Lista *lista){
    char placa[8];
    char escolha;
    float hora = 0;
    printf("\n=================");
    printf("\nREGISTRAR ENTRADA");
    printf("\n=================");
    Carro *nova = NULL;
    while (1)
    {
        printf("\nDIGITE A PLACA DO CARRO.");
        fgets(placa,sizeof(placa),stdin);
        placa[strcspn(placa, "\n")] = '\0';
        Carro *encontrado = buscar(lista,placa);
        if (encontrado ==NULL)
        {
            nova = malloc(sizeof(Carro));        
            if (nova == NULL){
                printf("\nERRO NA ALOCAÇÃO DE MEMORIA");
                return;
                }
            strcpy(nova->placa, placa);
            nova->proximo = NULL;     
            break;
        }else{
            printf("\n PLACA JÁ CADASTRADA");
            printf("\n DESEJA ADICIONAR MAIS HORAS ? Y/N");
            scanf(" %c", &escolha);
             if (escolha == 's' || escolha == 'S') {
                printf("\nDIGITE QUANTAS HORAS DESEJADA: ");
                scanf("%f",&hora);
                encontrado->hora = encontrado->hora+hora;
                return;
            } else if (escolha == 'n' || escolha == 'N') {
            printf("VOLTANDO PRO MENU.\n");
            return;
            }else {
            printf("Opcao invalida.\n");
            }
        }
    }
    printf("\nDIGITE QUANTAS HORAS DESEJADA: ");
    scanf("%f",&nova->hora);
    if (lista->inicio == NULL) {
        lista->inicio = nova;
    } else {
        Carro *atual = lista->inicio;
        while (atual->proximo != NULL) {
            atual = atual->proximo;
        }
        atual->proximo = nova;
    }
    printf("\nCARRO ADICIONADO COM SUCESSO.\n");
}
Carro *buscar(const Lista *lista, char placa[]){
        Carro *atual = lista->inicio;
        while (atual !=NULL)
        {
            if (strcmp(atual->placa,placa)==0)
            {
                return atual;
            }
            atual = atual->proximo;
        }
        return NULL;
        
   }
void adicionartempo(Lista *lista){
    char placa[8];
    float hora;
    if (lista->inicio == NULL){
        printf("\n ERRO: NÃO HÁ CARROS NO SISTEMA.");
        return;
    }
    printf("\n=========================");
    printf("\nAdicionar tempo iniciado.");
    printf("\n=========================");
    printf("\n DIGITE A PLACA DO CARRO.");
    fgets(placa,sizeof(placa),stdin);
    placa[strcspn(placa, "\n")] = '\0';
    Carro *encontrado = buscar(lista,placa);
    if (encontrado == NULL)
    {
        printf("\nCARRO NÂO ENCONTRADO.");
        return;
    }
    printf("\nQuantas Horas o Carro está");
    scanf("%f",&hora);
    encontrado->hora = encontrado->hora + hora;
    printf("\nHoras adicionadas com sucesso.");
}
void RegistrarSaida(Lista *lista){
    if (lista->inicio == NULL)
    {
        printf("\nERRO:Não usuarios cadastrados.");
        return;
    }
    char placa [8];
    printf("\n================");
    printf("\nREGISTRAR SAIDA.");
    printf("\n================");
    printf("\nQUANTAS HORAS O CARRO ESTÁ NO ESTACIONAMENTO.");
    fgets(placa,sizeof(placa),stdin);
    placa[strcspn(placa, "\n")] = '\0';
    Carro *atual = lista->inicio;
    Carro *anterior = NULL;
    while (atual !=NULL && strcmp(atual->placa,placa)!=0)
    {
        anterior = atual;
        atual= atual->proximo;
    }
    if (atual == NULL) {
        printf("\nErro: PLACA: %s não encontrada.\n", placa);
        return;
    }
    if (anterior == NULL)
    {
        lista->inicio = atual->proximo;
    }else{
        anterior ->proximo = atual->proximo;
    }
    printf("\nVeículo: %s Tempo: %.2f horas Valor: R$ %.2f", atual->placa,atual->hora,atual->hora*8);
    free (atual);
    printf("\n Veiculo Excluido com sucesso.");
}
void liberarEstacionamento(Lista *lista) {
    Carro *atual = lista->inicio;
    Carro *proximo;

    while (atual != NULL) {
        proximo = atual->proximo; 
        free(atual);              
        atual = proximo;          
    }
    
    lista->inicio = NULL;
}
void imprimir(const Lista *lista){
    if (lista->inicio == NULL)
    {
        printf("\nERRO:Não há carros cadastrados");
        return;
    }
    Carro *atual = lista->inicio;
    printf ("\n========================");
    printf("\nCARROS NO ESTACIONAMENTO:%i",len(lista));
    printf ("\n==========================");
    while (atual != NULL)
    {
        printf("\nPLACA: %s Hora: %.2f",atual->placa,atual->hora);
        atual = atual->proximo;
    }
    
}
//MENUS

int menu (){
    int opcao;
    printf("\n======================");
    printf("\nSISTEMA ESTACIONAMENTO");
    printf("\n======================");
    printf("\n1 - Registrar entrada\n2 - Adicionar tempo\n3 - Registrar saída\n4 - Mostrar estacionamento\n0 - Encerrar");
    printf("\nDIGITE A OPÇÃO: ");
    if (scanf("%i", &opcao) != 1) {
        opcao = -1;
    }
    getchar();
    return opcao;
}
int main(){
    int escolha;
    Lista lista;
    lista.inicio = NULL;
    do
    {   
        escolha = menu();
        switch (escolha)
        {
        case 1:
            insertCarro(&lista);
            break;
        case 2:
            adicionartempo(&lista);
        break;
        case 3:
            RegistrarSaida(&lista);
        break;
        case 4:
            imprimir(&lista);
            break;
        case 0:
            liberarEstacionamento(&lista);
            printf("\nSaindo...");
        break;
        default:
            break;
        }
    } while (escolha != 0);
    
}