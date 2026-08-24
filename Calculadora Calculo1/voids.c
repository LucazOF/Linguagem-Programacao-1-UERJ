#include <stdio.h>
#include "voids.h"
void calculapolinomio(HistoricoCalculo *calc,int *total){
    if (*total >= 100)
    {
        printf("\nErro! Historico cheio.Reinicie a Calculadora");
        return;
    }
    printf("\n===CALCULO INICIADO===\n");
    printf("\nf(x)=ax²+bx+c");
    calc[*total].a = ler_float("\nDigite um valor para A: ");
    calc[*total].b = ler_float("\nDigite um valor para B: ");
    calc[*total].c = ler_float("\nDigite um valor para C: ");
    calc[*total].x = ler_float("\nDigite um valor para X: ");
    calc[*total].resultado = calc[*total].a*(calc[*total].x*calc[*total].x) +  calc[*total].b * calc[*total].x + calc[*total].c;
    printf("Resultado: %.2f",calc[*total].resultado);
    (*total)++;
}
void exibirpolinomios(HistoricoCalculo *calc, int total){
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