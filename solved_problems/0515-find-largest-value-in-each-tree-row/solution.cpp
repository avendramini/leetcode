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
    vector<int> largestValues(TreeNode* root) {
        queue<TreeNode*> q;
        vector<int> ris;
        q.push(root);
        int mancanti=1;
        int massimo=INT_MIN;
        if(root==nullptr)
            return ris;
        while(q.size()>0)
        {
            TreeNode* top=q.front();
            q.pop();
            mancanti--;
            massimo=max(massimo,top->val);
            if(top->left!=nullptr){
                q.push(top->left);
            }
            if(top->right!=nullptr)
            {
                q.push(top->right);
            }
            if(mancanti==0)
            {
                ris.push_back(massimo);
                massimo=INT_MIN;
                mancanti=q.size();
            }
        }
        return ris;
    }
};
