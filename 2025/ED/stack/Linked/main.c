#include <stdio.h>

#include "Pilha encadeada.h"
#include "Pilha encadeada.c"


int main() {
    Pilha pilha;
    Dado dado;
    int opcao;
    int resultado;

    criaPilha(&pilha);

    do {
        printf("=========== MENU ==========\n");
        printf("1 - Empilha\n");
        printf("2 - Desempilha\n");
        printf("3 - Quantidade de nodos\n");
        printf("4 - Exibe situacao da pilha\n");
        printf("5 - Consulta topo\n");
        printf("0 - Fim\n");
        printf("===========================\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        printf("\n");

        switch (opcao) {
            case 1:
                printf("Informe o codigo: ");
                scanf("%d", &dado.cod);
                printf("Informe o peso: ");
                scanf("%f", &dado.peso);
                resultado = empilha(&pilha, dado);
                if (resultado == SUCESSO)
                    printf("Empilhado com SUCESSO!\n");
                else
                    printf("Falha ao empilhar!\n");
                exibe(pilha);
                break;

            case 2:
                resultado = desempilha(&pilha, &dado);
                if (resultado == SUCESSO)
                    printf("Desempilhado com SUCESSO! -> Codigo: %d | Peso: %.2f\n", dado.cod, dado.peso);
                else
                    printf("Falha: pilha vazia!\n");
                exibe(pilha);
                break;

            case 3:
                printf("Quantidade de nodos: %d\n", quantidadeNodos(pilha));
                exibe(pilha);
                break;

            case 4:
                printf("Situacao atual da pilha:\n");
                exibe(pilha);
                break;

            case 5:
                resultado = consultaTopo(pilha, &dado);
                if (resultado == SUCESSO)
                    printf("Topo -> Codigo: %d | Peso: %.2f\n", dado.cod, dado.peso);
                else
                    printf("Falha: pilha vazia!\n");
                exibe(pilha);
                break;

            case 0:
                printf("Encerrando programa...\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }

        printf("-----------------------------------\n\n");
    } while (opcao != 0);

    return 0;
}
