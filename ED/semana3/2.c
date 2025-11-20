#include <stdio.h>

typedef struct {
    int dia, mes, ano;
} Data;

typedef struct {
    int matricula;
    Data dtnasc;
} Aluno;

int main() {
    Aluno input;
    Data currentDate;

    printf("Data atual (dd mm aaaa): ");
    scanf("%d %d %d", &currentDate.dia, &currentDate.mes, &currentDate.ano);

    while (1) {
        printf("Matricula: ");
        scanf("%d", &input.matricula);
        if (input.matricula < 0) break;

        printf("Data nasc. do aluno (dd mm aaaa): ");
        scanf("%d %d %d", &input.dtnasc.dia, &input.dtnasc.mes, &input.dtnasc.ano);

        int idade = currentDate.ano - input.dtnasc.ano;

        // Ajusta se ainda não fez aniversário no ano atual
        if (currentDate.mes < input.dtnasc.mes ||
           (currentDate.mes == input.dtnasc.mes && currentDate.dia < input.dtnasc.dia)) {
            idade--;
        }

        if (idade >= 18) {
            printf("Aluno %d ja completou 18 anos.\n", input.matricula);
        } else {
            printf("Aluno %d nao completou 18 anos.\n", input.matricula);
        }
    }

    return 0;
}
