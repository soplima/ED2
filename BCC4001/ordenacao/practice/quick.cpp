#include <iostream>
#include <cstdlib>

//o ultimo elemento sera o pivo
//incrementar o j sempre
//o i sera incrementado quando encontrar 
//um menor do que o pivo e trocara o que esta naquele prox index com o menor 
//encontrado por j
//implementar recursivamente

void swap(int* v, int a, int b){
    int temp = v[a];
    v[a] = v[b];
    v[b] = temp;
}

int partition(int*v, int n){
    int pivot = v[n-1];
    int i = -1;
    for(int j = 0; j <= n-1; j ++){
        if(v[j] < pivot){
            i++;
            swap(v, i, j);
        }
    }
    swap(v, i +1, n-1);

    return i +1;
}

void quickSort(int* v, int left, int right){
    if(left< right){
        int IndexPivot = partition(v + left, right - left + 1);
        IndexPivot += left;

        quickSort(v, left, IndexPivot -1);
        quickSort(v, IndexPivot + 1, right);
    }
}

int main() {
    int v[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(v)/sizeof(v[0]);

    std::cout << "Vetor antes do QuickSort: ";
    for(int i = 0; i < n; i++)
        std::cout << v[i] << " ";
    std::cout << std::endl;

    quickSort(v, 0, n - 1);

    std::cout << "Vetor depois do QuickSort: ";
    for(int i = 0; i < n; i++)
        std::cout << v[i] << " ";
    std::cout << std::endl;

    return 0;
}
