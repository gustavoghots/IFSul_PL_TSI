#include<stdio.h>

void duplaClassificada(int x,int y,int ordem){
    if(ordem == 0 && x>y){
        printf("%d %d\n",y,x);
        return;
    }else if(ordem == 1 && x<y){
        printf("%d %d\n",y,x);
        return;
    }
    printf("%d %d\n",x,y);
}

void main(){
    int x,y;
    scanf("%d",&x);
    scanf("%d",&y);
    while(x!=y){
        duplaClassificada(x,y,(x+y)%2);
        scanf("%d",&x);
        scanf("%d",&y);
    };
    printf("programa encerrado");
}