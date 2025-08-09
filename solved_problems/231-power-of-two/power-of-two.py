class Solution:
    def isPowerOfTwo(self, n: int) -> bool:
        if(n==0):
            return False
        negative=False
        if n<0:
            negative=True
        if negative:
            x=int(log2(-n))
            if((2**-x)==n):
                return True
        else:
            x=int(log2(n))
            if((2**x)==n):
                return True
        return False