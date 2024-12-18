class Solution:
    def finalPrices(self, prices: List[int]) -> List[int]:
        s=deque()
        tot=prices.copy()
        for i in range(len(prices)-1,-1,-1):
            att=0
            while len(s)>0 and s[0]>prices[i]:
                s.popleft()
            if len(s)>0:
                att=s[0]
            tot[i]-=att
            s.appendleft(prices[i])
        return tot
