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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ris;
        if(root==nullptr)
            return ris;
        queue<TreeNode*> q;
        q.push(root);
        int dentro=1;
        while(q.size()!=0)
        {   
            TreeNode* att=q.front();
            q.pop(),
            dentro--;
            if(att->left!=nullptr)
            {
             q.push(att->left);
            }
            if(att->right!=nullptr)
            {
                q.push(att->right);
            }
            if(dentro==0)
            {
                ris.push_back(att->val);
                dentro=q.size();
            }
            
        }
        return ris;

    }
};
