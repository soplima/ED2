#include "BST_tree.h"

int tamanho(NOH_AB *A){
    if(!A)return 0;
    int esq = tamanho(A->esq);
    int dir = tamanho(A->dir);
    return esq + dir + 1;
}