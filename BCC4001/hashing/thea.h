#pragma once

#include <vector>
#include <utility>
#include <climits>

class TabHashEndAberto {
public:
    TabHashEndAberto(int tamanho, float limiar = 0.5) {
        this->m = tamanho;
        this->n = 0;
        this->limiar = limiar;
        this->redims = 0;
        this->min = INT_MAX;
        this->max = INT_MIN;
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
        if(h != -1){ //se a chave ja existir, atualiza o valor. se nao, insere. 
            this->tabela[h].valor = valor;
            this->n--;
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
        if(this->tabela[h].chave < this->min){
            min = chave;
        }
        if(this->tabela[h].chave > this->max){
            max = chave;
        }
        this->n++;
    }

    int obter_min() const {
    return this->min;
    }

    int obter_max() const {
    return this->max;
    }
    
    //Remove o par com a chave da tabela
    void remover(int chave){
        int h = buscar_pos(chave);
        if(h != -1){
            this->tabela[h].estado = Estado::APAGADO;
            this->n--;
        }

        //reinicia min e max para poder calcular
        this->min = INT_MAX;
        this->max = INT_MIN;
        //se as posicoes estiverem ocupadas
        //percorrer as posicoes achar o maior ou menor
        for(int i = 0; i<this->m; i++){
            if(this->tabela[i].estado == Estado::OCUPADO){
                if(this->tabela[i].chave < this->min){
                    this->min = this->tabela[i].chave;
                }
                if(this->tabela[i].chave > this->max){
                    this->max = this->tabela[i].chave;
                }
            }
        }
        if(this->n == 0){
            this->min, this->max = 0;
        }
        
    }
    
    int cluster_maximo() const{
        int count, maxCluster = 0;
        for(int i = 0; i< this->m; i++){
            if(this->tabela[i].estado == Estado::OCUPADO){
                count++;
                if(count > maxCluster){
                maxCluster = count;
                }
            }else{
                count = 0;
            }
        }
        return maxCluster;
    } 

    float tamanho_medio_clusters() const{
    int totalElementos = 0;
    int numClusters = 0;
    int count = 0;

    for (int i = 0; i < this->m; i++) {
        if (this->tabela[i].estado == Estado::OCUPADO) {
            count++;
        } else {
            if (count > 0) {
                totalElementos += count;
                numClusters++;
                count = 0;
            }
        }
    }

    if (count > 0) {
        totalElementos += count;
        numClusters++;
    }
        return totalElementos / numClusters;
    }

    float custo_bem_sucedida() const{
        int elementos = 0;
        int clusters = 0;
        int total = 0;


        for(int i = 0; i < this->m; i++){
            if(this->tabela[i].estado == Estado::OCUPADO){
                elementos++;
            }else{
                if(elementos > 0){
                total += std::max(elementos / 2.0f, 1.0f);
                clusters++;
                elementos = 0;
                }
            }     
        }
        if (elementos > 0) {
        total += std::max(elementos / 2.0f, 1.0f);
        clusters++;
    }
        return total / clusters;  
    }

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
    int min;
    int max;

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
                this->n++;
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