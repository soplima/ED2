#include <stdio.h>
#include "BST_tree.h"

void imprimir_pos_ordem(NOH_AB *A){
    if(!A)return;
    imprimir_pos_ordem(A->esq);
    imprimir_pos_ordem(A->dir);
    printf("%d", A->chave);
}