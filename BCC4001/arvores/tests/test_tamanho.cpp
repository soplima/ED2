#include "BST_tree.h"
#include "catch2/catch_all.hpp"

TEST_CASE("A funcao deve retornar o tamanho da arvore"){
    NOH_AB esquerdo = {
        .esq = NULL,
        .dir = NULL,
        .chave = 10 
    };
    NOH_AB direito = {
        .esq = NULL,
        .dir = NULL,
        .chave = 20
    };
    NOH_AB Arvore = {
        .esq = &esquerdo,
        .dir = &direito,
        .chave = 15
    };

    int tamanho_arvore = tamanho(&Arvore);
    REQUIRE(tamanho_arvore == 3);
}