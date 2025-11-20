#include <stdio.h>

typedef struct {
    int h, m, s;
} Horario;

int main() {
    Horario x, y;
    scanf("%d %d %d", &x.h, &x.m, &x.s);
    scanf("%d %d %d", &y.h, &y.m, &y.s);

    if (x.h == y.h && x.m == y.m && x.s == y.s) {
        printf("Horarios iguais\n");
    } else if (
        (x.h < y.h) ||
        (x.h == y.h && x.m < y.m) ||
        (x.h == y.h && x.m == y.m && x.s < y.s)
    ) {
        printf("%02d:%02d:%02d\n", x.h, x.m, x.s);
    } else {
        printf("%02d:%02d:%02d\n", y.h, y.m, y.s);
    }

    return 0;
}
