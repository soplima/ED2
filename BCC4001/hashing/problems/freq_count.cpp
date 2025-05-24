#include <unordered_map>
#include <vector>
#include <iostream>
using namespace std;

/*Retorna: um dicionario com a frequencia de cada inteiro, onde a chave é o inteiro
e o valor é a frequência.*/

std::unordered_map<int,int> contarFrequencia(std::vector<int>& arr){
    unordered_map<int, int>hash;

    for(const int x: arr){
        hash[x]++;
    }
    return hash;
}

int main(int argc, char** argv){
    vector<int> v = {1, 2, 5, 8, 4, 2, 4, 2};
    unordered_map<int, int> saida = contarFrequencia(v);
    for(auto& [chave, valor] : saida){
        cout << chave << "->" << valor << "\n";
    }
}