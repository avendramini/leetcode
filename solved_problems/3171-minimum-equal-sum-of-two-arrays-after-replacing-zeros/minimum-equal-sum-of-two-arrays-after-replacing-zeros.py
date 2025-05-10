class Solution:
    def minSum(self, nums1: List[int], nums2: List[int]) -> int:
        count1=0
        somma1=0
        for x in nums1:
            somma1+=x
            if x ==0:
                count1+=1
        count2=0
        somma2=0
        for x in nums2:
            somma2+=x
            if x==0:
                count2+=1
        if(count1==0 and count2==0):
            return -1 if somma1!=somma2 else somma1
        if (somma1<=somma2 and count1==0) or (somma1>somma2 and count2==0) or (somma1<=somma2 and count2==0 and count1>somma2-somma1) or (somma1>somma2 and count1==0 and count2>somma1-somma2):
            return -1
        return max(somma1+count1,somma2+count2)