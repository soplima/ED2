#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iostream>

using namespace std;
// Dado um vetor de strings palavras, retorne um vetor de vetores, onde cada vetor 
// interno contém todas as palavras que são anagramas entre si. 
// Por exemplo, se palavras = {"ate", "eat", "tea", "bat", "tab"}, 
// então a saída deve ser {{"ate", "eat", "tea"}, {"bat", "tab"}}.

std::vector<std::vector<std::string>> agruparAnagramas(
    std::vector<std::string>& palavras){
    unordered_map<string, vector<string>> grupos;

    for(string palavra : palavras){
        string chave = palavra;
        sort(chave.begin(), chave.end());
        grupos[chave].push_back(palavra);
    }
    vector<vector<string>> resultado;
    for (auto& par : grupos) {
        resultado.push_back(par.second);
    }

    return resultado;
}

int main() {
    vector<string> palavras = {"ate", "eat", "tea", "bat", "tab"};
    vector<vector<string>> grupos = agruparAnagramas(palavras);

    for (const auto& grupo : grupos) {
        cout << "{ ";
        for (const auto& palavra : grupo) {
            cout << palavra << " ";
        }
        cout << "}" << endl;
    }

    return 0;
}
