/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        map<ListNode*, bool> m;
        while(headA!=nullptr)
            {
                m[headA]=true;
                headA=headA->next;
            }
        while(headB!=nullptr)
        {
           if(m[headB])
            return headB;
            headB=headB->next;
        }
        return nullptr;
    }
};
