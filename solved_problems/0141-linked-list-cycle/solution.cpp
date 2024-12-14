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
    bool hasCycle(ListNode *head) {
        map<ListNode*,bool> m;
        while(head!=nullptr&&m.count(head)==0)
        {
            m[head]=true;
            head=head->next;
        }
        if(m.count(head))
            return true;
        return false;
    }
};
