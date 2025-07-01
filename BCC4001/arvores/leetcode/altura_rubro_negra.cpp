typedef struct noh_ab{
    struct noh_ab *esq, *dir;
    int chave;
    char cor;
}NOH_AB;

int rubro_altura(NOH_AB *A){
    if(!A)return 0;
    int altura = rubro_altura(A->esq);
    if(A->cor == 'P')
        altura = +1;
    else
        return altura;
}