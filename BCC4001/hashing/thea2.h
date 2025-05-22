#pragma once

#include <vector>
#include <utility>
#include <climits>
#include <iostream>

class TabHashEndAberto {
public:
    TabHashEndAberto(int tamanho, float limiar = 0.5) {
        
    }

    //Destrutor: libera todos os recursos alocados para a tabela
    ~TabHashEndAberto(){
        delete[]this->tabela;
    }
    
    //Insere um novo par (chave, valor) na tabela
    void inserir(int chave, int valor){
        
    }
    
    //Remove o par com a chave da tabela
    void remover(int chave){
        int h = buscar_pos(chave);
        if(h != -1){
            this->tabela[h].estado = Estado::APAGADO;
        }
    }
    
    //Busca o valor associado a chave na tabela
    std::pair<int,int> buscar(int chave){
        
    }
    
    //Imprime a tabela
    void imprimir(){
        
               
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
    int min;
    int max;

    Elemento *tabela; // tabela hash

    int hash(int chave, int k){ //função hash
        int sondagemLinear = (chave % this->m + k) % this->m;
        int sondagemQuadratico = (chave % this->m + k*k) % this->m;
        int sondagemDupla = ((chave % this->m) + k * ((chave % (this->m - 1)) + 1)) % this->m;
        return sondagemLinear;
    }

    // redimensiona a tabela para o novo tamanho (novo_m)
    void redimensionar(int novo_m){
    // Alocar uma nova tabela com o novo tamanho
    // Inicializar todas as posições da nova tabela como LIVRE
    // Guardar o ponteiro da tabela antiga
    // Atualizar o ponteiro da tabela atual para a nova tabela
    // Reinserir os elementos OCUPADOS da tabela antiga na nova
    // Liberar a memória da tabela antiga

        Elemento* nova_tabela = new Elemento[novo_m];
        for(int i = 0; i<novo_m; i++){
            nova_tabela[i].estado == Estado::LIVRE;
        }
        Elemento* antiga = this->tabela;
        int m_antigo = this->m;
        this->tabela = nova_tabela;
        this->m = novo_m;
        this->n = 0;
        for(int i = 0; i < m_antigo; i++){
            if(antiga[i].estado == Estado::OCUPADO){
                this->inserir(antiga[i].chave, antiga[i].valor);
            }
        }
        delete[]antiga;
    }
    

    //retorna a posição que a chave ocupa na tabela. 
    //(ou -1 se a chave não estiver na tabela)
    int buscar_pos(int chave){
        //k = 0
        //calcular hash
            //enquanto posicao for diferente de livre
                //se a posicao for ocupada
                //se a chave for igual a chave, retornar h
            //k++
            //calcular novo hash
        //retornar -1, pois nao foi possivel encontrar

        int k = 0;
        int h = this->hash(chave, k);
        while(this->tabela[h].estado != Estado::LIVRE){
            if(this->tabela[h].estado == Estado::OCUPADO &&
            this->tabela[h].chave == chave){
                return h;
            }
            k++;
            h = this->hash(chave, k);
        }
        return -1;
    }
};