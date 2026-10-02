#ifndef LISTA_H
#define LISTA_H

typedef struct No{
    int id;
    char descricao[100];
    int concluido;
    struct No *prox;
}No;
void cadastro(No **inicio);
No *search(No *inicio, int id);
void BuscarTarefa( No **inicio);
void imprimir(No **inicio);
#endif