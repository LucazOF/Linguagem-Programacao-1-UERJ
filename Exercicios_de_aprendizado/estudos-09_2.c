#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char*argv[]){
    int i;

    if(argc > 1){
        printf("Foram inseridos argumentos antesde iniciar");
        for (i=0;i<argc;i++){
            printf("%s\n",argv [i]);
        }
    } else{
        printf("não foram insereidos argumentos");
    }

}