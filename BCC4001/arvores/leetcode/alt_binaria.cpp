#include "BST_tree.h"
#include <algorithm>

int alt(NOH_AB *A){
    if(!A) return 0;
    int esq = alt(A->esq);
    int dir = alt(A->dir);
    int max = std::max(esq, dir);
    return max + 1;
}