#ifndef FUNCAO_H
#define FUNCAO_H
typedef enum{
    AGUARDANDO,
    ESTACIONADO,
    PAGO,
    SAIU
}Estadoatual;
typedef enum{
    ENTRAR,
    PAGAR,
    SAIR
}Evento;
typedef struct No{
    int id;
    char placa[8];
    struct No *proximo;
    Estadoatual status;
}No;
void insert(No **inicio);
No *search(No *inicio, int id);
void atualizarstatus(No **inicio);
int processar_evento(No *encontrado,Evento evento);
void excluir(No **inicio);
void liberar(No **inicio);
void imprimir(const No *inicio);
#endif