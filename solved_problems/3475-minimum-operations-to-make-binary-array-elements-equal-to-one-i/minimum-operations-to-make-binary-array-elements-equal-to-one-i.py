class Solution:
    def minOperations(self, nums: List[int]) -> int:
        ris=0
        for i,x in enumerate(nums):
            if x ==0 and i<=len(nums)-3:
                nums[i]=1-nums[i]
                nums[i+1]=1-nums[i+1]
                nums[i+2]=1-nums[i+2]
                ris+=1
            if nums[i]==0:
                return -1
        return ris    