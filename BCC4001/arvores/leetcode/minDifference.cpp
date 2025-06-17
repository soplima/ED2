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
class Solution
{
public:
    int getMinimumDifference(TreeNode *root)
    {
        int minDif = __INT_MAX__;
        TreeNode *prev = nullptr;
        traverse(root, prev, minDif);
        return minDif;
    }

private:
    void traverse(TreeNode *node, TreeNode *&prev, int &minDif)
    {
        if (!node)
            return;
        traverse(node->left, prev, minDif);
        if (prev != nullptr)
        {
            minDif = min(minDif, abs(node->val - prev->val));
        }
        prev = node;
        traverse(node->right, prev, minDif);
    }
};