#ifndef FUNCAO_H
#define FUNCAO_H

typedef enum{
    ABERTO,
    EM_ATENDIMENTO,
    CANCELADO,
    RESOLVIDO
}EstadoAtual;
typedef enum{
    INICIAR,
    CANCELAR,
    FINALIZAR
}Evento;
typedef struct No{
    int numero;
    char desc[500];
    EstadoAtual status;
    struct No* proximo;
}No;
void buscarchamado(No *incio);
void liberar(No **inicio);
int processar_evento(No *encontrado,Evento evento);
void atualizarstatus(No **incio);
No *search(No *inicio, int id);
void insert(No **incio);
void imprimir(const No *incio);
#endif