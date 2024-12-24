# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def delete(self, head,m,n, attm,attn,salvo):
        if head==None:
            return None
        if salvo:
            if attm==1:
                head.next=self.delete(head.next,m,n,m,attn,False)
            else:
                head.next=self.delete(head.next,m,n,attm-1,n,True)
            return head
        else:
            if attn==1:
                return self.delete(head.next,m,n,attm,n,True)
            return self.delete(head.next,m,n,attm,attn-1,False)
        return None
    def deleteNodes(self, head: Optional[ListNode], m: int, n: int) -> Optional[ListNode]:
        return self.delete(head,m,n,m,n,True)
        