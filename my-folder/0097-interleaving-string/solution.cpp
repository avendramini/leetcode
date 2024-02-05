class Solution {
public:
    vector<vector<short> > dp;
    int n,m;
    string ss1,ss2,ss3;
    bool rico(int i,int j)
    {
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(i==n&&j==m)
            return dp[i][j]=true;
        bool ok=false;
        if(i!=n&&ss1[i]==ss3[i+j])
        {
            ok|=rico(i+1,j);
        }
        if(j!=m && ss2[j]==ss3[i+j])
            ok|=rico(i,j+1);
        return dp[i][j]=ok;
    }
    bool isInterleave(string s1, string s2, string s3) {
        n=s1.size();
        m=s2.size();
        ss1=s1;
        ss2=s2;
        ss3=s3;
        if(s3.size()!=n+m)
            return false;
        dp.assign(n+1,vector<short>(m+1,-1));
        return rico(0,0);
        
    }
};
