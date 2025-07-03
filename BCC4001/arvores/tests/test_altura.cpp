#include "BST_tree.h"
#include "catch2/catch_all.hpp"

TEST_CASE("funcao altura deve retornar a altura max da arvore"){
    NOH_AB no_esq = {
        .esq = NULL,
        .dir = NULL,
        .chave = 10
    };
    NOH_AB no_dir = {
        .esq = NULL,
        .dir = NULL,
        .chave = 20
    };
    NOH_AB arvore = {
        .esq = &no_esq,
        .dir = &no_dir,
        .chave = 15
    };

    int altura_arvore = altura(&arvore);
    REQUIRE(altura_arvore == 2);
}