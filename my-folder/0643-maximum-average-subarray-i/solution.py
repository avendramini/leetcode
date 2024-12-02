class Solution:
    def findMaxAverage(self, nums: List[int], k: int) -> float:
        
        somma=sum(nums[0:k])
        mag=somma/k
        for i in range(k,len(nums)):
            somma-=nums[i-k]
            somma+=nums[i]
            if somma/k> mag:
                mag=somma/k
        return mag


