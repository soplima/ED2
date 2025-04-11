#include <iostream>
#include <ctime>
#include <cstdlib>

//encontrar o indice do maior de todos 
//e trocar com o da  ultima posicao
//trocar o proximo max com o da proxima ultima posicao n-2;


//Implemente a função max usada no algoritmo de ordenação por seleção 
int max(int *v, int ini, int fim){
    int max = ini;
    for(int i = ini+1; i<= fim; i ++){
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
    for(int i = n-1; i>0; n--){
        int vmax = max(v, 0, i);
        swap(v, 0, i);
    }
}