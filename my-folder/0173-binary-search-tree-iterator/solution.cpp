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
class BSTIterator {
public:
    int pos=0;
    vector<int> v;
    BSTIterator(TreeNode* root) {
        crea(root);
    }
    void crea(TreeNode* root)
    {
        if(root==nullptr)
            return;
        if(root->left!=nullptr)
            crea(root->left);
        v.push_back(root->val);
        if(root->right!=nullptr)
            crea(root->right);
    }
    int next() {
        return v[pos++];
    }
    
    bool hasNext() {
        if(pos!=v.size())
        {
            return true;
        }
        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
