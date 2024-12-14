class Solution:
    def closeStrings(self, word1: str, word2: str) -> bool:
        d1=dict()
        d2=dict()
        for x in word1:
            if x in d1:
                d1[x]+=1
            else:
                d1[x]=1
        for x in word2:
            if x in d2:
                d2[x]+=1
            else:
                d2[x]=1
        
        x=sorted(d1.values())
        x1=sorted(d2.values())
        
        return x==x1 and sorted(d1.keys())==sorted(d2.keys())

