#include <iostream>
#include <cstdlib>

//Funcao max ou min
//swap
//colocar o maximo ao final e percorrer de traz para a frente sempre colocando o maior ao final
//sempre atualizando a ultima posicao 


//implementacao da funcao max
int max(int* v, int first, int last){
    int max = first;
    for(int i = first+1; i<=last; i++){
        if(v[max] > v[i]){ //inverter para devolver ao contrario
            max = i;
        }
    }
    return max;
}

//implementacao da funcao swap
void swap(int* v, int a, int b){
    int temp = v[a];
    v[a] = v[b];
    v[b] = temp;
}

void SelectionSort(int* v, int n){
    for(int i = n-1;i>0; i--){
        int vmax = max(v, 0, i);
        swap(v, vmax, i);
    }
}

int* vetor_aleatorio(int n, int seed){
    srand(seed);
    int* v = new int[n];
    for(int i = 0; i < n; i++){
        v[i] = rand() % (n*100);
    }
    return v;
}

void imprimir_vetor(int* v, int n){
    for(int i = 0; i < n; i++){
        std::cout << v[i] << " ";
    }
    std::cout << "\n";    
}

int main(int argc, char** argv){
    if(argc < 2)(
        printf("O tamanho do vetor nao foi informado")
    );
    // int v[] = {3, 1, 0, 4, 6, 2};

    // SelectionSort(v, 6);

    // for(int i = 0; i < 6; i++){
    //     std::cout << v[i] << " ";
    // }
    int n = atoi(argv[1]);

    int* v = vetor_aleatorio(n, 1);

    imprimir_vetor(v, n);

    SelectionSort(v, n);

    imprimir_vetor(v, n);

    delete[] v;

    return 0;
}