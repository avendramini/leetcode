class Solution {
public:
    vector<vector<int>> dp;
    int rico(int pos,int vendi,vector<int>& prices)
    {
        if(pos>=prices.size())
        {
            if(vendi==1)
            return dp[pos][vendi]=-1e9;
            return dp[pos][vendi]=0;
        }
        if(dp[pos][vendi]!=-1e9)
            return dp[pos][vendi];
        int massimo=-1e9;
        if(vendi==0)
        {
            massimo=max(massimo,rico(pos+1,vendi,prices));
            massimo=max(massimo,rico(pos+1,1,prices)-prices[pos]);
        }
        else
        {
            massimo=max(massimo,rico(pos+1,vendi,prices));
            massimo=max(massimo,rico(pos+2,0,prices)+prices[pos]);
        }
        return dp[pos][vendi]=massimo;

    }
    int maxProfit(vector<int>& prices) 
    {   
        
        dp.assign(prices.size()+2,vector<int>(2,-1e9));
        return rico(0,0,prices);
    }
};
