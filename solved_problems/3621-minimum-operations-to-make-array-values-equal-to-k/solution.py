class Solution:
    def minOperations(self, nums: List[int], k: int) -> int:
        ok=list(sorted(set(nums)))
        steps=0
        for x in ok:
            if x<k:
                return -1
            else: steps+=1
        return steps- int(k in ok)
