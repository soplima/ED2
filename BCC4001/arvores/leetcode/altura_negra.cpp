typedef struct noh_ab{
    struct noh_ab *esq, *dir;
    int chave;
    char cor;
}NOH_AB;

int altura_negra(NOH_AB *A){
    if(!A) return 0;
    int altura_subarvore = altura_negra(A->esq);
    if(A->cor == 'P')
        return altura_subarvore +1;
    else
        return altura_subarvore;
}