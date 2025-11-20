#include <stdio.h>
#include <math.h>

void exibeDivisores(int n) {
    printf("%d:", n);

    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            printf(" %d", i);
            if (i != n / i) {
                printf(" %d", n / i);
            }
        }
    }

    printf("\n");
}

int main(void) {
    for (int i = 1; i <= 20; i++) {
        exibeDivisores(i);
    }
    return 0;
}