#include <stdio.h>

#define TAM      5
#define MARCA_H  1
#define MARCA_V  2

/* Helpers de posicionamento */
static void posiciona_horizontal(int tab[TAM][TAM], int linha, int col_ini, int tamanho, int marca) {
    for (int i = 0; i < tamanho; i++) {
        tab[linha][col_ini + i] = marca;
    }
}

static void posiciona_vertical(int tab[TAM][TAM], int coluna, int linha_ini, int tamanho, int marca) {
    for (int i = 0; i < tamanho; i++) {
        tab[linha_ini + i][coluna] = marca;
    }
}

/* Helpers de impressão */
static void imprime_coords_horizontal(int linha, int col_ini, int tamanho) {
    printf("Coordenadas do navio horizontal:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("(%d, %d)\n", linha, col_ini + i);
    }
}

static void imprime_coords_vertical(int coluna, int linha_ini, int tamanho) {
    printf("\nCoordenadas do navio vertical:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("(%d, %d)\n", linha_ini + i, coluna);
    }
}

int main(void) {
    // Nível Novato - Posicionamento dos Navios

    // Tabuleiro 5x5 zerado
    int tabuleiro[TAM][TAM] = {0};

    // Navio horizontal (tamanho 3)
    const int linha_h      = 1;
    const int col_inicio_h = 0;
    const int tamanho_h    = 3;

    posiciona_horizontal(tabuleiro, linha_h, col_inicio_h, tamanho_h, MARCA_H);

    // Navio vertical (tamanho 2)
    const int coluna_v        = 3;
    const int linha_inicio_v  = 2;
    const int tamanho_v       = 2;

    posiciona_vertical(tabuleiro, coluna_v, linha_inicio_v, tamanho_v, MARCA_V);
    
    imprime_coords_horizontal(linha_h, col_inicio_h, tamanho_h);
    imprime_coords_vertical(coluna_v, linha_inicio_v, tamanho_v);

    return 0;
}
