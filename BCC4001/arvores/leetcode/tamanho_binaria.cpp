typedef struct noh_ab{
    struct noh_ab *esq, *dir;
    int chave;
}NOH_AB;

int tamanho(NOH_AB *A){
    if(!A)return 0;
    int esq = tamanho(A->esq);
    int dir = tamanho(A->dir);
    return esq + dir + 1;
}