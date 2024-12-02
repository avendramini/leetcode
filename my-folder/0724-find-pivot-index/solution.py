class Solution:
    def pivotIndex(self, nums: List[int]) -> int:
        tot=sum(nums)
        att=0
        i=0
        for x in nums:
            if (tot-x)/2==att:
                return i
            i+=1
            att+=x
        return -1
