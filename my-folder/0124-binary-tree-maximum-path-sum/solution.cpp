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

struct info
{
    int maxDestra=0;
    int maxSinistra=0;
    int max=-1e9;
};
class Solution {
public:
    map<TreeNode*,info> m;
    void rico(TreeNode* root)
    {
        m[root].max=root->val;
        if(root->left==nullptr && root->right==nullptr)
        {
            m[root].maxDestra=root->val;
            m[root].maxSinistra=root->val;
            m[root].max=root->val;
            return;
        }
        if(root->left!=nullptr)
        {
            rico(root->left);
            m[root].maxSinistra=max(m[root->left].maxDestra,m[root->left].maxSinistra)+root->val;

            m[root].max=max(m[root].max,m[root->left].max);
        }
        else
        m[root].maxSinistra=root->val;
        if(root->right!=nullptr)
        {
            rico(root->right);
            m[root].maxDestra=max(m[root->right].maxDestra,m[root->right].maxSinistra)+root->val;
            m[root].max=max(m[root].max,m[root->right].max);
        }
        else
        {
            m[root].maxDestra=root->val;
        }
        m[root].max=max(m[root].max,m[root].maxDestra+m[root].maxSinistra-root->val);
        m[root].max=max({m[root].max,m[root].maxDestra,m[root].maxSinistra});
        m[root].max=max(m[root].max,root->val);
        m[root].maxDestra=max(m[root].maxDestra,root->val);
        m[root].maxSinistra=max( m[root].maxSinistra,root->val);
    }
    int maxPathSum(TreeNode* root) {
        rico(root);
        for(auto x: m)
            cout<<x.second.maxDestra<<" "<<x.second.maxSinistra<<" "<<x.second.max<<endl;
        return m[root].max;

    }
};
