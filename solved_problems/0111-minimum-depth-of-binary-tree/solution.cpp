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
    int minDepth(TreeNode* root) {
        if(root==nullptr)
            return 0;
        int mini=1e9;
        if(root->left!=nullptr)
        mini=min(minDepth(root->left)+1,mini);
        if(root->right!=nullptr)
        mini=min(mini,minDepth(root->right)+1);
        if(mini==1e9)
            return 1;
        return mini;
    }
};
