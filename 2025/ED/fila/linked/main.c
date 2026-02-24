//
// Created by gusta on 09/11/2025.
//

#include <stdio.h>
#include "filaSE.h"
#include "filaSE.c"

int main() {
    FilaSE fila;
    Dado d;
    int opcao, retorno;

    criaFila(&fila);

    do {
        printf("\n=========================\n");
        printf("        MENU FILA        \n");
        printf("=========================\n");
        printf("0. Fim\n");
        printf("1. Insere\n");
        printf("2. Retira\n");
        printf("3. Quantidade de nodos\n");
        printf("4. Exibe situacao da fila\n");
        printf("5. Consulta frente\n");
        printf("=========================\n");
        printf("Digite sua opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {

            case 1: // Insere
                printf("Digite o codigo: ");
                scanf("%d", &d.cod);
                printf("Digite o peso: ");
                scanf("%f", &d.peso);

                retorno = insere(&fila, d);
                if (retorno == SUCESSO)
                    printf("Insercao realizada com sucesso.\n");
                else
                    printf("Falha na insercao (faltou memoria).\n");
                break;

            case 2: // Retira
                retorno = retira(&fila, &d);
                if (retorno == SUCESSO)
                    printf("Removido -> Codigo: %d | Peso: %.2f\n", d.cod, d.peso);
                else
                    printf("Nao foi possivel retirar (fila vazia).\n");
                break;

            case 3: // Quantidade de nodos
                printf("Quantidade de nodos na fila: %d\n", quantidadeDeNodos(fila));
                break;

            case 4: // Situação da fila
                if (estaVazia(fila))
                    printf("A fila esta vazia.\n");
                else
                    printf("A fila possui 1 ou mais nodos.\n");
                break;

            case 5: // Consulta frente
                retorno = consulta(fila, &d);
                if (retorno == SUCESSO)
                    printf("Frente -> Codigo: %d | Peso: %.2f\n", d.cod, d.peso);
                else
                    printf("A fila está vazia.\n");
                break;

            case 0:
                printf("Encerrando o programa...\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }

        // Exibe a fila após cada operação
        if (opcao != 0) {
            printf("\nEstado atual da fila:\n");
            exibe(fila);
        }

    } while (opcao != 0);

    return 0;
}