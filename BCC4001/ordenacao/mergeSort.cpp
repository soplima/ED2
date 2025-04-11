#include <iostream>

void merge(int * v, int p, int q, int r) {
    //calcular n1 e n2
    int n1 = q - p + 1;
    int n2 = r - q;
    // alocar vetor E com n1 elementos
    int * E = new int[n1];
    // alocar vetor D com n2 elementos
    int * D = new int[n2];
    // copiar V[p...q] para E[0...n1-1]
    for(int i = 0; i < n1; i ++){
        E[i] = v[p + i];
    }
    //copiar V[q+1...r] para D[0...n2-1]
    for(int i = 0; i < n2; i ++){
        D[i] = v[q + 1 + i];
    }
    //inicializar indexadores
    int i = 0, j = 0, k = p;
    //intercalar vetores E e D de volta em V
    while (i<n1 && j<n2){
        if(E[i] <= D[j]){
            v[k] = E[i];
            i++;
        } else{
                v[k] = D[j];
                j++;
        }
        k++;
    }
    //despejar resto em v[k];
        while(i<n1){
        v[k] = E[i];
        i++;
        k++;
    }

        while(j<n2){
        v[k] = D[j];
        j++;
        k++;
    } 
    delete [] E;
    delete [] D;
}

int main(){
    int v[] = {3, 5, 6, 0, 4, 7};
    int n = 6;

    merge(v, 0, 2, 5);

    for(int i = 0; i < n; i++){
        std:: cout << v[i] << ", ";
    }
    std::cout << "\n";
}