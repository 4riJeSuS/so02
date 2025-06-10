#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>
#include "4line.h"

// permite a comunicaçãi entre os processos do jogo -> jogador 1 e jogador 2
void criar_fifo()
{
    if (mkfifo(FIFO_PATH, 0666) == -1)
        perror("ERRO: cirar FIFO");
}

// abre a FIFO para escrita e envia a mensagem
//  a mensagem é uma string que representa a coluna onde o jogador quer jogar
void escrever_fifo(char *mensagem)
{
    int fd = open(FIFO_PATH, O_WRONLY);
    if (fd == -1)
    {
        perror("ERRO: abrir FIFO para escrita");
        return;
    }
    write(fd, mensagem, strlen(mensagem) + 1); //+1 para enviar p \0
    close(fd);
}

// lê a FIFO e armazena a mensagem no buffer
//  o buffer deve ter tamanho suficiente para armazenar a mensagem
void ler_fifo(char *buffer, int tamanho)
{
    int fd = open(FIFO_PATH, O_RDONLY);
    if (fd == -1)
    {
        perror("ERRO: abrir FIFO para leitura");
        return;
    }
    read(fd, buffer, tamanho);
    close(fd);
}

// remove a FIFO do sistema de arquivos
void limpar()
{
    unlink(FIFO_PATH);
}

// limpa os recursos do jogo, removendo a FIFO
void limpar_recursos()
{
    limpar();
}