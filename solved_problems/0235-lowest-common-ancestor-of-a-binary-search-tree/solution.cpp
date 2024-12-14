/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    vector<vector<TreeNode*> > v;
    void dfs(TreeNode* root, TreeNode* p, TreeNode* q,vector<TreeNode*>& att)
    {
        if(root==nullptr)
            return;
        att.push_back(root);
        if(root==p||root==q)
            v.push_back(att);
        
        dfs(root->left,p,q,att);
        
        
        dfs(root->right,p,q,att);
        att.pop_back();
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> att;
        dfs(root,p,q,att);
        TreeNode* com=root;
        for(int i=0;i<min(v[0].size(),v[1].size());i++)
        {
            if(v[0][i]!=v[1][i])
                break;
            com=v[0][i];
        }
        return com;
    }
};
