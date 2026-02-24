#include <stdio.h>
#include <stdlib.h>

main() {
    char cpf[12];  // Precisa ser 12 para caber os 11 dígitos + o caractere nulo '\0'
    int sum, check, dreal;
    
    printf("Digite o CPF: \n");
    scanf("%11s", cpf); // %11s impede buffer overflow

    for (int j = 10; j<12; j++){
        sum = 0;
        for(int i = 0; i<j-1; i++){
            //printf("%c --> %d\n", cpf[i], (cpf[i] - '0') * (j - i));
            sum += (cpf[i] - '0') * (j - i);
        }
        check = 11-sum%11;
        dreal = cpf[j-1] - '0';
        if(check>=10){
            check = 0;
        }
        if(check!=dreal){
            printf("CPF invalido");
            return 0;
        }
    }
    printf("CPF valido");
    return 0;
}