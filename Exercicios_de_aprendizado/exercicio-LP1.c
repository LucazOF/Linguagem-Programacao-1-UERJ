#include <stdio.h>

typedef struct 
{   

    int idade;
    float peso;
}Pessoa;
void criarpessoa(Pessoa *p1){
    p1->idade = 20;
    p1->peso = 75.2;
    printf("\n Idade: %i Peso:%.2f",(*p1).idade,(*p1).peso);
    printf("\nsaindo da função...");
}
int main(){
    Pessoa p1;
    criarpessoa(&p1);
    printf("\n Estou na main");
}