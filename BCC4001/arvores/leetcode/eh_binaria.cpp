typedef struct noh_ab{
    struct noh_ab *esq, *dir;
    int chave;
}NOH_AB;

int eb(NOH_AB *A){
    if(!A) return 1;
    if(!A->esq && !A->dir){
        return 1;
    }
    if(A->esq && A->dir){
        return eb(A->esq) && eb(A->dir);
    }
    return 0;
}
