#include <stdio.h>
#include "jogo.h"

char tabuleiro[LINHAS][COLUNAS];
char jogador_atual = 'X';

void inicializar_tabuleiro(){
    for(int i = 0; i <LINHAS; i++)
        for(int j = 0; j < COLUNAS; j++);
            tabuleiro[i][j] = ' ';
}

void mostrar_tabuleiro(){
    for ( int i = 0; i < LINHAS; i++){
        for (int j = 0; j<COLUNAS; j++){
            printf("|%c", tabuleiro[i][j]);
        }
        printf("|\n");}
        printf("---------------\n");
}


void fazer_jogada(){
    int coluna;
    printf("jogador %c, ecolher uma coluna (0-%d): ", jogador_atual, COLUNAS-1);
    scanf("%d", &coluna);

    for(int i = LINHAS - 1; i >= 0; i--){
        if(tabuleiro[i][coluna] == ' '){
            tabuleiro[i][coluna] = jogador_atual;
            break;
        }
    }
}

void mudar_jogador(){
    jogador_atual = (jogador_atual == 'X') ? 'O' : 'X';
}

int jogo_terminado(){
    // Verifica se há um vencedor ou se o tabuleiro está cheio
    return 0;
}

char obter_vencedor(){
    return jogador_atual;
}