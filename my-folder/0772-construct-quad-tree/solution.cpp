/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* create(vector<vector<int>>& grid,int a,int y, int lato)
    {
        Node* x= new Node;
        if(lato==1)
        {
            x->val=grid[a][y];
            x->isLeaf=true;
            return x;
        }
        Node* lu=create(grid,a,y,lato/2);
        Node* ld=create(grid,a+lato/2,y,lato/2);
        Node * ru=create(grid,a,y+lato/2,lato/2);
        Node* rd=create(grid,a+lato/2,y+lato/2,lato/2);
        if(lu->isLeaf&&ld->isLeaf&&ru->isLeaf&&rd->isLeaf)
        {
            if(lu->val==ld->val&&ld->val==ru->val&&ru->val==rd->val)
            {
                x->isLeaf=true;
                x->val=lu->val;
                delete lu;
                delete ld;
                delete ru;
                delete rd;
            }
            else
            {
                x->isLeaf=false;
                x->topLeft=lu;
                x->topRight=ru;
                x->bottomLeft=ld;
                x->bottomRight=rd;
            }
        }
        else
        {
            x->isLeaf=false;
            x->topLeft=lu;
            x->topRight=ru;
            x->bottomLeft=ld;
            x->bottomRight=rd;
        }
        return x;
    }
    Node* construct(vector<vector<int>>& grid) {
        return create(grid,0,0,grid.size());
    }
};
