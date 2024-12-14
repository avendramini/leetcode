class Solution:
    def findCircleNum(self, isConnected: List[List[int]]) -> int:
        vis= [0]*len(isConnected)
        cont=0
        for i in range(0,len(isConnected)):
            if vis[i]:
                continue
            q=deque()
            q.append(i)
            while len(q)>0:
                top=q[0]
                q.popleft()
                vis[top]=True
                for j in range(0,len(isConnected)):
                    if not vis[j] and isConnected[top][j]:
                        q.append(j)
            cont+=1
        return cont

