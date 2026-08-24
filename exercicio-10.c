#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ================= ESTRUTURAS =================
typedef struct {
    int id;
    char descricao[100];
    int concluida; // 0 = não | 1 = sim
} Tarefa;
// ================= Funções =================
//CALCULOS
int BuscarTarefa(Tarefa *task,int totaltarefa, int id_busca){
    for (int  i = 0; i < totaltarefa; i++)
    {
        if (task[i].id == id_busca)
        {
            return i;
        }
        
    }
    return -1;
}


//REGISTROS E PRINTS
void CadastrarTarefa(Tarefa *task, int *totaltarefa){
    int n_cadastro =0,id_b,situacao;
    printf("\n===CADASTRO INICIADO====\n");
    while (n_cadastro <=0)
    {
        printf("\nDigite a quantiade de cadastro a serem realizados: ");
        scanf("%i",&n_cadastro);
        if (n_cadastro <=0)
        {
            printf("Valor invalido tente novamente.\n");
        }    
    }
    
    for (int i = 0; i < n_cadastro; i++)
    {
        int encontrado =0;
        while (!encontrado)
        {
            printf("\nDigite o ID do %i: ",i+1);
            scanf("%i",&id_b);
            if (BuscarTarefa(task,*totaltarefa,id_b)==-1)
            {
                encontrado = 1;
            }else{
                printf("Erro: O ID %i já existe. Escolha outro!\n", id_b);
            }
        }
        task[*totaltarefa].id = id_b;
        printf("\nDigite a descrição: ");
        getchar(); 
        // 1. Executa a leitura diretamente
        fgets(task[*totaltarefa].descricao, sizeof(task[*totaltarefa].descricao), stdin);
        // 2. Limpa o '\n' logo em seguida
        task[*totaltarefa].descricao[strcspn(task[*totaltarefa].descricao, "\n")] = '\0';
        do {
        printf("\nA Tarefa foi concluida? (0 = nao | 1 = sim): ");
        scanf("%d", &situacao);

        // Se o número for diferente de 0 E diferente de 1, dá erro.
        if (situacao != 0 && situacao != 1) {
            printf("ERRO: Valor invalido. Tente novamente com 1 ou 0.\n");
        }
        
    
        } while (situacao != 0 && situacao != 1);
        task[*totaltarefa].concluida = situacao;
        (*totaltarefa)++;
        printf("\nCADASTRO %i° CONCLUIDO\n",i+1);
    }
    printf("\nTODOS OS CADASTROS TERMINARAM\n");
}

void ListarTarefas(Tarefa *task,int totaltarefas){
    if (totaltarefas ==0)
    {
        printf("\nERRO:Não há tarefas registradas.");
        return;
    }
    printf("\n=====LISTA INICIADA=====\n");
    for (int i = 0; i < totaltarefas; i++)
    {
        printf("ID: %i | ",task[i].id);
        printf("DESCRIÇÃO: %s | ",task[i].descricao);
        if (task[i].concluida == 1)
        {
            printf("CONCLUIDA:[X]\n");
            printf("\n==================\n");
        }else if (task[i].concluida==0){
            printf("CONCLUIDA:[ ]\n");
            printf("\n==================\n");
        }
        
    }
    
}

void  MarcaComo(Tarefa *task, int totaltarefa){
    int id_b,indice;
    if (totaltarefa ==0)
    {
        printf("\nNão há tarefas na lista.");
        return;
    }
    printf("===MARCA COMO INICIADO===");
    printf("\nDigite o ID que você quer marca com concluida: ");
    scanf("%i",&id_b);
    indice = BuscarTarefa(task,totaltarefa,id_b);
    if (indice ==-1)
    {
        printf("ERRO:ID não encontrado.\n");
        return;
    }else{
        if (task[indice].concluida == 0)
        {
            task[indice].concluida = 1;
            printf("Tarefa Marcada como concluida.\n");
            return;
        }else if (task[indice].concluida ==1){
            printf("Tarefa já está concluida.");
        }
    }
    
}
void BuscarTask_semlogica(Tarefa *task,int totaltarefas){
    int id_b,indice;
    if(totaltarefas ==0){
        printf("Não há tarefas cadastradas");
        return;
    }
    printf("Digite o ID da Tarefa");
    scanf("%i",&id_b);
    indice = BuscarTarefa(task,totaltarefas,id_b);
    if (indice ==-1)
    {
        printf("ERRO:ID não encontrado.\n");
        return;
    }else{
        printf("ID: %i | ",task[indice].id);
        printf("DESCRIÇÃO: %s | ",task[indice].descricao);
        if (task[indice].concluida == 1)
        {
            printf("CONCLUIDA:[X]\n");
            printf("\n==================\n");
        }else if (task[indice].concluida==0){
            printf("CONCLUIDA:[ ]\n");
            printf("\n==================\n");
        }
    }
    
}
//====MANIPUALAÇÃO DE ARQUIVOS=======
void salvarArquivo(Tarefa *task, int totaltarefas) {
    FILE *arquivo;
    char resposta;

    arquivo = fopen("backup-10.dat", "rb");

    if (arquivo != NULL) {
        fclose(arquivo);
        printf("\nO arquivo 'backup-10.dat' ja existe. Deseja sobrescrever? (S/N): ");
        scanf(" %c", &resposta);

        if (resposta == 'N' || resposta == 'n') {
            printf("\nSalvamento cancelado.\n");
            return;
        }
    }

    arquivo = fopen("backup-10.dat", "wb");

    if (arquivo == NULL) {
        printf("\nErro ao criar arquivo!\n");
        return;
    }
    fwrite(&totaltarefas, sizeof(int), 1, arquivo);
    if (totaltarefas > 0) {
        fwrite(task, sizeof(Tarefa), totaltarefas, arquivo);
    }
    fclose(arquivo);

    printf("\n--- Dados salvos com sucesso! ---\n");
}

void carregarArquivo(Tarefa *task, int *totaltarefas) {
    
    FILE *arquivo = fopen("backup-10.dat", "rb");

    if (arquivo == NULL) {
        printf("\nNenhum arquivo encontrado ou erro ao ler (backup.dat).\n");
        return; 
    }

    fread(totaltarefas, sizeof(int), 1, arquivo);

    if (*totaltarefas > 0) {
        fread(task, sizeof(Tarefa), *totaltarefas, arquivo);
    }    
    fclose(arquivo);
    printf("\n--- %d Arquivo carregado com sucesso! ---\n", *totaltarefas);
}






// ================= Menu/Main =================
int menu(){
    int escolha;
    printf("\n1 - Cadastrar tarefa\n");
    printf("2 - Listar tarefas\n");
    printf("3 - Marcar tarefa como concluída\n");
    printf("4 - Buscar tarefa por ID\n");
    printf("5 - Salvar\n");
    printf("6 - Carregar\n");
    printf("0 - Sair\n");
    printf("\nEscolha uma opção: ");
    scanf("%i",&escolha);
    return escolha;
}

int main (){
    Tarefa task[100];
    int opcao,totaltarefa = 0;
    do
    {
        opcao = menu();

        switch (opcao)
        {
        case 1:
            CadastrarTarefa(task,&totaltarefa);
            break;
        case 2:
            ListarTarefas(task,totaltarefa);
            break;
        case 3:
            MarcaComo(task,totaltarefa);
            break;
        case 4:
            BuscarTask_semlogica(task,totaltarefa);
            break;
        case 5:
            salvarArquivo(task,totaltarefa);
            break;
        case 6:
            carregarArquivo(task,&totaltarefa);
            break;
        case 0:
            printf("\nPrograma Finalizando...");
            break;
        default:
             printf("\nOpção inválida! Tente novamente.\n");
            break;
        }
    } while (opcao != 0);
    


}


