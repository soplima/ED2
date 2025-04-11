#include <iostream>
using namespace std;

//fatorial(5) -> 5! = 5 * 4 * 3 * 2 * 1 = 120


int factorial(int n){
    if(n == 0){
        return 1;
    }else{
        return n * factorial(n-1);
    }
}   

int main(){
    int n = 5;
    cout << "Fsctorial: " << factorial(n) << endl;
    return 0;

}