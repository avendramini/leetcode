class Solution:
    def highFive(self, items: List[List[int]]) -> List[List[int]]:
        m={}
        for x in items:
            if x[0] in m:
                m[x[0]].append(x[1])
            else:
                m[x[0]]=[x[1]]
        ris=[]
        for x in m:
            print(m[x])
            m[x]=sorted(m[x])
            ris.append([x,sum(m[x][-5:])//5])
        ris.sort(key=lambda x : x[0])
        return ris
        