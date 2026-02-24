#include <stdio.h>

int maiorNumero(int a, int b) {
    if (a > b) return a;
    if (b > a) return b;
    return -1;
}

int main(void) {
    int N, x, y, resultado;

    printf("Digite a quantidade de duplas: ");
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        printf("\nDigite a dupla %d (dois inteiros positivos): ", i + 1);
        scanf("%d %d", &x, &y);

        resultado = maiorNumero(x, y);

        if (resultado == -1) {
            printf("Eles sao iguais\n");
        } else {
            printf("Maior numero: %d\n", resultado);
        }
    }

    return 0;
}