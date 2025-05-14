//Uma função de hashing popularmente utilizada em strings baseia-se em converter
// a representação em ASCII da string em um inteiro em uma base K qualquer, seguido por módulo M. Por
// exemplo, a string “ABC” (65, 66, 67) pode ser representada na base K=31 por: 65×312+ 66×311+ 67×310 =
// 65 × 961 + 66 × 31 + 67 × 1 = 64578. Com M=37, H(ABC; 37) = 64578 % 37 = 13. Lembrando que K e M
// são parâmetros e podem ser escolhidos de acordo com a aplicação.

#include <stdio.h>

// Considere que a string é terminada em ‘\0’ (null-terminated).
unsigned int string_hash(char* string, int M){
    int hash = 0;
    int k = 31;
    for(int i = 0; string[i] != '\0'; i++){
        hash = hash * k + string[i];
    }
    return hash % M;
}


int main() {
    char* palavra = "ABCDEFGHIJKLMNOPQRS";
    int K = 31;
    int M = 37;

    unsigned int h = string_hash(palavra, M);
    printf("Hash da string \"%s\" = %u\n", palavra, h);

    return 0;
}