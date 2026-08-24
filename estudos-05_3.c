#include <stdio.h>
#include <stdlib.h>


int main(){
    int i = 0;
    int n = 0;
    printf("Até quando você quer que repita: \n");
    scanf("%i",&n);
    while(i<20){
        printf("%i° vez repetindo\n ",i+1);
        
        i++;
        
        if(i==n){
            printf("Rodando break\n");
            break;
        }
        /* code */
    }
    printf("Você saiu pelo break\n");

}