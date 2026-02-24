//
// Created by gusta on 13/10/2025.
//

#ifndef ED_PILHA_ENCADEADA_H
#define ED_PILHA_ENCADEADA_H

#define SUCESSO 0
#define PILHA_VAZIA 1
#define FALTOU_MEMORIA 2

typedef struct {
    int cod;
    float peso;
} Dado;

typedef struct nodo Nodo;
struct nodo {
    Dado info;
    Nodo *prox;
};

typedef struct {
    Nodo *topo;
} Pilha;

void criaPilha(Pilha *pilha);
int empilha(Pilha *pilha, Dado dado);
int desempilha(Pilha *pilha, Dado *dado);
int estaVazia(Pilha pilha);
int consultaTopo(Pilha pilha, Dado *dado);
void exibe(Pilha pilha);
int quantidadeNodos(Pilha pilha);

#endif //ED_PILHA_ENCADEADA_H