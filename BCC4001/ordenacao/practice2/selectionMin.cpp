#include <iostream>
#include <cstdlib>

//escolher o menor elemento do vetor e colocar no comeco
//funcao de troca
//ir parqa a proxima pos e fazer isso recursivamente

int min(int*v, int first, int last){
    int min = first;
    for(int i = first+1; i<=last; i++){
        if(v[min] > v[i]){
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

//implementando selection com min
void SelectionSort(int* v, int n){
    for(int i = 0; i <= n-1; i++){
        int vmin = min(v, i, n-1);
        swap(v, vmin, i);
    }
}

int* vetor_aleatorio(int n, int seed){
    srand(seed);
    int* v = new int[n];
    for(int i = 0; i < n; i++){
        v[i] = rand() % (n*100);
    }
    return v;
}

void imprimir_vetor(int* v, int n){
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

    int* v = vetor_aleatorio(n, 1);

    imprimir_vetor(v, n);

    SelectionSort(v, n);

    imprimir_vetor(v, n);

    delete[] v;

    return 0;
}
