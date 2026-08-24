#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char nome[50];
} Contato;

int buscar_contato_por_id(Contato *cont, int *total, int id_procurado) {
    for (int i = 0; i < *total; i++) {
        if (cont[i].id == id_procurado) {
            return i; 
        }
    }
    return -1; 
}

void cadastrarcontato(Contato *cont, int *totalcontato) {
    int nu = 0;
    int novo_id;
    printf("\n------Cadastro Contato------\n");
    printf("\nDigite o numero de contatos a serem cadastrados: ");
    scanf("%i", &nu);
    
    for (int i = 0; i < nu; i++) {
        int id_valido = 0;

        while (!id_valido) { 
            printf("\nDigite o ID para o contato %d: ", i + 1);
            scanf("%i", &novo_id);

            
            if (buscar_contato_por_id(cont, totalcontato, novo_id) == -1) {
                id_valido = 1;
            } else {
                printf("Erro: O ID %i ja existe. Escolha outro!\n", novo_id);
            }
        }
        cont[*totalcontato].id = novo_id;
        printf("Digite o Nome do contato: ");
        setbuf(stdin, NULL); 
        fgets(cont[*totalcontato].nome, 50, stdin);
        cont[*totalcontato].nome[strcspn(cont[*totalcontato].nome, "\n")] = 0;
        
        (*totalcontato)++;
        printf("--- Contato salvo! ---\n");
    }
}

void editarcontato(Contato *cont, int *totacontato){
    int id_busca;
        if (*totacontato == 0){
        printf ("Não há contatos cadastrados. ");
        return;
    }
    printf("\nDigite o ID do contato que voce quer editar: ");
    scanf("%i", &id_busca);
    
    int indice = buscar_contato_por_id(cont, totacontato, id_busca);
    if(indice != -1){
        printf("\n---Contato Encontrado---\n");
        printf("ID: %d\n", cont[indice].id);
        printf("Digite o novo nome do Contato: ");
        setbuf(stdin, NULL); 
        fgets(cont[indice].nome, 50, stdin);
        cont[indice].nome[strcspn(cont[indice].nome, "\n")] = 0;
        printf("--- Contato Alterado! ---\n");   
    }else{
        printf("\nErro: O ID %d nao foi encontrado no sistema.\n", id_busca);
    }
}

void removercontato(Contato *cont, int *totacontato){
    int id_busca;
    if (*totacontato == 0){
        printf ("Não há contatos cadastrados. ");
        return;
    }
    printf("\nDigite o ID do contato que voce quer remover: ");
    scanf("%i", &id_busca);
    
    
    int indice = buscar_contato_por_id(cont, totacontato, id_busca);
    if(indice != -1){
        printf("\n---Contato Encontrado---\n");
        for (int j = indice; j < *totacontato - 1; j++) {
            cont[j] = cont[j + 1]; 
        }
        (*totacontato)--;
        printf("--- Contato Removido! ---\n");   
    }else{
        printf("\nErro: O ID %d nao foi encontrado no sistema.\n", id_busca);
    }
}

void listacontato(Contato *cont, int *totacontato){
    if (*totacontato == 0){
        printf("\nNenhum Contato Cadastrado.\n");
        return;
    }else{
        printf("\n---LISTA CONTATOS---\n");
        for (int i = 0; i < *totacontato; i++) {
            printf("ID: %d", cont[i].id);
            printf(" | Nome: %s\n", cont[i].nome);
            printf("-----------------------------------\n");
        }
    }
}

int menu(){
    int opcao;
    printf("\n--- MENU PRINCIPAL ---\n");
    printf("1. Cadastrar Contato\n");
    printf("2. Buscar Contato\n");
    printf("3. Editar Nome Contato\n");
    printf("4. Remover Contato\n");
    printf("5. Listar Contatos\n"); 
    printf("0. Sair\n");
    printf("Escolha uma opcao: ");
    
    scanf("%d", &opcao);
    return opcao;
}

int main (){
    Contato cont[100];
    int escolha, totalcontato = 0;
    do {
        escolha = menu();
        switch (escolha) {
            case 1:
                cadastrarcontato(cont, &totalcontato);
                break;
            case 2:
                { 
                    if (totalcontato ==0)
                    {
                        printf("Não há contatos cadastrados");
                        break;
                    }
                    
                    int id_busca;
                    printf("\nDigite o ID do contato que voce quer buscar: ");
                    scanf("%i", &id_busca);
                    int indice_encontrado = buscar_contato_por_id(cont, &totalcontato, id_busca);
                    if(indice_encontrado != -1){
                        printf("\n---Contato Encontrado---\n");
                        printf("ID: %d", cont[indice_encontrado].id);
                        printf(" | Nome: %s\n", cont[indice_encontrado].nome);
                        printf("-----------------------------------\n");
                    }else{
                        printf("\nErro: Contato com ID %d nao encontrado.\n", id_busca);
                    }
                }
                break;
            case 3:
                editarcontato(cont, &totalcontato);
                break;
            case 4:
                removercontato(cont, &totalcontato);
                break;
            case 5:
                listacontato(cont, &totalcontato);
                break;
        }
    } while (escolha != 0);
    
    printf("\nPrograma finalizado com sucesso.\n");
    return 0;
}