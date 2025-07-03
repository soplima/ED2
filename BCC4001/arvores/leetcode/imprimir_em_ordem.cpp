#include <stdio.h>
#include "BST_tree.h"

void imprimir_em_ordem(NOH_AB *A){
    if(!A)return;
    imprimir_em_ordem(A->esq);
    printf("%d", A->chave);
    imprimir_em_ordem(A->dir);
}