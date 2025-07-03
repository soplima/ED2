#pragma once

typedef struct noh_ab{
    struct noh_ab *esq, *dir;
    int chave;
}NOH_AB;

void imprimir_em_ordem(NOH_AB *A);
int altura(NOH_AB *A);
int balanceada(NOH_AB *A);
int eh_binaria(NOH_AB *A);
int eb(NOH_AB *A);
void imprimir_pos_ordem(NOH_AB *A);
void imprimir_pre_ordem(NOH_AB *A);
int tamanho(NOH_AB *A);