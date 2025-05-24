#include <unordered_map>
#include <vector>
#include <iostream>

using namespace std;

// Dado um vetor de inteiros arr, retorne um vetor com os elementos de arr, 
// mas sem elementos repetidos. Os elementos no vetor de saída precisam estar na 
// mesma ordem que os elementos do vetor de entrada.

std::vector<int> semDuplicatas(std::vector<int>& arr){
    unordered_map<int, int>freq;
    vector<int> v;

    for(int x : arr){
        freq[x]++;
        if(freq[x] == 1){
            v.push_back(x);
        }
    }
    return v;
}

int main() {
    std::vector<int> entrada = {1, 2, 2, 3, 1, 4};

    std::vector<int> resultado = semDuplicatas(entrada);

    std::cout << "Vetor sem duplicatas: ";
    for (int x : resultado) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    return 0;
}
