#include <stdio.h>
#include <stdlib.h>



int main (){
    int n;
    float m, s;

    printf("Defina quantos numero você quer registrar");
    scanf("%i",&n);
    int v[n];// tamanho do vetor
    
    for (int i=0; i < n; i++)
    {
        printf("Digite o %i° numero",i+1);
        scanf("%i",&v[i]); // ele pega o indice do for com indice da varivavel funciona como se fosse uma matriz eu acho
    }
    

   // v[0] = 10;
   // v[1] = 20;
   // v[2] = 60;
   // v[3] = 40;
   // v[4] = 50;

    //m = (v[0] + v[1]+ v[2]+v[3]+v[4])/n;
    //faz a mesma coisa so que organiza tuda pra não precisa puxando vetor por indice pra completar, assim o codigo não muda mesmo se tiver 999999 numeros
    for(int i=0;i<n;i++){
        s += v[i];
    }
    m = s/n;
    printf("Media do valor é %.2f",m);
}