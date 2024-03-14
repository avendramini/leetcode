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
    ListNode* reverseList(ListNode* head) {
        if(head==nullptr)
            return nullptr;

        ListNode* att=head->next;
        ListNode* prec=head;
        ListNode* start=head;
        head->next=nullptr;
        while(att!=nullptr)
        {
            
            start=att;
            ListNode* next=att->next;
            att->next=prec;
            prec=att;
            att=next;
        }
        
        return start;
    }
};
