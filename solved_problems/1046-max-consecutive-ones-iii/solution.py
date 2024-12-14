class Solution:
    def longestOnes(self, nums: List[int], k: int) -> int:
        zero=0
        start=0
        end=0
        ris=0
        ok=False
        for x in nums:
            ok|=x
        if not ok:
            return k
        for i in range(0,len(nums)):
            if nums[i]==0:
                zero+=1
            end+=1
            if zero>=k:
                break
        if zero<=k:
            ris=end-start
        print(f"{start}-{end}")
        for fine in range(end,len(nums)):
            if nums[fine]==0:
                zero+=1
            while start<fine and zero>k:
                if nums[start]==0:
                    zero-=1
                start+=1
            print(f"{start}-{fine+1}")
            ris=max([ris,fine+1-start])
        return ris
