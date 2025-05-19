#include <stdio.h>

// Hashing de Strings – Uma função de hashing popularmente utilizada em strings baseia-se em 
// converter a representação em ASCII da string em um inteiro em uma base K qualquer, seguido por 
// módulo M. Por exemplo, a string “ABC” (65, 66, 67) pode ser representada na 
// base K=31 por: 65 × 31^2 + 66 × 31^1 + 67 × 31^0 = 65 × 961 + 66 × 31 + 67 × 1 = 64578. 
// Com M=37, H(ABC; 37) = 64578 % 37 = 13. Lembrando que K e M são parâmetros e podem ser 
// escolhidos de acordo com a aplicação.

//!Considere que a string é terminada em ‘\0’ (null-terminated).

unsigned int string_hash(char* string, int M){
    //dividir a string eem tokens 
    //somar e multiplicar cada token 
    int k = 31;
    int h = 0;
    for(int i = 0; string[i] != '\0'; i++){
        h = (h * k) + string[i];
        // (0 * 31) + 65
        // (65 * 31) + 66
        //(2081 * 31) + 67
    }
    return h % M;
}

int main() {
    char* palavra = "ABCDEFGHIJKLMNOPQRS";
    int K = 31;
    int M = 37;

    unsigned int h = string_hash(palavra, M);
    printf("Hash da string \"%s\" = %u\n", palavra, h);

    return 0;
}