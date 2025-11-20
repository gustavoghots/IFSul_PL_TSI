#include <stdio.h>
#include <stdlib.h>
#include "listase.h"

void criaLista(ListaSE *lt){
     lt->inicio = NULL;
}

int incluiNoInicio(ListaSE *lt, Dado d){
    Nodo *pNodo = malloc (sizeof (Nodo));
    if (pNodo == NULL)
       return(FALTOU_MEMORIA);
    else {
       pNodo->info = d;
       pNodo->prox = lt->inicio;
       lt->inicio = pNodo;
       return(SUCESSO);
    }
}
 
void exibe(ListaSE lt){
    Nodo *pAux = lt.inicio;
     printf("\nInicio: %p \n", lt.inicio);
     printf("Exibindo a Lista\n");
     printf("[EndNodo] [cd] [peso] [EndProx]\n");
     while (pAux != NULL) {
           printf("%p - %3d %.2f - %p\n", pAux, pAux->info.cod, pAux->info.peso, pAux->prox);
           pAux = pAux->prox;
     }
}

int quantidadeDeNodos(ListaSE lt){
    int conta=0;

    Nodo *pAux = lt.inicio;
    while (pAux != NULL) {
           conta++;
           pAux = pAux->prox;
    }
    return(conta);
}

int estaVazia(ListaSE lt){
    if (lt.inicio==NULL)
       return(LISTA_VAZIA);
    else
       return(0);     
}

int excluiDoInicio(ListaSE *lt, Dado *d){
    if (estaVazia(*lt))
        return LISTA_VAZIA;

    Nodo *pAux = lt->inicio;
    *d = pAux->info;
    lt->inicio = pAux->prox;
    free(pAux);

    return SUCESSO;
}


int incluiNoFim(ListaSE *lt, Dado d) {
    Nodo *pNodo = malloc(sizeof(Nodo));
    if (pNodo == NULL)
        return FALTOU_MEMORIA;

    pNodo->info = d;
    pNodo->prox = NULL;

    if (lt->inicio == NULL) {
        lt->inicio = pNodo;
    } else {
        Nodo *pAux = lt->inicio;
        while (pAux->prox != NULL) {
            pAux = pAux->prox;
        }
        pAux->prox = pNodo;
    }

    return SUCESSO;
}


int excluiDoFim(ListaSE *lt, Dado *d) {
    if (estaVazia(*lt))
        return LISTA_VAZIA;

    Nodo *pAtual = lt->inicio;
    Nodo *pAnterior = NULL;

    while (pAtual->prox != NULL) {
        pAnterior = pAtual;
        pAtual = pAtual->prox;
    }

    *d = pAtual->info;

    if (pAnterior == NULL) {
        lt->inicio = NULL;
    } else {
        pAnterior->prox = NULL;
    }

    free(pAtual);
    return SUCESSO;
}

int incluiDepois(ListaSE *lt, int codigo, Dado d) {
    if (estaVazia(*lt))
        return CODIGO_INEXISTENTE;

    Nodo *pAtual = lt->inicio;

    while (pAtual != NULL && pAtual->info.cod != codigo) {
        pAtual = pAtual->prox;
    }

    if (pAtual == NULL)
        return CODIGO_INEXISTENTE;

    Nodo *pNodo = malloc(sizeof(Nodo));
    if (pNodo == NULL)
        return FALTOU_MEMORIA;

    pNodo->info = d;
    pNodo->prox = pAtual->prox;
    pAtual->prox = pNodo;

    return SUCESSO;
}

int excluiNodo(ListaSE *lt, int codigo, Dado *d) {
    if (estaVazia(*lt))
        return CODIGO_INEXISTENTE;

    Nodo *pAtual = lt->inicio;
    Nodo *pAnterior = NULL;

    while (pAtual != NULL && pAtual->info.cod != codigo) {
        pAnterior = pAtual;
        pAtual = pAtual->prox;
    }

    if (pAtual == NULL)
        return CODIGO_INEXISTENTE;

    *d = pAtual->info;

    if (pAnterior == NULL) {
        lt->inicio = pAtual->prox;
    } else {
        pAnterior->prox = pAtual->prox;
    }

    free(pAtual);

    return SUCESSO;
}

int consultarPorCodigo(ListaSE lt, int codigo, Dado *d) {
    Nodo *pAtual = lt.inicio;

    while (pAtual != NULL && pAtual->info.cod != codigo) {
        pAtual = pAtual->prox;
    }

    if (pAtual == NULL)
        return CODIGO_INEXISTENTE;

    *d = pAtual->info;

    return SUCESSO;
}
