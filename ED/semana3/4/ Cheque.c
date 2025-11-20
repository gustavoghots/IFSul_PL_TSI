#include " Cheque.h"

#include <stdio.h>

// criaCheque
Cheque criaCheque(int numero) {
    Cheque c;
    c.numero = numero;
    c.valor = 0;
    c.situacao = 0;
    return c;
}

// exibeCheque
void exibeCheque(Cheque c) {
    printf("Numero: %d | Valor: %.2f | Situacao: %d\n", c.numero, c.valor, c.situacao);
}

// obtemSituacao
int obtemSituacao(Cheque c) {
    return c.situacao;
}

// obtemValor
double obtemValor(Cheque c) {
    return c.valor;
}

// obtemNumero
int obtemNumero(Cheque c) {
    return c.numero;
}

// compensaCheque
int compensaCheque(Cheque *c) {
    if (c->situacao == 1) { // só compensa se emitido
        c->situacao = 2;
        return 0; // sucesso
    }
    return 1; // erro
}

// emiteCheque
int emiteCheque(Cheque *c, double valor) {
    if (c->situacao == 0) { // só emite se em branco
        c->valor = valor;
        c->situacao = 1;
        return 0; // sucesso
    }
    return 1; // erro
}