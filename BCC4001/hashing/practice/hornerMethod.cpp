#include <stdio.h>
#include <unordered_map>
#include <string>
#include <vector>
#include <iostream>

unsigned int string_hash(char* s, int k, int M, int n){
    int hash = 0;
    for(int i = 0; i < n; i++){
        hash = (hash * k) + s[i];
    }
    return hash % M;
}