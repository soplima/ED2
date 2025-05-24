#include <iostream>
#include <vector>

using namespace std;

int primo_antes(int x) {
    while (--x > 1) {
        bool eh_primo = true;
        for (int i = 2; i*i <= x; i++) {
            if (x % i == 0) {
                eh_primo = false;
                break;
            }
        }
        if (eh_primo) return x;
    }
    return 2;
}

class HashTable {
    int M;
    int ocupados;
    vector<int> tabela;

public:
    HashTable(int tam) : M(tam), ocupados(0), tabela(tam, -1) {}

    void redimensionar() {
        int novoM = primo_antes(M * 2);
        vector<int> antigos = tabela;
        tabela.assign(novoM, -1);
        M = novoM;
        ocupados = 0;

        for (int val : antigos) {
            if (val != -1) inserir(val);
        }
    }

    void inserir(int chave) {
        if ((float)ocupados / M >= 0.5f) redimensionar();

        int h = chave % M;
        while (tabela[h] != -1) {
            h = (h + 1) % M;
        }
        tabela[h] = chave;
        ocupados++;
    }

    void imprimir() {
        cout << "Tabela (" << M << "): ";
        for (int i = 0; i < M; i++) {
            if (tabela[i] != -1) cout << tabela[i] << " ";
            else cout << "- ";
        }
        cout << endl;
    }
};
