/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
    class Solution {
    public:
        vector<int> findMode(TreeNode* root) {
            unordered_map<int, int>count; //!inicializa um hashmap para organizar a frequencia de cada val
            int maxFreq = 0; //!inicializa a max freq
            traverse(root, count); //!Chama a funcao auxiliar que atravessa a arvore

            for(auto& [val, freq]: count){ //!atravessa count tendo como mwtrixas val e freq
                maxFreq = max(maxFreq, freq); //! maxima frequencia e o valor maximo presente em freq
            }

            vector<int>modes; //!cria um vetor de inteiros para as modas
            for(auto& [val, freq]: count){
                if(freq == maxFreq){ //!Se houver mais de um valor com a frequecia maxima, devolve os dois 
                    modes.push_back(val); //! coloca no vetor o valor das variaveis com a frequencia maxima
                }
            }
            return modes;
        }
    private: 
        void traverse(TreeNode* node, unordered_map<int, int>& count){
            if(!node) return; //!se o no for nulo, retorna
            count[node->val]++; //!se nao for nulo, conta o valor
            traverse(node->left, count); //!conta os valores da esquerda
            traverse(node->right, count);//!conta os valores da direita
        }
    };