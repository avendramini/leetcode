# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def findPath(self, root, val, path):
        if root==None:
            return False
        if root.val==val.val:
            path.append(root)
            return True
        if self.findPath(root.left, val, path) or self.findPath(root.right, val, path):
            path.append(root)
            return True
        return False
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        path1=[]
        self.findPath(root, p, path1)
        path2=[]
        self.findPath(root, q, path2)
        if path1==[] or path2==[] or path1[len(path1)-1]!=path2[len(path2)-1]:
            return False
        i=len(path1)-1
        j=len(path2)-1
        
        for _ in range(max([len(path1),len(path2)])):
            if i==-1:
                return path1[0]
            elif j==-1:
                return path2[0]
                
            if path1[i].val!=path2[j].val:
                return path1[i+1]
            i-=1
            j-=1
        
        return None