#pragma once

#include <vector>
#include <utility>

class TabHashEndAberto {
public:
    TabHashEndAberto(int tamanho, float limiar = 0.5) {
        this->m = tamanho;
        this->n = 0;
        this->limiar = limiar;
        this->redims = 0;
        this->tabela = new Elemento[this->m];
        for (int i = 0; i < this->m; i++) {
            this->tabela[i].estado = Estado::LIVRE;
        }
        this->invalido = std::make_pair(-1, -1); 
    }


    //Destrutor: libera todos os recursos alocados para a tabela
    ~TabHashEndAberto(){
        delete[]this->tabela;
    }
    
    //Insere um novo par (chave, valor) na tabela
    void inserir(int chave, int valor){
        int h = buscar_pos(chave);
        if(h >= 0){
            this->tabela[h].valor = valor;
            return;
        }

        if((this-> n+1 )/ this->m > this->limiar){
            this->redimensionar(this->m * 2);
            this->redims++;
        }

        int k = 0;
        h = this->hash(chave, k);
        while(this->tabela[h].estado == Estado::OCUPADO){
            k++;
            h = this->hash(chave, k);
            this->colisoes++;
        }
        this->tabela[h].chave = chave;
        this->tabela[h].valor = valor;
        this->tabela[h].estado = Estado::OCUPADO;
    }
    
    //Remove o par com a chave da tabela
    void remover(int chave);
    
    //Busca o valor associado a chave na tabela
    std::pair<int,int> buscar(int chave){
        int pos = buscar_pos(chave);
        if(pos >= 0){
            return std::make_pair(this->tabela[pos].chave,
                                  this->tabela[pos].valor);
        }
        return this->invalido;
    }
    
    //Imprime a tabela
    void imprimir(){
        for (int i = 0; i < this->m; i++) {
            std::cout << i << ": ";
            const auto& el = this->tabela[i];
            std::cout << "(" << el.chave << "," << el.valor << ") ";
            char estado = el.estado == Estado::APAGADO ? 'A' :
                        (el.estado == Estado::LIVRE ? 'L' : 'O');
            std::cout << "[" << estado << "]";
            std::cout << std::endl;
        }    
    }

    //Imprime informações sobre a tabela (m, n e fator de carga)
    void imprimir_info()
    {
        std::cout << "m: " << this->m << std::endl;
        std::cout << "n: " << this->n << std::endl;
        std::cout << "fator de carga: " << (float)this->n/this->m << std::endl;
        std::cout << "redimensionamentos: " << this->redims << std::endl;
    }

    //par chave-valor inválido para indicar que a chave não foi encontrada
    std::pair<int,int> invalido;

    // retorna as chaves da tabela
    std::vector<int> chaves();

    // retorna todos os pares (chave, valor) da tabela
    std::vector<std::pair<int,int>> itens();

private:

    enum class Estado {
        LIVRE,
        OCUPADO,
        APAGADO
    };

    struct Elemento {
    public:
        int chave;
        int valor;
        Estado estado;
    };

    int m; // tamanho da tabela
    int n; // número de elementos na tabela
    // limiar para redimensionamento. quando n/m > limiar, redimensionar
    float limiar; 
    int redims; // número de redimensionamentos realizados
    int colisoes = 0;

    Elemento *tabela; // tabela hash

    int hash(int chave, int k){ //função hash
        return ((chave % this->m ) + k) % m;
    }

    // redimensiona a tabela para o novo tamanho (novo_m)
    void redimensionar(int novo_m){
        Elemento* nova_tabela = new Elemento[novo_m];
        for(int i = 0; i < novo_m; i++){
            nova_tabela[i].estado = Estado::LIVRE;
        }
        Elemento*antiga = this->tabela;
        int m_antigo = this->m;
        this->tabela = nova_tabela;
        this->m = novo_m;
        this->n = 0;
        for(int i = 0; i<m_antigo; i++){
            if(antiga[i].estado== Estado::OCUPADO){
                this->inserir(antiga[i].chave, antiga[i].valor);
            }
        }
        delete[]antiga;
    }
    

    //retorna a posição que a chave ocupa na tabela. 
    //(ou -1 se a chave não estiver na tabela)
    int buscar_pos(int chave){
        int k = 0;
        int h = this->hash(chave, k);
        while(this->tabela[h].estado != Estado::LIVRE){
            if((this->tabela[h].estado == Estado::OCUPADO)
            && (this->tabela[h].chave == chave)){
                return h;
            }
            k++;
            h = this->hash(chave, k);
        }
        return -1;
    }
    
};