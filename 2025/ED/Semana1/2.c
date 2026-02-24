#include <stdio.h>

void exibeOnzeTracos(){
    printf("-----------\n");
}

void retanguloTracos(){
    for(int i=0; i<4;i++){
        exibeOnzeTracos();
    }
    printf("\n\n");
}

void main (){
    retanguloTracos();
    retanguloTracos();
}