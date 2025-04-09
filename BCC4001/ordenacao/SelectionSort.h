#include <iostream>


void selection_sort(int* v, int n){
	for(int i = n-1; i > 0; i--){
		int pmaior = pmax(v, 0, i );
		trocar(v, pmaior, i);
 	}
}

int pmax(int* v, int ini, int fim){
    int pmaior = ini;
    
    for (int i = ini + 1; i < fim; i++){
        if(v[i] > v[pmaior]){
            pmaior = i;
        }
    }
    return pmaior;
}

void trocar (int* v, int a , int b ){
    int temp = v[a];
    v[a] = v[b];
    v[b] = temp;
}

void SelectionSort(int *v, int n){
    for(int = n-1; i>0; i--){
        int pmaior = pmax(v, 0, i);
        trocar(v, pmaior, i);
    }
}