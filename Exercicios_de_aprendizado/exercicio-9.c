#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ================= ESTRUTURAS =================
typedef struct {
    int id;
    char nome[50];
} Produto;

typedef struct {
    int id;
    int idProduto;
    int quantidade;
    char tipo; // 'E' = entrada | 'S' = saída
} Movimentacao;

// ================= FUNÇÕES DE BUSCA E CÁLCULO =================
int buscarproduto(Produto *produ, int totalprodu, int id) {
    for (int i = 0; i < totalprodu; i++) {
        if (produ[i].id == id) {
            return i; // Retorna o índice no array
        }
    }
    return -1; // Não encontrou
}

int buscarmovi(Movimentacao *movi, int totalmovi, int id) {
    for (int i = 0; i < totalmovi; i++) {
        if (movi[i].id == id) {
            return i;
        }
    }
    return -1;
}

int calcularEstoqueAtual(Movimentacao *movi, int totalmovi, int id_p) {
    int saldo = 0;
    for (int i = 0; i < totalmovi; i++) {
        if (movi[i].idProduto == id_p) {
            if (movi[i].tipo == 'E' || movi[i].tipo == 'e') {
                saldo += movi[i].quantidade;
            } else if (movi[i].tipo == 'S' || movi[i].tipo == 's') {
                saldo -= movi[i].quantidade;
            }
        }
    }
    return saldo;
}

// ================= FUNÇÕES DE CADASTRO E LISTAGEM =================
void cadastroproduto(Produto *produ, int *totalprodu) {
    int nproduto = 0, idprod;
    printf("\nDigite quantos produtos serão cadastrados: ");
    scanf("%d", &nproduto);
    
    for (int i = 0; i < nproduto; i++) {
        int encontrado = 0;
        while (!encontrado) {
            printf("\nDigite o ID do %i° produto: ", i + 1);
            scanf("%i", &idprod);
            if (buscarproduto(produ, *totalprodu, idprod) == -1) {
                encontrado = 1;
            } else {
                printf("Erro: O ID %i já existe. Escolha outro!\n", idprod);
            }
        }
        
        produ[*totalprodu].id = idprod;
        printf("Digite o nome do produto: ");
        getchar(); // Limpa o buffer
        fgets(produ[*totalprodu].nome, 50, stdin);
        produ[*totalprodu].nome[strcspn(produ[*totalprodu].nome, "\n")] = '\0'; // Tira o \n do final
        
        (*totalprodu)++;
        printf("--- Produto %i° Cadastrado com Sucesso ---\n", i + 1);
    }
}

void cadastromovi(Movimentacao *movi, Produto *produ, int *totalmovi, int *totalpro) {
    int qntd_m = 0, id_m, id_p;
    
    while (qntd_m <= 0) {
        printf("\nDigite a quantidade de movimentações que deseja registrar: ");
        scanf("%i", &qntd_m);
        if (qntd_m <= 0) {
            printf("ERRO: Digite um valor válido.\n");
        }
    }
    
    for (int i = 0; i < qntd_m; i++) {
        // Validação do ID da Movimentação
        int id_valido = 0;
        while (!id_valido) {
            printf("\nDigite o ID da %iª movimentação: ", i + 1);
            scanf("%i", &id_m);
            if (buscarmovi(movi, *totalmovi, id_m) == -1) {
                id_valido = 1;
            } else {
                printf("ERRO: ID já cadastrado.\n");
            }
        }
        
        int indice_p = -1;
        while (indice_p == -1) {
            printf("Digite o ID do produto que será movimentado: ");
            scanf("%i", &id_p);
            indice_p = buscarproduto(produ, *totalpro, id_p);
            if (indice_p == -1) {
                printf("ERRO: Produto ID %i não encontrado no sistema.\n", id_p);
            }
        }
        
        // Preenche os IDs na movimentação nova
        movi[*totalmovi].id = id_m;
        movi[*totalmovi].idProduto = id_p;
        
        char tipom;
        int qntd = 0;
        printf("Tipo de movimentação ('E' = entrada | 'S' = saída): ");
        scanf(" %c", &tipom); 
        
        if (tipom == 'E' || tipom == 'e') {
            printf("Digite o valor da entrada: ");
            scanf("%i", &qntd);
            
            movi[*totalmovi].tipo = 'E';
            movi[*totalmovi].quantidade = qntd;
            (*totalmovi)++;
            printf("Entrada registrada com sucesso!\n");
            
        } else if (tipom == 'S' || tipom == 's') {
            int estoqueDisponivel = calcularEstoqueAtual(movi, *totalmovi, id_p);
            
            if (estoqueDisponivel <= 0) {
                printf("ERRO: Operação cancelada. Produto sem estoque para saída (Saldo: 0).\n");
            } else {
                int saida_valida = 0;
                while (!saida_valida) {
                    printf("Digite o valor da saída (Estoque Disponível: %i): ", estoqueDisponivel);
                    scanf("%i", &qntd);
                    
                    if (qntd > estoqueDisponivel) {
                        printf("ERRO: Estoque insuficiente para essa saída!\n");
                    } else if (qntd <= 0) {
                        printf("ERRO: Digite um valor maior que zero.\n");
                    } else {
                        movi[*totalmovi].tipo = 'S';
                        movi[*totalmovi].quantidade = qntd;
                        (*totalmovi)++;
                        saida_valida = 1;
                        printf("Saída registrada com sucesso!\n");
                    }
                }
            }
        } else {
            printf("ERRO: Tipo de movimentação inválido. Operação ignorada.\n");
        }
    }
}

void listarprodu(Produto *produ, int totalpro) {
    if (totalpro == 0) {
        printf("\nNenhum produto cadastrado no momento.\n");
        return;
    }
    
    printf("\n--- LISTA DE PRODUTOS ---\n");
    for (int i = 0; i < totalpro; i++) {
        printf("ID: %i | NOME: %s\n", produ[i].id, produ[i].nome);
    }
    printf("-------------------------\n");
}
void listarmovimentacao(Movimentacao *movi, Produto *produ, int totalmovi, int totalpro){
    if (totalmovi ==0 || totalpro == 0){
        printf("Não há produtos no estoque.");
        return;
    }
    printf("\n---Lista Movimentação---\n");
    for (int i = 0; i < totalmovi; i++)
    {
        int id_buscado = movi[i].idProduto;
        int indice_p = buscarproduto(produ, totalpro, id_buscado);
        printf("\nNome: %s",produ[indice_p].nome);
        printf("ID MOVIMENTACAO: %i| ",movi[i].id);
        printf("ID Produto: %i| ",movi[i].idProduto);
        printf("Tipo: %c",movi[i].tipo);
        
    }
    
}
void listarEstoqueAtual(Produto *produ, int totalpro, Movimentacao *movi, int totalmovi) {
    if (totalpro == 0) {
        printf("\nNenhum produto cadastrado para verificar estoque.\n");
        return;
    }

    printf("\n--- RELATÓRIO DE ESTOQUE ATUAL ---\n");
    printf("%-5s | %-20s | %-10s\n", "ID", "NOME", "SALDO");
    printf("--------------------------------------------\n");

    for (int i = 0; i < totalpro; i++) {
        int saldo = calcularEstoqueAtual(movi, totalmovi, produ[i].id);
        printf("%-5d | %-20s | %-10d\n", produ[i].id, produ[i].nome, saldo);
    }
    printf("--------------------------------------------\n");
}

// ================= MENU E MAIN =================
int menu() {
    int escolha;
    printf("\n----- MENU PRINCIPAL -----\n");
    printf("1- CADASTRAR PRODUTO\n");
    printf("2- LISTAR PRODUTOS\n");
    printf("3- REGISTRAR MOVIMENTAÇÃO\n");
    printf("4- LISTAR MOVIMENTAÇÃO\n"); 
    printf("5- VER ESTOQUE DE PRODUTOS\n");
    printf("0- SAIR\n");
    printf("ESCOLHA UMA OPÇÃO: ");
    scanf("%d", &escolha);
    return escolha;
}

int main() {
    Produto produ[100];
    Movimentacao movi[100];
    int opcao, totalprodu = 0, totalmovi = 0;
    
    do {
        opcao = menu();
        switch (opcao) {
            case 1:
                cadastroproduto(produ, &totalprodu);
                break;
            case 2:
                listarprodu(produ, totalprodu);
                break;
            case 3:
                cadastromovi(movi, produ, &totalmovi, &totalprodu);
                break;
            case 4:
                listarmovimentacao(movi, produ,totalmovi,totalprodu);
                break;
            case 5:
                listarEstoqueAtual(produ, totalprodu, movi, totalmovi);
                break;
            case 0:
                printf("\nSaindo do programa...\n");
                break;
            default:
                printf("\nOpção inválida! Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}