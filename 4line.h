#ifndef PROJETO_H
#define PROJETO_H

// Constantes do jogo
#define LINHAS 6
#define COLUNAS 7
// Constantes de comunicação (pipes)
#define FIFO_PATH "/tmp/fifo" // podes ajustar conforme necessário

extern char jogador_atual;

// Funções do jogo
void inicializar_tabuleiro();
void mostrar_tabuleiro();
void fazer_jogada();
int aplicar_jogada(int coluna);
void mudar_jogador();
int jogo_terminado();
char obter_vencedor();


// Funções para IPC (Pipes)
void criar_fifo();
void escrever_fifo(char *mensagem);
void ler_fifo(char *buffer, int tamanho);
void limpar();
void limpar_recursos();

#endif
