#include <stdio.h>
#include "menu.h"
int menu(){
    int opcao;
    printf("\n=============== CALCMASTER C1 ===============");
    printf("\n1 - Polinômios");
    printf("\n2 - Limites");
    printf("\n3 - Derivadas");
    printf("\n4 - Tangente da Função");
    printf("\n5 - Crescimento e Decrescimento");
    printf("\n6 - Máximos e Mínimos");
    printf("\n7 - Histórico");
    printf("\n8 - Sobre a Função");
    printf("0 - 0 - Sair");
    scanf("%i",&opcao);
    return opcao;
}
int menupolimonio(Calculo*calc,int *total){
    int opcao;
    printf("\nDigite o que você quer:");
    printf("\n1- Calcular um novo polinomio ");
    printf("\n2- Historico polinomios");
    printf("\n3- Voltar menu");
    printf("\nDigite sua opção: ");
    return scanf("%i",&opcao);
}