//
// Created by gusta on 09/11/2025.
//

#ifndef ED_FILASE_H
#define ED_FILASE_H

#define SUCESSO 0
#define FILA_VAZIA 1
#define FALTOU_MEMORIA 2

typedef struct {
    int cod;
    float peso;
} Dado;

typedef struct nodo {
    Dado info;
    struct nodo *prox;
} Nodo;

typedef struct {
    Nodo *frente;
    Nodo *re;
} FilaSE;

void criaFila(FilaSE *f);
int insere(FilaSE *f, Dado d);
int retira(FilaSE *f, Dado *d);
int estaVazia(FilaSE f);
int consulta(FilaSE f, Dado *d);
void exibe(FilaSE f);
int quantidadeDeNodos(FilaSE f);


#endif //ED_FILASE_H