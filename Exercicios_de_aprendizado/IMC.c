#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//======Estruturas=====

typedef struct 
{
    int matricula;
    float peso;
    float altura;
    char nome[100];
    float imc;
}Pessoa;
//FUNCOES;

float IndiceMassaCorporal(float altura,float peso){
    return peso/(altura*altura);
}

int SearchPessoa(Pessoa *pessoas,int totalpessoa,int mat_b){
    for (int i = 0; i < totalpessoa; i++)
    {
        if (pessoas[i].matricula == mat_b)
        {
            return i;
        }
    
    }
    return -1;
}

const char* obeterClassificaoIMC(float imc){
    if (imc < 18.5) {
        return "Abaixo do peso (Magro)";
    }
    if (imc < 25.0) { 
        return "Peso ideal";
    } 
    if (imc < 30.0) {
        return "Sobrepeso";
    } 
    if (imc < 35.0) {
        return "Obesidade Grau I";
    } 
    if (imc < 40.0) {
        return "Obesidade Grau II";
    } 
    return "Obesidade Grau III (Grave)";
}

void BuscarPessoa(Pessoa *pessoas,int totalpessoa){
    if (totalpessoa == 0){
        printf("\nErro não pessoas cadastradas ");
    }
    int mat_b;
    int indice;
    printf("\nBUSCA INICIADA\n");
    printf("\nDigite a Matricula da pessoa: ");
    scanf("%i",&mat_b);
    indice = SearchPessoa(pessoas,totalpessoa,mat_b);
    if (indice == -1)
    {
        printf ("\nErro! Não foi encontrado no sitema a matricula");
        return;
    }else{
           printf("Matricula: %i | Nome: %s | Peso %.2f | Altura %.2f | IMC %.2f | Classficação: %s \n",pessoas[indice].matricula,pessoas[indice].nome,pessoas[indice].peso,pessoas[indice].altura,pessoas[indice].imc,obeterClassificaoIMC(pessoas[indice].imc));   
    }
    

}
void CadastroPessoa(Pessoa *pessoas,int *totalpessoa){
    int mat_b, qntd;
    printf("\n===CADASTRO PESSOAS INICIADO===\n");
    printf("\n Digite a quantidade de pessoas a serem cadastradas: ");
    scanf("%i",&qntd);
    for (int i = 0; i < qntd; i++)
    {
        int encontrado =0;
        while (!encontrado)
        {
            printf("\nDigite a matricula: ");
            scanf("%i",&mat_b);
            if (SearchPessoa(pessoas,*totalpessoa,mat_b)==-1)
            {
                encontrado = 1;
            }else{
                printf("\nERRO! MATRICULA %i , JA CADASTRADA ",mat_b);
            }
        }
            pessoas[*totalpessoa].matricula = mat_b;
            printf("\nDIGITE O NOME: ");
            getchar();
            fgets(pessoas[*totalpessoa].nome,sizeof(pessoas[*totalpessoa].nome),stdin);
            pessoas[*totalpessoa].nome[strcspn(pessoas[*totalpessoa].nome, "\n")] = '\0';
            do
            {
               printf("Digite a altura: (Metros)");
               if (scanf("%f",&pessoas[*totalpessoa].altura) != 1)
               {
                    printf("Entrada inválida. Digite um número.\n");
                    while (getchar() != '\n'); 
                    pessoas[*totalpessoa].altura = -1; // Força a repetição
               }else if (pessoas[*totalpessoa].altura <= 0){
                    printf("A altura deve ser maior que zero.\n");
               }
            } while (pessoas[*totalpessoa].altura <= 0 );
            do
            {
               printf("Digite a peso: (Kg)");
                if (scanf("%f", &pessoas[*totalpessoa].peso) != 1)               {
                    printf("Entrada inválida. Digite um número.\n");
                    while (getchar() != '\n'); 
                    pessoas[*totalpessoa].peso = -1; // Força a repetição
               }else if (pessoas[*totalpessoa].peso <= 0){
                    printf("A altura deve ser maior que zero.\n");
               }
            } while (pessoas[*totalpessoa].peso <= 0 );
        
        pessoas[*totalpessoa].imc = IndiceMassaCorporal(pessoas[*totalpessoa].altura,pessoas[*totalpessoa].peso);
        (*totalpessoa)++;
        printf("\nCadastro Realizado com Sucesso.");
    }
}
void ListarPessoas(Pessoa *pessoas, int total){
    if(total == 0){
        printf("\n Não pessoas cadastradas. ");
        return;
    }
    printf("\n===Lista Iniciada===\n");
    for (int i = 0; i < total; i++)
    {
        printf("Matricula: %i | Nome: %s | Peso %.2f | Altura %.2f | IMC %.2f | Classficação: %s \n",pessoas[i].matricula,pessoas[i].nome,pessoas[i].peso,pessoas[i].altura,pessoas[i].imc,obeterClassificaoIMC(pessoas[i].imc));   
    }
    
}


// MAIN e MENU
int menu(){
    int opcao;
    printf("\n===MENU===\n");
    printf("\n1- Cadastrar Pessoa");
    printf("\n2- Buscar Pessoa");
    printf("\n3- Listar pessoas");
    printf("\n0- Sair");
    printf("\nDigite a opção desejada: ");
    scanf("%i",&opcao);
    return opcao;
}
int main(){
    int totalpessoa = 0,escolha;
    Pessoa pessoas [100];
    do
    {
        escolha = menu();
        switch (escolha)
        {
        case 1:
            CadastroPessoa(pessoas,&totalpessoa);
            break;
        case 2:
            BuscarPessoa(pessoas,totalpessoa);
            break;
        case 3:
            ListarPessoas(pessoas,totalpessoa);
            break;
        case 0:
            printf("\nSaindo...");
            break;
        default:
            printf("\nValor Invalido");
            break;
        }
    } while (escolha != 0);
    
}