class Solution:
    def distinctNumbers(self, nums: List[int], k: int) -> List[int]:
        m={}
        if k>len(nums):
            return []
        for i in range(k):
            if nums[i] in m:
                m[nums[i]]+=1
            else:
                m[nums[i]]=1
        l=[]
        l.append(len(m))
        for i in range(k,len(nums)):
            if nums[i] in m:
                m[nums[i]]+=1
            else:
                m[nums[i]]=1
            if m[nums[i-k]]==1:
                del m[nums[i-k]]
            else:
                m[nums[i-k]]-=1
            l.append(len(m))
        return l
