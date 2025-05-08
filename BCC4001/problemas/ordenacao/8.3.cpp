#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


//Dado um vetor de inteiros não-negativos v, retorne um vetor com os k inteiros
//mais próximos de x.
//O vetor de entrada não deve ser modificado.
//Exemplo: v = {10, 14, 4, 7, 6, 8, 12, 3, 5, 9}
//k_mais_proximos(v, 7, 3) = {6, 7, 8} (ou outra permutação)
vector<int> k_mais_proximos(vector<int> &v, int x, int k){
    vector<pair<int, int>>distancia;
    vector<int>result;

    for(int i = 0; i<v.size(); i++){
        int dist = abs(v[i] - x);
        distancia.push_back({dist, v[i]});
    }
    sort(distancia.begin(), distancia.end());

    for(int i = 0; i<distancia.size() && i<k; i++){
        result.push_back(distancia[i].second);
    }
    return result;
}

int main(){
    vector<int> v = {10, 14, 4, 7, 6, 8, 12, 3, 5, 9};

    vector<int> res = k_mais_proximos(v, 7, 3);

    for(auto i : res){
        cout << i << " ";
    }
    cout << "\n";

    return EXIT_SUCCESS;
}