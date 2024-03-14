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
    void reorderList(ListNode* head) {
        vector<ListNode*> v;
        
        while(head!=nullptr)
            v.push_back(head),head=head->next,v[v.size()-1]->next=nullptr;
        
        ListNode* start=v[0];
        ListNode* att=start;
        int l=1;
        int r=v.size()-1;
        bool ok=false;
        while(l<=r)
        {
            if(ok){
                att->next=v[l];
                att=v[l];
                l++;
            }
            else
            {
                att->next=v[r];
                att=v[r];
                r--;
            }
            ok=!ok;
        }


    }
};
