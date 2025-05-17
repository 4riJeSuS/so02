#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include "pipes.h"

void criar_fifo(){
    mkfifo(FIFO_PATH, 0666);
}

void escrever_fifo(char *mensagem){
    int fd = open(FIFO_PATH, O_WRONLY);
    write(fd, mensagem, 100);
    close(fd);
}

void ler_fifo(char *buffer, int tamanho){
    int fd = open(FIFO_PATH, o_RDONLY);
    read(fd, buffer, tamanho);
    close(fd);
}

void limpar(){
    unlink(FIFO_PATH);
}