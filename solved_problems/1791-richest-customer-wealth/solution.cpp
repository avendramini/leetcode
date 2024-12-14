class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int massimo=-1e9;
        for(int i=0;i<accounts.size();i++)
        {
            int n=0;
            for(int j=0;j<accounts[i].size();j++)
            {
                n+=accounts[i][j];
            }
            massimo=max(massimo,n);
        }
        return massimo;
    }
};
