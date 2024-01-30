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
bool ris=true;
    bool isBalanced(TreeNode* root) {
        altezza(root);
        return ris;
    }
    
    int altezza(TreeNode* root)
    {
        if(root==nullptr)
        return 0;
        int sx=altezza(root->left);
        int dx=altezza(root->right);
        if(abs(sx-dx)>1)
            ris=false;
        return max(sx,dx)+1;
    }
};
