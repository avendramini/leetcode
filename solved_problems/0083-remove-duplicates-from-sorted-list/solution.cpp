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
        if(head==nullptr)
            return nullptr;
        ListNode* att=head->next;
        while(att!=nullptr&&att->val==head->val)
        {
            ListNode* app=att;
            att=app->next;
            delete app;
        }
        head->next=att;
        deleteDuplicates(att);
        return head;
    }
};
