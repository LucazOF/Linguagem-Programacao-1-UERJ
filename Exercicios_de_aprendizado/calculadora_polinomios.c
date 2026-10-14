#include <stdio.h>
#include <stdlib.h>

// Estruturas
typedef struct{
    float resultado,a,b,c,x;
}calculadora;
// Funções
void calculapolinomio(calculadora *calc,int *total){
    if (*total >= 100)
    {
        printf("\nErro! Historico cheio.Reinicie a Calculadora");
        return;
    }
    printf("\n===CALCULO INICIADO===\n");
    printf("\nf(x)=ax²+bx+c");
    printf("\nDigite um valor para A: ");
    scanf("%f",&calc[*total].a);
    printf("\nDigite um valor para B: ");
    scanf("%f",&calc[*total].b);
    printf("\nDigite um valor para C: ");
    scanf("%f",&calc[*total].c);
    printf("\nDigite um valor para X: ");
    scanf("%f",&calc[*total].x);
    calc[*total].resultado = calc[*total].a*(calc[*total].x*calc[*total].x) +  calc[*total].b * calc[*total].x + calc[*total].c;
    printf("Resultado: %.2f",calc[*total].resultado);
    (*total)++;
}
void exibirlista(calculadora *calc,int total){
    if(total ==0){
        printf("Erro! Nada no historico");
        return;
    }
    printf("\n===HISTORICO INICIADO===\n");
    for (int i = 0; i < total; i++)
    {
        printf("\n %i° Resultado - %.2f",i+1,calc[i].resultado);
    }
    
}
int menu(){
    int opcao;
    printf("\n====CALCULADORA POLINOMIOS===\n");
    printf("\n1- Calcular Polinomios.");
    printf("\n2- Historico Calculadora.");
    printf("\n0- Sair.");
    printf("\nDigite um opção: ");
    scanf("%i",&opcao);
    return opcao;
}
int main(){
    int total = 0;
    calculadora calc [100];
    int escolha;
    do{
        escolha = menu();
        switch (escolha)
        {
        case 1:
            calculapolinomio(calc,&total);
            break;
        case 2:
            exibirlista(calc,total);
            break;
        case 0:
            printf("\nSaindo...");
            break;
        default:
            printf("\nDigite um valor valido.");
            break;
        }
    
    }while(escolha != 0);
}