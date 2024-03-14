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
    bool checkEqual(TreeNode* root, TreeNode* subRoot)
    {
        if(subRoot==nullptr&&root==nullptr)
            return true;
        if(subRoot==nullptr)
            return false;
        if(root==nullptr)
            return false;
        if(root->val!=subRoot->val)
            return false;
        bool ok=true;
        ok= ok & checkEqual(root->left,subRoot->left);
        ok= ok & checkEqual(root->right,subRoot->right);
        return ok;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==nullptr)
            return false;
        bool ok=false;
        ok=ok|checkEqual(root,subRoot);
        ok=ok|isSubtree(root->left,subRoot);
        ok=ok|isSubtree(root->right,subRoot);
        return ok;
    }
};
