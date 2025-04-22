#include <iostream>
#include <cstdlib>
#include <stdio.h>

//pior caso = quando o vetor esta ordenado
//solucao -> escolher um pivot randomizado

//funcao de troca
//funcao partition 
    //definir um pivot no ultimo elemento do vetor      
    //incrementar sempre j
    //quando j for menor do que pivot, incrementar i e trocar o elem com j
    //quando chegar ate o pivot, trocar o pivot com a proxima i e devolver o indice 
//funcao quickSort
    //

void swap(int* v, int a , int b){
    int temp = v[a];
    v[a] = v[b];
    v[b] = temp;
}
int partition(int* v, int n){
    int pivot = v[n-1];
    int i = -1;
    for(int j = 0; j < n - 1; j++){
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
        int IndexPivot = partition(v + left, right - left +1);
            IndexPivot += left;
            
        quickSort(v, left, IndexPivot -1);
        quickSort(v, IndexPivot + 1, right);
    }
}

int main() {
    int vetor[] = {1, 2, 3, 4, 5};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);

    printf("Vetor original:\n");
    for(int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    quickSort(vetor, 0, tamanho - 1);

    printf("Vetor ordenado:\n");
    for(int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    return 0;
}
