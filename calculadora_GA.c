//PROJETO QUE FAZ CALCULOS DE GA.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _USE_MATH_DEFINES
#include <math.h>
/*
ANOTAÇÃOES DA CALCULADORA.
(X) Falta adicionar calculo do modulo no cadastro e no calculo de vetor e adicionar modulo na struct 
(X)Possivel melhoria adicionar o campo z pois usara no futuro.
(X)Adicionar uma função que transforme graus em radianos.
( )Pensar numa forma de calcular o produto misto entre os vetores.
( )Dizer se o vetor A e B são e C formam um triangulo retantuglo ("Calcular triangulo").
(X) Parar de pedir o angulo para o usuario e simplesmente descobrir.
(X) Calcular o produto Vetorial
( ) Trocar os while (1) por do while
(X) Criar opção de salvar o vetor do produto vetorial.
( ) Começar a aprender a separar o projeto . main.h , main.c e etc..
*/typedef struct 
{   
    char nome[10];
    float x,y,z,modulo;
}vetor;

//FUNÇÕES QUE CALCULAM ALGO.
int buscarvetorpornome(vetor *vector,int total,char *nomebuscado){
    for (int i = 0; i < total; i++)
    {
       if (strcmp(vector[i].nome, nomebuscado)==0) //Se o nome = nome buscado (char por char)
       {
        return i;
       }
       
    }
    return -1;
}
float graustoradius(float anguloGraus){
    return (anguloGraus * M_PI) / 180.0;
}
float calcmodulo(float vx, float vy,float vz){
    float modulo;
        modulo = sqrt((vx * vx) + (vy * vy) + (vz*vz));
    return modulo;
}
float calcularangulo(const vetor *v1,const vetor *v2){
    float ProdEscalar = (v1->x*v2->x) + (v1->y*v2->y) + (v1->z*v2->z);
    if (v1->modulo ==0 || v2->modulo==0)
    {
        return 0;
    }
    float cosseno = ProdEscalar / (v1->modulo * v2->modulo);
    if (cosseno > 1.0) 
    {
        cosseno = 1.0;
    }
    if (cosseno < -1.0){
        cosseno = -1.0;
    }
    float anguloRadianos = acos(cosseno);
    return (anguloRadianos*180.0)/M_PI; //retorna em graus
    
}
float calcularProdutoEscalar(const vetor *v1, const vetor *v2){
    float resultado = 0;
    resultado = (v1->x * v2->x)  + (v1->y * v2->y) + (v1->z * v2->z);
    return resultado;
}
vetor calcularProdutoVetorial(const vetor *v1 , const vetor *v2){
    float u [3] = {v1->y*v2->z,v1->z*v2->x,v1->x*v2->y};
    float w[3] = { v1->z * v2->y, v1->x * v2->z, v1->y * v2->x };

    vetor resultado;
    resultado.x = u[0] - w[0];
    resultado.y = u[1] - w[1];
    resultado.z = u[2] - w[2];
    resultado.modulo = calcmodulo( resultado.x, resultado.y, resultado.z);
    return resultado;
} //criando nosso vetor ortogonal.
float calcularProdutoMisto(const vetor *v1,const vetor *v2,const vetor *v3){
    float u =0,v=0;
    u = (v1->x*v2->y*v3->z)+(v1->y*v2->z*v3->x)+(v1->z*v2->x*v3->y);
    v = (v1->z*v2->y*v3->x)+(v1->x*v2->z*v3->y)+(v2->y*v2->x*v3->z);
    return u - v;
}
//FUNÇÔES VOIDS
void calcularvetor(vetor *vector,int *total){
    float ax,ay,az,bx,by,bz;
    char buscarnome[10];
    while (1)
    {
        printf ("\nDigite o primeiro ponto (X Y Z): ");
        if (scanf("%f %f %f",&ax,&ay,&az)==3){ // se for um sucesso então sai do loop
            break;   
    }
        printf("\nEntrada invalida! Use apenas numeros (ex: 2.5 3).\n");
            while (getchar() != '\n'); 
    }
    while (1)
    {
        printf ("\nDigite o segundo ponto (X Y Z): ");
        if (scanf("%f %f %f",&bx,&by,&bz)==3){ 
            break;   
    }
        printf("\nEntrada invalida! Use apenas numeros (ex: 2.5 3).\n");
            while (getchar() != '\n');
    }
    vector[*total].x = (bx -ax);
    vector[*total].y = (by -ay);
    vector[*total].z = (bz -az);
    vector[*total].modulo = calcmodulo(vector[*total].x,vector[*total].y,vector[*total].z);

    while (1)
    {
        printf("De um nome pro vetor: ");
        scanf("%s", buscarnome);
        if (buscarvetorpornome(vector,*total,buscarnome)!=-1)
        {
            printf("\nErro: Esse nome ja existe! Escolha outro.\n");
        }else{
            break;
        }
    }
    strcpy(vector[*total].nome, buscarnome); //Copia a string para struct  
    (*total)++;
    printf("\nOperação concluida. ");
}

void registrarvetor(vetor *vector, int *total){
    float vx, vy,vz; 
    char buscarnome[10];
    while (1) {
        printf("\nDigite as coordenadas do vetor (X Y Z): ");
        if (scanf("%f %f %f", &vx, &vy,&vz) == 3) { 
            break; 
        }
        printf("\nEntrada invalida! Use apenas numeros (ex: 3.5 -2).\n");
        while (getchar() != '\n'); // Limpa o buffer do teclado
    }
    vector[*total].x = vx;
    vector[*total].y = vy;
    vector[*total].z = vz;
    vector[*total].modulo = calcmodulo(vx,vy,vz);
    
    while (1)
    {
        printf("De um nome pro vetor: ");
        scanf("%s", buscarnome);
        if (buscarvetorpornome(vector,*total,buscarnome)!=-1)
        {
            printf("\nErro: Esse nome ja existe! Escolha outro.\n");
        }else{
            break;
        }
    }
    strcpy(vector[*total].nome, buscarnome); //Copia a string para struct  
    (*total)++;
    printf("\nOperação concluida.\n"); 
}

void produtoescalar(vetor *vector, int total){
    char nomebusca[11];
    int indice1, indice2;
    float resultado = 0;
    int tipoCalculo;
    
    if (total < 2){
        printf("\nPrecisa ter pelo menos 2 vetores cadastrados.");
        return;
    } 
    
    printf("\n=== CALCULAR PRODUTO ESCALAR ===");
    printf("\n1 - Calcular pelas Coordenadas ");
    printf("\n2 - Calcular pelo Metodo Geometrico");
    printf("\nEscolha o metodo: ");
    scanf("%i", &tipoCalculo);


    while (1) {    
        printf("\nDigite o nome do primeiro vetor: ");
        scanf("%s", nomebusca);
        indice1 = buscarvetorpornome(vector, total, nomebusca); 
        if (indice1 == -1) printf("\nErro: vetor nao encontrado");
        else break;
    }
    
    while (1) {    
        printf("Digite o nome do segundo vetor: ");
        scanf("%s", nomebusca);
        indice2 = buscarvetorpornome(vector, total, nomebusca); 
        if (indice2 == -1) printf("\nErro: vetor nao encontrado");
        else break;
    }

    switch (tipoCalculo) {
        case 1:
            resultado = calcularProdutoEscalar(&vector[indice1],&vector[indice2]);
            printf("\n[Metodo Coordenadas] %s • %s = %.2f\n", vector[indice1].nome, vector[indice2].nome, resultado);
            break;
            
        case 2: {
            float anguloGraus = calcularangulo(&vector[indice1],&vector[indice2]);
            float anguloRadianos = 0;
            anguloRadianos = graustoradius(anguloGraus);
            // Fórmula Geométrica: |v1| * |v2| * cos(θ)
            resultado = vector[indice1].modulo * vector[indice2].modulo * cos(anguloRadianos);
            
            printf("\n[Metodo Geometrico] %s • %s = %.2f\n", vector[indice1].nome, vector[indice2].nome, resultado);            
            printf("\n Angulo entre eles: %.2f °",anguloGraus);
            break;
        }
            
        default:
            printf("\nOpcao de metodo invalida!\n");
            break;
    }
}
void produtovetorial(vetor *vector, int *total){
    char nomebusca[11];
    int indice1, indice2;
    char opcao;
    float resultado = 0;
    
    if (*total < 2){
        printf("\nPrecisa ter pelo menos 2 vetores cadastrados.");
        return;
    } 
    while (1) {    
        printf("\nDigite o nome do primeiro vetor: ");
        scanf("%s", nomebusca);
        indice1 = buscarvetorpornome(vector, *total, nomebusca); 
        if (indice1 == -1) printf("\nErro: vetor nao encontrado");
        else break;
    }
    while (1) {    
        printf("\nDigite o nome do segundo vetor: ");
        scanf("%s", nomebusca);
        indice2 = buscarvetorpornome(vector, *total, nomebusca); 
        if (indice2 == -1) printf("\nErro: vetor nao encontrado");
        else break;
    }
    vetor novovetor;
    novovetor = calcularProdutoVetorial(&vector[indice1],&vector[indice2]);
    printf("\nResultado do Calculo Vetorial:");
    printf("\n{%.2f, %.2f, %.2f}", novovetor.x, novovetor.y, novovetor.z);
    printf("\nDeseja salvar o vetor (Y|N)");
    scanf(" %c",&opcao);
    if (opcao == 'Y' || opcao =='y')
    {
            while (1)
    {
        printf("De um nome pro vetor: ");
        scanf("%s", nomebusca);
        if (buscarvetorpornome(vector,*total,nomebusca)!=-1)
        {
            printf("\nErro: Esse nome ja existe! Escolha outro.\n");
        }else{
            break;
        }
    }
    strcpy(novovetor.nome, nomebusca); //Copia a string para struct  
    vector[*total] = novovetor;
    (*total)++; 
    }else{
        printf("\nVoltando pro menu.");
        return;
    }
    

}
void exibirvetores(vetor *vector, int total){
    if (total ==0){
        printf("\nERRO! Não há vetores cadastrados.");
        return;
    }
    printf("\n=======================");
    printf("\n   Lista de Vetores    ");
    printf("\n=======================");
    for (int i = 0; i < total; i++)
    {
        printf("\n| Nome: %s Modulo:%.2f Coordenadas: %.2f %.2f %.2f",vector[i].nome,vector[i].modulo,vector[i].x,vector[i].y,vector[i].z);

    }
    
}
void produtomisto(vetor *vector,int *total){
    if(total ==0){
        printf("\nNão há vetores cadastrados.");
        return;
    }
    int indice1,indice2,indice3;
    float resultado = 0;
    char nomebusca [11];
    if (*total < 3){
        printf("\nPrecisa ter pelo menos 3 vetores cadastrados.");
        return;
    } 
    while (1) {    
        printf("\nDigite o nome do primeiro vetor: ");
        scanf("%s", nomebusca);
        indice1 = buscarvetorpornome(vector, *total, nomebusca); 
        if (indice1 == -1) printf("\nErro: vetor nao encontrado");
        else break;
    }
    while (1) {    
        printf("\nDigite o nome do segundo vetor: ");
        scanf("%s", nomebusca);
        indice2 = buscarvetorpornome(vector, *total, nomebusca); 
        if (indice2 == -1) printf("\nErro: vetor nao encontrado");
        else break;
    }
        while (1) {    
        printf("\nDigite o nome do terceiro vetor: ");
        scanf("%s", nomebusca);
        indice3 = buscarvetorpornome(vector, *total, nomebusca); 
        if (indice3 == -1) printf("\nErro: vetor nao encontrado");
        else break;
    }
    resultado = calcularProdutoMisto(&vector[indice1],&vector[indice2],&vector[indice3]);
    printf("\n %.2f",resultado);
}
int menu (){
    int opcao;
    printf("\n=============================");
    printf("\n     CALCULADORA GA          ");
    printf("\n=============================");   
    printf("\n1- Calcular um vetor");
    printf("\n2- Registrar vetor");
    printf("\n3- Calcular um produto escalar");
    printf("\n4- Calcular produto vetorial");
    printf("\n5- Exibir Vetores");

    /*printf("\n");
    printf("\n");
    printf("\n"); */
    printf("\nDigite uma opção: ");
    scanf("%i",&opcao);
    return opcao;
}
int main(){
    vetor vector[100];
    int total = 0;
    int escolha;
    do
    {
        escolha = menu();
        switch (escolha)
        {
        case 1:
            calcularvetor(vector, &total);
            break;
        case 2:
            registrarvetor(vector, &total); 
            break;
        case 3:
            produtoescalar(vector, total);
            break;
        case 4:
            produtovetorial(vector,&total); //pasando o total pra dps criar opção de salvar
            break;
        case 5:
            exibirvetores(vector,total);
            break;
        default:
            break;
        }
    } while (escolha != 0);
    
    return 0;
}
