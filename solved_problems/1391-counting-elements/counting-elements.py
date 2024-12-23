class Solution:
    def countElements(self, arr: List[int]) -> int:
        m={}
        for x in arr:
            if x in m:
                m[x]+=1
            else:
                m[x]=1
        
        cont=0
        for x in m:
            if x+1 in m:
                cont+=m[x]
        return cont