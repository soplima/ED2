#include <algorithm>

typedef struct noh_ab{
    struct noh_ab *esq, *dir;
    int chave;
}NOH_AB;

int altura(NOH_AB *A){
    if(!A)return 0;
    int esq = altura(A->esq);
    int dir = altura(A->esq);
    int max = std::max(esq, dir);
    return max + 1;
}