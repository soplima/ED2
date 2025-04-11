#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int max(int* vec, int first, int last){
    int max = first;
    for(int i = first+1; i<=last; i++){
        if(vec[i] > vec[max]){
            max = i;
        }
    }
    return max;
}

void swap(int* vec, int a, int b){
    int temp = vec[a];
    vec[a] = vec[b];
    vec[b] = temp;
}

void selectionSort(int* vec, int n){
    for(int i = n-1; i >= 0; i--){
        int vmax = max(vec, 0, i);
        swap(vec, vmax, i);
    }
}

int main() {
    const int n = 10;
    int vec[n];

    // Preenche o vetor com valores aleatórios
    srand(time(0));
    for(int i = 0; i < n; i++) {
        vec[i] = rand() % 100;  // números de 0 a 99
    }

    // Mostra vetor original
    cout << "Vetor original: ";
    for(int i = 0; i < n; i++) {
        cout << vec[i] << " ";
    }
    cout << endl;

    // Ordena
    selectionSort(vec, n);

    // Mostra vetor ordenado
    cout << "Vetor ordenado: ";
    for(int i = 0; i < n; i++) {
        cout << vec[i] << " ";
    }
    cout << endl;

    return 0;
}