class Solution:
    def longestSubarray(self, nums: List[int]) -> int:
        prefix=[0]*(len(nums)+1) #quindi prefix[i] mi dice quanti 1 ci sono prima di i (escluso)
        suffix=[0]*(len(nums)+1) #quindi suffix[i] mi dice quanti 1 ci sono dopo di i (incluso)
        for i,x in enumerate(nums):
            if nums[i]==1:
                prefix[i+1]=prefix[i]+1
            else:
                prefix[i+1]=0
        for i,x in enumerate(reversed(nums)):
            original_index=len(nums)-i-1
            if x==1:
                suffix[original_index]=suffix[original_index+1]+1
            else:
                suffix[original_index]=0

        print(prefix)
        print(suffix)
        ris=0
        ris=max([ris,max(prefix)-1,max(suffix)-1])

        for i,x in enumerate(nums):
            if x==0:
                ris=max([ris,prefix[i]+suffix[i+1]])
        
        return ris


