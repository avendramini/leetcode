class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        n=len(cost)
        dp=[0 for _ in range(0,n+1)]
        dp[0]=0
        dp[1]=0
        for x in range(2,n+1):
            dp[x]=min(dp[x-1]+cost[x-1],dp[x-2]+cost[x-2])
        
        return dp[n]
        
        
