typedef struct noh_ab{
    struct noh_ab *esq, *dir;
    int chave;
}NOH_AB;

int eh_binaria(NOH_AB *A){
    if(!A)return 1;
    if(!A->esq && !A->dir) return 1;
    if(A->esq && A->dir){
        return eh_binaria(A->esq) && eh_binaria(A->dir);
    }
    return 0;
}