#include <iostream>
#include <cstdlib>
using namespace std;

// funcao swap
//  o ultimo elemento sera o pivot
// incrementar o j sempre
// o j sempre sera incrementado
//  o i comeca em -1 e so e incrementado quando j < pivot
// troca j com i
// implementar recursivamente

void swap(int *v, int a, int b)
{
    int temp = v[a];
    v[a] = v[b];
    v[b] = temp;
}

int partition(int *v, int n)
{
    int i = -1;
    int pivot = v[n - 1];
    for (int j = 0; j < n - 1; j++)
    {
        if (v[j] < pivot)
        {
            i++;
            swap(v, i, j);
        }
    }
    swap(v, i + 1, n - 1);
    return i + 1;
}

void quickSort(int *v, int left, int right)
{
    if (left < right)
    {
        int indexPivot = partition(v + left, right - left + 1);
        indexPivot += left;

        quickSort(v, left, indexPivot - 1);
        quickSort(v, indexPivot + 1, right);
    }
}

void QuickSort(int *v, int n)
{
    quickSort(v, 0, n - 1);
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