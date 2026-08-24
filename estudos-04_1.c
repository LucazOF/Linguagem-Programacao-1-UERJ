#include <stdio.h>
#include <stdlib.h>

int main(){
    float n1 , n2 , m;

    printf("Insira sua 1° nota:\n");
    scanf("%f",&n1);

    printf("Insira sua 2° nota:\n");
    scanf("%f",&n2);

    m = (n1+n2)/2;

    if (m >=7.0){
        printf("Sua media é %.2f e você foi aprovado",m);

    }
    else if (5 <= m && m < 7.0){
        printf("Sua media é %.2f e você está de recuperação",m);
        
    }
    else if (m < 5){
        printf("Sua media é %.2f e você foi reprovado",m);
        
    }
    return 0;
}