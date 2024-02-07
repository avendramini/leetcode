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
    int ris=0;
    void dfs(TreeNode* root,int k,int &visti)
    {
        if(root==nullptr)
            return;
        dfs(root->left,k,visti);
        visti++;
        if(visti==k)
            ris=root->val;
        dfs(root->right,k,visti);
    }

    int kthSmallest(TreeNode* root, int k) {
        int visti=0;
        dfs(root,k,visti);
        return ris;
    }
};
