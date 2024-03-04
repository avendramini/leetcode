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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* start=head;
        bool primo=true;
        ListNode* att=head;
        ListNode* prec=head;
        while(att!=nullptr)
        {
            if(att->next!=nullptr&&att->val==att->next->val)
            {
                int val=att->val;
                while(att!=nullptr&&att->val==val)
                    att=att->next;
                prec->next=att;
                if(primo)
                {
                    start=att;
                }
            }
            else
            {
                prec=att;
                att=att->next;
                primo=false;
            }
        }
        return start;
    }
};
