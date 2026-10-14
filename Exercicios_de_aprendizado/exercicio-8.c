#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char nome[50];
} Cliente;

typedef struct {
    int id;
    int idCliente; // ligação com Cliente
    float valor;
} Pedido;

int buscarPedido(Pedido *pedido, int total, int id){
    for (int i = 0; i < total; i++)
    {
        if (pedido[i].id == id)
        {
            return i; //acho
        }
        
    }
    return -1; //não acho
}

int buscarCliente(Cliente *clientes, int total, int id){
    for (int i = 0; i < total; i++)
    {
        if (clientes[i].id == id)
        {
            return i; //acho
        }
        
    }
    return -1; 
}

void cadastrocliente(Cliente *cliente,int *totalcliente){
    int n_client = 0;
    int id_c;
    printf("\n---Cadastro Cliente Iniciado---\n");
    printf("Digite a quantidade de clientes:");
    scanf("%i",&n_client);
    for (int i = 0; i < n_client; i++)
    {
        int id_valido = 0;
        while (!id_valido)
        {
            printf("Digite o ID do %i°: ",i+1);
            scanf("%d",&id_c);
            
            
            if (buscarCliente(cliente, *totalcliente, id_c) == -1)
            {
                id_valido = 1;
            }else{
                printf("Erro: O ID %i ja existe. Escolha outro!\n", id_c);
            }
        }
        cliente[*totalcliente].id = id_c;
        printf("Digite o nome do Cliente: ");
        getchar();
        fgets(cliente[*totalcliente].nome, 50, stdin);
        cliente[*totalcliente].nome[strcspn(cliente[*totalcliente].nome, "\n")] = '\0';
        (*totalcliente)++;
    }
    
}

void cadastrarpedido(Pedido *pedido,Cliente *cliente,int totalcliente,int *totalpedido){
    if (totalcliente == 0)
    {
        // CORREÇÃO: Adicionado '\n' para melhor formatação no terminal.
        printf("Não há clientes no sistema ainda, para cadastrar um pedido.\n");
        return;
    }
    int i_pedido ,i_cliente;
    int q_pedido;
    printf("Digite a quantidade de Pedidos:");
    scanf("%i",&q_pedido);
    for (int i = 0; i < q_pedido; i++)
    {
        int id_valido = 0;
        while (!id_valido)
        {
            printf("Digite o ID do pedido: ");
            scanf("%i",&i_pedido);
            if (buscarPedido(pedido,*totalpedido,i_pedido)== -1)
            {
                id_valido = 1;
            }else{
                printf("Erro: O ID %i ja existe. Escolha outro!\n", i_pedido);
            }
            
        }
        pedido[*totalpedido].id = i_pedido;

        int id_cvalido=0;
        while (!id_cvalido)
        {
            printf("Digite o ID do cliente: ");
            scanf("%i",&i_cliente);
            if (buscarCliente(cliente,totalcliente,i_cliente)== -1)
            {
                printf("Erro: O cliente com ID %i nao foi encontrado. Tente outro!\n", i_cliente);
            }else{
                id_cvalido = 1;
            }  
        }
        int indice_c = buscarCliente(cliente,totalcliente,i_cliente);
        if (indice_c != -1)
        {
            pedido[*totalpedido].idCliente = i_cliente;
            printf("Insira valor do pedido: ");
            scanf("%f",&pedido[*totalpedido].valor);
            (*totalpedido)++;
        }else{
            printf("\nErro: O ID %d nao foi encontrado no sistema.\n", i_cliente);
        }
    }
}

void listarcliente(Cliente *cliente,int totalcliente){
    if (totalcliente ==0){
        printf("Não há clientes cadastrados para listar\n");
        return;
    }
    printf("---Lista Iniciada---");
    for (int i = 0; i < totalcliente; i++)
    {
        printf("\nID: %i ",cliente[i].id);
        printf("| Nome: %s", cliente[i].nome);
        printf("\n------------\n");
    }
}

void listarpedido(Pedido *pedido,Cliente *cliente,int totalcliente,int totalpedido){
    if (totalcliente == 0 || totalpedido == 0)
    {
        printf("Não há clientes ou pedidos no sistema ainda.\n");
        return;
    }
    printf("----Lista Pedidos Inicialiada----\n");
    for (int i = 0; i < totalcliente; i++)
    {
        for (int j = 0; j < totalpedido; j++)
        {
            if (pedido[j].idCliente == cliente[i].id)
            {
                printf("ID Pedido: %i ",pedido[j].id);
                printf("| ID Cliente: %i",pedido[j].idCliente);       
                printf("| Nome: %s",cliente[i].nome);
                printf("\n Valor: %.2f\n",pedido[j].valor);
            }
        }
    }
}

void salvarArquivo(Pedido *pedido, Cliente *cliente, int totalcliente, int totalpedido) {
    FILE *arquivo;
    char resposta;

    arquivo = fopen("backup.dat", "rb");

    if (arquivo != NULL) {
        fclose(arquivo);
        printf("\nO arquivo 'backup.dat' ja existe. Deseja sobrescrever? (S/N): ");
        scanf(" %c", &resposta);

        if (resposta == 'N' || resposta == 'n') {
            printf("\nSalvamento cancelado.\n");
            return;
        }
    }

    arquivo = fopen("backup.dat", "wb");

    if (arquivo == NULL) {
        printf("\nErro ao criar arquivo!\n");
        return;
    }

    // salva quantidade de clientes
    fwrite(&totalcliente, sizeof(int), 1, arquivo);

    // salva clientes
    if (totalcliente > 0) {
        fwrite(cliente, sizeof(Cliente), totalcliente, arquivo);
    }

    // salva quantidade de pedidos
    fwrite(&totalpedido, sizeof(int), 1, arquivo);

    // salva pedidos
    if (totalpedido > 0) {
        fwrite(pedido, sizeof(Pedido), totalpedido, arquivo);
    }

    fclose(arquivo);

    printf("\n--- Dados salvos com sucesso! ---\n");
}

void carregarArquivo(Pedido *pedido, Cliente *cliente, int *totalcliente, int *totalpedido) {
    
    FILE *arquivo = fopen("backup.dat", "rb");

    if (arquivo == NULL) {
        printf("\nNenhum arquivo encontrado ou erro ao ler (backup.dat).\n");
        return; 
    }

    fread(totalcliente, sizeof(int), 1, arquivo);

    if (*totalcliente > 0) {
        fread(cliente, sizeof(Cliente), *totalcliente, arquivo);
    }
    fread(totalpedido,sizeof(int),1,arquivo);
    
    if (*totalpedido>0) {
        fread(pedido, sizeof(Pedido), *totalpedido, arquivo);
    }
    
    fclose(arquivo);
    printf("\n--- %d Clientes carregados do arquivo com sucesso! ---\n", *totalcliente);
    printf("\n--- %d Pedidos carregados do arquivo com sucesso! ---\n", *totalpedido);
}

void buscarpedidocliente(Pedido *pedido,Cliente *cliente,int totalcliente,int totalpedido){
    int id_cb;
    int encontrado = 0;
    if(totalcliente == 0 || totalpedido ==0){
        printf("Não há pedidos ou clientes no sistema\n");
        return;
    }
    printf("Digite o ID do cliente para buscar: ");
    scanf("%i",&id_cb);
    int indice_c = buscarCliente(cliente,totalcliente,id_cb);
    if (indice_c != -1)
    {
        printf("ID: %i | Nome: %s\n",cliente[indice_c].id,cliente[indice_c].nome);
        for (int i = 0; i < totalpedido; i++)
        {
            if (pedido[i].idCliente == id_cb)
            {
                printf("Pedido %d: %.2f\n", pedido[i].id, pedido[i].valor);
                encontrado = 1;
            }   
        }
        if (!encontrado)
        {
            printf("Cliente sem pedidos.\n");
        }

    }else{
        printf("Cliente não encontrado\n");
        return;
    }
}

int menu(){
    int opcao;
    printf("\n-----Programa inicializado-----\n");
    printf("1- Cadastrar Cliente\n");
    printf("2- Listar Cliente\n");
    printf("3- Cadastrar Pedido\n");
    printf("4- Listar pedidos\n");
    printf("5- Buscar pedidos por cliente\n");
    printf("6- Backup Sistema\n");
    printf("7- Carregar backup\n");
    printf("0- Sair\n");
    scanf("%i",&opcao);
    return opcao;
}

int main(){
    Cliente cliente [100];
    Pedido pedido [100];
    int escolha;
    int totalpedido = 0;
    int totalcliente = 0;
    do
    {
        escolha = menu();
        switch (escolha)
        {
        case 1:
            cadastrocliente(cliente,&totalcliente);
            break;
        case 2:
            listarcliente(cliente,totalcliente);
            break;
        case 3:
            cadastrarpedido(pedido,cliente,totalcliente,&totalpedido);
            break;
        case 4:
            listarpedido(pedido,cliente,totalcliente,totalpedido);
            break;
        case 5:
            buscarpedidocliente(pedido, cliente, totalcliente, totalpedido);
            break;
        case 6:
            salvarArquivo(pedido, cliente, totalcliente, totalpedido);
            break;
        case 7:
            carregarArquivo(pedido,cliente,&totalcliente,&totalpedido);
            break;
        }
    } while (escolha!=0);
    
    return 0;
}