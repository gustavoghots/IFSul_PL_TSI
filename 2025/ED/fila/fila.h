//
// Created by gusta on 23/09/2025.
//

#ifndef ED_FILA_H
#define ED_FILA_H

#define SUCESSO          0
#define FILA_VAZIA       1
#define FILA_CHEIA       2
#define DADO_INEXISTENTE 3
#define MAX_NODOS        5

typedef struct {
    int cod;
    float peso;
} Dado;

typedef struct {
    Dado v[MAX_NODOS];
    int frente;
    int re;
} FilaCF;

void criaFila(FilaCF *f);
int estaVazia(FilaCF f);
int insere(FilaCF *f, Dado d);
int retira(FilaCF *f, Dado *d);
int consulta(FilaCF f, Dado *d);
void exibe(FilaCF f);
int pesquisa(FilaCF f, int cod, Dado *d);


#endif //ED_FILA_H