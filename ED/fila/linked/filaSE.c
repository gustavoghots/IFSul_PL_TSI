//
// Created by gusta on 09/11/2025.
//

#include "filaSE.h"
#include <stdio.h>
#include <stdlib.h>

void criaFila(FilaSE *f) {
    f->frente = NULL;
    f->re = NULL;
}

int estaVazia(FilaSE f) {
    return (f.frente == NULL);
}

int insere(FilaSE *f, Dado d) {
    Nodo *novo = (Nodo *) malloc(sizeof(Nodo));
    if (novo == NULL)
        return FALTOU_MEMORIA;

    novo->info = d;
    novo->prox = NULL;

    if (estaVazia(*f)) {
        f->frente = novo;
    } else {
        f->re->prox = novo;
    }
    f->re = novo;

    return SUCESSO;
}

int retira(FilaSE *f, Dado *d) {
    if (estaVazia(*f))
        return FILA_VAZIA;

    Nodo *removido = f->frente;
    *d = removido->info;
    f->frente = removido->prox;

    if (f->frente == NULL)
        f->re = NULL;

    free(removido);
    return SUCESSO;
}

int consulta(FilaSE f, Dado *d) {
    if (estaVazia(f))
        return FILA_VAZIA;

    *d = f.frente->info;
    return SUCESSO;
}

void exibe(FilaSE f) {
    Nodo *aux = f.frente;

    if (aux == NULL) {
        printf("Fila vazia.\n");
        return;
    }

    printf("\nExibindo a fila:\n");
    printf("[cod] [peso]\n");
    while (aux != NULL) {
        printf("%3d %.2f\n", aux->info.cod, aux->info.peso);
        aux = aux->prox;
    }
}

int quantidadeDeNodos(FilaSE f) {
    int contador = 0;
    Nodo *aux = f.frente;

    while (aux != NULL) {
        contador++;
        aux = aux->prox;
    }
    return contador;
}
