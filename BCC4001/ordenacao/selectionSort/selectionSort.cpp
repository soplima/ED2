#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

//encontrar o indice do maior de todos 
//e trocar com o da  ultima posicao
//trocar o proximo max com o da proxima ultima posicao n-2;


//Implemente a função max usada no algoritmo de ordenação por seleção 
int max(int *v, int ini, int fim){
    int max = ini;
    for(int i = ini+1; i< fim; i ++){
        if(v[i] > v[max]){
            max = i;
        }
    }
    return max;
}

//Implemente a função troca usada nos algoritmos de ordenação por seleção e bolha
void swap(int *v, int a, int b){
    int temp = v[b];
    v[b] = v[a];
    v[a] = temp;
}

void selectionSort(int *v, int n){
    for(int i = n-1; i>0; i--){
        int vmax = max(v, 0, i); //Vai do final (i = n-1) para o início (i > 0).
        //troca o maior valor encontrado com i = ultima pos
        swap(v, vmax, i);
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
