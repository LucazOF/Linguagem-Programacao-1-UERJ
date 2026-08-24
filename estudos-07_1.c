#include <stdio.h>
#include <stdlib.h>

//Matrizes

int main(){
    int n1;
    int n2;
    
    printf("Digite o tamanho da linha: ");
    scanf("%i",&n1);
    printf("Digite o tamanho da coluna: ");
    scanf("%i",&n2);
    
    int mat [n1][n2];
    // logica para registro 
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            printf("Digite o valor para mat[%i][%i]\n",i,j);
            scanf("%i",&mat[i][j]);

        }
        
        

    }
    // logica para impressão
      for (int i = 0; i < n1; i++){
        for (int t = 0; t < n2; t++)
        {
            printf("%i  " ,mat[i][t]);    
        }
        printf("\n");
    }
    printf("programa finalizado.");
    return 0;
}