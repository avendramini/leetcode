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
    void dfs(TreeNode* root,map<int,vector<int>> &m)
    {
        if(root==nullptr)
            return;
        queue<pair<int,TreeNode*> > q;
        q.push({0,root});
        while(q.size()>0)
        {
            int pos=q.front().first;
            TreeNode* att=q.front().second;
            q.pop();
            m[pos].push_back(att->val);
            if(att->left!=nullptr)
            q.push({pos-1,att->left});
            if(att->right!=nullptr)
            q.push({pos+1,att->right});
        }
    }
    vector<vector<int>> verticalOrder(TreeNode* root) {
        map<int,vector<int> >m;
        dfs(root,m);
        vector<vector<int >> ris;
        for(auto x: m)
        {
            vector<int> b;
            for(auto k : x.second)
            {
                b.push_back(k);
            }
            ris.push_back(b);
        }
        return ris;
    }
};