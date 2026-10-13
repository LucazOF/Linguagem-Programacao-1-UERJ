#ifndef AULA_H
#define AULA_H

typedef enum{
    DISPONIVEL,
    RESERVADO,
    EMPRESTADO

}Estado;

typedef enum{
    RESERVAR,
    RETIRAR,
    CANCELAR_RESERVA,
    DEVOLVER

}EventoLivro;

typedef struct No{
    Estado estado;
    char titulo[100];
    int id;

    struct No *proximo;
}No;

void inserir_lista(No **inicio);
int processar_evento(No *encontrado,EventoLivro evento);
void liberar(No **inicio);
void imprimir(const No *inicio);
void Buscar_livro(No **inicio);
No *search(No *inicio, int id);
void liberar(No **inicio);
#endif