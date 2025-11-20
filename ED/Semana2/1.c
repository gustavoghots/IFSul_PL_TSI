#include<stdio.h>

void duplaCrescente(int x, int y){
    if (x > y){
        printf("%d %d\n",y,x);
    }else {
        printf("%d %d\n",x,y);
    }
}

void main(){
    int x,y;
    scanf("%d",&x);
    scanf("%d",&y);
    while(x!=y){
        duplaCrescente(x,y);
        scanf("%d",&x);
        scanf("%d",&y);
    };
    printf("programa encerrado");
}