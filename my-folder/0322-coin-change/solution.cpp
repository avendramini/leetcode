class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        sort(coins.begin(),coins.end());
        vector<vector<long long> > dp(amount+1,vector<long long>(n,1e9));
        for(int i=0;i<n;i++)
            dp[0][i]=0;
        for(int l=1;l<=amount;l++)
        {
            for(int i=0;i<n;i++)
            {
                if(l-coins[i]>=0)
                {
                    dp[l][i]=min(dp[l-coins[i]][i]+1,dp[l][i]);
                }
                if(i-1>=0)
                dp[l][i]=min(dp[l][i],dp[l][i-1]);
            }
        }
        if(dp[amount][n-1]==1e9)
            return -1;
        return dp[amount][n-1];   
    }
};
