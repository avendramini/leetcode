class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int> > dp(triangle.size(),vector<int>(triangle[triangle.size()-1].size(),1e9));
        dp[0][0]=triangle[0][0];
        for(int i=1;i<triangle.size();i++)
        {
            for(int j=0;j<triangle[i].size();j++)
            {
                dp[i][j]=min(dp[i-1][j]+triangle[i][j],dp[i][j]);
                if(j-1>=0)
                    dp[i][j]=min(dp[i-1][j-1]+triangle[i][j],dp[i][j]);
            }
        }
        int massimo=1e9;
        for(int i=0;i<triangle[triangle.size()-1].size();i++)
        massimo=min(massimo,dp[triangle.size()-1][i]);
        return massimo;
    }
};
