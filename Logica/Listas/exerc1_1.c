#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>

int main(){
    float a,b,c;

    printf("digite o valor de a:\n");
    scanf("%f",&a);
    printf("digite o valor de b:\n");
    scanf("%f",&b);
    printf("digite o valor de c:\n");
    scanf("%f",&c);

    printf("área do triângulo: %0.0f\n",(a*b/2));
    printf("área do quadrado: %0.0f\n",pow(b,2));
    printf("área do retângulo: %0.0f\n",b*a);
    printf("área do círculo: %0.0f\n", M_PI * c * c);
    return 0;
}