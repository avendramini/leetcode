class Solution:
    def countGoodStrings(self, low: int, high: int, zero: int, one: int) -> int:
        MOD=int(1e9+7)
        dp=[0 for _ in range(high+1)]
        dp[0]=1
        for i in range(1,high+1):
            if i-zero>=0:
                dp[i]+=dp[i-zero]
            dp[i]%=MOD
            if i-one>=0:
                dp[i]+=dp[i-one]
            dp[i]%=MOD
        
        ris=0
        for i in range(low,high+1):
            #print(dp[i])
            ris+=dp[i]
            ris%=MOD
        return ris