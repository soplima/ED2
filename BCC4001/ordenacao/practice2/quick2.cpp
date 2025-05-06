#include <iostream>
#include <cstdlib>
using namespace std;

//funcao swap
//funcao partition
    //o j e iterado a todo momento
    //o i comeca no -1
    //o i so e implementado quando o j e menor do que o pivot
    //wuando e, o j troca com o i
///chamar recursivamente

void swap(int* v, int a, int b){
    int temp = v[a];
    v[a] = v[b];
    v[b] = temp;
}

int partition(int* v, int n){
    int pivot = v[n-1];
    int i = -1;
    for(int j = 0; j <= n-1; j++){
        if(v[j] > pivot){ //return in reverse order
            i++;
            swap(v, i, j);
        }
    }
    swap(v, i+1, n-1);
    return i+1;
}

void quickSort(int* v, int left, int right){
    if(left < right){
        int iPivot = partition(v + left, right - left + 1);
        iPivot += left;
        quickSort(v, left, iPivot - 1);
        quickSort(v, iPivot + 1, right);
    }
}

void QuickSort(int* v, int n){
    quickSort(v, 0, n-1);
}

int *vetor_ordenado(int n)
{
    int *v = new int[n];
    for (int i = 0; i < n; i++)
    {
        v[i] = i;
    }
    return v;
}

int *vetor_aleatorio(int n)
{
    int *v = new int[n];
    for (int i = 0; i < n; i++)
    {
        v[i] = rand() % (n * 100);
    }
    return v;
}

int main(int argc, char **argv)
{

    int n = atoi(argv[1]);

    int *v = vetor_aleatorio(n);

    QuickSort(v, n);

    for (int i = 0; i < n; i++)
        cout << v[i] << " ";
    cout << endl;

    return 0;
}