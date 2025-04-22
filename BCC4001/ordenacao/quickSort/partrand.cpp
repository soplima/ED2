#include <iostream>
#include <cstdlib>
#include <stdio.h>

//funcao funcao de troca
//funcao partition
    //pivot aleatorio ecolhido
    //incrementar o j a cada iteracao
    // o i e incrementado quando encontrado um j menor do q p pivo i = -1
    //quando j chegar no pivot, trocar a posicao com i +1
//implementar quickSort

void swap(int* v, int a, int b){
    int temp = v[a];
    v[a] = v[b];
    v[b] = temp;
}

//*pivot aleatorio!
int randPartition(int *v, int n){
    int pivotIndex = rand() % n; // indice aleatorio entre 0 e n-1
    swap(v, pivotIndex, n-1); //coloca o pivot aleatorio na ultima posicao

    int pivot = v[n-1];
    int i = -1;
    for(int j = 0; j < n-1; j ++){
        if(v[j] < pivot){
            i++;
            swap(v, i, j);
        }
    }
    swap(v, i+1, n-1);
    return i+1;
}

void quickSort(int* v, int left, int right){
    if(left < right){
    int indexPivot = randPartition(v + left, right - left +1);
    indexPivot += left;

    quickSort(v, left, indexPivot - 1);
    quickSort(v, indexPivot + 1, right);
    }
}