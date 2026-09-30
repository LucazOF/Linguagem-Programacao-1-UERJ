#ifndef LISTA_H
#define LISTA_H

typedef struct No{
    int id;
    char descricao[100];
    int concluido;
    struct No *prox;
}No;
void cadastro(No **inicio);
#endif