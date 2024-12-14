class Solution:
    def isArraySpecial(self, nums: List[int], queries: List[List[int]]) -> List[bool]:
        prefix=[0]*len(nums)
        for i in range(1,len(nums)):
            prefix[i]=prefix[i-1]
            if nums[i]%2!=nums[i-1]%2:
                prefix[i]+=1
        ris=[]
        for x in queries:
            if x[0]==x[1]:
                ris.append(True)
            else:
                if prefix[x[1]]-prefix[x[0]]==x[1]-x[0]:
                    ris.append(True)
                else:
                    ris.append(False)
        return ris
