#include <stdio.h>

typedef struct {
    int numero;
    double saldo;
} Conta;

// Funções
Conta criarConta(int numero) {
    Conta conta;
    conta.numero = numero;
    conta.saldo = 0;
    return conta;
}

double obtemSaldo(Conta conta) {
    return conta.saldo;
}

void retiraDaConta(Conta *conta, double retira) {
    conta->saldo -= retira;
}

void depositaNaConta(Conta *conta, double deposito) {
    conta->saldo += deposito;
}

void main() {
    Conta corrente, poupanca;
    int numeroCorrente = 0, numeroPoupanca = 1;

    // Criação das contas
    corrente = criarConta(numeroCorrente);
    poupanca = criarConta(numeroPoupanca);

    int codigo;
    double valor;

    while (1) {
        printf("\nOperacao (1=Dep CC, 2=Dep Poup, 3=Ret CC, 4=Ret Poup, 5=Fim): ");
        scanf("%d", &codigo);

        if (codigo == 5) break;

        printf("Valor: ");
        scanf("%lf", &valor);

        switch (codigo) {
            case 1: // depósito corrente
                depositaNaConta(&corrente, valor);
                break;

            case 2: // depósito poupanca
                depositaNaConta(&poupanca, valor);
                break;

            case 3: // retirada corrente
                if (corrente.saldo >= valor) {
                    retiraDaConta(&corrente, valor);
                } else {
                    double falta = valor - corrente.saldo;
                    if (poupanca.saldo >= falta) {
                        // transfere da poupanca
                        retiraDaConta(&poupanca, falta);
                        depositaNaConta(&corrente, falta);
                        retiraDaConta(&corrente, valor);
                    } else {
                        printf("Saldo insuficiente!\n");
                    }
                }
                break;

            case 4: // retirada poupanca
                if (poupanca.saldo >= valor) {
                    retiraDaConta(&poupanca, valor);
                } else {
                    printf("Saldo insuficiente!\n");
                }
                break;

            default:
                printf("Codigo invalido!\n");
                break;
        }

        printf("Saldo CC: %.2lf | Saldo Poup: %.2lf\n", corrente.saldo, poupanca.saldo);
    }
}
