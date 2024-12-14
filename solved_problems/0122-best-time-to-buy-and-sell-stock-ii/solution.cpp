class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int n=prices.size();
        int tot=0;
        for(int i=0;i<prices.size();i++)
        {
            int j=i+1;
            while(j<n&&prices[j]>=prices[j-1])
            {
                j++;
            }
            tot+=prices[j-1]-prices[i];
            i=j-1;
        }
        return tot;
    }
};
