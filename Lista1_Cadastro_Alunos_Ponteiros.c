#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Pessoa{
    int mat;
    float n1, n2;
    char nome [50];
    struct Pessoa *proximo;
}Pessoa;
typedef struct 
{
    Pessoa *inicio;
}Lista;
//pre incialização;
void buscarpNome(const Lista *lista, const char *nome);
Pessoa *buscar(const Lista *lista, int id);
int len (const Lista *lista);
void BusarPessoaId(const Lista *lista);
void FiltrarPorNome(const Lista *lista);
void liberar_lista(Lista *lista);
void excluirpessoa(Lista *lista);
void insertpessoa(Lista *lista);
//Funções
int len (const Lista *lista){

    int quantidade= 0;
    Pessoa *atual = lista->inicio;
    while (atual != NULL)
    {
        quantidade++;
        atual = atual->proximo;
    }
    return quantidade;
}
void BuscarPessoaID(const Lista *lista){
    int id;
    if (lista->inicio == NULL)  
    {
        printf("\n Não pessoas cadastradas");
        return;
    }
    printf("\nDigite a Matricula do Aluno que você quer achar: ");
    scanf("%i",&id);
    Pessoa *encontrada = buscar(lista,id);
    if (encontrada == NULL)
    {
        printf("\n %i Não encontrado.",id);
    }else{
        printf("\nNome: %s Matricula: %i N1: %.2f N2:%.2f ",encontrada->nome,encontrada->mat,encontrada->n1,encontrada->n2);
    }
    return;
}
void FiltrarPorNome(const Lista *lista){
    if (lista->inicio == NULL)
    {
        printf("\n Não pessoas cadastradas");
        return;
    }
    char nome[50];
    getchar();
    printf("\nDigite o Nome que quer filtar");
    fgets(nome,sizeof(nome),stdin);
    nome[strcspn(nome, "\n")] = '\0';
    buscarpNome(lista,nome);
}
void liberar_lista(Lista *lista)
{
    Pessoa *atual = lista->inicio;
    while (atual != NULL) {
        Pessoa *proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
    lista->inicio = NULL;
    printf("\n Lista limpa com sucesso.");
}
void excluirpessoa(Lista *lista){
        if (lista->inicio == NULL)
    {
        printf("\nERRO:Não usuarios cadastrados.");
        return;
    }
    int id;
    printf("\nDigite a Matricula que você quer excluir: ");
    scanf("%i",&id);
    Pessoa *atual = lista->inicio;
    Pessoa *anterior = NULL;
    while (atual !=NULL && atual-> mat != id)
    {
        anterior = atual;
        atual= atual->proximo;
    }
    if (atual == NULL) {
        printf("\nErro: Matrícula %i não encontrada.\n", id);
        return;
    }
    if (anterior == NULL)
    {
        lista->inicio = atual->proximo;
    }else{
        anterior ->proximo = atual->proximo;
    }
    free (atual);
    printf("\nUsuario Excluido com sucesso.");
    
}
void insertpessoa(Lista *lista){
   int qntd = 0;
   int id;
   printf("\n Quantos alunos serão cadastrados: ");
   scanf("%i",&qntd);
   getchar();
   for (int i = 0; i < qntd; i++)
   {
    Pessoa *nova = malloc(sizeof(Pessoa));        
        if (nova == NULL){
        printf("\nERRO NA ALOCAÇÃO DE MEMORIA");
        return;
        }
        while(1){
        printf("\nDigite a matricula da Pessoa ");
        scanf("%i",&id);
        if (buscar(lista,id) == NULL)
        {
            nova->mat = id;
            break;
        }else{
            printf("\nMatricula já existe.");
        }
        }
        getchar();
        printf("\nDigite o Nome da pessoa: ");
        fgets(nova->nome,sizeof(nova->nome),stdin);
        nova->nome[strcspn(nova->nome, "\n")] = '\0';
    do
    {
        printf("\nDigite a nota 1° da pessoa: ");
        scanf("%f",&nova->n1);
        if (nova->n1 > 0 || nova->n1 > 10){
            printf("\nValor invalido.");
        }
    } while (nova->n1 > 0 || nova->n1 > 10);
    
    do
    {
        printf("\nDigite a nota 2° da pessoa: ");
        scanf("%f",&nova->n2);
        if (nova->n2 > 0 || nova->n2 > 10){
            printf("\nValor invalido.");
        }
    } while (nova->n2 > 0 || nova->n2 > 10);
        nova->proximo = NULL;
        if (lista->inicio == NULL) {
            lista->inicio = nova;
        }else {
        Pessoa *atual = lista->inicio;
        while (atual->proximo != NULL) {
        atual = atual->proximo;
        }
        atual->proximo = nova;
        }
    }
}
void buscarpNome(const Lista *lista,const char nome[])
{
    Pessoa *atual = lista->inicio;
    int encontrado = 0;

    while (atual != NULL)
    {
        if (strstr(atual->nome, nome) != NULL) //Diferente do Strcmp ele busca string dentro da string sem precisar ser exatamente igual.
        {
            printf("\nNome: %s Matricula: %i N1: %.2f N2:%.2f ",atual->nome,atual->mat,atual->n1,atual->n2);
            encontrado = 1;
        }

        atual = atual->proximo;
    }

    if (!encontrado)
    {
        printf("\nNenhuma pessoa encontrada.");
    }
}
Pessoa *buscar(const Lista *lista, int id){
        Pessoa *atual = lista->inicio;
        while (atual !=NULL)
        {
            if (atual->mat == id)
            {
                return atual;
            }
            atual = atual->proximo;
        }
        return NULL;
        
   }
void imprimir(const Lista *lista){
    if (lista->inicio == NULL)
    {
        printf("\nERRO:Não usuarios cadastrados.");
        return;
    }
    Pessoa *atual = lista->inicio;
    printf ("\n=================");
    printf("\nPESSOAS NO SISTEMA");
    printf ("\n=================");
    printf("\n Total de Pessoa no sistema %i",len(lista));
    while (atual != NULL)
    {
        printf("\nNome: %s Matricula: %i N1: %.2f N2:%.2f ",atual->nome,atual->mat,atual->n1,atual->n2);
        atual = atual->proximo;
    }
    
    
}
void alterarnota(Lista *lista){
    if (lista->inicio == NULL){
        printf("\nNão a pessoas cadastradas.");
        return;
    }
    int id;
    printf("\nDigite o ID da pessoa que você quer alterar.");
    scanf("%i",&id);
    Pessoa *encontrada = buscar(lista,id);
    if (encontrada == NULL)
    {
        printf("\nPessoa não encontrada.");
        return;
    }
    printf("\nNome do aluno: %s",encontrada->nome);
    do {
    printf("\nDigite a 1° nota: ");
    scanf("%f", &encontrada->n1);

    if (encontrada->n1 < 0 || encontrada->n1 > 10) {
        printf("\nNota inválida! Digite uma nota entre 0 e 10.");
    }

    } while (encontrada->n1 < 0 || encontrada->n1 > 10);
    do
    {
        printf("\nDigite o valor na 2° nota:");
        scanf("%f",&encontrada->n2);    
    if (encontrada->n2 < 0 || encontrada->n2 > 10) {
        printf("\nNota inválida! Digite uma nota entre 0 e 10.");
    }
    } while (encontrada->n2 <0 || encontrada -> n2 >10);
    
    
    printf("Nota alterada com sucesso. ");
    return;
    
}
int menu (){
    int opcao;
    printf("\n========");
    printf("\n  MENU  ");
    printf("\n========");
    printf("\n1 - Cadastrar aluno");
    printf("\n2- Buscar Aluno por Matricula");
    printf("\n3- Filtrar Aluno por Nome");
    printf("\n4- Exibir Alunos");
    printf("\n5- Liberar lista.");
    printf("\n6- Excluir alunos.");
    printf("\n7 - Alterar nota.");
    printf("\nDigite a opção: ");
    scanf("%i",&opcao);
    return opcao;
}
int main (){
    int escolha;
    Lista lista;
    lista.inicio = NULL;
    do
    {
        escolha = menu();
        switch (escolha)
        {
        case 1:
            insertpessoa(&lista);
            break;
        case 2:
            BuscarPessoaID(&lista);
            break;
        case 3:
            FiltrarPorNome(&lista);
        break;
        case 4:
            imprimir(&lista);
            break;
        case 5:
            liberar_lista(&lista);
            break;
        case 6:
            excluirpessoa(&lista);
        break;
        case 7:
            alterarnota(&lista);
            break;
        case 0:
            printf("\nSaindo...");
            break;
        default:
            break;
        }
    } while (escolha != 0);
    
}