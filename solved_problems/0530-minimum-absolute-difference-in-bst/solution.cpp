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
    int massi(TreeNode* root)
    {
        if(root==nullptr)
            return -1e9;
        if(root->left==nullptr&&root->right==nullptr)
            return root->val;
        if(root->right!=nullptr)
            return massi(root->right);
        return root->val;
    }
    int mini(TreeNode* root)
    {
        if(root==nullptr)
            return 1e9;
        if(root->left==nullptr&&root->right==nullptr)
            return root->val;
        if(root->left!=nullptr)
            return mini(root->left);
        return root->val;
    }
    int getMinimumDifference(TreeNode* root) 
    {
        if(root==nullptr)
            return 1e9;
        return min({abs(root->val-mini(root->right)),abs(root->val-massi(root->left)),getMinimumDifference(root->left),getMinimumDifference(root->right)});
    }
};
