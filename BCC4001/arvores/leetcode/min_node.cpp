#include "BST_tree.h"

NOH_AB* minimo(NOH_AB *A){
    if(!A) return nullptr;
    if(!A->esq) return A;
    return minimo(A->esq);
}