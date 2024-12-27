class Solution:
    def isMajorityElement(self, nums: List[int], target: int) -> bool:
        low=0
        up=len(nums)-1
        start=len(nums)//2
        if nums[start]!=target:
            return False
        while low<=up:
            mid=(low+up)//2
            if nums[mid]==nums[len(nums)//2]:
                start=mid
                up=mid-1
            else:
                low=mid+1
        low=0
        up=len(nums)-1
        end=len(nums)//2
        while low<=up:
            mid=(low+up)//2
            if nums[mid]==nums[len(nums)//2]:
                end=mid
                low=mid+1
            else:
                up=mid-1
        
        return (end-start+1)>len(nums)/2