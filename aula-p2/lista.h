#ifndef LISTA_H
#define LISTA_H

typedef struct No{
    char nome[50];
    int quantidade;

    struct No* proximo;
}No;


void inserir_lista(No **lista);
void imprimir_lista(const No *lista);


#endif