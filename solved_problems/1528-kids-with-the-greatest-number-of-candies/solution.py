class Solution:
    def kidsWithCandies(self, candies: List[int], extraCandies: int) -> List[bool]:
        att=max(candies)
        result=[]
        for x in candies:
            if x==att:
                result.append(True)
            elif x+extraCandies>=att:
                result.append(True)
            else:
                result.append(False)
        return result
