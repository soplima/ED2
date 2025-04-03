//#include "list.h"
#include "climbStairs.h"

/*
int main(){
    ILISTA* l = new ILISTA();

    l->imprimir();
    l->inserir(10);
    l->imprimir();
    l->inserir(20);
    l->imprimir();
    l->inserir(30);
    l->imprimir();
    l->inserir(40);
}
*/

int main() {
    Solution solution;

    int n;
    cout << "Digite o número de degraus: ";
    cin >> n;

    int result = solution.climbStairs(n);
    cout << "O número de maneiras de subir " << n << " degraus é: " << result << endl;

    return 0;
}
