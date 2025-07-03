#include "BST_tree.h"

NOH_AB* maximo(NOH_AB *A){
    if(!A) return nullptr;
    if(!A->dir) return A;
    return maximo(A->dir);
}