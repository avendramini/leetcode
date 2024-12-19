class Solution:
    def maxChunksToSorted(self, arr: List[int]) -> int:
        cont=0
        maxim=-1
        for i,x in enumerate(arr):
            maxim=max([maxim,x])
            if maxim==i:
                maxim=-1
                cont+=1
        return cont
