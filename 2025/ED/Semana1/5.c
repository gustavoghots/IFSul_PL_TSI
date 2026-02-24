#include <stdio.h>

int main(void) {
    int n, Y;

    printf("Digite o tamanho do vetor Z: ");
    scanf("%d", &n);

    int Z[n], W[n]; 
    int j = 0;       

    printf("Digite os %d elementos do vetor Z:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &Z[i]);
    }

    printf("Digite o valor Y: ");
    scanf("%d", &Y);

    for (int i = 0; i < n; i++) {
        if (Z[i] > Y) {
            W[j] = Z[i];
            j++;
        }
    }

    printf("Vetor W (elementos maiores que %d): ", Y);
    if (j == 0) {
        printf("nenhum elemento encontrado.\n");
    } else {
        for (int i = 0; i < j; i++) {
            printf("%d ", W[i]);
        }
        printf("\n");
    }

    return 0;
}