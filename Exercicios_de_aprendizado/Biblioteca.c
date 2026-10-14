#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
    int codigo;
    char autor [100];
    char titulo [100];
    int ano;
    int status;
}Livro;


//Funções
int Search(Livro *book,int total,int cod){
    for (int i = 0; i < total; i++)
    {
        if (book[i].codigo == cod)
        {
            return i;
        }
        
    }
    return -1;
}
void buscar(Livro *book,int total){
    if (total == 0){
        printf("\nERRO! NÃO HÁ LIVROS CADASTRADOS.");
        return;
    }
    int cod,indice;
    char escolha;
    printf("\nBusca iniciada. ");
    printf("\nDigite o codigo do livro: ");
    scanf("%i",&cod);
    if(Search(book,total,cod)==-1){
        printf("ERRO!Livro não encontrado");
        return;
    }
    indice = Search(book,total,cod);
    printf("\nO seguinte livro foi empretado, com sucesso.");
    printf("\nCodigo: %i | Titulo: %s | Autor: %s | Ano: %i |",book[indice].codigo,book[indice].titulo,book[indice].autor,book[indice].ano);
    if(book[indice].status == 1){
            printf("Disponivel [ ]");
        }else{
            printf("Indisponivel [X]");
    }
    
}
void cadastrolivro(Livro *book,int *total){
    int cod;
    int encontrado = 0;
    printf("\n===CADASTRO LIVRO===\n");
    if (*total >= 100) {
        printf("\nERRO! Limite de %d livros atingido.\n");
        return;
    }
    while (!encontrado)
    {
        printf("\nDigite o codigo do livro: ");
        scanf("%i",&cod);
        if (Search(book,*total,cod)==-1)
        {
            encontrado = 1;
        }else{
            printf("\nERRO! CODIGO %i , JA CADASTRADA ",cod);
        }
        
    }
    book[*total].codigo = cod;
    printf("\nDigite o Titulo do Livro: ");
    getchar();
    fgets(book[*total].titulo,sizeof(book[*total].titulo),stdin);
    book[*total].titulo[strcspn(book[*total].titulo, "\n")] = '\0';
    printf("\nDigite o autor do Livro: ");
    getchar();
    fgets(book[*total].autor,sizeof(book[*total].autor),stdin);
    book[*total].autor[strcspn(book[*total].autor, "\n")] = '\0';
    getchar();
    printf("\nDigite o ano de lançamento: ");
    scanf("%i",&book[*total].ano);
    book[*total].status = 1;
    (*total)++;
    printf("\nCadastro Realizado com Sucesso.");

}
void exibirlivros(Livro *book,int total){
    if (total == 0){
        printf("\nERRO! NÃO HÁ LIVROS CADASTRADOS.");
        return;
    }
    printf("\nLista de Livros Iniciada.");
    for(int i=0;i < total;i++){
        printf("\nCodigo: %i | Titulo: %s | Autor: %s | Ano: %i |",book[i].codigo,book[i].titulo,book[i].autor,book[i].ano);
        if(book[i].status == 1){
            printf("Disponivel [ ]");
        }else{
            printf("Indisponivel [X]");
        }
    }
}
void empretar(Livro *book,int total){
    if (total ==0){
        printf("\nNão há livros cadastrados");
        return;
    }
    int cod,indice;
    printf("\nEmprestar Livro Iniciado.");
    printf("\nDigite o Livro que quer emprestar: ");
    scanf("%i",&cod);
    if(Search(book,total,cod)==-1){
        printf("ERRO!Livro não encontrado");
        return;
    }
    indice = Search(book,total,cod);
    printf("\nO seguinte livro foi empretado, com sucesso.");
    printf("\nCodigo: %i | Titulo: %s | Autor: %s | Ano: %i |",book[indice].codigo,book[indice].titulo,book[indice].autor,book[indice].ano);
    book[indice].status = 0;
    return;
}
void devolver(Livro *book,int total){
    if (total ==0){
        printf("\nNão há livros cadastrados");
        return;
    }
    int cod,indice;
    printf("\nEmprestar Livro Iniciado.");
    printf("\nDigite o Livro que quer emprestar: ");
    scanf("%i",&cod);
    if(Search(book,total,cod)==-1){
        printf("ERRO!Livro não encontrado");
        return;
    }
    indice = Search(book,total,cod);
    printf("\nO seguinte livro foi devolvido, com sucesso.");
    printf("\nCodigo: %i | Titulo: %s | Autor: %s | Ano: %i |",book[indice].codigo,book[indice].titulo,book[indice].autor,book[indice].ano);
    book[indice].status = 1;
    return;
}
void remover(Livro *book, int *total){
    int cod;
    if (*total == 0){
        printf("\nERRO! NÃO HÁ LIVROS CADASTRADOS.");
        return;
    }
    printf("\nDigite o codigo do Livro: ");
    scanf("%i",&cod);
    int indice = Search(book,*total,cod);
    if (indice!= -1){
        printf("\nLivro encontrado");
        for(int i=indice;i < *total -1;i++){
            book[i]=book[i +1];
        }
        (*total)--;
        printf("\n Livro removido.");
    }else{
        printf("\nErro: O codigo %i não encontrado",cod);
    }
}
//menu e main

int menu(){
    int opcao;
    printf("\n===MENU BIBLIOTECA===\n");
    printf("\n1 - Cadastrar livro");
    printf("\n2 - Buscar livro pelo código");
    printf("\n3 - Listar todos os livros");
    printf("\n4 - Emprestar livro");
    printf("\n5 - Devolver livro");
    printf("\n6 - Excluir livro");
    printf("\n0 - Sair");
    printf("\nDigite uma opção: ");
    scanf("%i",&opcao);
    return opcao;
}
int main(){
    Livro book[100];
    int total = 0,escolha;

    do
    {
        escolha = menu();
        switch (escolha)
        {
        case 1:
            cadastrolivro(book,&total);
            break;
        case 2:
            buscar(book,total);
            break;
        case 3:
            exibirlivros(book,total);
            break;
        case 4:
            empretar(book,total);
            break;
        case 5:
            devolver(book,total);
            break;
        case 6:
            remover(book,&total);
            break;
        case 0:
            printf("\nSaindo...");
            break;
        
        default:
            printf("\nValor invalido.");
            break;
        }
    } while (escolha!=0);
    
}