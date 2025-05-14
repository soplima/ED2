#include <stdio.h>
#include <stdlib.h>
#include "tabelahash_ed.h"
#include "ilist.h"

int main(int arg, char**argv){
    int i;
    int x;

    THED* th = TH_Criar(7, 10);
    THED_Inserir(th, 0, 0);
    THED_Inserir(th, 3, 3);
    THED_Inserir(th, 11, 11);
    THED_Inserir(th, 12, 12);
    THED_Inserir(th, 6, 6);
    THED_Inserir(th, 14, 14);

    for(i = 0; i<th->M; i++){
        printf("%d ", i);
        ILIST_Imprimir(th->th[i], 1);
    }

    x = 0;
    INOH* el = THED_Buscar(th, x);
    if(el){
        printf("buscar %d = %d\n", x, el->valor);
    }else{
        printf("%d nao encontrado!\n", x);
    }
}