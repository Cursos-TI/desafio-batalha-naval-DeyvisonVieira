#include <stdio.h>

#define N 10
#define NAVIO 3

/* ---------- Exibição ---------- */
static void exibirMatriz(const int matriz[N][N], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

/* ---------- Construção do tabuleiro ---------- */
static void zeraTabuleiro(int t[N][N]) {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            t[i][j] = 0;
}

static void marcaHorizontal(int t[N][N], int linha, int colIni, int colFimExc, int marca) {
    for (int j = colIni; j < colFimExc; j++)
        t[linha][j] = marca;
}

static void marcaVertical(int t[N][N], int coluna, int linIni, int linFimExc, int marca) {
    for (int i = linIni; i < linFimExc; i++)
        t[i][coluna] = marca;
}

static void marcaDiagPrincipal(int t[N][N], int iIni, int iFimExc, int marca) {
    for (int i = iIni; i < iFimExc; i++)
        t[i][i] = marca;
}

static void marcaDiagSecundaria(int t[N][N], int iIni, int iFimExc, int marca) {
    for (int i = iIni; i < iFimExc; i++)
        t[i][(N - 1) - i] = marca;
}

/* Mantém exatamente o padrão do seu gerador */
static void gerarTabuleiroAventureiro(int tabuleiro[N][N]) {
    zeraTabuleiro(tabuleiro);

    /* Horizontal: linha 0, colunas 2..5 */
    marcaHorizontal(tabuleiro, /*linha*/0, /*colIni*/2, /*colFimExc*/6, NAVIO);

    /* Vertical: coluna 3, linhas 2..5 */
    marcaVertical(tabuleiro, /*coluna*/3, /*linIni*/2, /*linFimExc*/6, NAVIO);

    /* Diagonal principal: i=0..3 */
    marcaDiagPrincipal(tabuleiro, /*iIni*/0, /*iFimExc*/4, NAVIO);

    /* Diagonal secundária: i=0..3 (col = 9 - i) */
    marcaDiagSecundaria(tabuleiro, /*iIni*/0, /*iFimExc*/4, NAVIO);
}

int main(void) {
    int tabuleiro[N][N];
    gerarTabuleiroAventureiro(tabuleiro);

    printf("Tabuleiro - Nível Aventureiro:\n");
    exibirMatriz(tabuleiro, N);

    return 0;
}
