#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Livro
{
    int codigo;
    int status;
    char titulo[51];
    char autor[51];
    struct Livro *proximo;
}Livro;
typedef struct 
{
    Livro *inicio;
}Lista;
//PROTOTIPO
int len(const Lista *lista);
void insert(Lista *lista);
void changer_status(Livro *encontrado,int status);
Livro *buscar(const Lista *lista,int id);
void imprimir(const Lista *lista);
void status(Lista *lista);
void filter_livro(const Lista *lista);
void liberar(Lista *lista);
void ExcluirLivro(Lista *lista);
//FUNCOES
int len(const Lista *lista){
    int qntd=0;
    Livro *atual = lista->inicio;
    while (atual!=NULL)
    {
        qntd ++;
        atual = atual->proximo;
    }
    return qntd;
}
void insert(Lista *lista){
    int id;
    char escolha;
    int status;
    printf("\n=================");
    printf("\n REGISTRAR LIVRO ");
    printf("\n=================");
    Livro *novo = NULL;
    while (1)
    {
        printf("\nDigite o codigo do livro: ");
        scanf("%i",&id);
        Livro *encontrado = buscar(lista,id);
        if (encontrado==NULL)
        {
            novo = malloc(sizeof(Livro));
            if (novo == NULL)
            {
                printf("\nERRO NA ALOCACAO DE MEMORIA.");
                return;
            }
            novo->codigo = id;
            break;
        }else{
            printf("\nCODIGO %i JÁ CADASTRO REGISTRADO");
            printf("\nDESEJA ATUALIZAR O STATUS ?");
            printf("\n PLACA JÁ CADASTRADA");
            printf("\n DESEJA ADICIONAR MAIS HORAS ? Y/N");
            scanf(" %c", &escolha);
             if (escolha == 's' || escolha == 'S') {
                printf("\nDIGITE 1 PARA ATUALIZAR PRA EMPRETADO E 0 PARA DISPONIVEL");
                scanf("%i",&status);
                changer_status(encontrado,status);
                return;
            } else if (escolha == 'n' || escolha == 'N') {
            printf("VOLTANDO PRO MENU.\n");
            }
        }
        
    }
    getchar();
    printf("\nDIGITE O TITULO DO LIVRO");
    fgets(novo->titulo,sizeof(novo->titulo),stdin);
    novo->titulo[strcspn(novo->titulo, "\n")] = '\0';
    printf("\nDIGITE O AUTOR DO LIVRO");
    fgets(novo->autor,sizeof(novo->autor),stdin);
    novo->autor[strcspn(novo->autor, "\n")] = '\0';
    novo->status = 0;
    novo->proximo = lista->inicio;
    lista->inicio = novo;
    printf("\n LIVRO ADICIONADO A BIBLOTECA.");
    return;
}
void changer_status(Livro *encontrado,int status){
    if (status == 1)
    {
        encontrado->status = 1;
        printf("\n STATUS ATUALIZADO PARA DISPONIVEL");
    }else if (status == 0)
    {
        encontrado->status=0;
        printf("\n STATUS ATUALIZADO PARA EMPRESTADO");
    }else{
        printf("\nVALOR INVALIDO VOLTANDO AO MENU");
        return;
    }
}
Livro *buscar(const Lista *lista,int id){
    Livro *atual= lista->inicio;
    while (atual != NULL)
    {
        if (atual->codigo == id){
            return atual;
        }
        atual = atual->proximo;
    }
    return NULL;
}
void status(Lista *lista){
    int att;
   if (lista->inicio == NULL){
    printf("\nNÃO HÁ LIVROS CADASTRADOS NA BIBLOTECA.");
    return;
   }
   int id ;
   printf("\nDIGITE O CODIGO DO LIVRO QUE VOCÊ DESEJA ALTERAR: ");
   scanf("%i",&id);
   Livro *encontrado = buscar(lista,id);
   if (encontrado == NULL){
    printf("\n LIVRO NÃO ENCONTRADO.");
    return;
   }
    printf("\nDIGITE 1 PARA ATUALIZAR PRA EMPRETADO E 0 PARA DISPONIVEL");
    scanf("%i",&att);
    changer_status(encontrado,att);
}
void imprimir(const Lista *lista){
    if (lista->inicio == NULL){
    printf("\nNÃO HÁ LIVROS CADASTRADOS NA BIBLOTECA.");
    return;
    }
    printf("\n===============================================");
    printf("\nLIVROS CADASTRADOS NA BIBLIOTECA: %i",len(lista));
    printf("\n===============================================");
    Livro *atual = lista->inicio;
    while(atual != NULL){
        printf("\nID: %i TITULO: %s AUTOR %s",atual->codigo,atual->titulo,atual->autor);
        if (atual->status ==1)
        {
            printf("\nSTATUS: EMPRESTADO");
        }else if (atual->status == 0)
        {
            printf("\nSTATUS: DISPONIVEL");
        }
        atual = atual->proximo;
    }
}
void filter_livro(const Lista *lista) {
    int situacao;
    if (lista->inicio == NULL) {
        printf("\nNÃO HÁ LIVROS CADASTRADOS NA BIBLOTECA.\n");
        return;
    }

    printf("\nDIGITE 1 PARA FILTRAR OS EMPRESTADOS E 0 PARA OS DISPONIVEIS: ");
    scanf("%i", &situacao);

    if (situacao != 0 && situacao != 1) {
        printf("\nOPÇÃO INVALIDA!\n");
        return;
    }

    Livro *atual = lista->inicio;
    int encontrados = 0;

    while (atual != NULL) {
        if (atual->status == situacao) {
            printf("\nID: %i | TITULO: %s | AUTOR: %s", atual->codigo, atual->titulo, atual->autor);
            if (atual->status == 1) {
                printf("\nSTATUS: EMPRESTADO\n");
            } else {
                printf("\nSTATUS: DISPONIVEL\n");
            }
            encontrados++;
        }
        atual = atual->proximo; 
    }

    if (encontrados == 0) {
        printf("\nNENHUM LIVRO ENCONTRADO COM ESSE STATUS.\n");
    }
}
void liberar(Lista *lista){
    Livro *atual = lista->inicio;
    Livro *proximo;
    while (atual != NULL){
        proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
    lista->inicio = NULL;
}
void ExcluirLivro(Lista *lista){
        if (lista->inicio == NULL)
    {
        printf("\nERRO:Não usuarios cadastrados.");
        return;
    }
    int id;
    printf("\n==============================");
    printf("\nALERTA EXLCUIR LIVRO INICIADO.");
    printf("\n==============================");
    printf("\nDIGITE O CODIGO QUE VOCÊ DESEJA EXCLUIR");
    scanf("%i",&id);
    Livro *atual = lista->inicio;
    Livro *anterior = NULL;
    while (atual!= NULL && atual->codigo!=id)
    {
        anterior = atual;
        atual = atual->proximo;
    }
    if(anterior == NULL){
        lista->inicio=atual->proximo;
    }else{
        anterior->proximo = atual->proximo;
    }
    free(atual);
    printf("LIVRO EXCLUIDO");
}
//MAIN & MENU
int menu(){
    int opcao;
    printf("\n================");
    printf("\nMENU BIBLIOTECA ");
    printf("\n================");
    printf("\n1- CADASTRAR LIVRO");
    printf("\n2- EXIBIR LIVRO");
    printf("\n3- ATUALIZAR LIVRO");
    printf("\n4- EXCLUIR LIVRO");
    printf("\n5- FILTRAR LIVROS.");
    printf("\n0- SAIR");
    printf("\nDIGITE UMA OPCAO: ");
    scanf("%i",&opcao);
    return opcao;
}
int main(){
    int escolha;
    Lista lista;
    lista.inicio = NULL;
    do
    {
        escolha= menu();
        switch (escolha)
        {
        case 1:
            insert(&lista);
            break;
        case 2:
            imprimir(&lista);
            break;
        case 3:
            status(&lista);
        break;
        case 4:
            ExcluirLivro(&lista);
            break;
        case 5:
            filter_livro(&lista);
        break;
        case 0:
            printf("\nSaindo...");
            liberar(&lista);
        break;
           
        default:
            printf("VALOR INVALIDO");
            break;
        }
    } while (escolha!=0);
    
}