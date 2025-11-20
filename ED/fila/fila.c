#include <stdio.h>
#include "fila.h"

void criaFila(FilaCF *f) {
    f->frente = 0;
    f->re = -1;
}

int estaVazia(FilaCF f) {
    return (f.re == -1);
}

int insere(FilaCF *f, Dado d) {
    if ((f->re + 1) % MAX_NODOS == f->frente && f->re != -1) {
        return FILA_CHEIA;
    }
    if (estaVazia(*f)) {
        f->frente = 0;
        f->re = 0;
    } else {
        f->re = (f->re + 1) % MAX_NODOS;
    }
    f->v[f->re] = d;
    return SUCESSO;
}

int retira(FilaCF *f, Dado *d) {
    if (estaVazia(*f)) {
        return FILA_VAZIA;
    }
    *d = f->v[f->frente];
    if (f->frente == f->re) {
        f->frente = 0;
        f->re = -1;
    } else {
        f->frente = (f->frente + 1) % MAX_NODOS;
    }
    return SUCESSO;
}

int consulta(FilaCF f, Dado *d) {
    if (estaVazia(f)) {
        return FILA_VAZIA;
    }
    *d = f.v[f.frente];
    return SUCESSO;
}

void exibe(FilaCF f) {
    if (estaVazia(f)) {
        printf("Fila vazia.\n");
        return;
    }
    int i = f.frente;
    while (1) {
        printf("Cod: %d, Peso: %.2f\n", f.v[i].cod, f.v[i].peso);
        if (i == f.re) break;
        i = (i + 1) % MAX_NODOS;
    }
}

int pesquisa(FilaCF f, int cod, Dado *d) {
    if (estaVazia(f)) {
        return FILA_VAZIA;
    }
    int i = f.frente;
    while (1) {
        if (f.v[i].cod == cod) {
            *d = f.v[i];
            return SUCESSO;
        }
        if (i == f.re) break;
        i = (i + 1) % MAX_NODOS;
    }
    return DADO_INEXISTENTE;
}
