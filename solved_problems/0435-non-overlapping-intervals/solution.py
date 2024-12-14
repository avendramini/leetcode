class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        inverted=[]
        for x in intervals:
            inverted.append((x[1],x[0]))
        inverted=sorted(inverted)
        cont=0
        right=-1e9
        for x in inverted:
            if x[1]>=right:
                right=x[0]
            else:
                cont+=1

        return cont
