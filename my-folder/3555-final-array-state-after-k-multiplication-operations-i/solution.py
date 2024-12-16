class Solution:
    def getFinalState(self, nums: List[int], k: int, multiplier: int) -> List[int]:
        ris=[]
        heap=[]
        for i,x in enumerate(nums):
            ris.append(x)
            heapq.heappush(heap,(x,i))
        while k>0:
            k-=1
            print(len(heap))
            top=heapq.heappop(heap)
            ris[top[1]]*=multiplier
            heapq.heappush(heap,(top[0]*multiplier,top[1]))
        return ris
        
