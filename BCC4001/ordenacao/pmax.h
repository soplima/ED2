



int pmax(int* v, int ini, int fim){
    
    for(int i = 0; i< fim; i++){
        if(v[i] > v[i + 1]){
            return v[i];
        }
    }
}