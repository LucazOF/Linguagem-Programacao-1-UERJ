#include <stdio.h>
#include "main.h"

int main(){
    int total = 0;
    HistoricoCalculo calc [100];
    int escolha;
    do{
        escolha = menu();
        switch (escolha)
        {
        case 1:
            
            int escolha2;
             do
            {
                escolha2 = menupolimonio(calc,&total);
                switch (escolha2)
                {
                        
                case 1:
                    calculapolinomio(calc,&total);
                    break;
                case 2:
                    exibirpolinomios(calc,total);
                    break;
                case 3:
                    printf("\nVoltando pro menu.");
                    break;
                default:
                    printf("\nValor invalido");
                    break;
                }
            } while (escolha2 != 0);
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
