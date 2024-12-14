# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def rico(self,prec,head,cont,n):
        if head==None:
            return
        n[0]+=1
        self.rico(head,head.next,cont+1,n)
        if n[0]//2==cont:
            prec.next=head.next
            del head
        return

    def deleteMiddle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head==None or head.next==None:
            return None
        #if head.next.next==None:
            #return head.next
        self.rico(None,head,0,[0])
        return head
