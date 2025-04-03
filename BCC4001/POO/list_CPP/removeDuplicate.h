class ListNode{
    public:
    ListNode(int dado){
            this->proximo = nullptr;
            this->dado = dado;
        }
        friend class ILIST;
        friend class Solution;
    
    private:
        int dado;
        ListNode* proximo;
    };
    
    class ILIST{
    public:
        ILIST(){
            this->tamanho = 0;
            this -> primeiro = nullptr;
            this -> ultimo = nullptr;
        }
        void inserir(int dado){
            ListNode* n = new ListNode(dado);
    
            if(is_empty()){
                this->primeiro = n;
                this->ultimo = n;
                this->tamanho++;
            }
            else{
                this->ultimo->proximo = n;
                this->ultimo = n;
                this->tamanho++;
            }
        }
        bool is_empty(){
            return tamanho == 0;
        }
    
        friend class Solution;
    
    private:
        int tamanho;
        ListNode* primeiro;
        ListNode* ultimo;
    };
    
    class Solution {
        public:
            ListNode* deleteDuplicates(ListNode* head) {
                ListNode* current = head;
                while(head != nullptr && current->proximo != nullptr){
                    if(head->dado == head->proximo->dado){
                        ListNode* temp = current->proximo;
                        delete temp;
                    }else{
                        current = current->proximo;
                    }
                }
                return head;
            }
        };