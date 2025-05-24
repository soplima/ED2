#include <unordered_set>
#include <vector>
#include <utility>
#include <iostream>
using namespace std;

// Dado um vetor de inteiros arr, retorne true se arr contém algum elemento 
// repetido, e false caso contrário.

bool temDuplicatas(std::vector<int>& arr){
    unordered_set<int>element;
    for(const int x : arr){
        if(element.count(x)){
        return true;
        }
        element.insert(x);
    }
    return false;
}

int main() {
    vector<int> v = {1, 2, 5, 8, 4, 1};
    bool saida = temDuplicatas(v);
    cout << (saida ? "true" : "false") << "\n";
}
