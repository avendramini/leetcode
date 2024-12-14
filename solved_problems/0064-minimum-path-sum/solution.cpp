class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int > > dp(grid.size(),vector<int>(grid[0].size(),1e9));
        dp[0][0]=grid[0][0];
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(j-1>=0)
                {
                    dp[i][j]=min(dp[i][j],dp[i][j-1]+grid[i][j]);
                }
                if(i-1>=0)
                {
                    dp[i][j]=min(dp[i][j],dp[i-1][j]+grid[i][j]);
                }
            }
        }
        return dp[n-1][m-1];
    }
};
