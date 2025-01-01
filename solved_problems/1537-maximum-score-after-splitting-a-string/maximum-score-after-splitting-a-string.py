class Solution:
    def maxScore(self, s: str) -> int:
        zero=s.count('0')
        uno=s.count('1')
        attzero=0
        attuno=0
        massimo=0
        for i,x in enumerate(s):
            if i==len(s)-1:
                continue
            if x=='0':
                attzero+=1
            else:
                attuno+=1
            massimo=max([massimo,attzero+uno-attuno])
        return massimo
