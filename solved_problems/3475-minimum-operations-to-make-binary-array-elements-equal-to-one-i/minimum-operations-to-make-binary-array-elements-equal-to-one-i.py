from typing import List

class Solution:
    def minOperations(self, nums: List[int]) -> int:
        operations = 0
        
        for i in range(len(nums)):
            if nums[i] == 0:
                if i > len(nums) - 3:
                    return -1  # If we can't flip a full triplet, it's impossible
                
                # Flip the triplet
                nums[i] = 1 - nums[i]
                nums[i+1] = 1 - nums[i+1]
                nums[i+2] = 1 - nums[i+2]
                operations += 1
        
        return operations