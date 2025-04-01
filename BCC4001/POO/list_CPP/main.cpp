#include "list.h"

int main(){
    ILISTA* l = new ILISTA();

    l->imprimir();
    l->inserir(10);
    l->imprimir();
    l->inserir(20);
    l->imprimir();
    l->inserir(30);
    l->imprimir();
    l->inserir(40);
}