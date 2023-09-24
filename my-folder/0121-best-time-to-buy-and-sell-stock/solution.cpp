class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int tot=0;
        int n=prices.size();
        int massimi[n+1];
        massimi[n]=0;
        for(int i=n-1;i>=0;i--)
        {
            massimi[i]=max(prices[i],massimi[i+1]);
        }
        for(int i=0;i<n-1;i++)
        {
            tot=max(tot,massimi[i+1]-prices[i]);
        }
        return tot;
    }
};
