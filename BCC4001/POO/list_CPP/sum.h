#include <iostream>
#include <vector>
template <typename T>

T soma_array(T* arr, int n){
    T result = 0;
    for(int i = 0; i < n; i ++){
        result += arr[i];
    }
    return result;
}





