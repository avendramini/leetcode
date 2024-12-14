class Solution:
    def stringShift(self, s: str, shift: List[List[int]]) -> str:
        cnt=0
        for x in shift:
            if x[0]==0:
                cnt-=x[1]
            else:
                cnt+=x[1]
        l=[' ']*len(s)
        for i,x in enumerate(s):
            l[(i+cnt+len(s))%len(s)]=x
        ris=""
        for x in l:
            ris+=str(x)
        return ris
        
        
