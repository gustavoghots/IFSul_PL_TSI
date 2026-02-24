#include <stdio.h>
#include <stdlib.h>

int main() {
    int qtd_empr, qtd_bic;
    float sal_m, custoBic, lucroB, sal_vendedor, lucroL;

    printf("quantidade de empregados da loja:\n");
    scanf("%d",&qtd_empr);
    printf("valor do salário mínimo:\n");
    scanf("%f",&sal_m);
    printf("preço de custo de cada bicicleta:\n");
    scanf("%f",&custoBic);
    printf("quantidade de bicicletas vendidas:\n");
    scanf("%d",&qtd_bic);

    sal_vendedor = (sal_m*2)+((qtd_bic*custoBic)*0.15/qtd_empr);
    lucroB = qtd_bic*custoBic*0.5;
    lucroL = lucroB-(sal_vendedor*qtd_empr);

    printf("salário final de cada empregado: %f \n",sal_vendedor);
    printf("lucro da loja: %f",lucroL);

}