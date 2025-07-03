#include "BST_tree.h"

NOH_AB* buscar_no(NOH_AB *A, int chave){
    while(A != nullptr){
        if(A->chave == chave){
            return A;
        }
    if(A->chave > chave){
        return buscar_no(A->esq, chave);
    }
    else{
        return buscar_no(A->dir, chave);
    }
    }
    return nullptr;
}