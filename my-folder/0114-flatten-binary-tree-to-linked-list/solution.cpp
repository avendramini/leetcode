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
    TreeNode* rico(TreeNode* root)
    {
        if(root==nullptr)
            return nullptr; 
        TreeNode* right=root->right;
        TreeNode* last=nullptr;
        if(root->left){
            root->right=rico(root->left);
            root->left=nullptr;
            last=root;
            while(last->right!=nullptr)
            {
                last=last->right;
            }
        }
        if(right)
        {
            if(last)
            {
                last->right=rico(right);
            }
            else
            {
                root->right=rico(right);
            }
        }
        return root;
    }
    void flatten(TreeNode* root) {
        rico(root);
    }
};
