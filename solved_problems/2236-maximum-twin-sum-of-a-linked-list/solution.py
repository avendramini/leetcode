# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def pairSum(self, head: Optional[ListNode]) -> int:
        l=[]
        while head!=None:
            l.append(head)
            head=head.next
        maxi=0
        for i, x in enumerate(l):
            maxi=max([maxi,x.val+l[len(l)-1-i].val])
        return maxi
        
