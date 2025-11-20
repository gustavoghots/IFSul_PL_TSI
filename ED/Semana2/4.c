#include<stdio.h>

int calcDivisao (int *x, int *y){
    if(*y == 0){
        return 1;
    }
    printf("%.2f\n",(float)*x / *y);
    return 0;
}

void main(){
    int x,y,n;

    scanf("%d",&n);

    for (int i = 0; i < n; i++){
        scanf("%d",&x);
        scanf("%d",&y);
        if(calcDivisao(&x,&y)){
            printf("Divisão por zero\n");
        }
    }
}