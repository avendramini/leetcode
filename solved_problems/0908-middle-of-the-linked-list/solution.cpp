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
    ListNode* middleNode(ListNode* head) {
        ListNode* app=head;
        int n=0;
        while(app!=nullptr)
        {
            n++;
            app=app->next;
        }
        app=head;
        for(int i=0;i<n/2;i++)
        {
            app=app->next;
        }
        return app;
    }
};
