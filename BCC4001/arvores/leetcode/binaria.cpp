#include "BST_tree.h"

int binaria(NOH_AB *A){
    if(!A)return 1;
    if(!A->esq && !A->dir) return 1;
    if(A->esq && A->dir){
        return binaria(A->esq) && binaria(A->dir);
    }
    return 0;
}