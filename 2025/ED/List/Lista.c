//
// Created by gusta on 30/09/2025.
//

#include "Lista.h"
#include <stdio.h>

void criaLista(ListaCF *lista) {
    lista->n=0;
}

int quantidadeDeNodos(ListaCF lista) {
    return lista.n;
}

int estaCheia(ListaCF lista) {
    if (lista.n == MAX_NODOS) {
        return LISTA_CHEIA;
    }
    return 0;
}

int estaVazia(ListaCF lista){
    if (lista.n == 0) {
        return LISTA_VAZIA;
    }
    return 0;
}

int incluiNoFim(ListaCF *lista,Dado dado) {
    if(estaCheia(*lista)){
        return LISTA_CHEIA;
    }
    lista->v[lista->n] = dado;
    lista->n++;
    return SUCESSO;
}

int incluiNoInicio(ListaCF *lista,Dado dado){
    if(estaCheia(*lista)){
        return LISTA_CHEIA;
    }
    for (int i = lista->n; i > 0; i--) {
        lista->v[i] = lista->v[i - 1];
    }
    lista->v[0] = dado;
    lista->n++;
    return SUCESSO;
}

int incluiAntes(ListaCF *lista,Dado dado,int cod) {
    if (estaVazia(*lista)) {
        return LISTA_VAZIA;
    }
    if (estaCheia(*lista)) {
        return LISTA_CHEIA;
    }
    for (int i = 0; i < lista->n; i++) {
        if (lista->v[i].cod == cod) {
            for (int j = lista->n; j > i; j--) {
                lista->v[j] = lista->v[j - 1];
            }
            lista->v[i] = dado;
            lista->n++;
            return SUCESSO;
        }
    }
    return CODIGO_INEXISTENTE;
}

int excluiDoFim(ListaCF *lista, Dado *dado) {
    if (estaVazia(*lista)) {
        return LISTA_VAZIA;
    }
    lista->n--;
    *dado = lista->v[lista->n];
    return SUCESSO;
}

int excluiDoInicio(ListaCF *lista, Dado *dado) {
    if (estaVazia(*lista)) {
        return LISTA_VAZIA;
    }
    *dado = lista->v[0];
    for (int i = 0; i < lista->n - 1; i++) {
        lista->v[i] = lista->v[i + 1];
    }
    lista->n--;
    return SUCESSO;
}

int excluiNodo(ListaCF *lista, int codigo, Dado *dado) {
    if (estaVazia(*lista)) {
        return LISTA_VAZIA;
    }
    for (int i = 0; i < lista->n; i++) {
        if (lista->v[i].cod == codigo) {
            *dado = lista->v[i];
            for (int j = i; j < lista->n - 1; j++) {
                lista->v[j] = lista->v[j + 1];
            }
            lista->n--;
            return SUCESSO;
        }
    }
    return CODIGO_INEXISTENTE;
}

int consultaPorCodigo(ListaCF lista, int codigo, Dado *dado) {
    if (estaVazia(lista)) {
        return LISTA_VAZIA;
    }
    for (int i = 0; i < lista.n; i++) {
        if (lista.v[i].cod==codigo) {
            *dado = lista.v[i];
            return SUCESSO;
        }
    }
    return CODIGO_INEXISTENTE;
}

void exibe(ListaCF lista) {
    if (estaVazia(lista)) {
        printf("Lista vazia.\n");
        return;
    }
    printf("Lista (%d elementos):\n", lista.n);
    for (int i = 0; i < lista.n; i++) {
        printf("Posicao %d -> Codigo: %d | Peso: %.2f\n", i, lista.v[i].cod, lista.v[i].peso);
    }
}