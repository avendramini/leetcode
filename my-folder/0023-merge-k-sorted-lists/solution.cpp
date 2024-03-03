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
    ListNode* merge(ListNode* a,ListNode* b)
    {
        if(a==nullptr)
            return b;
        if(b==nullptr)
            return a;
        ListNode* start=nullptr;
        if(a->val<=b->val)
        {
            start=a;
            a=a->next;
        }
        else
        {
            start=b;
            b=b->next;
        }
        ListNode* att=start;
        while(b!=nullptr&&a!=nullptr)
        {
            if(a->val<=b->val)
            {
                att->next=a;
                a=a->next;
            }
            else
            {
                att->next=b;
                b=b->next;
            }
            att=att->next;
        }
        if(a==nullptr)
            att->next=b;
        else if(b==nullptr)
            att->next=a;

        return start;
            
        
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<ListNode*> tot;
        for(auto x: lists)
            tot.push_back(x);
        while(tot.size()>1)
        {
            vector<ListNode*> rim;
            for(int i=0;i<tot.size();i+=2)
            {
                
                if(i==tot.size()-1)
                    rim.push_back(tot[i]);
                else
                {
                    rim.push_back(merge(tot[i],tot[i+1]));
                }
            }
            tot.resize(0);
            for(auto x: rim)
                tot.push_back(x);

        }
        if(tot.size()==0)
            return nullptr;
        return tot[0];
    }
};
