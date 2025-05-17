#ifndef IPC_H
#define IPC_H

#define FIFO_PATH "/tmp/fifo" //??????

void criar_fifo();
void escrever_fifo(char *mensagem);
void ler_fifo(char *buffer, int tamanho);
void limpar();