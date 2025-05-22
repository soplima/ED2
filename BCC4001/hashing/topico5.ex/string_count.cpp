#include <stdio.h>
#include <unordered_map>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

unordered_map<string, int> stringcount(const vector<string>& v) {
    unordered_map<string, int> hash;

    for (const string& x : v) {
        hash[x]++;  // se x não existir, inicializa com 0 e incrementa para 1
    }
    return hash;
}


int main(int argc, char** argv){
    vector<string> v = {"a", "b", "a", "c", "d", "a", "z", "b"};
    unordered_map<string, int> saida = stringcount(v);

    for(auto& [chave, valor] : saida){
        cout << chave << "->" << valor << "\n";
    }
}