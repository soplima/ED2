#include <stdio.h>

//Uma forma eficiente de implementar a função de 
//hashing sugerida acima é utilizando o Método de Horner.
// 2x^3 + 3x^2 + 4x + 5 = ((2x + 3)x + 4)x + 5
unsigned int string_hash(char* string, int M){
    int hash = 0;
    int k = 31;
    for(int i = 0; string[i] != '\0'; i++){
        hash = hash * k + string[i];
    }
    return hash % M;
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