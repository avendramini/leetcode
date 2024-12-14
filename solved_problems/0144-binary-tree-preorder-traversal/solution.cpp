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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ris;
        nuova(ris,root);
        return ris;
    }
    void nuova(vector<int> &ris,TreeNode* root)
    {
        if(root==nullptr)
            return;
        ris.push_back(root->val);
        nuova(ris,root->left);
        nuova(ris,root->right);
        
    }
};
