#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int id;
    char titulo[100];
    char autor[100];
    int disponivel; //disponivel = 1 No estoque . 0 = Emprestado
}Livro;


void cadastrarLivro(Livro book[], int *totallivros) {
    int n, id_digitado;
    
    printf("Quantos livros voce quer registrar? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int encontrado = 0;
        
        printf("\n--- Registro do %d° Livro ---\n", i + 1);
        printf("ID do livro: ");
        scanf("%d", &id_digitado);

        // Verifica se o ID já existe
        for (int j = 0; j < *totallivros; j++) {
            if (book[j].id == id_digitado) {
                encontrado = 1;
                break;
            }
        }

        if (encontrado) {
            printf("Erro: ID %d ja registrado no estoque!\n", id_digitado);
            // Se o ID já existe, podemos decrementar o 'i' para repetir essa entrada
            // ou apenas pular para o próximo.
        } else {
            book[*totallivros].id = id_digitado;
            
            getchar();
            
            printf("Titulo do livro: ");
            fgets(book[*totallivros].titulo, sizeof(book[*totallivros].titulo), stdin);
            book[*totallivros].titulo[strcspn(book[*totallivros].titulo, "\n")] = 0;

            printf("Autor do livro: ");
            fgets(book[*totallivros].autor, sizeof(book[*totallivros].autor), stdin);
            book[*totallivros].autor[strcspn(book[*totallivros].autor, "\n")] = 0;

            book[*totallivros].disponivel = 1;

            (*totallivros)++; // Incrementa o contador real na main
            printf("Livro registrado com sucesso!\n");
        }
    }
}
void listalivro(Livro book[], int *totallivros){
    printf("\n--- Lista dos Livros ---\n");
    if (*totallivros == 0) {
        printf("Nenhum livro cadastrado no momento.\n");
        return; // Sai da função se não houver nada para listar
    }
    for (int i = 0; i < *totallivros; i++)
    {
        
        printf("\nID: %i",book[i].id);
        printf("\nTitulo: %s",book[i].titulo);
        printf("\nAutor: %s",book[i].autor);
        if (book[i].disponivel == 1)
        {
            printf("\nSituação: Disponivel");
            printf("\n----------------------------");
        }else{
            printf("\nSituação: Emprestado");
            printf("\n----------------------------");
        }
        
        
    }
    

}
void buscarlivro(Livro book[], int *totallivros){
    int id_busca;
    int encontrado = 0;
     if (*totallivros == 0) {
        printf("Nenhum livro cadastrado no momento.\n");
        return; // Sai da função se não houver nada para listar
    }
    printf("Qual ID você quer buscar ?");
    scanf("%i",&id_busca);
    for (int i = 0; i < *totallivros; i++)//SEMPRE USAMOS * pra pegar o valor que ja tem do int
    {
        if (book[i].id == id_busca)
        {   
            encontrado = 1;
            printf("\nID: %i",book[i].id);
            printf("\nTitulo: %s",book[i].titulo);
            printf("\nAutor: %s",book[i].autor);
            if (book[i].disponivel == 1)
            {
                printf("\nSituação: Disponivel");
                printf("\n----------------------------");
            }else{
                printf("\nSituação: Emprestado");
                printf("\n----------------------------");
            }
            break;
        }
    }
    if (!encontrado)
    {
        printf("ID não encontrado");
    }
    
}


void empretarLivro(Livro book[], int *totallivros){
    int id_busca;
    int encontrado = 0;
    if (*totallivros == 0) {
        printf("Nenhum livro cadastrado no momento.\n");
        return; // Sai da função se não houver nada para listar
    }
    printf("Qual ID você quer emprestar ?");
    scanf("%i",&id_busca);
    for (int i = 0; i < *totallivros; i++)
    {
        if (book[i].id == id_busca){
            encontrado = 1;
            if (book[i].disponivel == 1)
            {
                book[i].disponivel = 0;
                printf("\n======Situação Atualizada======\n");
                printf("\nID: %i",book[i].id);
                printf("\nTitulo: %s",book[i].titulo);
                printf("\nAutor: %s",book[i].autor);
                printf("\nSituação: Emprestado");
                printf("\n___________________________\n");
            }else{
                printf("Esse livro já foi emprestado");
            }
            break;
        }
    }
    if (!encontrado) {
        printf("\nErro: Livro com ID %d nao encontrado.\n", id_busca);
    }
}

void devolverlivro(Livro book[], int *totallivros){
    int id_busca;
    int encontrado = 0;
    if (*totallivros == 0) {
        printf("Nenhum livro cadastrado no momento.\n");
        return; // Sai da função se não houver nada para listar
    }
    printf("Qual ID você quer emprestar ?");
    scanf("%i",&id_busca);
    for (int i = 0; i < *totallivros; i++)
    {
        if (book[i].id == id_busca){
            encontrado = 1;
            if (book[i].disponivel == 0)
            {
                book[i].disponivel = 1;
                printf("\n======Situação Atualizada======\n");
                printf("\nID: %i",book[i].id);
                printf("\nTitulo: %s",book[i].titulo);
                printf("\nAutor: %s",book[i].autor);
                printf("\nSituação: Disponivel");
                printf("\n___________________________\n");
            }else{
                printf("Esse livro já está disponivel");
            }
            break;
        }
    }
    if (!encontrado) {
        printf("\nErro: Livro com ID %d nao encontrado.\n", id_busca);
    }
}




int main (){
    Livro book[100];
    int menu,n,id_livro;
    int totallivros = 0;
    int encontrado =0;

    do
    {
        printf("\n1- Cadastrar Livro\n2- Lista de Livros\n3- Buscar Livro por ID\n4-Emprestar o livro\n5-Devolver Livro\n0-sair\n");
        scanf("%i",&menu);
        switch (menu)
        {
        case 1:
            cadastrarLivro(book,&totallivros);
            break;
        
        case 2:
            listalivro(book,&totallivros);
            break;
        case 3:
            buscarlivro(book,&totallivros);
            break;
        case 4:
            empretarLivro(book,&totallivros);
            break;
        case 5:
            devolverlivro(book,&totallivros);
            break;
        }
    } while (menu!=0);
    printf("\nPrograma finalizado com sucesso !.\n");
    
}