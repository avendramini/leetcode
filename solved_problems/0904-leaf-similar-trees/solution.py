# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def dfs(self, root1,lis)->None:

        if root1==None:
            return
        if root1.left==root1.right==None:
            lis.append(root1.val)
            return
        self.dfs(root1.left,lis)
        self.dfs(root1.right,lis)
        return


    def leafSimilar(self, root1: Optional[TreeNode], root2: Optional[TreeNode]) -> bool:
        lis1=[]
        lis2=[]
        self.dfs(root1,lis1)
        self.dfs(root2,lis2)
        return lis1==lis2
