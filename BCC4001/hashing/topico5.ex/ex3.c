#include <stdio.h>

// Seja n o comprimento da string. Encontre duas funções 
// (matemáticas) fa(n) e fb(n) que calcule o número
// de somas e multiplicações realizadas pelos métodos implementados 
// nos exercícios a e b. Compare os fa(n) e
// fb(n) para n = 5, 10, 20, 100.

unsigned int string_hash(char* string, int M){
    int k = 31;
    int h = 0;
    int mult = 0;
    int som = 0;
    for(int i = 0; string[i] != '\0'; i++){
        h = (h * k) + string[i];
        mult++;
        som++;
    }
    printf("Somas: %d\n", som);
    printf("Multiplicações: %d\n", mult);
    return h % M;
}

int main() {
    char palavra[] = "ABCDEFJHIJ";
    unsigned int hash = string_hash(palavra, 37);
    printf("Hash de \"%s\" = %u\n", palavra, hash);
    return 0;
}