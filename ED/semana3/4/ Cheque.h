#ifndef ED_CHEQUE_H
#define ED_CHEQUE_H

typedef struct {
    int numero;
    double valor;
    int situacao;
    /*
        0 = em branco
        1 = emitido
        2 = compensado
    */
} Cheque;

// Protótipos
Cheque criaCheque(int numero);
void exibeCheque(Cheque c);
int obtemSituacao(Cheque c);
double obtemValor(Cheque c);
int obtemNumero(Cheque c);
int compensaCheque(Cheque *c);
int emiteCheque(Cheque *c, double valor);

#endif //ED_CHEQUE_H