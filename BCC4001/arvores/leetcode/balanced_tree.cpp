#include <algorithm>
#include "BST_tree.h"

int alturaBalanceada(NOH_AB *no) {
    if (!no) return 0;
    int altEsq = alturaBalanceada(no->esq);
    if (altEsq == -1) return -1;
    int altDir = alturaBalanceada(no->dir);
    if (altDir == -1) return -1;
    if (std::abs(altEsq - altDir) > 1)
        return -1;
    return 1 + std::max(altEsq, altDir);
}

int balanceada(NOH_AB *A) {
    return alturaBalanceada(A) != -1 ? 1 : 0;
}