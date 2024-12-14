# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def goodNodes(self, root: TreeNode, maximum=-1e9) -> int:
        
        if root==None:
            return 0
        
        cont=int(root.val>=maximum)
        if cont==1:
            print(root.val)
        cont+=self.goodNodes(root.left,maximum=max([maximum,root.val]))
        cont+=self.goodNodes(root.right,maximum=max([maximum,root.val]))
        return cont

