# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def longestZigZag(self, root: Optional[TreeNode],att=0,prec=-1) -> int:
        if root==None:
            return 0
        if prec==-1:
            return max([att,self.longestZigZag(root.left,att=1,prec=0),self.longestZigZag(root.right,att=1,prec=1)])
        elif prec==0:
            return max([att,self.longestZigZag(root.left,att=1,prec=0),self.longestZigZag(root.right,att=att+1,prec=1)])
        else:
            return max([att,self.longestZigZag(root.left,att=att+1,prec=0),self.longestZigZag(root.right,att=1,prec=1)])


        
