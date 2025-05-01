#include <iostream>

void merge(int *v, int p, int q, int r){
    int n1 = q - p + 1;
    int n2 = r - q;

    int *e = new int[n1];
    int *d = new int[n2];

    for(int i = 0; i < n1; i++)
        e[i] = v[p+i];
    
    for(int i = 0; i < n2; i++)
        d[i] = v[(q+1)+i];
    
    int k = p, i = 0, j = 0;

    while( (i < n1) && (j < n2) ){
        if(e[i] <= d[j]){
            v[k] = e[i];
            i++;
        }
        else{
            v[k] = d[j];
            j++;
        }
        k++;
    }
    while(i < n1){
        v[k] = e[i];
        i++;
        k++;
    }
    while(j < n2){
        v[k] = d[j];
        j++;
        k++;
    }
    delete[] e;
    delete[] d;
}

void MergeSort(int *v, int p, int r){
    if(p<r){
        int m = (p+r)/2;
        MergeSort(v, p, m);
        MergeSort(v, m+1, r);
        merge(v, p, m, r);
    }
}

void imprimir_vetor(int *v, int n){
    using namespace std;
    for(int i = 0; i < n; i++){
        cout << v[i] << ", ";
    }
    cout << "\n";
}

int* vetor_aleatorio(int n, int max, int seed){
    srand(seed);
    int* v = new int[n];
    for(int i = 0; i < n; i++){
        v[i] = rand() % max;
    }
    return v;
}

int main(int argc, char** argv){
    int n = std::atoi(argv[1]); // std::atoi converte de string pra int
    //int v[] = {7, 4, 6, 5, 0, 1};
    int* v = vetor_aleatorio(n, n*100, 99);

    imprimir_vetor(v, n);

    MergeSort(v, 0, n-1);

    imprimir_vetor(v, n);
}