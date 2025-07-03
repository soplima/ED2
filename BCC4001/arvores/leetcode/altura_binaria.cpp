#include <algorithm>
#include "BST_tree.h"

int altura(NOH_AB *A){
    if(!A)return 0;
    int esq = altura(A->esq);
    int dir = altura(A->esq);
    int max = std::max(esq, dir);
    return max + 1;
}