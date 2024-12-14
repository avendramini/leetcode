/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    map<Node*,Node*> ris;
    map<Node* , bool> vis;
    Node* cloneGraph(Node* node) {
        if(node==nullptr)
            return nullptr;
        Node* clone=new Node;
        clone->val=node->val;
        ris[node]=clone;
        vis[node]=true;
        for(auto x: node->neighbors)
        {
            if(!vis[x])
                clone->neighbors.push_back(cloneGraph(x));
            else
                clone->neighbors.push_back(ris[x]);
        }
        return clone;
    }
};
