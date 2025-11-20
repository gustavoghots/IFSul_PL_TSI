//
// Created by gusta on 30/09/2025.
//

#ifndef ED_LISTA_H
#define ED_LISTA_H

#define MAX_NODOS 5
#define SUCESSO 0
#define LISTA_VAZIA 1
#define LISTA_CHEIA 2
#define CODIGO_INEXISTENTE 3

typedef struct {
    int cod;
    float peso;
} Dado;

typedef struct {
    int n;
    Dado v[MAX_NODOS];
} ListaCF;


void criaLista(ListaCF *lista);
int quantidadeDeNodos(ListaCF lista);
int estaCheia(ListaCF lista);
int estaVazia(ListaCF lista);

int incluiNoFim(ListaCF *lista,Dado dado);
int incluiNoInicio(ListaCF *lista,Dado dado);
int incluiAntes(ListaCF *lista,Dado dado,int cod);


int excluiDoFim(ListaCF *lista, Dado *dado);
int excluiDoInicio(ListaCF *lista, Dado *dado);
int excluiNodo(ListaCF *lista, int codigo, Dado *dado);

int consultaPorCodigo(ListaCF lista, int codigo, Dado *dado);
void exibe(ListaCF lista);

#endif //ED_LISTA_H