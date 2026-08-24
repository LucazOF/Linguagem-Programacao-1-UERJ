#include <stdio.h>
#include <stdlib.h>

typedef struct No
{
    int numero;
    struct No *proximo;
} No;

typedef struct
{
    No *inicio;
} Lista;


void libera(Lista *li){
    if (li != NULL)
    {
        No* atual;
        while (li->inicio != NULL)
        {
            atual = li->inicio;
            li ->inicio = li ->inicio->proximo;
            free(atual);
        }
    }
}

void insert(Lista *lista, int posicao, int num)
{
    No *novo = malloc(sizeof(No));

    novo->numero = num;

    if (posicao == 0)
    {
        novo->proximo = lista->inicio;
        lista->inicio = novo;
        return;
    }

    No *atual = lista->inicio;

    for (int i = 0; i < posicao - 1; i++)
    {
        atual = atual->proximo;
    }

    novo->proximo = atual->proximo;
    atual->proximo = novo;
}


void imprime(const Lista *lista)
{
    No *atual = lista->inicio;

    while (atual != NULL)
    {
        printf("%d\n", atual->numero);
        atual = atual->proximo;
    }
}


int len(const Lista *lista)
{
    int contador = 0;
    No *atual = lista->inicio;

    while (atual != NULL)
    {
        contador++;
        atual = atual->proximo;
    }

    return contador;
}


int menu()
{
    int opcao;

    printf("\n=====");
    printf("\n MENU");
    printf("\n=====");
    printf("\n1- Adicionar o numero na lista.");
    printf("\n2- ");
    printf("\n3- Imprimir.");
    printf("\n3- Liberar Memoria");
    printf("\n0- Sair.");
    printf("\nEscolha: ");

    scanf("%d", &opcao);

    return opcao;
}


int main()
{
    int escolha;

    Lista lista;
    lista.inicio = NULL;

    do
    {
        escolha = menu();

        switch (escolha)
        {
        case 1:
        {
            int posicao, num;

            printf("\nQual e a posicao que voce quer adicionar o elemento: ");
            scanf("%d", &posicao);

            printf("\nQual numero voce quer adicionar: ");
            scanf("%d", &num);

            insert(&lista, posicao, num);

            break;
        }

        case 3:
            imprime(&lista);
            break;
        case 4:
        libera(&lista);
        break;
        }
        
    } while (escolha != 0);

    return 0;
}