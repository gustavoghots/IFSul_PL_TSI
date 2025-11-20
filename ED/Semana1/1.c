#include <stdio.h>

int main(void) {
    int q, tipo, count_aluna = 0;
    float altura, maior = 0, sum_aluna = 0;

    printf("Digite a quantidade de alunos: ");
    scanf("%d", &q);

    for (int i = 0; i < q; i++) {
        printf("\nAluno %d\n", i + 1);

        printf("Digite o codigo (1 = masculino, 2 = feminino): ");
        do {
            scanf("%d", &tipo);
        } while (tipo != 1 && tipo != 2);

        printf("Digite a altura (em metros): ");
        scanf("%f", &altura);

        // Verifica se é a maior altura
        if (altura > maior) {
            maior = altura;
        }

        // Se for aluna, acumula na média
        if (tipo == 2) {
            count_aluna++;
            sum_aluna += altura;
        }
    }

    printf("\n=== RESULTADOS ===\n");
    printf("Altura do aluno mais alto: %.2f m\n", maior);

    if (count_aluna > 0) {
        printf("Media da altura das alunas: %.2f m\n", sum_aluna / count_aluna);
    } else {
        printf("Nao ha alunas na turma.\n");
    }

    return 0;
}