    //cria uma tabela hash inicialmente com m posicoes
//TH* TH_Criar(size_t m);
    //so retorna true se a chave esta na tabela
//bool TH_Buscar(TH* t, int chave);
    //insere a chave na tabela. Caso a chave ja esteja na tabela/
        //a tabela nao e alterada.
//void TH_inserir(TH* t, int chave);
    //remover a chave da tabela. Caso a chave nao esteja na tabela, 
    //a tabela nao e alterada.
//void TH_remover(TH* t, int chave);
    //retorna um vetor com os elementos em comum entre os vetores de A e B.
    //os vetores A e B possuem nA e nB elementos respectivamente. O nmumero
    //de elementos retornados e escrito no parametro de saida nInter.
//int* TH*_Intersecao(int* A, int nA, int *B, int nB, nInter);
    //retorna um vetor com todos os elementos que estao em A, mas nao em B.
    //o numero e escrito no parametro nDif.
//int* TH_Diferenca(int* A, int nA, int *B, int nB, int* nDif);
    //retorna um vetor com todas as chaves inseridas na tabela.
//int* TH_Chaves(TH* t, int *n);
    //desaloca a tabela hash t
//void TH_Destruir(TH* t);

//Usando o TAD definido acima, implemente as seguintes operacoes;

int* diferenca_simetrica(int* A, int nA, int* B, int nB, int* nDifSim) {
    TH* tabelaA = TH_Criar(nA * 2);
    TH* tabelaB = TH_Criar(nB * 2);

    for (int i = 0; i < nA; i++) {
        TH_inserir(tabelaA, A[i]);
    }

    for (int i = 0; i < nB; i++) {
        TH_inserir(tabelaB, B[i]);
    }

    int* resultado = new int[nA + nB];
    int count = 0;

    // A - B
    for (int i = 0; i < nA; i++) {
        if (!TH_Buscar(tabelaB, A[i])) {
            resultado[count++] = A[i];
        }
    }

    // B - A
    for (int i = 0; i < nB; i++) {
        if (!TH_Buscar(tabelaA, B[i])) {
            resultado[count++] = B[i];
        }
    }

    TH_Destruir(tabelaA);
    TH_Destruir(tabelaB);

    *nDifSim = count;

    if (count == 0) return NULL;

    return resultado;
}
