//A estrutura ILISTA_EL é responsável por armazenar um único elemento e o endereço do próximo elemento.
#include <iostream>
class No{
public:
    No (int dado){
        this -> proximo = nullptr;
        this->dado = dado;
    }
    int getDado(){
        return this->dado;
    }

    friend class ILISTA;

private:
    int dado;
    No* proximo;
};

//A estrutura ILISTA representa a lista toda, com ponteiros para o primeiro e o ultimo elemento.
class ILISTA{
public:
    ILISTA(){
        this->tamanho = 0;
        this->primeiro = nullptr;
        this->ultimo = nullptr;
    }

    ~ILISTA(){
        No* p = this->primeiro;
        while(p != nullptr){
            No* t = p->proximo;
            delete p;
            p = t;
        }
    }

    void inserir(int dado){
        No* n = new No(dado);

        if(is_empty){
            this->primeiro = n;
        }
        else{
            this->ultimo->proximo;
        }
        this->ultimo = n;
        this->tamanho++;
    }

    void imprimir(){
        std::cout << "Tamanho da Lista: " << this->tamanho;
        No* p = this ->primeiro;
        while (p != nullptr){
            std::cout << p->getDado() << ", ";
            p= p-> proximo;
        };
        std::cout <<  ", \n";
    }

    bool is_empty(){
        return tamanho == 0;
    }

private:
    int tamanho;
    No* primeiro;
    No* ultimo;
};