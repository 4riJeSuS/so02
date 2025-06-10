#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "4line.h"

int main(int argc, char *argv[])
{
    // verifica se o user indicou certo se o jogador sera o 1 ou o 2
    if (argc != 2)
    {
        printf("Uso: %s [1|2]\n", argv[0]);
        return 1;
    }

    int jogador = atoi(argv[1]); // 1 ou 2
    char buffer[100];

    // inicia a matriz do tabuleiro e cria o fifo para a comunicaçao entre os jogadores
    inicializar_tabuleiro();
    criar_fifo();

    int terminou = 0;

    // mostra o estado atual do tabuleiro a cada jogada
    while (!terminou)
    {
        mostrar_tabuleiro();

        // verifica se e a vez do jogador 'X' ou jogador 'O', representados respetivamente por 1 e 2
        if ((jogador_atual == 'X' && jogador == 1) || (jogador_atual == 'O' && jogador == 2))
        {
            int coluna;
            printf("Jogador %c, escolher uma coluna: ", jogador_atual);
            scanf("%d", &coluna);

            while (!aplicar_jogada(coluna))
            {
                printf("Jogada inválida. Tente novamente: ");
                scanf("%d", &coluna);
            }

            sprintf(buffer, "%d", coluna);
            escrever_fifo(buffer);
        }
        // depois de aplicada a jogada e enviado atraves do fifo
        else
        {
            printf("Aguardando jogada do adversário...\n");
            ler_fifo(buffer, sizeof(buffer));
            int coluna = atoi(buffer);
            aplicar_jogada(coluna);
        }
        // espera pela jogada do adversairo e aplica
        terminou = jogo_terminado();
        if (!terminou)
            mudar_jogador(); // verifica se o jogo terminou, se nao terminou muda o jogador
    }

    // mostra o resultado
    mostrar_tabuleiro();
    if (terminou == 1)
    {
        printf("Jogo terminado! Vencedor: %c\n", obter_vencedor());
    }
    else
    {
        printf("Empate!\n");
    }

    limpar_recursos();
    return 0;
}
