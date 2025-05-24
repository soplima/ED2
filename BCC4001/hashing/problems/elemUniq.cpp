#include <unordered_map>
#include <vector>
#include <iostream>

using namespace std;
// Dado um vetor de inteiros arr, retorne a posição do primeiro elemento do vetor 
// que não tem duplicata.
// Se todos os elementos ocorrerrem pelo menos duas vezes, retorne -1.

int primeiroUnico(std::vector<int>& arr){
    unordered_map<int, int> freq;
    for(int x : arr){
        freq[x]++;
    }
    for(int i = 0; i < arr.size(); i++){
        if(freq[arr[i]] == 1){
            return i;
        }
    }
    return -1;
    
}

int main(int argc, char** argv){
    vector<int> v = {1, 1, 2, 5, 8, 4, 2, 4, 2};
    int saida = primeiroUnico(v);
    cout << saida << "\n";
}