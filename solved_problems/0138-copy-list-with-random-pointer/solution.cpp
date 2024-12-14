/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    map<Node*,Node*> corrispondente;
    Node* copyRandomList(Node* head) {
        Node* nuova;
        if(head==nullptr)
        return nullptr;
        nuova=new Node(head->val);
        Node* spost=nuova;
        Node * copia=head;
        corrispondente[head]=nuova;
        corrispondente[nullptr]=nullptr;
        while(copia->next!=nullptr)
        {
            Node* next=new Node(copia->next->val);
            corrispondente[copia->next]=next;
            spost->next=next;
            spost=spost->next;
            copia=copia->next;
        }
        copia=head;
        spost=nuova;
        while(copia!=nullptr)
        {
            spost->random=corrispondente[copia->random];
            spost=spost->next;
            copia=copia->next;
        }

        return nuova;


    }
};
