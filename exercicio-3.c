#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//ESSE PROGRAM FICO CHEIO DE BUGS KKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKK UM DIA RESOLVO.
#define TAM 80
typedef struct
{
    int id;
    char nome[TAM];
    int quantidade;
    float preco;
}Produto;

void buscarproduto(Produto * produ, int total, int id_busca){
    for (int i = 0; i < total; i++)
    {
        if (produ[i].id == id_busca)
        {
            printf("ID: %d | Nome: %s\n |Quantidade: %d\n |Preço: %.2f\n_______________________ ", produ[i].id, produ[i].nome,produ[i].quantidade,produ[i].preco);
        }else{
            printf("Produto não foi encontrado\n");
        }
        
    }
}
void atualizarEstoque(Produto *produc,int total){
int opcao,id_produto, quantidade_n;
printf("1 - Entrada de estoque 2 - Saída de estoque");
scanf("%i",&opcao);
if (opcao==1){
    printf("Qual ID do produto que sera atualizado: ");
    scanf("%i",&id_produto);
    for (int i = 0; i < total; i++)
    {
        if (produc[i].id == id_produto){
            printf("Quantos produtos serão adicionados no estoque: ");
            scanf("%i",&quantidade_n);
            produc[i].quantidade += quantidade_n;
            printf("Estoque atualizado\n");
            printf("ID: %d | Nome: %s\n |Quantidade: %d\n |Preço: %.2f\n_______________________ ", produc[i].id, produc[i].nome,produc[i].quantidade,produc[i].preco);
        }
        else{
            printf("Produto não encontrado.");
        }
    }
    }else if (opcao==2){
         printf("Qual ID do produto que sera atualizado: ");
        scanf("%i",&id_produto);
        for (int i = 0; i < total; i++)
        {
            if (produc[i].id == id_produto){
                printf("Quantos produtos serão removido no estoque: ");
                scanf("%i",&quantidade_n);
                produc[i].quantidade -= quantidade_n;
                printf("Estoque atualizado\n");
                printf("ID: %d | Nome: %s\n |Quantidade: %d\n |Preço: %.2f\n_______________________ ", produc[i].id, produc[i].nome,produc[i].quantidade,produc[i].preco);
            }else{
            printf("Produto não encontrado.");
        }
    }
    
}

}


int main(){
    int n = 0;
    int entrada ;
    Produto prod[100];      
    int totalcadastro = 0, id_check=0; 
    
    
    
    do
    {
        printf("\n1- Cadastrar produto\n2- Lista de produtos\n3- Buscar produto por ID\n4-Atualizar o estoque\n0-sair\n");
        scanf("%i",&entrada);
        switch (entrada)
        {
        case 1:
            int totalcadastro =0;
            printf("Quantos produtos você quer cadastrar: ");
            scanf("%i",&n);
            getchar();
            if (totalcadastro + n > 100) {
            printf("Erro: Nao ha espaco suficiente no estoque!\n");
            } else {
            
            for (int i =0; i < n; i++){
            printf("Nome do produto: ");
            fgets(prod[i].nome, TAM, stdin);
            prod[i].nome[strcspn(prod[i].nome, "\n")] = '\0';
            
            printf("Digite o ID do produto");
            scanf("%i",&prod[i].id);

            printf("Digite o preço do produto");
            scanf("%f",&prod[i].preco);
            
            printf("Digite o quantidade do produto");
            scanf("%i",&prod[i].quantidade);
            totalcadastro++;
            getchar();

                }
            printf("Produto cadastrado com sucesso.");
            break;
            }
        case 2:
            for (int i = 0; i < totalcadastro; i++)
            {
                printf("\nID: %d | Nome: %s |Quantidade: %d |Preço: R$%.2f\n_______________________ ", prod[i].id, prod[i].nome,prod[i].quantidade,prod[i].preco);
            }
            
            break;
        case 3:
            int busca;
            printf("Qual ID do produto que você quer buscar ?");
            scanf("%i",&busca);
            buscarproduto(prod,totalcadastro,busca);
            break;
        case 4:
            atualizarEstoque(prod,totalcadastro);
            break;
        case 0:
            printf("Saindo...");
            break;  
       } 
    }while (entrada !=0);
   printf("Programma finalizado");
}