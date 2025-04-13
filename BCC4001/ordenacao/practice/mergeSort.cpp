#include <iostream>
#include <cstring>
using namespace std;

//dividir o vetor recursivamente em duas metades ate que fiquem so vetores unitarios
//reordenar o vetor com os elementos unitarios


void merge(int *v, int n){
    //se forem vetores unitaros, esta finalizado;
    if(n == 1) return;

    int meio = n/2;
    int *e = new int[meio];
    int *d = new int[n - meio];

    for(int i = 0; i < meio; i ++) e[i] = v[i];
    for(int i = 0; i < n - meio; i ++) d[i] = v[meio + i];

    merge(e, meio);
    merge(d, n - meio);

    //reordenar o vetor

    int i = 0, j = 0, k = 0;

    while(i<meio || j<n-meio){
        if(i < meio && j >= n-meio || e[i] < d[j]){
            v[k] = e[i];
            i++;
        }else{
            v[k] = d[j];
            j++;
        }
    }
    k++;
}