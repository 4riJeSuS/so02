#include <stdio.h>
#include "jogo.h"
#include "jogo.c"

int main(){
    inicializar_tabuleiro();

    while(!jogo_terminado()){
        motrar_tabuleiro();
        fazer_jogada();
        mudar_jogador();
    }

    motrar_tabuleir();
    printf("jogo terminado: vencedor: %c\n," obter_vencedor());

    limpar_recursos();
    return 0;
}