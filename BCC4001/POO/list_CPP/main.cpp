//#include "list.h"
//#include "sum.h"
#include "isPalindrome.h"


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

/*
int main(){
    int arr [] = {3, 4, 1, 6, 2, 0, 8, 6, 16, 52, 39, 24, -1};
    float u [] = {1.5, 1.4, 2.5};
    double w [] = {3.1, 5.2, 2.5};
    unsigned char y [] = {0, 244, 152};

    int n1 = sizeof(arr) / sizeof(arr[0]);  
    int resultado = soma_array(arr, n1);  

    int n2 = sizeof(u) / sizeof(u[0]);
    float resultado2 = soma_array(u, n2);

    int n3 = sizeof(w) / sizeof(w[0]);
    double resultado3 = soma_array(w, n3);

    int n4 = sizeof(y) / sizeof(y[0]);
    int resultado4 = soma_array(y, n4);

    std::cout << "A soma dos elementos do array int é: " << resultado << std::endl;
    std::cout << "A soma dos elementos do array de floats é: " << resultado2 << std::endl;
    std::cout << "A soma dos elementos do array de doubles é: " << resultado3 << std::endl;
    std::cout << "A soma dos elementos do array de uns char é: " << resultado4 << std::endl;

    return 0;
}
*/

int main() {
    Solution sol;
    string input;
    cout << "Enter a string to check if it is a palindrome: ";
    getline(cin, input);
    
    if (sol.isPalindrome(input)) {
        cout << "The string is a palindrome." << endl;
    } else {
        cout << "The string is not a palindrome." << endl;
    }
    
    return 0;
}
