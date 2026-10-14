#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    int id;
    char nome [50];
}Contato;
//Funções

int buscarcontato(Contato *contac,int totalcontato, int id_busca){
    for (int i = 0; i < totalcontato; i++)
    {
        if (contac[i].id == id_busca)
        {
            return i;// vai retorna o I que no caso é a memoria desse id
        }
        
    }
    return -1;
}


void cadastrarcontato(Contato *contac,int *totalcontato){
    int num = 0;
    int novo_id=0;
    printf("\nDigite o numero de contatos a serem cadastrados: ");
    scanf("%i", &num);
    for (int i = 0; i < num; i++)
    {
        int id_valido = 0;
        while (!id_valido)
        {
            printf("\nDigite o ID para o contato %d: ", i + 1);
            scanf("%i", &novo_id);
             if (buscarcontato(contac, totalcontato, novo_id) == -1) {
                id_valido = 1;
            } else {
                printf("Erro: O ID %i ja existe. Escolha outro!\n", novo_id);
            }
        }
        //usamos o total de contato pra um contato não sobrescrever outro assim pulando sempre pra proxima vaga.
        contac[*totalcontato].id = novo_id;
        printf("Digite o nome do contato: ");
        getchar();
        // 2. Lê o nome com segurança
        fgets(contac[*totalcontato].nome, 50, stdin);
        // 3. Remove o '\n' que o fgets captura no fina
        contac[*totalcontato].nome[strcspn(contac[*totalcontato].nome, "\n")] = '\0';
        (*totalcontato)++;
    }
    
}

void editarcontato(Contato *contac,int totalcontato){
    int buscar_id;  
    if (totalcontato == 0){
        printf ("Não há contatos cadastrados. ");
        return;
    }

    printf("Digite o ID que você quer editar:");
    scanf("%i",&buscar_id);
    int indice = buscarcontato(contac,totalcontato, buscar_id);
    if (indice != -1){
        printf("\n---Contato Encontrado---\n");
        printf("ID: %d\n", contac[indice].id);
        printf("Digite o novo nome do Contato: ");
        setbuf(stdin, NULL); 
        fgets(contac[indice].nome, 50, stdin);
        contac[indice].nome[strcspn(contac[indice].nome, "\n")] = 0;
        printf("--- Contato Alterado! ---\n");   
    }else{
        printf("\nErro: O ID %d nao foi encontrado no sistema.\n", buscar_id);
    }
}
void removercontato(Contato *contac,int *totalcontato){
    int id_b;
    if(*totalcontato ==0){
        printf("Não existe contatos cadastrados para remover.");
        return;
    }
    printf("\nDigite o ID do contato que voce quer remover: ");
    scanf("%i", &id_b);
    int indice = buscarcontato(contac,totalcontato, id_b);
    if(indice != -1){
        printf("\n---Contato Encontrado---\n");
        for (int j = indice; j < *totalcontato - 1; j++) {
            contac[j] = contac[j + 1]; 
        }
        (*totalcontato)--;
        printf("--- Contato Removido! ---\n");   
    }else{
        printf("\nErro: O ID %d nao foi encontrado no sistema.\n", id_b);
    }
}
void listacontato(Contato *contac, int *totalcontato){
    if (*totalcontato == 0){
        printf("\nNenhum Contato Cadastrado.\n");
        return;
    }else{
        printf("\n---LISTA CONTATOS---\n");
        for (int i = 0; i < *totalcontato; i++) {
            printf("ID: %d", contac[i].id);
            printf(" | Nome: %s\n", contac[i].nome);
            printf("-----------------------------------\n");
        }
    }
}
void salvarArquivo(Contato *contac, int *totalcontato) {
    FILE *arquivo;
    char resposta;

    arquivo = fopen("contatos.dat", "rb");

    if (arquivo != NULL) {

        fclose(arquivo);
        printf("\nO arquivo 'contatos.dat' ja existe. Deseja sobrescrever os dados? (S/N): ");
        scanf(" %c", &resposta); 

        if (resposta == 'N' || resposta == 'n') {
            printf("\nSalvamento cancelado pelo usuario.\n");
            return;
        }
    }
    arquivo = fopen("contatos.dat", "wb");

    if (arquivo == NULL) {
        printf("\nErro ao criar o arquivo para salvar!\n");
        return; 
    }
    fwrite(totalcontato, sizeof(int), 1, arquivo);

    if (*totalcontato > 0) {
        fwrite(contac, sizeof(Contato), *totalcontato, arquivo);
    }

    fclose(arquivo);
    printf("\n--- %d Contatos salvos com sucesso no arquivo! ---\n", *totalcontato);
}

void carregarArquivo(Contato *contac, int *totalcontato) {
    
    FILE *arquivo = fopen("contatos.dat", "rb");

    if (arquivo == NULL) {
        printf("\nNenhum arquivo encontrado ou erro ao ler (contatos.dat).\n");
        return; 
    }

    
    fread(totalcontato, sizeof(int), 1, arquivo);

    
    if (*totalcontato > 0) {
        fread(contac, sizeof(Contato), *totalcontato, arquivo);
    }

    fclose(arquivo);
    printf("\n--- %d Contatos carregados do arquivo com sucesso! ---\n", *totalcontato);
}




int menu (){
    int escolha ;
    printf("\n-----Programa Inicializado-----\n");
    printf("\n1- Cadastrar Contato \n");
    printf("\n2- Buscar Contato \n");
    printf("\n3- Editar Contatos \n");
    printf("\n4- Remover Contato \n");
    printf("\n5- Listar Contato \n");
    printf("\n6- Salvar Arquivo \n");
    printf("\n7- Carregar do Arquivo \n");
    printf("\n0- Sair \n");
    printf("\nEscolha uma opção para continuar: ");
    scanf("%i",&escolha);
    return escolha;
}
int main (){
    Contato contac [100];
    int opcao , totalcontato = 0;
    do
    {
    opcao = menu();        //sempre dentro do DO pra repetir o menu.
    switch (opcao)
    {
    case 1:
        cadastrarcontato(contac,&totalcontato);
        /* code */
        break;
    case 2:{
        if (totalcontato ==0)
        {
            printf("Não há contatos cadastrados");
            break;
        }
        int id_b;
        printf("Digite o ID que você quer editar:");
        scanf("%i",&id_b);
        int indice = buscarcontato(contac,&totalcontato,id_b);
        if (indice !=-1)
        {
            printf("\n---Contato Encontrado---\n");
            printf("\nID: %i ",contac[indice].id);
            printf("Nome: %s ",contac[indice].nome);
            printf("-----------------------------------\n");
        }else{
            printf("\nErro: Contato com ID %d nao encontrado.\n", id_b);
        }
        }
        break;
    case 3:
        editarcontato(contac,&totalcontato);
        break;
    case 4:
        removercontato(contac,&totalcontato);
        break;
    case 5:
        listacontato(contac,&totalcontato);
        break;
    case 6:
        salvarArquivo(contac,&totalcontato);
        break;
    case 7:
        carregarArquivo(contac,&totalcontato);
        break;
    
    }
    } while (opcao != 0);
       
}