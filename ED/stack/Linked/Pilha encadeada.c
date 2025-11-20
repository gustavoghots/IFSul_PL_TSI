//
// Created by gusta on 13/10/2025.
//

#include "Pilha encadeada.h"

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

void criaPilha(Pilha *pilha) {
    pilha->topo = NULL;
}

int empilha(Pilha *pilha, Dado dado) {
    Nodo *novo = malloc(sizeof(Nodo));
    if (!novo) return FALTOU_MEMORIA;

    novo->info = dado;
    novo->prox = pilha->topo;
    pilha->topo = novo;

    return SUCESSO;
}

int estaVazia(Pilha pilha) {
    if (!pilha.topo) return PILHA_VAZIA;
    return SUCESSO;
}

int desempilha(Pilha *pilha, Dado *dado) {
    if (estaVazia(*pilha)) return PILHA_VAZIA;

    Nodo *removido = pilha->topo;
    *dado = removido->info;
    pilha->topo = removido->prox;
    free(removido);
    return SUCESSO;
}

int consultaTopo(Pilha pilha, Dado *dado) {
    if (estaVazia(pilha)) return PILHA_VAZIA;

    *dado = pilha.topo->info;
    return SUCESSO;
}

void exibe(Pilha pilha) {
    Nodo *aux = pilha.topo;

    if (aux == NULL) {
        printf("Pilha vazia.\n");
        return;
    }

    printf("Elementos da pilha:\n");
    while (aux != NULL) {
        printf("Codigo: %d | Peso: %.2f\n", aux->info.cod, aux->info.peso);
        aux = aux->prox;
    }
}

int quantidadeNodos(Pilha pilha) {
    int cont = 0;
    Nodo *aux = pilha.topo;
    while (aux != NULL) {
        cont++;
        aux = aux->prox;
    }
    return cont;
}

