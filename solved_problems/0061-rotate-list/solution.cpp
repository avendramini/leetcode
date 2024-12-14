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
    ListNode* rotateRight(ListNode* head, int k) 
    {
        vector<ListNode*> list;
        while(head!=nullptr)
        {
            list.push_back(head);
            head=head->next;
        }
        if(list.size()==0)
            return nullptr;
                if(k==0)
            return list[0];
        k=k%list.size();
        if(k==0)
            return list[0];
        if(list.size()==0)
            return list[0];
        ListNode* start=list[list.size()-k];
        ListNode* last=list[list.size()-k-1];
        list[list.size()-1]->next=list[0];
        last->next=nullptr;
        return start;
    }
};
