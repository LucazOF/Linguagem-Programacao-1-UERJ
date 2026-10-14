#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//===============ESTRUTURAS=================
typedef struct {
    int id;
    char nome[50];
    float nota1;
    float nota2;
} Aluno;
//=============PROTOTIPO FUNÇÕES==========
int BuscarAluno(Aluno *alunos,int totalalunos , int id);
float MediaAlunos(float n1 , float n2);
//===============FUNÇÕES=================
int BuscarAluno(Aluno *alunos,int totalalunos , int id){
    for (int i = 0; i < totalalunos; i++)
    {
        if (alunos[i].id == id)
        {
            return i;
        }
        
    }
    return -1;
}
float MediaAlunos(float n1 , float n2){
    float me;
    me = (n1 + n2) / 2;
    return me;
}

void CadastrarAlunos(Aluno *alunos,int *totalalunos){
    float n1 = 0 , n2 =0;
    int id_a, qtd_a = 0;

    printf("\n=====CADASTRO INICIADO=====\n");
    do
    {
        printf("\nDIGITE A QUANTIADADE DE ALUNOS A SEREM CADASTRADOS: ");
        scanf("%i",&qtd_a);
        if (qtd_a<=0)
        {
            printf("\nERRO: VALOR INVALIDO, TENTE NOVAMENTE.");
        }
        
    } while (qtd_a<=0);
    for (int i = 0; i < qtd_a; i++)
    {
        int encontrado = 0;
        while (!encontrado)
        {
            printf("\nDigite o ID %i desejado: ",i+1);
            scanf("%d",&id_a);
            if (BuscarAluno(alunos,*totalalunos,id_a)==-1)
            {
                encontrado = 1;
            }else{
                printf("\nERRO:ID %i já utilizado",id_a);
            }
        }
        alunos[*totalalunos].id = id_a;
        printf("\nDigite o nome do aluno: ");
        getchar();
        fgets(alunos[*totalalunos].nome,sizeof(alunos[*totalalunos].nome),stdin);
        alunos[*totalalunos].nome[strcspn(alunos[*totalalunos].nome, "\n")] = '\0';
        do
        {
            printf("\nDigite a primeira nota: ");
            scanf("%f",&n1);
            if (n1<0 || n1 > 10)
            {
                printf("\nERRO: Valor %.2f invalido ",n1);
            }
        }while (n1<0 || n1 > 10);
        do
        {
            printf("\nDigite a segunda nota: ");
            scanf("%f",&n2);
            if (n2<0 || n2 > 10)
            {
                printf("\nERRO: Valor %.2f invalido ",n2);
            }
            
        }while (n2<0 || n2 > 10);
        alunos[*totalalunos].nota1 = n1;
        alunos[*totalalunos].nota2 = n2;
        (*totalalunos)++;
        printf("\nAluno %i cadastrado.",i+1);
    }
    printf("\n----CADASTRO FINALIZADO----\n");

}
void ListarAlunos(Aluno *alunos, int totalalunos){
    float media =0;
    if (totalalunos ==0)
    {
        printf("\nERRO: Não há alunos cadastrados.");
        return;
    }
    for ( int i = 0; i < totalalunos; i++)
    {
        printf("\nID: %i |",alunos[i].id);
        printf(" NOME: %s |",alunos[i].nome);
        printf("NOTA 1: %.2f",alunos[i].nota1);
        printf("| NOTA 2: %.2f",alunos[i].nota2);
        media = MediaAlunos(alunos[i].nota1,alunos[i].nota2);
        printf("| MEDIA: %.2f",media);
        if (media >=7)
        {
            printf("| Situação: Aprovado");
        }else if(media < 7){
            printf("| Situação: Reprovado");
        }        
    }
}
void SearchAluno(Aluno *alunos, int totalalunos){
    int id_a, indice;
    if (totalalunos ==0)
        {
            printf("\nERRO: Não há alunos cadastrados.");
            return;
        }
    printf("Digite o ID desejado: ");
    scanf("%d",&id_a);
    indice = BuscarAluno(alunos,totalalunos,id_a);
    if (indice == -1)
    {
        printf("\nERRO: ID %i não encontrado.",id_a);
        return;
    }
    printf("\nID: %i |",alunos[indice].id);
    printf(" NOME: %s |",alunos[indice].nome);
    printf("NOTA 1: %.2f",alunos[indice].nota1);
    printf("| NOTA 2: %.2f",alunos[indice].nota2);
    printf("| MEDIA: %.2f",MediaAlunos(alunos[indice].nota1,alunos[indice].nota2));
        if (MediaAlunos(alunos[indice].nota1,alunos[indice].nota2) >=7)
        {
            printf("| Situação: Aprovado");
        }else if(MediaAlunos(alunos[indice].nota1,alunos[indice].nota2)< 7){
            printf("| Situação: Reprovado");
        }        
    
}

void Atualizarnotas(Aluno *alunos, int totalalunos){
    int id_a, indice;
    float n1 = 0, n2 =0;
    if (totalalunos ==0)
        {
            printf("\nERRO: Não há alunos cadastrados.");
            return;
        }
    printf("\n====ALTERAR NOTA INICIADO====\n");
    printf("Digite o ID desejado: ");
    scanf("%d",&id_a);
    indice = BuscarAluno(alunos,totalalunos,id_a);
    if (indice == -1)
    {
        printf("\nERRO: ID %i não encontrado.",id_a);
        return;
    }
    do
        {
            printf("\nDigite a primeira nota: ");
            scanf("%f",&n1);
            if (n1<0 || n1 > 10)
            {
                printf("\nERRO: Valor %.2f invalido ",n1);
            }
        }while (n1<0 || n1 > 10);
        do
        {
            printf("\nDigite a segunda nota: ");
            scanf("%f",&n2);
            if (n2<0 || n2 > 10)
            {
                printf("\nERRO: Valor %.2f invalido ",n2);
            }
            
        }while (n2<0 || n2 > 10);
        alunos[indice].nota1 = n1;
        alunos[indice].nota2 = n2;
        printf("\nNOTA ALTERADA COM SUCESSO!\n");
}
// SALVAR E CARREGAR
void Salvar(Aluno *alunos, int total) {
    FILE *arquivo;
    char resposta;

    arquivo = fopen("backup-12.dat", "rb");

    if (arquivo != NULL) {
        fclose(arquivo);
        printf("\nO arquivo 'backup-11.dat' ja existe. Deseja sobrescrever? (S/N): ");
        scanf(" %c", &resposta);

        if (resposta == 'N' || resposta == 'n') {
            printf("\nSalvamento cancelado.\n");
            return;
        }
    }

    arquivo = fopen("backup-12.dat", "wb");

    if (arquivo == NULL) {
        printf("\nErro ao criar arquivo!\n");
        return;
    }
    fwrite(&total, sizeof(int), 1, arquivo);
    if (total > 0) {
        fwrite(alunos, sizeof(Aluno), total, arquivo);
    }
    fclose(arquivo);

    printf("\n--- Dados salvos com sucesso! ---\n");
}

void Carregar(Aluno *alunos, int *total) {
    
    FILE *arquivo = fopen("backup-12.dat", "rb");

    if (arquivo == NULL) {
        printf("\nNenhum arquivo encontrado ou erro ao ler (backup12.dat).\n");
        return; 
    }

    fread(total, sizeof(int), 1, arquivo);

    if (*total > 0) {
        fread(alunos, sizeof(Aluno), *total, arquivo);
    }    
    fclose(arquivo);
    printf("\n--- %d Arquivo carregado com sucesso! ---\n", *total);
}

//===============MAIN E MENU=================
int menu(){
    int opcao;
    printf("\nMENU PROGRAMA ALUNOS\n");
    printf("1 - Cadastrar Aluno\n");
    printf("2 - Listar Alunos\n");
    printf("3 - Buscar Aluno por ID\n");
    printf("4 - Salvar\n");
    printf("5 - Carregar\n");
    printf("6 - Alterar Nota\n");
    printf("0 - Sair\n");
    printf("Escolha uma opção: ");
    scanf("%i",&opcao);
    return opcao;
}
int main(){
    int totalalunos = 0,escolha;
    Aluno alunos[100];
    do
    {
        escolha = menu();
        switch (escolha)
        {
        case 1:
            CadastrarAlunos(alunos,&totalalunos);
            break;
        case 2:
            ListarAlunos(alunos,totalalunos);
            break;
        case 3:
            SearchAluno(alunos,totalalunos);
            break;
        case 4:
            Salvar(alunos,totalalunos);
            break;
        case 5:
            Carregar(alunos,&totalalunos);
            break;
        case 6:
            Atualizarnotas(alunos,totalalunos);
            break;
        case 0:
            printf("\nSAINDO...\n");
            break;
        default:
            printf("\nOpção inválida! Tente novamente.\n");
            break;
        }
    } while (escolha !=0);
}