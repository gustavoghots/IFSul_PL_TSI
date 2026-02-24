#include <stdio.h>
#include <stdlib.h>

int main() {

    float a, b, c;

    printf("Digite o valor de a:\n");
    scanf("%f", &a);
    printf("Digite o valor de b:\n");
    scanf("%f", &b);
    printf("Digite o valor de c:\n");
    scanf("%f", &c);

    printf("Área do triângulo: %0.0f\n", (a * b / 2));
    printf("Área do quadrado: %0.0f\n", b * b);
    printf("Área do retângulo: %0.0f\n", a * b);
    printf("Área do círculo: %0.0f\n", 3.14159 * c * c);
    
    return 0;
}