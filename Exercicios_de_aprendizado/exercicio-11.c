#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//===============ESTRUTURAS=================
typedef struct {
    int id;
    char titulo[50];
    float nota;   // 0 a 10
    int assistido; // 0 = não | 1 = sim
} Filme;
//=========PROTOTIPO FUNÇÕES========
int BuscarFilme(Filme *movie, int totalfilmes, int id);
void AtualizarNota(Filme *movie, int totalfilmes, int indice_conhecido);
void MarcaLido(Filme *movie, int totalfilmes);

//===============FUNÇÕES=================
int BuscarFilme(Filme *movie,int totalfilmes,int id){
    for (int i = 0; i < totalfilmes; i++)
    {
        if (movie[i].id == id)
        {
            return i;
        }
        
    }
    return -1;
}
//SEM CALCULO
void CadastrarFilmme(Filme *movie,int *totalfilmes){
    int n_filmes=0,id_f,assistido;
    float nota = 0;
    printf("\n=====CADASTRO INICIADO=====\n");
    do
    {
        printf("\nDIGITE A QUANTIADADE DE FILMES A SEREM CADASTRADOS: ");
        scanf("%i",&n_filmes);
        if (n_filmes<=0)
        {
            printf("\nERRO: VALOR INVALIDO, TENTE NOVAMENTE.");
        }
        
    } while (n_filmes<=0);
    for (int i = 0; i < n_filmes; i++)
    {  
        int encontrado = 0;
        while (!encontrado)
        {   
            printf("\nDIGITE O ID DO FILME: ");
            scanf("%i",&id_f);
            if (BuscarFilme(movie,*totalfilmes,id_f) == -1)
            {
                encontrado = 1;
            }else{
                printf("ERRO: ID %i JÁ CADASTRADO",id_f);
            }
        }
         movie[*totalfilmes].id = id_f;
    printf("\nDIGITE O TITULO DO FILME: ");
    getchar();
    fgets(movie[*totalfilmes].titulo,sizeof(movie[*totalfilmes].titulo),stdin);
    movie[*totalfilmes].titulo[strcspn(movie[*totalfilmes].titulo, "\n")] = '\0';
    do {
        printf("\nO FILME FOI ASSISTIDO: (0 = nao | 1 = sim): ");
        scanf("%d", &assistido);

        // Se o número for diferente de 0 E diferente de 1, dá erro.
        if (assistido != 0 && assistido != 1) {
            printf("ERRO: Valor invalido. Tente novamente com 1 ou 0.\n");
        }
    } while (assistido != 0 && assistido != 1);
    movie[*totalfilmes].assistido = assistido;
    if (assistido == 1)
    {
       do {
                printf("DIGITE A NOTA DO FILME (0 a 10): ");
                scanf("%f", &nota);    
                if (nota < 0 || nota > 10) {
                    printf("ERRO: VALOR INVALIDO, TENTE NOVAMENTE.\n");
                }
            } while (nota < 0 || nota > 10);
            
            movie[*totalfilmes].nota = nota;
    }else{
        movie[*totalfilmes].nota = 0;
    }
    (*totalfilmes)++;
    }
   
    printf("\n======CADASTRO FINALIZADO=====\n");
}
void ListarFilmes(Filme *movie,int totalfilmes){
    if (totalfilmes == 0)
    {
        printf("\nERRO: NÃO HÁ FILMES CADASTRADOS.\n");
        return;
    }
    printf("\n====LISTA INICIADA====\n");
    for (int i = 0; i < totalfilmes; i++)
    {
        printf("\nID: %i |",movie[i].id);
        printf(" TITULO: %s |",movie[i].titulo);
        if (movie[i].assistido == 1)
        {
            printf(" ASSISTIDO: [X] |");
            printf("NOTA: %.2f",movie[i].nota);
        }else{
            printf(" ASSISTIDO: [ ] |");
            printf("NOTA: Ñ HÁ AINDA ");
        }
    }
    printf("\n====LISTA FINALIZADA====\n");
}
void exibirbuscafilme(Filme *movie,int totalfilmes){
    int id_b, indice;
    if (totalfilmes == 0)
    {
        printf("\nERRO: NÃO HÁ FILMES CADASTRADOS.\n");
        return;
    }
    printf("\n=====BUSCA INICIADA======\n");
    printf("\nDIGITE O ID QUE VOCÊ QUER BUSCAR: ");
    scanf("%i",&id_b);
    indice = BuscarFilme(movie,totalfilmes,id_b);
    if (indice == -1)
    {
        printf("\nERRO:ID Ñ ENCONTRADO.");
        return;
    }else{
        printf("ID: %i |",movie[indice].id);
        printf(" TITULO: %s |",movie[indice].titulo);
        if (movie[indice].assistido == 1)
        {
            printf(" ASSISTIDO: [X] |");
            printf("NOTA: %.2f",movie[indice].nota);
        }else{
            printf(" ASSISTIDO: [ ] |");
            printf("NOTA: Ñ HÁ AINDA");
        }
    }
    printf("\n=====BUSCA FINALIZADA======\n");
}
void MarcaLido(Filme *movie, int totalfilmes){
    int id_f,indice;
    char pergunta;
    if (totalfilmes == 0)
    {
        printf("\nERRO: NÃO HÁ FILMES CADASTRADOS.\n");
        return;
    }
    printf("\n====MARCA COMO LIDO VISTO====\n");
    printf("\nDIGITE O ID QUE VOCÊ QUER BUSCAR: ");
    scanf("%i",&id_f);
    indice = BuscarFilme(movie,totalfilmes,id_f);
       if (indice == -1)
    {
        printf("\nERRO:ID Ñ ENCONTRADO.");
        return;
    }else{
        if (movie[indice].assistido == 1)
        {
            printf("\nERRO: FILME JA ASSISTIDO");
        }else{
            movie[indice].assistido = 1;
            printf("\nFILME ATUALIZADO COM SUCESSO");
            printf("\nDESEJA ATUALIZAR A NOTA ? (S / N)");
            scanf(" %c", &pergunta);
            if (pergunta == 'S' || pergunta == 's')
            {
                AtualizarNota(movie, totalfilmes, indice);            
            }else if (pergunta == 'n' || pergunta == 'N'){
                printf("\nSAINDO...\n");
                return;
            }
            
        }
        
    }
}
void AtualizarNota(Filme *movie,int totalfilmes, int indice_conhecido){
    int id_f, indice;
    if (totalfilmes == 0)
    {
        printf("\nERRO: NÃO HÁ FILMES CADASTRADOS.\n");
        return;
    }
    printf("\n=====ATUALIZAR NOTA======\n");

    if (indice_conhecido != -1) {
        indice = indice_conhecido;
    } else {
        printf("DIGITE O ID QUE VOCÊ QUER BUSCAR: ");
        scanf("%i", &id_f);
        indice = BuscarFilme(movie, totalfilmes, id_f);
    }
    if (indice == -1)
    {
        printf("\nERRO:ID Ñ ENCONTRADO.");
        return;
    }else{
        if (movie[indice].assistido == 0)
        {
            printf("ERRO: ASSISTA O FILME PRIMEIO.");
            return;
        }else{
            printf("\n---FILME ENCONTRADO---\n");
            printf("ID: %i | TITULO: %s | NOTA ATUAL: %.2f",movie[indice].id , movie[indice].titulo,movie[indice].nota);
            printf("\nDIGITE A NOVA NOTA: ");
            scanf("%f",&movie[indice].nota);
            printf("\n===NOTA ATUALIADA COM SUCESSO===\n");
        }
        
    }
}
//---Salvar e Carregar
void salvarArquivo(Filme *movie, int total) {
    FILE *arquivo;
    char resposta;

    arquivo = fopen("backup-11.dat", "rb");

    if (arquivo != NULL) {
        fclose(arquivo);
        printf("\nO arquivo 'backup-11.dat' ja existe. Deseja sobrescrever? (S/N): ");
        scanf(" %c", &resposta);

        if (resposta == 'N' || resposta == 'n') {
            printf("\nSalvamento cancelado.\n");
            return;
        }
    }

    arquivo = fopen("backup-11.dat", "wb");

    if (arquivo == NULL) {
        printf("\nErro ao criar arquivo!\n");
        return;
    }
    fwrite(&total, sizeof(int), 1, arquivo);
    if (total > 0) {
        fwrite(movie, sizeof(Filme), total, arquivo);
    }
    fclose(arquivo);

    printf("\n--- Dados salvos com sucesso! ---\n");
}

void carregarArquivo(Filme *movie, int *total) {
    
    FILE *arquivo = fopen("backup-11.dat", "rb");

    if (arquivo == NULL) {
        printf("\nNenhum arquivo encontrado ou erro ao ler (backup11.dat).\n");
        return; 
    }

    fread(total, sizeof(int), 1, arquivo);

    if (*total > 0) {
        fread(movie, sizeof(Filme), *total, arquivo);
    }    
    fclose(arquivo);
    printf("\n--- %d Arquivo carregado com sucesso! ---\n", *total);
}




//===============MAIN E MENU=================
int menu(){
    int opcao;
    printf("\nMENU PROGRAMA FILMES\n");
    printf("\n1 - Cadastrar filme\n");
    printf("\n2 - Listar filmes\n");
    printf("\n3 - Buscar filme por ID\n");
    printf("\n4 - Marcar como assistido\n");
    printf("\n5 - Atualizar nota\n");
    printf("\n6 - Salvar filmes\n");
    printf("\n7 - Carregar filmes\n");
    printf("\n0 - Sair\n");
    printf("\nEscolha uma opção: ");
    scanf("%i",&opcao);
    return opcao;
}
int main(){
    int totalfilmems = 0,escolha;
    Filme movie[100];
    do
    {
        escolha = menu();
        switch (escolha)
        {
        case 1:
            CadastrarFilmme(movie,&totalfilmems);
            break;
        case 2:
            ListarFilmes(movie,totalfilmems);
            break;
        case 3:
            exibirbuscafilme(movie,totalfilmems);
            break;
        case 4:
            MarcaLido(movie,totalfilmems);
            break;
        case 5:{
            int indice_conhecido =-1;
            AtualizarNota(movie,totalfilmems,indice_conhecido);
            break;
            }
        case 6:
            salvarArquivo(movie,totalfilmems);
            break;
        case 7:
            carregarArquivo(movie,&totalfilmems);
            break;
        case 0:
            printf("\nSAINDO...");
            break;
        default:
            printf("\nOpção inválida! Tente novamente.\n");
            break;
        }
    } while (escolha !=0);
}