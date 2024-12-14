class Solution:
    def predictPartyVictory(self, senate: str) -> str:
        q=deque()
        rcont=0
        dcont=0
        for x in senate:
            q.append(x)
            if x=='R':
                rcont+=1
            else:
                dcont+=1
        if dcont==0:
            return 'Radiant'
        elif rcont==0:
            return 'Dire'
        rban=0
        dban=0
        rtoban=0
        dtoban=0
        while len(q)>0:
            p=q[0]
            q.popleft()
            if p=='R':
                if rtoban>0:
                    rtoban-=1
                    rban+=1
                else:
                    dtoban+=1
                    q.append(p)
            else:
                if dtoban>0:
                    dtoban-=1
                    dban+=1
                else:
                    rtoban+=1
                    q.append(p)
            if dban==dcont:
                return 'Radiant'
            elif rban==rcont:
                return 'Dire'
        return 'Radiant'
