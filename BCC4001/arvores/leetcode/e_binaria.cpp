#include "BST_tree.h"

int eh_binaria(NOH_AB *A){
    if(!A)return 1;
    if(!A->esq && !A->dir) return 1;
    if(A->esq && A->dir){
        return eh_binaria(A->esq) && eh_binaria(A->dir);
    }
    return 0;
}