#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//=================ESTRTURUAS===============
typedef struct 
{
    int id;
    char nome[50];
    float preco;
}Produto;
//===================FUNÇÔES================
int buscar(Produto *product,int totalproduto, int id){
    for (int i = 0; i < totalproduto; i++)
    {
        if (product[i].id == id)
        {
            return i;
        }
        
    }
    return -1;
}

int maior(Produto *product, int totalproduto) {
    if (totalproduto <= 0) {
        return -1;
    }
    int indice_maior = 0;

    for (int i = 1; i < totalproduto; i++) {
        
        if (product[i].preco > product[indice_maior].preco) {
            indice_maior = i;
        }
    }

    return indice_maior;
}
int menor(Produto *product, int totalproduto) {
    if (totalproduto <= 0) {
        return -1;
    }
    int indice_menor = 0;

    for (int i = 1; i < totalproduto; i++) {
        if (product[i].preco < product[indice_menor].preco) {
            indice_menor = i;
        }
    }

    // Após verificar todos, retorna o índice do produto mais barato
    return indice_menor;
}

void CadastrarProduto(Produto *product,int *totalproduto){
    int id_p;
    float preco;
    printf("\nCADASTRO PRODUTO INICIADO.\n");
    int encontrado = 0;
    while (!encontrado){
        printf("DIGITE O ID DO PRODUTO: ");
        scanf("%i",&id_p);
        if (buscar(product,*totalproduto,id_p)==-1)
        {
            encontrado = 1;
        }else{
            printf("\nERRO! ID: %i JA CADASTRADO, TENTE NOVAMENTE.\n",id_p);
        }
    } 
    product[*totalproduto].id = id_p;
    printf("\nDIGITE NOME DO PRODUTO: ");
    getchar();
    fgets(product[*totalproduto].nome,sizeof(product[*totalproduto].nome),stdin);
    product[*totalproduto].nome[strcspn(product[*totalproduto].nome, "\n")] = '\0';

    do
    {
        printf("\nDIGITE O PRECO DO PRODUTO:");
        scanf("%f",&preco);
        if (preco > 0)
        {
            product[*totalproduto].preco = preco;
        }else{
            printf("\nVALOR INVALIDO TENTE NOVAMENTE");
        }
        
    } while (preco < 0);
    (*totalproduto)++;
    printf("CADASTRO FINALIZADO");
}
void ListaProduto(Produto *product,int totalproduto){
    int indice_menor,indice_maior;
    if (totalproduto == 0)
    {
        printf("ERRO:TOTAL DE PRODUTO: %i",totalproduto);
        return;
    }
    printf("\nLISTA PRODUTOS\n");
    for (int i = 0; i < totalproduto; i++)
    {
        printf("\nID %i | Nome %s | Preço %.2f",product[i].id,product[i].nome,product[i].preco);
    }
    printf("\nLISTA PRODUTOS MAIOR E MENOR\n");
    indice_menor= menor(product,totalproduto);
    indice_maior= maior(product,totalproduto);
    printf("\nMENOR:");
    printf("ID %i | Nome %s | Preço %.2f",product[indice_menor].id,product[indice_menor].nome,product[indice_menor].preco);
    printf("\nMAIOR: ");
    printf("ID %i | Nome %s | Preço %.2f",product[indice_maior].id,product[indice_maior].nome,product[indice_maior].preco);
}
void ExibirBusca(Produto *product, int total){
    int id_b,indice;
    if (total==0)
    {
    printf("ERRO:TOTAL DE PRODUTO: %i",total);
        return;
    }
    printf("\nDIGITE O ID QUE VOCÊ QUER BUSCAR: ");
    scanf("%i",&id_b);
    indice = buscar(product,total,id_b);
    if (indice==-1)
    {
        printf("ERRO ID %i não encontrado",id_b);
        return;
    }else{
            printf("ID %i | Nome %s | Preço %.2f",product[indice].id,product[indice].nome,product[indice].preco);
    }
    
}
void AlterarProdutoPreco(Produto *product,int total){
    int id_b,indice;
    float preco;
    if (total==0)
    {
    printf("ERRO:TOTAL DE PRODUTO: %i",total);
        return;
    }
    printf("\nDIGITE O ID QUE VOCÊ QUER ALTERAR: ");
    scanf("%i",&id_b);
    indice = buscar(product,total,id_b);
    if (indice==-1)
    {
        printf("ERRO ID %i não encontrado",id_b);
        return;
    }else{
            do
        {
            printf("\nDIGITE O PRECO DO PRODUTO:");
            scanf("%f",&preco);
            if (preco > 0)
            {
                product[indice].preco = preco;
                printf("\nVALOR ALTERADO.");
            }else{
                printf("\nVALOR INVALIDO TENTE NOVAMENTE");
            }
        } while (preco < 0);
    }
}

//=================MAIN E MENU==============
int menu (){
    int opcao;
    printf("\nPROGRAMA PRODUTO INICIADO\n");
    printf("1 - CADASTRAR PRODUTO\n");
    printf("2 - LISTAR PRODUTO\n");
    printf("3 - BUSCAR PRODUTO\n");
    printf("4 - ALTERAR PRODUTO\n");
    printf("0 - SAIR\n");
    printf("DIGITE A OPCAO DESEJADA: ");
    scanf("%i",&opcao);
    return opcao;
}
int main(){
    int escolha, totalproduto = 0;
    Produto product[100];

    do
    {
        escolha = menu();
        switch (escolha)
        {
        case 1:
            CadastrarProduto(product,&totalproduto);
            break;
        case 2:
            ListaProduto(product,totalproduto);
            break;
        case 3:
            ExibirBusca(product,totalproduto);
            break;
        case 4:
            AlterarProdutoPreco(product,totalproduto);
            break;
        case 0:
            printf ("\nSAINDO....\n");
            break;
        default:
            printf("ERRO INSIRA UM VALOR VALIDO.");
            break;
        }
    } while (escolha!=0);
    
}