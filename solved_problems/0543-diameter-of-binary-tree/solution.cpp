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
    int ans=0;
    int dfs(TreeNode* root){
        if (root==NULL) return 0;
     
        int r=dfs(root->right);
        
        int l=dfs(root->left);
        
        ans=max(ans, l+r);
    //    cout<<ans<<endl; 
        return 1+max(l, r); //heightest level
    }

    int diameterOfBinaryTree(TreeNode* root) {       
        dfs(root);
        return ans;
    }
};


auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
