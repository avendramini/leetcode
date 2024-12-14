/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> padriP;
    vector<TreeNode*> padriQ;
    int hP;
    int hQ;
    int lol;
    bool padri(TreeNode* root, TreeNode* p,vector<TreeNode*> &v,int h)
    {
        if(root==p){
            lol=h;
            v.push_back(root);
            return true;
        }
        if(root->left==nullptr&&root->right==nullptr)
            return false;
        if(root->left!=nullptr)
            if(padri(root->left,p,v,h+1))
            {
                v.push_back(root);
                return true;
            }
        if(root->right!=nullptr)
            if(padri(root->right,p,v,h+1))
            {
                v.push_back(root);
                return true;
            }
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        padri(root,p,padriP,0);
        hP=lol;
        padri(root,q,padriQ,0);
        hQ=lol;
        int indiceP=0;
        int indiceQ=0;
        for(auto x: padriP)
            cout<<x->val<<" ";
        cout<<endl;
        for(auto x: padriQ)
            cout<<x->val<<" ";
        cout<<endl;

        while(hP>hQ)
        {
            indiceP++;
            hP--;
            if(padriP[indiceP]==q)
                return q;
        }
        while(hQ>hP)
        {
            
            indiceQ++;
            hQ--;
            if(padriQ[indiceQ]==p)
                return p;
            
        }
        for(int i=0;i+indiceP<padriP.size()&&i+indiceQ<padriQ.size();i++)
        {
            if(padriP[i+indiceP]==padriQ[i+indiceQ])
            {
                return padriP[i+indiceP];
            }
        }
        return nullptr;
    }
};
