#include <stdio.h>
#include <stdlib.h>

int main() {
int i = 1;
float n [10]; //armazena 10 numeros
do{
    printf("Registre o %i° n: ",i);
    scanf("%f",&n[i]); // registra o numero n em i
    i++;

}while(i<=10);
for (i=0; i < 10; i++){
    printf("n[%d] = %.2f\n", i, n[i]);
}

return 0;
}