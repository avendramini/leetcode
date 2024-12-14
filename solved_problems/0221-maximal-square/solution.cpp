class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) 
    {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int> > dp(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i-1>=0)
                {
                    dp[i][j]+=dp[i-1][j];
                }
                if(j-1>=0)
                    dp[i][j]+=dp[i][j-1];
                if(i-1>=0&&j-1>=0)
                    dp[i][j]-=dp[i-1][j-1];
                dp[i][j]+=matrix[i][j]-'0';
            }
        }
        int massimo=0;
        if(dp[0][0]==1)
        massimo=1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                for(int l=0;l<n;l++)
                {
                    if(j+l>=m||i+l>=n)
                    {
                        break;
                    }
                    
                    int sum=dp[i+l][j+l];
                    if(j-1>=0)
                    sum-=dp[i+l][j-1];
                    if(i-1>=0)
                    sum-=dp[i-1][j+l];
                    if(i-1>=0&&j-1>=0)
                    sum+=dp[i-1][j-1];
                    if(sum==(l+1)*(l+1))
                        massimo=max(massimo,sum);
                    else
                        break;
                    
                    
                }
            }
        }
        return massimo;


        return 0;
    }
};
