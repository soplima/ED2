#include <iostream>
using namespace std;

//Escreva uma função recursiva que calcule a soma dos elementos positivos do vetor de inteiros v[0..n-1].  
//O problema faz sentido quando n é igual a 0?  Quanto deve valer a soma nesse caso?

int somaPositivos (int* v, int n){
    if(n == 0){
        return 0;
    }else{
     int ultimoElem = v[n - 1];
     if(ultimoElem > 0){
        return ultimoElem + somaPositivos(v, n-1);
     }else{
        return somaPositivos(v, n-1);
     }
    }
}

int main(){
    int v[] = {1, -3, 5, -2, 4};
    int n = sizeof(v) / sizeof(v[0]);
    cout << "Soma dos positivos: " << somaPositivos(v, n) << endl;
    return 0;

}