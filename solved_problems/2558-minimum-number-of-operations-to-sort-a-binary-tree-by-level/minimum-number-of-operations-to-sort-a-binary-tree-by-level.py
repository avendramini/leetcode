# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def minimumOperations(self, root: Optional[TreeNode]) -> int:
        q=deque()
        level=[]
        q.appendleft(root)
        inseriti=1
        ris=0
        while len(q)>0:
            top=q[0]
            q.popleft()
            level.append((top.val,len(level)))
            inseriti-=1
            print(inseriti)
            if top.left!=None:
                q.append(top.left)
            if top.right!=None:
                q.append(top.right)
            if inseriti==0:
                inseriti=len(q)
                if len(level)!=1:
                    vis=[False]*len(level)
                    level.sort(key=lambda x: x[0])
                    for i,x in enumerate(level):
                        if vis[i]:
                            continue
                        j=i
                        ciclo=0
                        while not vis[j]:
                            vis[j]=True
                            j=level[j][1]
                            ciclo+=1
                        ris+=ciclo-1
                    
                level=[]
        return ris

