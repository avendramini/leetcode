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
    ListNode* ok(ListNode* l1,ListNode* l2,int agg)
    {
        if(l1==nullptr&&l2==nullptr&&agg==0)
            return nullptr;
        
        ListNode * nuovo=new ListNode;
        nuovo->val=agg;
        if(l1!=nullptr)
            nuovo->val+=l1->val;
        if(l2!=nullptr)
            nuovo->val+=l2->val;
        
        int resto=0;
        if(nuovo->val>9)
            resto=1;
        nuovo->val%=10;
        nuovo->next=ok((l1!=nullptr?l1->next:nullptr),(l2!=nullptr?l2->next:nullptr),resto);
        return nuovo;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return ok(l1,l2,0);   
    }
};
