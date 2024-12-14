class Solution:
    def maximumLength(self, s: str) -> int:
        m={}
        i=0
        while i<len(s):
            j=i
            while j<len(s) and s[j]==s[i]:
                j+=1
            
            if not s[i] in m:
                m[s[i]]=[0]*50
            for k in range(0,j-i):
                m[s[i]][k]+=(j-i-k)
            i=j
        print(m)
        massimo=-1
        for x in m.values():
            cont=0
            for k in x:
                if k>=3:
                    massimo=max([massimo,cont+1])
                cont+=1
        return massimo

