class Solution {
public:
vector<int> pric;
    int dp[1002][101][2];
    int prof(int pos, int rim,bool vendere)
    {
        if(dp[pos][rim][vendere]!=-1)
            return dp[pos][rim][vendere];
        if(pos==pric.size())
            return dp[pos][rim][vendere]=0;
        if(rim==0&&!vendere)
            return dp[pos][rim][vendere]=0;
        int tot=0;
        if(vendere)
        {
            tot=max(tot,prof(pos+1,rim,false)+pric[pos]);
        }
        else
        {
            tot=max(tot,prof(pos+1,rim-1,true)-pric[pos]);
        }
        tot=max(tot,prof(pos+1,rim,vendere));
        return dp[pos][rim][vendere]=tot;
    }
    int maxProfit(int k,vector<int>& prices) {
        pric=prices;
        for(int i=0;i<1002;i++)
        {
            for(int j=0;j<101;j++)
            {
                dp[i][j][0]=-1;
                dp[i][j][1]=-1;
            }
        }
        return prof(0,k,0);
    }
};
