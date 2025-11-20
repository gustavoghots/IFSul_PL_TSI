#include <stdio.h>

int main(void) {
    int L, C;

    // leitura das dimensões
    printf("Digite a quantidade de linhas (max 10): ");
    scanf("%d", &L);

    printf("Digite a quantidade de colunas (max 10): ");
    scanf("%d", &C);

    int matriz[10][10]; // matriz com tamanho máximo

    // leitura da matriz
    printf("Digite os elementos da matriz %dx%d:\n", L, C);
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < C; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    // leitura indeterminada de valores
    int valor;
    printf("\nDigite valores para buscar (digite 0 ou negativo para encerrar):\n");
    while (1) {
        scanf("%d", &valor);
        if (valor <= 0) break; // critério de parada

        int encontrado = 0; // flag
        for (int i = 0; i < L; i++) {
            for (int j = 0; j < C; j++) {
                if (matriz[i][j] == valor) {
                    encontrado = 1;
                    break; // achou, pode sair
                }
            }
            if (encontrado) break;
        }

        if (encontrado) {
            printf("Valor %d encontrado na matriz.\n", valor);
        } else {
            printf("Valor %d nao encontrado na matriz.\n", valor);
        }
    }

    printf("\nPrograma encerrado.\n");
    return 0;
}