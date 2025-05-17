#ifndef JOGO_H
#define JOGO_H

#define LINHAS 6
#define COLUNAS 7

void inicializar_tabuleiro();
void mostrar_tabuleiro();
void fazer_jogada();    
void mudar_jogador();
int jogo_terminado();
char obter_vencedor();

#endif