class Solution:
    def canAttendMeetings(self, intervals: List[List[int]]) -> bool:
        if len(intervals)==0:
            return True
        intervals.sort(key=lambda x: x[0])
        last=0
        for x in intervals:
            if x[0]<last:
                return False
            last=x[1]
        return True