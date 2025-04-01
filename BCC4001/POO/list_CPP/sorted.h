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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ILIST mergedList;
        while(list1 != nullptr && list2 != nullptr){
            if(list1->dado <= list2->dado){
                mergedList.inserir(list1->dado);
                list1 = list1->proximo;
            }
            else{
                mergedList.inserir(list2->dado);
                list2 = list2->proximo;
            }
        }
        while(list1 != nullptr){
            mergedList.inserir(list1->dado);
            list1 = list1->proximo;
        }
        while(list2 != nullptr){
            mergedList.inserir(list2->dado);
            list2 = list2->proximo;
        }
        return mergedList.primeiro;
    }
    
};