#include <iostream>
#include <ctime>
#include <cstdlib>

template <typename T>
int max(T *v, int ini, int fim ){
    int maior = ini;
    for(int i = ini+1; i <= fim; i++){
        if(v[i] > v[maior])
            maior = i;
    }
    return maior;
}

template <typename T>
void troca(T *v, int a, int b){
    T aux = v[a];
    v[a] = v[b];
    v[b] = aux;
}

template <typename T>
void SelectionSort(T *v, int n){
    for(int i = n-1; i > 0; i--){
        int pmaior = max(v, 0, i);
        troca(v, pmaior, i);
    }
}

template <typename T>
T* vetor_aleatorio(int n, int seed){
    srand(seed);
    T* v = new T[n];
    for(int i = 0; i < n; i++){
        v[i] = (T) (rand() % (n*100));
    }
    return v;
}

template <typename T>
void imprimir_vetor(T* v, int n){
    for(int i = 0; i < n; i++){
        std::cout << v[i] << " ";
    }
    std::cout << "\n";    
}

int main(int argc, char** argv){
    // int v[] = {3, 1, 0, 4, 6, 2};

    // SelectionSort(v, 6);

    // for(int i = 0; i < 6; i++){
    //     std::cout << v[i] << " ";
    // }
    int n = atoi(argv[1]);

    int* v = vetor_aleatorio<int>(n, 1);

    imprimir_vetor(v, n);

    SelectionSort(v, n);

    imprimir_vetor(v, n);

    delete[] v;

    return 0;
}