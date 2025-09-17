#include <stdio.h>

#define N 5

/* ---------- Exibição ---------- */
static void exibirMatriz(const int matriz[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

/* ---------- Utilitário ---------- */
static void copiaPadrao(int destino[N][N], const int padrao[N][N]) {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            destino[i][j] = padrao[i][j];
}

/* ---------- Habilidades (mesmos padrões) ---------- */
void habilidadeCone(int matriz[N][N]) {
    static const int CONE[N][N] = {
        {0,0,1,0,0},
        {0,1,1,1,0},
        {1,1,1,1,1},
        {0,0,0,0,0},
        {0,0,0,0,0}
    };
    copiaPadrao(matriz, CONE);
}

void habilidadeCruz(int matriz[N][N]) {
    static const int CRUZ[N][N] = {
        {0,0,1,0,0},
        {1,1,1,1,1},
        {0,0,1,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0}
    };
    copiaPadrao(matriz, CRUZ);
}

void habilidadeOctaedro(int matriz[N][N]) {
    static const int OCTAEDRO[N][N] = {
        {0,0,1,0,0},
        {0,1,1,1,0},
        {0,0,1,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0}
    };
    copiaPadrao(matriz, OCTAEDRO);
}

int main(void) {
    int habilidade[N][N];

    printf("Habilidade: Cone\n");
    habilidadeCone(habilidade);
    exibirMatriz(habilidade);

    printf("\nHabilidade: Cruz\n");
    habilidadeCruz(habilidade);
    exibirMatriz(habilidade);

    printf("\nHabilidade: Octaedro\n");
    habilidadeOctaedro(habilidade);
    exibirMatriz(habilidade);

    return 0;
}
