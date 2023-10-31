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
    vector<double> averageOfLevels(TreeNode* root) {

        vector<double> ris;
        queue<TreeNode*> q;
        q.push(root);
        int dentro=1;
        double sum=0;
        double count=1;
        while(q.size()>0)
        {
            TreeNode* att=q.front();
            q.pop();
            sum+=att->val;
            dentro--;
            if(att->left!=nullptr)
                q.push(att->left);
            if(att->right!=nullptr)
                q.push(att->right);
            if(dentro==0)
            {
                dentro=q.size();
                ris.push_back(sum/count);
                count=dentro;
                sum=0;
            }
        }
        return ris;
        
    }
};
