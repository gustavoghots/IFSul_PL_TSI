#include <stdio.h>
#include "fila.h"
#include "fila.c"

int main() {
    FilaCF fila;
    criaFila(&fila);

    int opcao;
    do {
        printf("\n--- MENU FILA ---\n");
        printf("0. Fim\n");
        printf("1. Insere\n");
        printf("2. Retira\n");
        printf("3. Quantidade de nodos\n");
        printf("4. Exibe situacao da fila\n");
        printf("5. Consulta frente\n");
        printf("6. Pesquisa dado\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        int status;
        Dado d;
        int codBusca;

        switch (opcao) {
            case 1: // Insere
                printf("Digite codigo: ");
                scanf("%d", &d.cod);
                printf("Digite peso: ");
                scanf("%f", &d.peso);
                status = insere(&fila, d);
                break;

            case 2: // Retira
                status = retira(&fila, &d);
                if (status == SUCESSO) {
                    printf("Retirado -> Cod: %d, Peso: %.2f\n", d.cod, d.peso);
                }
                break;

            case 3: // Quantidade
                if (estaVazia(fila)) {
                    printf("Quantidade: 0\n");
                } else {
                    int qtd = (fila.re - fila.frente + MAX_NODOS) % MAX_NODOS + 1;
                    printf("Quantidade: %d\n", qtd);
                }
                status = SUCESSO;
                break;

            case 4: // Situacao
                if (estaVazia(fila)) {
                    printf("A fila esta vazia\n");
                } else {
                    int qtd = (fila.re - fila.frente + MAX_NODOS) % MAX_NODOS + 1;
                    if (qtd == MAX_NODOS) {
                        printf("A fila esta cheia\n");
                    } else {
                        printf("A fila possui %d nodo(s)\n", qtd);
                    }
                }
                status = SUCESSO;
                break;

            case 5: // Consulta frente
                status = consulta(fila, &d);
                if (status == SUCESSO) {
                    printf("Frente -> Cod: %d, Peso: %.2f\n", d.cod, d.peso);
                }
                break;

            case 6: // Pesquisa
                printf("Digite codigo para buscar: ");
                scanf("%d", &codBusca);
                status = pesquisa(fila, codBusca, &d);
                if (status == SUCESSO) {
                    printf("Encontrado -> Cod: %d, Peso: %.2f\n", d.cod, d.peso);
                }
                break;

            case 0:
                printf("Fim do programa.\n");
                continue;

            default:
                printf("Opcao invalida!\n");
                status = -1;
        }

        // Mostra resultado
        if (status == SUCESSO) {
            printf("Operacao executada com SUCESSO\n");
        } else if (status == FILA_VAZIA) {
            printf("Erro: FILA VAZIA\n");
        } else if (status == FILA_CHEIA) {
            printf("Erro: FILA CHEIA\n");
        } else if (status == DADO_INEXISTENTE) {
            printf("Erro: DADO INEXISTENTE\n");
        }

        printf("Fila atual:\n");
        exibe(fila);

    } while (opcao != 0);

    return 0;
}
