#include <iostream>
using namespace std;

//Durante a etapa de merge, quando um elemento da metade direita é 
//menor que um elemento da metade esquerda, todos os elementos restantes na 
//metade esquerda formam inversões com esse elemento da direita. 
//Portanto, cada vez que isso acontece, adicionamos o número de elementos 
//restantes na esquerda ao contador de inversões.

int merge(int *v, int n){

    if(n <= 1) return;

    int meio = n/2;
    int *e = new int[meio];
    int *d = new int[n - meio];

    for(int i = 0; i < meio; i ++) e[i] = v[i];
    for(int i = 0; i < n-meio; i ++) d[i] = v[meio + i];

    int inversao = 0;
    inversao += merge(e, meio);
    inversao += merge(d, n - meio);

    int i = 0, j = 0, k = 0;

    while(i < meio && j < n - meio){
        if(e[i] <= d[j]){
            v[k] = e[i];
            i++;
            k++;
        }else{
            v[k] = d[j];
            inversao += meio - i;
            j++;
            k++;
        }
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
int mergeSort(int *v, int n) {
    return merge(v, n);
}
