#include <stdio.h>
#include "BST_tree.h"

void imprimir_pre_ordem(NOH_AB *A){
    if(!A)return;
    printf("%d", A->chave);
    imprimir_pre_ordem(A->esq);
    imprimir_pre_ordem(A->dir);
}