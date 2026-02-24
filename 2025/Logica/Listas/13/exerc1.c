#include <stdio.h>

main(){
    int linha = 0, coluna = 0, DP = 0, DS = 0, total = 0, i, j,
    matriz[4][4]={{2,1,3,4},{0,2,1,1},{2,4,3,2},{8,6,3,2}};

    //linha 2
    i = 2;
    for(j=0;j<4;j++){
        linha +=  matriz[i][j];
    }

    //coluna 1
    j=1;
    for(i=0;i<4;i++){
        coluna += matriz[i][j];
    }

    //diagonal principal
    for(i=0;i<4;i++){
        DP += matriz[i][i];
    }

    //diagonal secundaria
    for(i=0;i<4;i++){
        DS += matriz[3-i][i];
    }

    for(j=0;j<4;j++){
        for(i=0;i<4;i++){
        total += matriz[i][j];
        }
    }

    printf("
        11 (linha 2)
        13 (coluna 1)
        9 (diagonal principal)
        17 (diagonal secundária)
        44 (toda matriz)
        ",total);
}