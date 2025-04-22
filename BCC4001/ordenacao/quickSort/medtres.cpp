#include <iostream>
#include <cstdlib>

void swap(int* v, int a, int b){
    int temp = v[a];
    v[a] = v[b];
    v[b] = temp;
}

int medPartition(int* v, int n){
    int p = 0;
    int r = n-1;
    int mid = (p + r)/2;

    swap(v, mid, r);

    int pivot = v[r];
    int i = -1;
    for(int j = 0; j < pivot; j ++){
        if(v[j] < pivot){
            i++;
            swap(v, i, j);
        }
    }
    swap(v, i+1, r);
    return i +1;
}

int quickSort(int*v, int left, int right){
    if(left < right){
        int indexPivot = medPartition(v + left, right - left + 1);
        indexPivot += left;

        quickSort(v, left, indexPivot -1);
        quickSort(v, indexPivot + 1, right);
    }
}