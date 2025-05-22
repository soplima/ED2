#include <stdio.h>
#include <unordered_set>
#include <utility>
#include <vector>
#include <iostream>

using namespace std;

pair<int, int> twosum(const vector<int>& v, int k){
    unordered_set<int> h;
    for(int x : v){
        h.insert(x);
    }
    for(int x : v){
        int complemento = k - x;
        if(h.count(complemento)){
            return make_pair(x, complemento);
        }
    }
    return make_pair(-1, -1);
}

int main(int argc, char** argv){

    vector<int> v = {6, 4, 2, 11, 6, 5};
    int k = atoi(argv[1]);
    pair<int, int> saida = twosum(v, k);

    if(saida.first + saida.second == k){
        cout<< "achou o par:" << saida.first << ", "
            << saida.second << "\n";
    }
    else{
        cout<< "nao ha um par de elementos que somem "
            << k << "\n";
    }
    return 0;
}