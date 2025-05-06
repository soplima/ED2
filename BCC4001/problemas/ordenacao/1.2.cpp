#include <cstdlib>
#include <cstdio>
#include <iostream>
#include "utils.h"
#include <vector>


#include <algorithm>

#define DEBUG 1

// retorna o k-ésimo maior elemento do vetor.
// Os elementos de v podem ser permutados durante a execução.
// pré-condição: o vetor não possui elementos repetidos
// k=1 retorna o maior elemento
// k=2 retorna o segundo maior elemento
// k=....
// k=n retorna o menor elemento

int maior(std::vector<int> &v, int first, int last){
    int max = first;
    for(int i = first+1; i <=last; i++){
        if(v[i] > v[max]){
            max = i;
        }
    }
    return max;
}

int k_maior(std::vector<int> &v, int k){
    int n = v.size();
    for(int i = 0; i < n; i++){
        int vmax = maior(v, i, n-1);
        std::swap(v[i], v[vmax]);
    }
    return v[k-1];
}

int main(int argc, char** argv){
    int n = atoi(argv[1]);
    int k = atoi(argv[2]);

    auto v = gerar_vetor_aleatorio_sem_reps(n, 42);

    #if DEBUG
    imprimir_vetor(v.data(), n);
    #endif

    int res = k_maior(v, k);

    #if DEBUG
    std::cout << "O " << k << "-ésimo maior elemento do vetor é o " << res << "!\n";
    #endif    

    return EXIT_SUCCESS;
}