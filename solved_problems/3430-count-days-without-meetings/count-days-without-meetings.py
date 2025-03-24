class Solution:
    def countDays(self, days: int, meetings: List[List[int]]) -> int:
        start=1
        
        meetings=sorted(meetings)
        ris=0
        for i,x in enumerate(meetings):
            if x[0]>start:
                if i==0:
                    ris+=1
                ris+=x[0]-start-1
            start=max([start,x[1]])
        ris+=days-start
        return ris
