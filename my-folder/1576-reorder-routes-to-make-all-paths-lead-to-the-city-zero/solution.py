class Solution:
    def minReorder(self, n: int, connections: List[List[int]]) -> int:
        adj = {i: [] for i in range(len(connections)+1)}
        for x in connections:
            adj[x[0]].append([x[1],1])
            adj[x[1]].append([x[0],0])
        print(adj[0])
        tot=0
        q=deque()
        q.append(0)
        vis=[0]*(len(connections)+1)
        while len(q)>0:
            top=q[0]
            q.popleft()
            vis[top]=True
            for x in adj[top]:
                if not vis[x[0]]:
                    tot+=x[1]
                    q.append(x[0])


        return tot
        
