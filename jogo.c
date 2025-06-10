#include <stdio.h>
#include "4line.h"

//variaveis globais
char tabuleiro[LINHAS][COLUNAS];
char jogador_atual = 'X';

// enche o tabuleiro com espaços vazios o que mostra todas as posicoes vazias
void inicializar_tabuleiro()
{
    for (int i = 0; i < LINHAS; i++)
    {
        for (int j = 0; j < COLUNAS; j++)
        {
            tabuleiro[i][j] = ' ';
        }
    }
}


//imprime o tabuleiro atual no terminal que faz as linhas e colunas'
void mostrar_tabuleiro()
{
    for (int i = 0; i < LINHAS; i++)
    {
        for (int j = 0; j < COLUNAS; j++)
        {
            printf("|%c", tabuleiro[i][j]);
        }
        printf("|\n");
    }
    printf("---------------\n");
    printf(" 0 1 2 3 4 5 6 \n");
}

//faz a jogfada do jogador atual, pedindo a coluna onde ele quer jogar
void fazer_jogada()
{
    int coluna;
    int jogada_valida = 0;

    while (!jogada_valida)
    {
        printf("Jogador %c, escolher uma coluna (0-%d): ", jogador_atual, COLUNAS - 1);
        scanf("%d", &coluna);

        if (coluna < 0 || coluna >= COLUNAS)
        {
            printf("Coluna inválida. Tente novamente.\n");
            continue;
        }

        for (int i = LINHAS - 1; i >= 0; i--)
        {
            if (tabuleiro[i][coluna] == ' ')
            {
                tabuleiro[i][coluna] = jogador_atual;
                jogada_valida = 1;
                break;
            }
        }
        if (!jogada_valida)
        {
            printf("Coluna cheia. Escolha outra.\n");
        }
    }
}


//poe a jogada do jogador atual no tabuleiro, se a coluna for valida 
int aplicar_jogada(int coluna)
{
    if (coluna < 0 || coluna >= COLUNAS)
        return 0;

    for (int i = LINHAS - 1; i >= 0; i--)
    {
        if (tabuleiro[i][coluna] == ' ')
        {
            tabuleiro[i][coluna] = jogador_atual;
            return 1;
        }
    }
    return 0; // coluna cheia
}

void mudar_jogador()
{
    jogador_atual = (jogador_atual == 'X') ? 'O' : 'X';
}

int jogo_terminado()
{
    // horizontal
    for (int i = 0; i < LINHAS; i++)
    {
        for (int j = 0; j < COLUNAS - 3; j++)
        {
            if (tabuleiro[i][j] == jogador_atual &&
                tabuleiro[i][j] == tabuleiro[i][j + 1] &&
                tabuleiro[i][j] == tabuleiro[i][j + 2] &&
                tabuleiro[i][j] == tabuleiro[i][j + 3])
            {
                return 1;
            }
        }
    }
    // vertical
    for (int j = 0; j < COLUNAS; j++)
    {
        for (int i = 0; i < LINHAS - 3; i++)
        {
            if (tabuleiro[i][j] == jogador_atual &&
                tabuleiro[i][j] == tabuleiro[i + 1][j] &&
                tabuleiro[i][j] == tabuleiro[i + 2][j] &&
                tabuleiro[i][j] == tabuleiro[i + 3][j])
            {
                return 1;
            }
        }
    }
    // diagonal para direita
    for (int i = 0; i < LINHAS - 3; i++)
    {
        for (int j = 0; j < COLUNAS - 3; j++)
        {
            if (tabuleiro[i][j] == jogador_atual &&
                tabuleiro[i][j] == tabuleiro[i + 1][j + 1] &&
                tabuleiro[i][j] == tabuleiro[i + 2][j + 2] &&
                tabuleiro[i][j] == tabuleiro[i + 3][j + 3])
            {
                return 1;
            }
        }
    }
    // diagonal para esquerda
    for (int i = 3; i < LINHAS; i++)
    {
        for (int j = 0; j < COLUNAS - 3; j++)
        {
            if (tabuleiro[i][j] == jogador_atual &&
                tabuleiro[i][j] == tabuleiro[i - 1][j + 1] &&
                tabuleiro[i][j] == tabuleiro[i - 2][j + 2] &&
                tabuleiro[i][j] == tabuleiro[i - 3][j + 3])
            {
                return 1;
            }
        }
    }
    // empate (tab cheio)
    int cheio = 1;
    for (int j = 0; j < COLUNAS; j++)
    {
        if (tabuleiro[0][j] == ' ')
        {
            cheio = 0;
            break;
        }
    }
    if (cheio)
        return 2; // 2 = empate
    return 0;
}

char obter_vencedor()
{
    return jogador_atual;
}