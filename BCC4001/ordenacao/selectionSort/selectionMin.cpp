#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int min(int* vec, int first, int last){
    int min = first;
    for(int i = first + 1; i <= last; i++){
        if(vec[i] < vec[min]){
            min = i;
        }
    }
    return min;
}

void swap(int* vec, int a, int b){
    int temp = vec[a];
    vec[a] = vec[b];
    vec[b] = temp;
}

void selectionSort(int* vec, int n){
    for(int i = 0; i < n-1; i ++){
        int vmin = min(vec, i, n-1);
        swap(vec, vmin, i);
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