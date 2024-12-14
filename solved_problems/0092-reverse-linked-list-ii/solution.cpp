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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        left--;
        right--;
        if(left==right)
        return head;
        ListNode* att=head;
        ListNode* prec=nullptr;
        ListNode* prox=head->next;
        int i=0;
        while(i<left&&att!=nullptr)
        {
            prec=att;
            att=prox;
            prox=att->next;
            i++;
        }
        vector<ListNode*> ris;
        ListNode* inizio=prec;
        ris.push_back(att);
        while(i<right&&att!=nullptr)
        {
            prec=att;
            att=prox;
            prox=att->next;
            ris.push_back(att);
            i++;
        }
        ListNode* fine=prox;
        if(left!=0)
        inizio->next=ris[ris.size()-1];
        else
        head=ris[ris.size()-1];
        for(int j=ris.size()-1;j>=1;j--)
        {
            ris[j]->next=ris[j-1];
        }
        ris[0]->next=fine;

        return head;
        

    }
};
