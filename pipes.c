#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>
#include "4line.h"

void criar_fifo()
{
    if (mkfifo(FIFO_PATH, 0666) == -1)
        perror("ERRO: cirar FIFO");
}

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

void limpar()
{
    unlink(FIFO_PATH);
}

void limpar_recursos()
{
    limpar();
}