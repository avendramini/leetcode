# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def oddEvenList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head or not head.next:
            return head

        # Initialize pointers for odd and even lists
        odd = head
        even = head.next
        even_head = even  # Save the start of the even list

        # Traverse and rearrange
        while even and even.next:
            odd.next = even.next
            odd = odd.next
            even.next = odd.next
            even = even.next

        # Merge odd and even lists
        odd.next = even_head

        return head
