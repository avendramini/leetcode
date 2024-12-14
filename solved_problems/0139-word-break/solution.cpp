class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        vector<bool> dp(n+1,false);
        dp[0]=true;
        for(int i=0;i<n;i++)
        {
            if(dp[i]==false)
                continue;
            string c="";
            for(int j=i;j<n;j++)
            {
                c+=s[j];
                for(int k=0;k<wordDict.size();k++)
                {
                    if(wordDict[k]==c){
                        dp[j+1]=max(dp[j],dp[i]);
                        break;
                    }
                }
            }
        }
        return dp[n];

    }
};
