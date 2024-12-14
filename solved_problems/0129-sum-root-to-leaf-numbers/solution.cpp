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
    int prova(TreeNode* root, int num)
    {
        num*=10;
        num+=root->val;
        if(root->left==nullptr&&root->right==nullptr)
            return num;
        int sum=0;
        if(root->left!=nullptr)
            sum+=prova(root->left,num);
        if(root->right!=nullptr)
            sum+=prova(root->right,num);
        return sum;
    }
    int sumNumbers(TreeNode* root) {
        return prova(root,0);
    }
};
