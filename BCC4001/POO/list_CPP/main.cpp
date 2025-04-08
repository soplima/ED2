//#include "list.h"
//#include "sum.h"
//#include "isPalindrome.h"
#include "singleNumber.h"


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
#include <iostream>
int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "Usage: ./main <list of numbers>\n";
        return 1;
    }

    vector<int> nums;
    for (int i = 1; i < argc; ++i) {
        nums.push_back(atoi(argv[i])); // convert string args to int
    }

    Solution sol;
    int result = sol.singleNumber(nums);

    cout << "The single number is: " << result << endl;

    return 0;
}

