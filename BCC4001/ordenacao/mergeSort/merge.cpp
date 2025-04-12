#include <iostream>
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

    for (int i = 0; i < meio; i++) e[i] = v[i];
    for(int i = 0; i < n - meio; i++) d[i] = v[meio + i];

    merge(e, meio);
    merge(d, n - meio);

//ordenar o vetor novamente

    int i = 0, j = 0, k = 0;

    while(e[i] < meio && d[j] < n - meio){
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


// Tempo para rodar 1000 sem a prevencao do caso n ==2 ->  012s
//Tempo para rodar 1000 usando caso n ==2 ->  011s