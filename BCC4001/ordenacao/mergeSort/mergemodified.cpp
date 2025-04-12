#include <iostream>
#include <cstring>
using namespace std;

void swap(int *v, int a, int b){
    int temp = v[a];
    v[a] = v[b];
    v[b] = temp;
}

//recursivamente dividindo ate ficar com somente um elemento de cada
void merge(int *v, int n){
    if(n == 1) return;
    // se tiver apenas dois elementos, so comparar e trocar. nao precisa de recursao
    if(n == 2){
        if(v[0] > v[1]){
            swap(v, 0, 1);
        }
    }

    int meio = n/2;
    int *e = new int[meio];
    int *d = new int[n - meio];

    memcpy(e, v, meio * sizeof(int));
    //void* memcpy(void* destino, const void* origem, size_t num_bytes);
    memcpy(d, v + meio, n-meio * sizeof(int));
    //void* memcpy(void* destino, const void* origem, size_t num_bytes);


    merge(e, meio);
    merge(d, n - meio);

//ordenar o vetor novamente

    int i = 0, j = 0, k = 0;

    while(i < meio && j < n - meio){
        if(e[i] < d[j]){
            v[k] = e[i];
            i++;
        }else{
            v[k] = d[j];
            j++;
        }
        k++;
    }

    while(i < meio){
        v[k] = e[i];
        i++;
        k++;
    }
    while(j < n - meio){
        v[k] = d[j];
        j++;
        k++;
    }

    // Liberar memória
    delete[] e;
    delete[] d;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        cout << "Uso: ./programa <numero_de_elementos>" << endl;
        return 1;
    }

    int n = atoi(argv[1]); // converte o argumento para inteiro

    // Agora você pode usar 'n' para gerar o vetor, por exemplo:
    int* v = new int[n];

    // preencher com números aleatórios
    for (int i = 0; i < n; i++) {
        v[i] = rand(); // ou alguma outra lógica
    }

    // resto do seu código...
    
    delete[] v;
    return 0;
}


// Tempo para rodar 10000000000 com o alg original ->  58.540s
//Tempo para rodar 10000000000 com o alg modificado ->  1m0.615s