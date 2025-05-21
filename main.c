#include <stdio.h>
#include "4line.h"

int main()
{
    inicializar_tabuleiro();

    while (!jogo_terminado())
    {
        mostrar_tabuleiro();
        fazer_jogada();
        mudar_jogador();
    }

    mostrar_tabuleiro();
    printf("Jogo terminado - Vencedor: %c\n", obter_vencedor());

    limpar_recursos();
    return 0;
}

/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "4line.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Uso: %s [1|2]\n", argv[0]);
        return 1;
    }

    int jogador = atoi(argv[1]); // 1 ou 2
    char buffer[100];

    inicializar_tabuleiro();
    criar_fifo();

    int terminou = 0;
    while (!terminou) {
        mostrar_tabuleiro();

        if ((jogador_atual == 'X' && jogador == 1) || (jogador_atual == 'O' && jogador == 2)) {
            int coluna;
            printf("Jogador %c, escolher uma coluna: ", jogador_atual);
            scanf("%d", &coluna);

            while (!aplicar_jogada(coluna)) {
                printf("Jogada inválida. Tente novamente: ");
                scanf("%d", &coluna);
            }

            sprintf(buffer, "%d", coluna);
            escrever_fifo(buffer);
        } else {
            printf("Aguardando jogada do adversário...\n");
            ler_fifo(buffer, sizeof(buffer));
            int coluna = atoi(buffer);
            aplicar_jogada(coluna);
        }

        terminou = jogo_terminado();
        if (!terminou) mudar_jogador();
    }

    mostrar_tabuleiro();
    if (terminou == 1) {
        printf("Jogo terminado! Vencedor: %c\n", obter_vencedor());
    } else {
        printf("Empate!\n");
    }

    limpar_recursos();
    return 0;
}
*/