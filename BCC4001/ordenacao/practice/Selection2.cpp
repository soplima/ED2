#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

//funcao max para escolher o maior elemento como pivot
//funcao de troca para colocar o maior elemento na ultima posicao
//ir repetindo o processo ate o fim do vetor

int max(int* v, int first, int last){
    int max = first;
    for(int i = first + 1; i <= last; i++){
        if(v[max] < v[i]){
            max = i;
        }
    }
    return max;
}

void swap(int* v, int a, int b){
    int temp = v[a];
    v[a] = v[b];
    v[b] = temp;
}

void selectionSort(int*v, int n){
    for(int i = n-1; i > 0; i --){
        int vmax = max(v, 0, i);
        swap(v, vmax, i);
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