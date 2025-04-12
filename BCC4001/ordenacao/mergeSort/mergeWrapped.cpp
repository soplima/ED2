#include <iostream>
#include <cstring>
#include <cstdlib> // para atoi e rand
using namespace std;

void swap(int *v, int a, int b){
    int temp = v[a];
    v[a] = v[b];
    v[b] = temp;
}

// Merge otimizado com vetores e/d pré-alocados
void merge(int *v, int n, int *e, int *d) {
    if(n == 1) return;

    // caso base: dois elementos → troca direta
    if(n == 2){
        if(v[0] > v[1]){
            swap(v, 0, 1);
        }
        return;
    }

    int meio = n / 2;

    // copiar partes para e e d usando memcpy
    for (int i = 0; i < meio; i++) e[i] = v[i];
    for(int i = 0; i < n - meio; i++) d[i] = v[meio + i];

    // chamadas recursivas com os mesmos vetores
    merge(e, meio, e, d);
    merge(d, n - meio, e, d);

    // intercalar de volta em v
    int i = 0, j = 0, k = 0;
    while(i < meio && j < n - meio){
        if(e[i] < d[j]) v[k++] = e[i++];
        else v[k++] = d[j++];
    }

    while(i < meio) v[k++] = e[i++];
    while(j < n - meio) v[k++] = d[j++];
}

// Função wrapper que aloca e libera os vetores apenas uma vez
void mergesort(int *v, int n){
    int *e = new int[n]; // espaço suficiente
    int *d = new int[n];

    merge(v, n, e, d); // chamada principal

    delete[] e;
    delete[] d;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        cout << "Uso: ./programa <numero_de_elementos>" << endl;
        return 1;
    }

    int n = atoi(argv[1]); // número de elementos

    int* v = new int[n];

    // preencher com números aleatórios
    for (int i = 0; i < n; i++) {
        v[i] = rand();
    }

    // Chamada para a versão otimizada com wrapper
    mergesort(v, n);

    delete[] v;
    return 0;
}


// 10000000000 tempo para rodar original / alocando a cada chamada -> 0m57.942s
// 10000000000 tempo para rodar wrapped / alocando no inicio -> 5m15.194s