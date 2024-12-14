# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxLevelSum(self, root: Optional[TreeNode]) -> int:
        q=deque()
        sumx=0
        cont=1
        ris=-1e9
        level=1
        rislevel=1
        q.append(root)
        while(len(q)>0):
            x=q[0]
            q.popleft()
            
            sumx+=x.val
            cont-=1
            if x.left != None:
                q.append(x.left)
            if x.right != None:
                q.append(x.right)
            if cont==0:
                cont=len(q)
                if sumx>ris:
                    ris=sumx
                    rislevel=level
                level+=1
                sumx=0
        return rislevel
