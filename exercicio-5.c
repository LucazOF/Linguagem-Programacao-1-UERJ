#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char nome[100];
    float salario;
    int ativo;
} Funcionario;

void cadastrarfuncionario(Funcionario *CLT, int *totalfuncionario){
    int nf, id_d;
    printf("Quantos funcionarios serao cadastrados: ");
    scanf("%i", &nf);

    for (int i = 0; i < nf; i++) {
        int encontrado = 0;
        printf("\nQual ID do %i o funcionario: ", i + 1);
        scanf("%i", &id_d);
        for (int j = 0; j < *totalfuncionario; j++) {
            if (CLT[j].id == id_d) {
                encontrado = 1;
                break;
            }
        }
        if (encontrado) {
            printf("Erro: ID %d ja registrado!\n", id_d);
            i--; 
        } else {
            CLT[*totalfuncionario].id = id_d;
            getchar();
            printf("Digite o nome desse funcionario: ");
            fgets(CLT[*totalfuncionario].nome, 100, stdin);
            CLT[*totalfuncionario].nome[strcspn(CLT[*totalfuncionario].nome, "\n")] = 0;
            printf("Digite o salario desse funcionario: ");
            scanf("%f", &CLT[*totalfuncionario].salario);
            CLT[*totalfuncionario].ativo = 1;
            (*totalfuncionario)++;
            printf("Funcionario cadastrado com sucesso.\n");
        }
    }
}

void listafuncionario(Funcionario *CLT, int *totalfuncionario){
    if (0 == *totalfuncionario)
    {
        printf("Nenhum Funcionario Cadastrado ");
        return;
    }
    printf("\n====LISTA FUNCINARIO====\n");
    for (int i = 0; i < *totalfuncionario; i++)
    {
        if (CLT[i].ativo==1)
        {
            printf("%i - ID: %i", i+1 , CLT[i].id);
            printf("| Nome: %s",CLT[i].nome);
            printf("| Salario: R$%.2f",CLT[i].salario);
            printf("\n");
        }
        
        
    }
}

void buscarfuncionario(Funcionario * CLT, int *totalfuncionario){
    int id_b;
    int encontrado = 0;
    if (0 == *totalfuncionario)
    {
        printf("Nenhum Funcionario Cadastrado ");
        return;
    }
    printf("Digite o ID que você quer buscar: ");
    scanf("%i",&id_b);
    for (int i = 0; i < *totalfuncionario; i++)
    {
        if (CLT[i].id == id_b && CLT[i].ativo == 1)
        {
                encontrado = 1;
                printf("\n---Funcionario Encontrado---\n");
                printf("ID: %i",CLT[i].id);
                printf("| Nome: %s",CLT[i].nome);
                printf("| Salario: R$%.2f",CLT[i].salario);
                printf("\n");
                printf("\n---------------\n");
                break;
        }
    }
    if (!encontrado){
        printf("Funcionario não encotrado");
    }
}

void aumentarsalario(Funcionario *CLT,int *totalfuncionario){
    int id_b;
    int encontrado = 0;   
    float percent;
    if (0 == *totalfuncionario)
    {
        printf("Nenhum Funcionario Cadastrado ");
        return;
    }
    printf("Digite o ID que você quer aumentar: ");
    scanf("%i",&id_b);
    for (int i = 0; i < *totalfuncionario; i++)
    {
        if (CLT[i].id == id_b && CLT[i].ativo == 1)
        {
            encontrado = 1;
            printf("Digite o percentual de aumento: ");
            scanf("%f",&percent);
            CLT[i].salario += CLT[i].salario * (percent/100.0);

            printf("\n---Informação atualizada---\n");
            printf("ID: %i",CLT[i].id);
            printf("| Nome: %s",CLT[i].nome);
            printf("| Salario: R$%.2f",CLT[i].salario);
            printf("\n");
            printf("\n---------------\n");
            break;
        }
    }
    if (!encontrado){
        printf("Funcionario não encotrado");
    }
}
void removerFuncionario(Funcionario CLT[], int *total) {
    int idBusca, i;
    printf("Digite o ID para remover: ");
    scanf("%d", &idBusca);

    for (i = 0; i < *total; i++) {
        if (CLT[i].id == idBusca && CLT[i].ativo == 1) {
            CLT[i].ativo = 0; // "Apaga" sem mover nada de lugar
            printf("Funcionario removido com sucesso!\n");
            return;
        }
    }
    printf("Funcionario nao encontrado ou ja excluido.\n");
}

int menu() {
    int opcao;

    printf("\n--- MENU PRINCIPAL ---\n");
    printf("1. Cadastrar funcionario\n");
    printf("2. Listar funcionarios\n");
    printf("3. Buscar funcionario por ID\n");
    printf("4. Aumentar salário\n");
    printf("5. Remover funcionario\n");
    printf("0. Sair\n");
    printf("Escolha uma opcao: ");
    
    scanf("%d", &opcao);

    return opcao; // Envia o valor de volta para quem chamou
}

int main (){
    Funcionario CLT [100];
    int escolha, totalfuncionario = 0;
    do
    {
        escolha = menu();
        switch (escolha)
        {
        case 1:
            cadastrarfuncionario(CLT,&totalfuncionario);
            break;
        
        case 2:
            listafuncionario(CLT,&totalfuncionario);
            break;
        case 3:
            buscarfuncionario(CLT,&totalfuncionario);
            break;
        case 4:
            aumentarsalario(CLT,&totalfuncionario);
            break;
        case 5:
            removerFuncionario(CLT,&totalfuncionario);
            break;
        }
        
    } while (escolha != 0);
    




}