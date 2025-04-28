#include <iostream>
#include <cstring>
using namespace std;

void swap(int* v, int a, int b){
    int temp = v[a];
    v[a] = v[b];
    v[b] = temp;
}

void merge(int* v, int n){
    if(n == 1) return;
    if(n == 2){
        if(v[0] > v[1]){
            swap(v, 0, 1);
        }
    }

    int meio = n/2;
    int *e = new int[meio];
    int *d = new int[n-meio];
    
    for(int i = 0; i < meio; i++) e[i] = v[i];
    for(int i = 0; i< n-meio; i++) d[i] = v[meio + i];

    merge(e, meio);
    merge(d, n-meio);

    int i = 0, j = 0, k = 0;

    while(i < meio && j < n - meio){
        if(e[i] < d[j]){
            v[k++] = e[i++];
        }else{
            v[k++] = d[j++];
        }
    }
    while(i<meio){
        v[k++] = e[i++];
    }
    while(j < n-meio){
        v[k++] = d[j++];
    }

    delete[] e;
    delete[] d;

}

int main() {
    int n;
    cout << "Quantos elementos tem o vetor? ";
    cin >> n;

    int* v = new int[n];

    cout << "Digite os " << n << " elementos do vetor:\n";
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    merge(v, n); // ordena

    cout << "Vetor ordenado:\n";
    for (int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    delete[] v;
    return 0;
}
