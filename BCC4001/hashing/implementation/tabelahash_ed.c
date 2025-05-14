#include <stdlib.h>
#include "tabelahash_ed.h"
#include "ilist.h"

int THED_Hash(THED* TH, int chave){
    return chave % TH->M;
}

// Função que cria e inicializa uma tabela hash encadeada
// m: número de buckets (tamanho da tabela)
// alloc_step: usado internamente para definir o tamanho inicial de cada lista (ILIST)
THED* TH_Criar(int m, int alloc_step) {
    THED* nova; // Declara um ponteiro para a estrutura da tabela hash
    int i;      // Variável auxiliar para o laço for

    // Aloca dinamicamente memória para a estrutura THED
    // Isso cria espaço para os campos M e th
    nova = malloc(sizeof(THED));

    // Define o tamanho da tabela (quantos buckets ela terá)
    nova->M = m;

    // Aloca memória para o vetor de ponteiros para ILISTs (cada um será um bucket)
    // Cada elemento do vetor th será um ponteiro para uma lista (ILIST*)
    nova->th = malloc(sizeof(ILIST*) * m);

    // Inicializa cada posição do vetor th com uma nova ILIST (lista vazia)
    // Ou seja, cria um bucket em cada posição
    for(int i = 0; i < m; i++) {
        nova->th[i] = ILIST_Criar(alloc_step);
    }

    // Retorna o ponteiro para a tabela hash criada
    return nova;
}

void THED_Inserir(THED* TH, int chave, int valor){
//Inserir um par (chave, valor) na tabela hash encadeada THED
    int place;
    place = THED_Hash(TH, chave); //Chama a função THED_Hash para calcular o 
    //índice do vetor th onde essa chave deve ser inserida
    ILIST_inserir(TH->th[place], chave, valor); //guarda na lista no indice place a chave e valor recebidos
}

INOH* THED_Buscar(THED* TH, int chave){
    int h, pos;
    h = THED_Hash(TH, chave); // Calcula o índice do bucket
    pos = ILIST_Buscar(TH->th[h], chave); //tabela hash TH, vá até o vetor de listas th e acesse o índice h
    return ILIST_Endereco(TH->th[h], pos);
}

void THED_Remover(THED* TH, int chave){
    int h,pos;
    h = THED_Hash(TH, chave); // Calcula o índice do bucket
    ILIST_Remover(TH->th[h], chave);
}