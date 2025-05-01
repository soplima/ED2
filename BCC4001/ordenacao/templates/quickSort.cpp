#include <iostream>
#include <cstdlib>

void troca(int *v, int a, int b){
    int aux = v[a];
    v[a] = v[b];
    v[b] = aux;
}

int partition(int *v, int p, int r){
    int x = v[r];
    int i = p-1;
    for(int j = p; j < r; j++){
        if(v[j] <= x){
            i++;
            troca(v, i, j);
        }
    }
    troca(v, i+1, r);
    return i+1;
}

void QuickSort(int *v, int p, int r){
    if(p < r){
        int q = partition(v, p, r);
        QuickSort(v, p, q-1);
        QuickSort(v, q+1, r);
    }
}

void QuickSort(int *v, int n){
    QuickSort(v, 0, n-1);
}

int * vetor_ordenado(int n){
    int *v = new int[n];
    for(int i = 0; i < n; i++){
        v[i] = i;
    }
    return v;
}

int* vetor_aleatorio(int n){
    int* v = new int[n];
    for(int i = 0; i < n; i++){
        v[i] = rand() % (n*100);
    }
    return v;
}

int main(int argc, char** argv){
    using namespace std;
    // int v[] = {6, 0, 4, 2, 5, 3};
    // partition(v, 0, 5);
    // for(int i = 0; i < 6; i++){
    //     cout << v[i] << " ";
    // }
    //cout << endl;
    
    int n = atoi(argv[1]);
    
    //int* v = vetor_aleatorio(n);
    int* v = vetor_ordenado(n);
    
    QuickSort(v, n);
    
    for(int i = 0; i < n; i++)
        cout << v[i] << " ";
    cout << endl;
    
    return 0;
}