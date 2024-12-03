# The guess API is already defined for you.
# @param num, your guess
# @return -1 if num is higher than the picked number
#          1 if num is lower than the picked number
#          otherwise return 0
# def guess(num: int) -> int:

class Solution:
    def guessNumber(self, n: int) -> int:
        low=0
        up=n
        while True:
            mid=int((low+up)/2)
            ris=guess(mid)
            if ris==0:
                return int(mid)
            elif ris==1:
                low=mid+1
            else:
                up=mid-1
        return -1
