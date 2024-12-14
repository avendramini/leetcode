class Solution {
public:
    int candy(vector<int>& ratings) 
    {
        int n=ratings.size();
        int tot=0;
        vector<int> lvl(n,1);
        int minimo=0;
        lvl[0]=1;
        for(int i=1;i<n;i++)
        {
            if(ratings[i]>ratings[i-1])
            {
                lvl[i]=lvl[i-1]+1;
            }
        }
        for(int i=n-1;i>0;i--)
        {
            if(ratings[i-1]>ratings[i])
                lvl[i-1]=max(lvl[i]+1,lvl[i-1]);
        }
        for(auto x: lvl)
        {
            tot+=x;
        }
        return tot;

    }
};
