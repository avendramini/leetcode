class Solution:
    def maxOperations(self, nums: List[int], k: int) -> int:
        m={}
        cont=0
        for x in nums:
            if k-x in m:
                if m[k-x]==1:
                    del m[k-x]
                else:
                    m[k-x]-=1
                cont+=1
            else:
                if x in m:
                    m[x]+=1
                else:
                    m[x]=1
        return cont
                
