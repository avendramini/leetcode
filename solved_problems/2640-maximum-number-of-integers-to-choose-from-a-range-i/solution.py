class Solution:
    def maxCount(self, banned: List[int], n: int, maxSum: int) -> int:
        
        mb={}
        for x in banned:
            if x<=n:
                mb[x]=True
        att=n*(n+1)/2 - sum(mb.keys())
        togliere=0
        tot=n-len(mb.keys())
        if att<=maxSum:
            return tot
        for i in range(n,0,-1):
            if not i in mb:
                togliere+=i
                tot-=1
                if att-togliere<=maxSum:
                    return tot
        
        return 0
