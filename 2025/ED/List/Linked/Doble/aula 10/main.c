//
// Created by gusta on 23/11/2025.
//

#include <stdio.h>
#include "DobleLinkedList.h"
#include "dobleLinkedList.c"
#include "jsonHandler.h"
#include "jsonHandler.c"

int main() {
    List_DL list;
    initList(&list);

    int op;

    do {
        printf("\n--- MENU ---\n");
        printf("0. Fim\n");
        printf("1. Inclui no inicio\n");
        printf("2. Exibe lista\n");
        printf("3. Quantidade de nodos\n");
        printf("4. Exibe situacao da lista\n");
        printf("5. Exclui do inicio\n");
        printf("6. Inclui no fim\n");
        printf("7. Exclui do fim\n");
        printf("8. Consulta por ID\n");
        printf("9. Inclui Depois\n");
        printf("10. Exclui nodo por ID\n");
        printf("11. Grava em Arquivo de Texto (JSON)\n");
        printf("12. Le de Arquivo de Texto (JSON)\n");

        printf("Opcao: ");
        scanf("%d", &op);

        int status = SUCCESS;
        Data aux;
        int idRef;
        char filename[128] = "database.json";

        switch (op) {

            case 1: // Inclui no início
                printf("ID: ");
                scanf("%d", &aux.id);
                printf("QTY: ");
                scanf("%lf", &aux.qty);
                status = insertStart(&list, createNode(aux));
                break;

            case 2: // Exibe lista
                printList(&list);
                break;

            case 3: // Quantidade de nodos
                printf("Quantidade de nodos = %d\n", listSize(&list));
                break;

            case 4: // Situação da lista
                if (isEmpty(&list))
                    printf("A lista esta vazia\n");
                else
                    printf("A lista possui 1 ou mais nodos\n");
                break;

            case 5: // Exclui início
                status = removeStart(&list, &aux);
                if (status == SUCCESS)
                    printf("Removido: ID=%d QTY=%.2lf\n", aux.id, aux.qty);
                break;

            case 6: // Inclui fim
                printf("ID: ");
                scanf("%d", &aux.id);
                printf("QTY: ");
                scanf("%lf", &aux.qty);
                status = insertEnd(&list, createNode(aux));
                break;

            case 7: // Exclui fim
                status = removeEnd(&list, &aux);
                if (status == SUCCESS)
                    printf("Removido: ID=%d QTY=%.2lf\n", aux.id, aux.qty);
                break;

            case 8: // Consulta por ID
                printf("ID a consultar: ");
                scanf("%d", &idRef);
                status = getByID(&list, idRef, &aux);
                if (status == SUCCESS)
                    printf("Encontrado: ID=%d QTY=%.2lf\n", aux.id, aux.qty);
                break;

            case 9: // Inclui depois
                printf("ID de referencia: ");
                scanf("%d", &idRef);
                printf("Novo ID: ");
                scanf("%d", &aux.id);
                printf("Novo QTY: ");
                scanf("%lf", &aux.qty);
                status = insertAfter(&list, idRef, aux);
                break;

            case 10: // Exclui por ID
                printf("ID a excluir: ");
                scanf("%d", &idRef);
                status = removeByID(&list, idRef, &aux);
                if (status == SUCCESS)
                    printf("Excluido: ID=%d QTY=%.2lf\n", aux.id, aux.qty);
                break;

            case 11: // Gravar JSON
                status = writeArrayToJSON(filename, &list);
                if (status == SUCCESS)
                    printf("Arquivo '%s' gravado com sucesso.\n", filename);
                else
                    printf("Falha ao gravar em '%s'.\n", filename);
                break;

            case 12: // Ler JSON
                initList(&list); // limpa a lista ANTES de carregar
                status = readArrayFromJSON(filename, &list);
                if (status == SUCCESS)
                    printf("Arquivo '%s' lido com sucesso.\n", filename);
                else
                    printf("Falha ao ler arquivo '%s'.\n", filename);
                break;

            case 0:
                printf("Encerrando...\n");
                break;

            default:
                printf("Opcao invalida!\n");
                status = INVALID_INDEX;
                break;
        }

        // Exibe lista e resultado após cada operação
        if (op != 0) {
            printf("\nEstado atual da lista:\n");
            printList(&list);

            if (status == SUCCESS)
                printf("Operacao executada com SUCESSO.\n");
            else
                printf("Operacao NAO executada. Codigo de erro = %d\n", status);
        }

    } while (op != 0);

    return 0;
}