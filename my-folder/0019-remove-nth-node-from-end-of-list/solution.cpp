/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        vector<ListNode*> lista;
        if(head==nullptr)
            return nullptr;
        while(head!=nullptr)
        {
            lista.push_back(head);
            head=head->next;
        }
        if(lista.size()==1)
            return nullptr;
        if((int)lista.size()-1-n>=0&&lista.size()-n+1<lista.size())
        {
            lista[lista.size()-1-n]->next=lista[lista.size()-n+1];
        }
        else if((int)lista.size()-1-n<0)
        {
            return lista[(int)lista.size()-n+1];
        }
        else if(lista.size()-n+1>=lista.size())
            lista[lista.size()-1-n]->next=nullptr;

        return lista[0];
    }
};
