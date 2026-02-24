#include <stdio.h>
#include <stdlib.h>
#include "listase.h"
#include "listase.c"

int main() {
    ListaSE lista;
    Dado d;
    int opcao, codigo, codRef, retorno;

    criaLista(&lista);

    do {
        printf("\n=========================\n");
        printf("        MENU LISTA       \n");
        printf("=========================\n");
        printf("0. Fim\n");
        printf("1. Inclui no inicio\n");
        printf("2. Exibe lista\n");
        printf("3. Quantidade de nodos\n");
        printf("4. Exibe situacao da lista\n");
        printf("5. Exclui do inicio\n");
        printf("6. Inclui no fim\n");
        printf("7. Exclui do fim\n");
        printf("8. Consulta por codigo\n");
        printf("9. Inclui depois\n");
        printf("10. Exclui nodo\n");
        printf("=========================\n");
        printf("Digite sua opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {

            case 1: // Inclui no início
                printf("Digite o codigo: ");
                scanf("%d", &d.cod);
                printf("Digite o peso: ");
                scanf("%f", &d.peso);

                retorno = incluiNoInicio(&lista, d);
                if (retorno == SUCESSO)
                    printf("Inclusao realizada com sucesso!\n");
                else
                    printf("Falha na inclusao!\n");
                break;

            case 2: // Exibe lista
                exibe(lista);
                break;

            case 3: // Quantidade de nodos
                printf("Quantidade de nodos: %d\n", quantidadeDeNodos(lista));
                break;

            case 4: // Exibe situação da lista
                if (estaVazia(lista))
                    printf("A lista esta vazia.\n");
                else
                    printf("A lista possui 1 ou mais nodos.\n");
                break;

            case 5: // Exclui do inicio
                retorno = excluiDoInicio(&lista, &d);
                if (retorno == SUCESSO)
                    printf("Excluido -> Codigo: %d | Peso: %.2f\n", d.cod, d.peso);
                else
                    printf("Nao foi possivel excluir (lista vazia).\n");
                break;

            case 6: // Inclui no fim
                printf("Digite o codigo: ");
                scanf("%d", &d.cod);
                printf("Digite o peso: ");
                scanf("%f", &d.peso);

                retorno = incluiNoFim(&lista, d);
                if (retorno == SUCESSO)
                    printf("Inclusao no fim realizada com sucesso!\n");
                else
                    printf("Falha na inclusao no fim!\n");
                break;

            case 7: // Exclui do fim
                retorno = excluiDoFim(&lista, &d);
                if (retorno == SUCESSO)
                    printf("Excluido do fim -> Codigo: %d | Peso: %.2f\n", d.cod, d.peso);
                else
                    printf("Nao foi possivel excluir (lista vazia).\n");
                break;

            case 8: // Consulta por codigo
                printf("Digite o codigo a consultar: ");
                scanf("%d", &codigo);

                retorno = consultarPorCodigo(lista, codigo, &d);
                if (retorno == SUCESSO)
                    printf("Encontrado -> Codigo: %d | Peso: %.2f\n", d.cod, d.peso);
                else
                    printf("Codigo nao encontrado.\n");
                break;

            case 9: // Inclui depois
                printf("Digite o codigo de referencia: ");
                scanf("%d", &codRef);
                printf("Digite o novo codigo: ");
                scanf("%d", &d.cod);
                printf("Digite o peso: ");
                scanf("%f", &d.peso);

                retorno = incluiDepois(&lista, codRef, d);
                if (retorno == SUCESSO)
                    printf("Inclusao realizada apos o codigo %d com sucesso!\n", codRef);
                else if (retorno == CODIGO_INEXISTENTE)
                    printf("Codigo de referencia %d nao encontrado.\n", codRef);
                else
                    printf("Falha na inclusao!\n");
                break;

            case 10: // Exclui nodo
                printf("Digite o codigo do nodo a excluir: ");
                scanf("%d", &codigo);

                retorno = excluiNodo(&lista, codigo, &d);
                if (retorno == SUCESSO)
                    printf("Excluido -> Codigo: %d | Peso: %.2f\n", d.cod, d.peso);
                else
                    printf("Codigo nao encontrado.\n");

            case 0:
                printf("Encerrando o programa...\n");
                break;

            default:
                printf("Opcao invalida! Tente novamente.\n");
        }

        // Exibe lista
        if (opcao != 0) {
            printf("\nEstado atual da lista:\n");
            exibe(lista);
        }

    } while (opcao != 0);

    return 0;
}