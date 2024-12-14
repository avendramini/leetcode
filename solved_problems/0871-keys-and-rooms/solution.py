class Solution:
    def canVisitAllRooms(self, rooms: List[List[int]]) -> bool:
        q=deque()
        q.append(0)
        vis=[0]*len(rooms)
        while len(q)>0:
            vis[q[0]]=1
            for x in rooms[q[0]]:
                if not vis[x]:
                    q.append(x)
            q.popleft()
        
        for x in vis:
            if not x:
                return False
        return True 

