#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

//encontrar o menor elemento do vetor 
//trocar o menor com o primeiro elemento do vetor

int min(int* v, int init, int fim){
    int min = init;
    for(int i = init+1; i <= fim; i ++){
        if(v[i] < v[min]){
            min = i;
        }
    }
    return min;
}

void swap(int* v, int a, int b){
    int temp = v[a];
    v[a] = v[b];
    v[b] = temp;
}

void selectionSort(int* v, int n){
    for(int i = 0; i < n-1; i ++){
        int vmenor = min(v, i, n-1); // vai encurtando pra direit. o i cresce pra direita porque ordena crescente
        swap(v, vmenor, i);
    }
}


int main() {
    const int n = 10;
    int v[n];

    // Preenche o vetor com valores aleatórios
    srand(time(0));
    for(int i = 0; i < n; i++) {
        v[i] = rand() % 100;  // números de 0 a 99
    }

    // Mostra vetor original
    cout << "Vetor original: ";
    for(int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    // Ordena
    selectionSort(v, n);

    // Mostra vetor ordenado
    cout << "Vetor ordenado: ";
    for(int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    return 0;
}
