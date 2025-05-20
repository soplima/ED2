#include <stdio.h>
#include <string.h>

// Seja n o comprimento da string. Encontre duas funções 
// (matemáticas) fa(n) e fb(n) que calcule o número
// de somas e multiplicações realizadas pelos métodos implementados 
// nos exercícios a e b. Compare os fa(n) e
// fb(n) para n = 5, 10, 20, 100.

unsigned int horner_hash(char* string, int M){
    int k = 31;
    int h = 0;
    int multHorn = 0;
    int somHorn = 0;
    for(int i = 0; string[i] != '\0'; i++){
        h = (h * k) + string[i];
        multHorn++;
        somHorn++;
    }
    printf("Somas: %d\n", somHorn);
    printf("Multiplicações: %d\n", multHorn);
    return h % M;
}

unsigned int polynomial_hash(char* string, int M){
    //dividir a string eem tokens 
    //somar e multiplicar cada token 
    int k = 31;
    int h = 0;
    int multPol = 0;
    int len = strlen(string);

    for (int i = 0; i < len; i++) {
    int power = 1;
        for (int j = 0; j < len - i - 1; j++) {
            power *= k;
            multPol++;
        }
        h += string[i] * power;
        multPol++;
    }
    printf("Multiplicações: %d\n", multPol);
    return h % M;
}


int main() {
    char palavra[] = "ABCDEFJHIJ"; // tamanho n = 10
    unsigned int hash1 = horner_hash(palavra, 37);
    printf("[Horner] Hash de \"%s\" = %u\n\n", palavra, hash1);

    unsigned int hash2 = polynomial_hash(palavra, 37);
    printf("[Polinomial] Hash de \"%s\" = %u\n", palavra, hash2);
    return 0;
}
