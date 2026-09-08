#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//STRUCTS
typedef struct Musica {
    int id;
    char nome[51];
    char artista[51];
    float duracao;
    struct Musica *proximo;
} Musica;
typedef struct{
     Musica *inicio;
}Lista;
//PROTOTIPOS
void insert(Lista *lista);
void search_id(const Lista *lista);
void filter_artista(const Lista *lista);
Musica *search(const Lista *lista, const int id);
void exibirDuracaoTotal(const Lista *lista);
void exibirMusicaMaisLonga(const Lista *lista);
void removerMusica(Lista *lista);
void liberar(Lista *lista);
void imprimir(const Lista *lista);
void changer_time(Lista *lista);
int len(const Lista *lista);
//FUNCOES
void insert(Lista *lista){
    int id ;
    float duracao;
    printf("\n================");
    printf("\nCADASTRAR MUSICA");
    printf("\n================");
    Musica *nova = NULL;
    
    while (1)
    {
        printf("\nDIGITE O ID DA MUSICA: ");
        scanf("%i",&id);    
        Musica *encontrada = search(lista,id);
        if (encontrada == NULL)
        {
            Musica *nova = malloc(sizeof(*nova));
            if (nova == NULL)
            {
                printf("\n ERRO NA ALOCAÇÂO DE MEMORIA.");
                return;
            }
            nova->id = id;
            break;
        }else{
            printf("\nERRO: ID %i JÁ CADASTRADO TENTE NOVAMENTE.",id);
        }
    
    }
    getchar();
    printf("\nDIGITE O NOME DA MUSICA: ");
    fgets(nova->nome,sizeof(nova->nome),stdin);
    nova->nome[strcspn(nova->nome, "\n")] = '\0';
    printf("\nDIGITE O NOME DO ARTISTA");
    fgets(nova->artista,sizeof(nova->artista),stdin);
    nova->artista[strcspn(nova->artista, "\n")] = '\0';
    do
    {
        printf("\nDIGITE A DURACAO DA MUSICA %s: ",nova->nome);
        scanf("%f",&duracao);
        if (duracao <= 0)
        {
            printf("\nERRO: DURACAO INVALIDA.");
        }
    } while (duracao <= 0);
    nova->duracao = duracao;
    nova->proximo = lista->inicio;
    lista->inicio = nova;
    printf("MUSICA ADICIONADA COM SUCESSO.");
}
void search_id(const Lista *lista){
    if(lista->inicio == NULL){
        printf("\nERRO NÂO HÁ MUSICAS CADASTRADAS");
        return;
    }
    int id;
    printf("\nDIGITE O ID QUE VOCÊ QUER BUSCAR: ");
    scanf("%i",id);
    Musica *encontrada = search(lista,id);  
    if (encontrada == NULL)
    {
        printf("ERRO: NÃO HÁ MUSICA COM ID %i", id);
    }
    printf("\nID | NOME MUSICA | ARTISTA | DURACAO");
    printf("\n%i |%s | %s | %.2f",encontrada->id,encontrada->nome,encontrada->artista,encontrada->duracao);
}
void filter_artista(const Lista *lista){
    if(lista->inicio == NULL){
        printf("\nERRO NÂO HÁ MUSICAS CADASTRADAS");
        return;
    }
    char nome[51];
    int encontrado = 0;
    printf("\nDIGITE O NOME DO ARTISTA: ");
    getchar();
    fgets(nome,sizeof(nome),stdin);
    nome[strcspn(nome, "\n")] = '\0';
    Musica *atual = lista->inicio;
    printf("\nID | NOME MUSICA | ARTISTA | DURACAO");
    while (atual != NULL)
    {
        if (strstr(atual->artista,nome)!=NULL)
        {
            printf("\n%i |%s | %s | %.2f",atual->id,atual->nome,atual->artista,atual->duracao);
            encontrado++;
        }
        atual = atual->proximo;
    }
    if (encontrado = 0)
    {
       printf("\nNão há musicas desse artista.");
    }
}
Musica *search(const Lista *lista, const int id){
    Musica *atual = lista->inicio;
    while (atual != NULL)
    {
        if(atual->id ==id){
            return atual;
        }
        atual = atual->proximo;
    }
    return NULL;
}
void exibirDuracaoTotal(const Lista *lista){
    if(lista->inicio == NULL){
        printf("\nERRO NÂO HÁ MUSICAS CADASTRADAS");
        return;
    }
    float duracao = 0;
    Musica *atual = lista->inicio;
    while (atual != NULL)
    {
        duracao += atual->duracao;
        atual = atual->proximo;
    }
    printf("\nA PLAYLIST TEM DURACAO DE %.2f HR");
}
void exibirMusicaMaisLonga(const Lista *lista){
    if(lista->inicio == NULL){
        printf("\nERRO NÂO HÁ MUSICAS CADASTRADAS");
        return;
    }
    Musica *atual = lista->inicio;
    Musica *longa = lista->inicio;
    while (atual != NULL)
    {
       if(longa->duracao < atual->duracao) {
            longa = atual;
        }
        atual = atual->proximo;
    }
    printf("\nID | NOME MUSICA | ARTISTA | DURACAO");
    printf("\n%i | %s | %s | %.2f\n", longa->id, longa->nome, longa->artista, longa->duracao);
}
void removerMusica(Lista *lista){
    if(lista->inicio == NULL){
        printf("\nERRO NÂO HÁ MUSICAS CADASTRADAS");
        return;
    }
    printf("\n================================");
    printf("\nALERTA: EXCLUIR MUSICA INICIADO.");
    printf("\n================================");
    int id;
    printf("\nDIGITE O CODIGO QUE VOCÊ DESEJA EXCLUIR");
    scanf("%i",&id);
    Musica *atual = lista->inicio;
    Musica *anterior = NULL;
    while (atual!= NULL || atual->id!=id)
    {
        anterior = atual;
        atual=atual->proximo;
    }
    if(atual == NULL){
        printf("\nLIVRO NAO ENCONTRADO.");
        return;
    }
    if (anterior == NULL){
        lista->inicio=atual->proximo;
    }else{
        anterior->proximo=atual->proximo;
    }
    free(atual);
    printf("\nMUSICA EXCLUIDA COM SUCESSO.");
}
void liberar(Lista *lista){
    Musica *atual = lista->inicio;
    Musica *proximo;
    while (atual!=NULL)
    {
        proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
    lista->inicio=NULL;
    
}
void imprimir(const Lista *lista){
    if(lista->inicio == NULL){
        printf("\nERRO NÂO HÁ MUSICAS CADASTRADAS");
        return;
    }
    Musica *atual = lista->inicio;
    printf("\n================================");
    printf("\nTOTAL DE MUSICAS CADASTRADAS: %i",len(lista));
    printf("\n================================");
    printf("\nID | NOME MUSICA | ARTISTA | DURACAO"); 
    while (atual !=NULL)
    {
        printf("\n%i | %s | %s | %.2f\n",atual->id,atual->nome,atual->artista,atual->duracao);
        atual = atual->proximo;
    }   
}
void changer_time(Lista *lista){
    if(lista->inicio == NULL){
        printf("\nERRO NÂO HÁ MUSICAS CADASTRADAS");
        return;
    }
    float duracao;
    int id;
    printf("\nDIGITE O ID DA MUSICA QUE VOCE QUER ALTERAR: ");
    scanf("%i",&id);
    Musica *encontrada = search(lista,id);
    if (encontrada == NULL)
    {
        printf("\nMUSICA NÂO ENCONTRADA.");
        return;
    }
    do{
        printf("\n Musica: %s Encontrada, DIGITE A DURACAO NOVA DA MUSICA: ", encontrada->nome);
        scanf("%f",&duracao);
        if (duracao <= 0)
        {
            printf("\nERRRO DIGITE UMA DURACAO VALIDA.");
        }
        
    }while(duracao <= 0);
}
int len(const Lista *lista){
    int qntd=0;
    Musica *atual = lista->inicio;
    while (atual!=NULL)
    {
        qntd ++;
        atual = atual->proximo;
    }
    return qntd;
}
//MENU E MAiN
int menu(){
    int opcao;
    printf("=============================\n");
    printf("       MINHA PLAYLIST        \n");
    printf("=============================\n\n");
    printf("1 - Adicionar música\n");
    printf("2 - Listar músicas\n");
    printf("3 - Buscar música por ID\n");
    printf("4 - Buscar por artista\n");
    printf("5 - Remover música\n");
    printf("6 - Alterar duração\n");
    printf("7 - Mostrar duração total\n");
    printf("8 - Mostrar música mais longa\n");
    printf("0 - Sair\n");
    printf("DIGITE SUA OPCAO: ");
    scanf("%i",&opcao);
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
            insert(&lista);
            break;
        case 2:
            imprimir(&lista);
        break;
        case 3:
            search_id(&lista);
        break;
        case 4:
            filter_artista(&lista);
        break;
        case 5:
            removerMusica(&lista);
        break;
        case 6:
            changer_time(&lista);
        break;
        case 7:
            exibirDuracaoTotal(&lista);
        break;
        case 8:
            exibirMusicaMaisLonga(&lista);
        break;
        case 0:
            liberar (&lista);
            printf("\nSAINDO DO SISTEMA");
        break;
        default:
            printf("\nVALOR INVALIDAO.");
            break;
        }
    } while (escolha != 0);
    
}