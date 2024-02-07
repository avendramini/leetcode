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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode* > q;
        q.push(root);
        vector<vector<int> > ris;
        int rim=1;
        ris.push_back({});
        int indice=0;
        while(q.size()!=0)
        {
            TreeNode* top=q.front();
            q.pop();
            if(top!=nullptr){
            ris[indice].push_back(top->val);
            if(top->left!=nullptr)
            q.push(top->left);
            if(top->right!=nullptr)
            q.push(top->right);
            }
            rim--;
            if(rim==0)
            {
                rim=q.size();
                indice++;
                ris.push_back({});
            }
        }
        
        while(ris.size()>0&&ris[ris.size()-1].size()==0)
            ris.pop_back();
        return ris;
    }
};
