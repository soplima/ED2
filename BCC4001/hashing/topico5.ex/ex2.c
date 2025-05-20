#include <stdio.h>

//2x 3 + 3x 2 + 4x + 5 = ((2x + 3)x + 4)x + 5

//!Considere que a string é terminada em ‘\0’ (null-terminated).

//!Aplicacao do metoddo Horner
unsigned int string_hash(char* string, int M){
int k = 31;
int h = 0;
    for (int i = 0; string[i] != 0; i++){
        h = (h * k ) + string[i]; 
    }
    return h % M;
}

int main() {
    int x;
    printf("Digite o valor de x: ");
    scanf("%d", &x);

    // Método de Horner: ((2x + 3)x + 4)x + 5
    int resultado = ((2 * x + 3) * x + 4) * x + 5;

    printf("Resultado da expressao 2x^3 + 3x^2 + 4x + 5 com x = %d: %d\n", x, resultado);

    return 0;
}