#include <stdio.h>

#include " Cheque.c"

int main() {
    int n1, n2;
    double v1, v2;

    // Ler dois números (números dos cheques)
    scanf("%d %d", &n1, &n2);

    // Criar 2 cheques
    Cheque c1 = criaCheque(n1);
    Cheque c2 = criaCheque(n2);

    // Ler 2 valores
    scanf("%lf %lf", &v1, &v2);

    // emitir os 2 cheques
    emiteCheque(&c1, v1);
    emiteCheque(&c2, v2);

    // Escrever na tela os dados dos 2 cheques
    exibeCheque(c1);
    exibeCheque(c2);

    // Compensar o que possui maior valor
    if (obtemValor(c1) > obtemValor(c2)) {
        compensaCheque(&c1);
    } else {
        compensaCheque(&c2);
    }

    // Escreva somente a co digo da situaça o dos 2 cheques
    printf("%d %d\n", obtemSituacao(c1), obtemSituacao(c2));

    // Escreva somente a nu mero dos 2 cheques
    printf("%d %d\n", obtemNumero(c1), obtemNumero(c2));

    return 0;
}
