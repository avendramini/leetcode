class Solution:
    def maxChunksToSorted(self, arr: List[int]) -> int:
        cont=0
        start=0
        massimo=-1
        for i,x in enumerate(arr):
            massimo=max([massimo,x])
            if massimo==i:
                massimo=-1
                cont+=1
        return cont