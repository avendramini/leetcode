class Solution:
    def isOneEditDistance(self, s: str, t: str) -> bool:
        if s==t:
            return False
        if len(s)==len(t):
            if len(s)==1:
                return True
            cont=0
            for i,x in enumerate(s):
                if x!=t[i]:
                    cont+=1
            return cont==1
        if len(s)>len(t):
            swap=s
            s=t
            t=swap
        if len(s)==len(t)-1:
            if len(t)==1:
                return True
            skip=0
            i=0
            while i<len(s):

                if s[i]!=t[i+skip]:
                    skip+=1
                    i-=1
                if skip>=2:
                    return False
                i+=1
            
            return skip<2
        return False
                    
                