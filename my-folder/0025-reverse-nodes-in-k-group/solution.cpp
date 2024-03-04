class Solution {
public:
ListNode* reversell(ListNode* head)
{
   // Initialize'temp' at
   // head of linked list
   ListNode* temp = head;  
   
   // Initialize pointer 'prev' to NULL,
   // representing the previous node
   ListNode* prev = NULL;  
   
   // Traverse the list, continue till
   // 'temp' reaches the end (NULL)
   while(temp != NULL){  
       // Store the next node in
       // 'front' to preserve the reference
       ListNode* front = temp->next;  
       
       // Reverse the direction of the
       // current node's 'next' pointer
       // to point to 'prev'
       temp->next = prev;  
       
        // Move 'prev' to the current
        // node for the next iteration
       prev = temp;  
       
        // Move 'temp' to the 'front' node
        // advancing the traversal
       temp = front; 
   }
   
   // Return the new head of
   // the reversed linked list
   return prev;  
}
ListNode* getknode(ListNode* temp, int k)
{
    k -= 1;
    while(temp!=NULL && k > 0)
    {
        k--;
        temp = temp->next;
    }
    return temp; 
}
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevlast = NULL;
        while(temp != nullptr)
        {
            ListNode* kthnode = getknode(temp,k);
            if(kthnode == nullptr)
            {
                if(prevlast)
                {
                    prevlast->next = temp;
                }
                break;
            }
            ListNode* nextnode = kthnode->next;
            kthnode->next = NULL;
            reversell(temp);
            if(temp == head)
            {
                head = kthnode;
            }
            else{
                prevlast->next = kthnode; 
            }
            prevlast = temp;
            temp = nextnode; 
        }
        return head;
    }
};
