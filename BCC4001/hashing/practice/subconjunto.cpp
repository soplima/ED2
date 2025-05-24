#include <stdio.h>
#include <unordered_map>
#include <string>
#include <vector>
#include <iostream>

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

bool eh_subconjunto(int* A, int nA, int* B, int nB) {
    // Cria a tabela hash com tamanho suficiente (ex: dobro de nB para evitar colisões)
    TH* tabela = TH_Criar(nB * 2);

    // Insere todos os elementos de B na tabela hash
    for (int i = 0; i < nB; i++) {
        TH_inserir(tabela, B[i]);  // Armazena cada elemento de B na tabela hash
    }

    // Verifica se cada elemento de A está presente na tabela (ou seja, em B)
    for (int i = 0; i < nA; i++) {
        // Se algum elemento de A não estiver presente na tabela, A não é subconjunto de B
        if (!TH_Buscar(tabela, A[i])) {
            TH_Destruir(tabela); // Libera a memória da tabela antes de sair
            return false;        // Retorna falso pois encontrou elemento de A que não está em B
        }
    }

    TH_Destruir(tabela); // Todos os elementos de A foram encontrados em B, libera a tabela
    return true;         // Retorna verdadeiro: A é subconjunto de B
}
