#include <iostream>
using namespace std;

//recursivamente dividindo ate ficar com somente um elemento de cada
void merge(int *v, int n){
    if(n == 1) return;

    int meio = n/2;
    int *e = new int[meio];
    int *d = new int[n - meio];

    for (int i = 0; i < meio; i++) e[i] = v[i];
    for(int i = 0; i < n - meio; i++) d[i] = v[meio + i];

    merge(e, meio);
    merge(d, n - meio);

//ordenar o vetor novamente

    int i = 0, j = 0, k = 0;

    while(e[i] < meio && d[j] < n - meio){
        if(e[i] < d[j]){
            v[k] = e[i];
            i++;
        }else{
            v[k] = d[j];
            j++;
        }
        k++;
    }

    while(i < meio){
        v[k] = e[i];
        i++;
        k++;
    }
    while(j < n - meio){
        v[k] = d[j];
        j++;
        k++;
    }

    // Liberar memória
    delete[] e;
    delete[] d;
}