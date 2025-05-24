#include <unordered_set>
#include <vector>
#include <utility>
#include <iostream>
using namespace std;

// Dado um vetor de inteiros arr, retorne um par de inteiros que somados 
// resultam em um valor k dado.

std::pair<int, int> twosum(std::vector<int>& arr, int k){
    unordered_set<int>par;

    for(const int x: arr){
        par.insert(x);
        int complemento = k - x;
        if(par.count(complemento)){
            return make_pair(x, complemento);
        }
    }
    return make_pair(-1, -1);
    
}

int main() {
    vector<int> v = {2, 7, 11, 15};
    int k = 9;

    auto resultado = twosum(v, k);
    cout << "Par encontrado: (" << resultado.first << ", " << resultado.second << ")\n";

    return 0;
}
