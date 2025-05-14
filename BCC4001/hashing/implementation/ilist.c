#include <stdio.h>
#include <stdlib.h>
#include "ilist.h"

ILIST* ILIST_Criar(int alloc_step) {
    ILIST* L = malloc(sizeof(ILIST));
    L->max = 0;
    L->tam = 0;
    L->alloc = alloc_step;
    L->alloc_step = alloc_step;
    L->nos = malloc(sizeof(INOH) * alloc_step);
    return L;
}

int ILIST_inserir(ILIST *L, int chave, int valor) {
    // Verifica se precisa alocar mais espaço
    if (L->tam >= L->alloc) {
        L->alloc += L->alloc_step;
        L->nos = realloc(L->nos, sizeof(INOH) * L->alloc);
    }

    // Insere novo nó
    L->nos[L->tam].chave = chave;
    L->nos[L->tam].valor = valor;
    L->nos[L->tam].ocupado = 1;
    L->tam++;
    return 1;
}

int ILIST_Buscar(ILIST *L, int chave) {
    for (int i = 0; i < L->tam; i++) {
        if (L->nos[i].ocupado && L->nos[i].chave == chave) {
            return i;
        }
    }
    return -1; // Não encontrado
}

INOH* ILIST_Endereco(ILIST *L, int pos) {
    if (pos >= 0 && pos < L->tam) {
        return &L->nos[pos];
    }
    return NULL;
}

int ILIST_Remover(ILIST *L, int chave) {
    int i = ILIST_Buscar(L, chave);
    if (i >= 0) {
        L->nos[i].ocupado = 0;
        return i;
    }
    return -1;
}

void ILIST_Imprimir(ILIST *L, int debug) {
    for (int i = 0; i < L->tam; i++) {
        if (L->nos[i].ocupado) {
            printf("(%d, %d) ", L->nos[i].chave, L->nos[i].valor);
        }
        if (debug) {
            printf("[ocupado=%d] ", L->nos[i].ocupado);
        }
    }
    printf("\n");
}
