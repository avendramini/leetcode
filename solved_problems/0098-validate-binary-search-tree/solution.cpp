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
    bool dfs(TreeNode* root, long long min,long long max)
    {
        if(root==nullptr)
            return true;
        if(root->val>=max||root->val<=min)
            return false;
        bool ok=true;
        ok &=dfs(root->left,min,root->val);
        ok&=dfs(root->right,root->val,max);
        return ok;
    }
    bool isValidBST(TreeNode* root) {
        return dfs(root,-1e18,1e18);
    }
};
