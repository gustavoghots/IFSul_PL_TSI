//
// Created by gusta on 01/10/2025.
//

#include <stdio.h>
#include "lista.h"
#include "lista.c"


int main() {
    ListaCF lista;
    Dado d, removido;
    int opcao, cod, retorno;

    criaLista(&lista);
    printf("Lista criada.\n");

    do {
        printf("\n====== MENU ======\n");
        printf("0. Fim\n");
        printf("1. Inclui no fim\n");
        printf("2. Exibe lista\n");
        printf("3. Quantidade de nodos\n");
        printf("4. Exibe situacao da lista\n");
        printf("5. Exclui do fim\n");
        printf("6. Inclui no inicio\n");
        printf("7. Exclui do inicio\n");
        printf("8. Consulta por codigo\n");
        printf("9. Inclui Antes\n");
        printf("10. Exclui nodo\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 0:
                printf("Fim do programa.\n");
                break;

            case 1: // inclui no fim
                printf("Digite codigo e peso: ");
                scanf("%d %f", &d.cod, &d.peso);
                retorno = incluiNoFim(&lista, d);
                printf("Operacao %s\n", retorno == SUCESSO ? "SUCESSO" : "FALHOU");
                exibe(lista);
                break;

            case 2: // exibe lista
                exibe(lista);
                break;

            case 3: // quantidade
                printf("Quantidade de nodos: %d\n", quantidadeDeNodos(lista));
                break;

            case 4: // situacao
                printf("Lista %s\n", estaVazia(lista) ? "VAZIA" : "NAO VAZIA");
                printf("Lista %s\n", estaCheia(lista) ? "CHEIA" : "NAO CHEIA");
                break;

            case 5: // exclui do fim
                retorno = excluiDoFim(&lista, &removido);
                if (retorno == SUCESSO) {
                    printf("Excluido do fim: cod=%d peso=%.2f\n", removido.cod, removido.peso);
                }
                printf("Operacao %s\n", retorno == SUCESSO ? "SUCESSO" : "FALHOU");
                exibe(lista);
                break;

            case 6: // inclui no inicio
                printf("Digite codigo e peso: ");
                scanf("%d %f", &d.cod, &d.peso);
                retorno = incluiNoInicio(&lista, d);
                printf("Operacao %s\n", retorno == SUCESSO ? "SUCESSO" : "FALHOU");
                exibe(lista);
                break;

            case 7: // exclui do inicio
                retorno = excluiDoInicio(&lista, &removido);
                if (retorno == SUCESSO) {
                    printf("Excluido do inicio: cod=%d peso=%.2f\n", removido.cod, removido.peso);
                }
                printf("Operacao %s\n", retorno == SUCESSO ? "SUCESSO" : "FALHOU");
                exibe(lista);
                break;

            case 8: // consulta por código
                printf("Digite codigo: ");
                scanf("%d", &cod);
                retorno = consultaPorCodigo(lista, cod, &removido);
                if (retorno == SUCESSO) {
                    printf("Encontrado: cod=%d peso=%.2f\n", removido.cod, removido.peso);
                }
                printf("Operacao %s\n", retorno == SUCESSO ? "SUCESSO" : "FALHOU");
                break;

            case 9: // inclui antes
                printf("Digite codigo e peso do novo elemento: ");
                scanf("%d %f", &d.cod, &d.peso);
                printf("Digite o codigo de referencia: ");
                scanf("%d", &cod);
                retorno = incluiAntes(&lista, d, cod);
                printf("Operacao %s\n", retorno == SUCESSO ? "SUCESSO" : "FALHOU");
                exibe(lista);
                break;

            case 10: // exclui nodo
                printf("Digite codigo a excluir: ");
                scanf("%d", &cod);
                retorno = excluiNodo(&lista, cod, &removido);
                if (retorno == SUCESSO) {
                    printf("Excluido: cod=%d peso=%.2f\n", removido.cod, removido.peso);
                }
                printf("Operacao %s\n", retorno == SUCESSO ? "SUCESSO" : "FALHOU");
                exibe(lista);
                break;

            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 0);

    return 0;
}
