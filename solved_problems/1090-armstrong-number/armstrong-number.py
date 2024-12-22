class Solution:
    def isArmstrong(self, n: int) -> bool:
        c=n
        att=0
        digits=[]
        while c>0:
            digits.append(c%10)
            c//=10
        
        for x in digits:
            att+=x**len(digits)
        return att==n