class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        vector<vector<int> > dp(n,vector<int>(m,0));
        dp[0][0]=1;
        if(obstacleGrid[0][0])
            return 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(obstacleGrid[i][j]==0)
                {
                    if(i-1>=0)
                    {
                        dp[i][j]+=dp[i-1][j];
                    }
                    if(j-1>=0)
                    {
                        dp[i][j]+=dp[i][j-1];
                    }
                }
            }
        }
        return dp[n-1][m-1];
    }
};
