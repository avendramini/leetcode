class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long l=1;
        long long r=1e9;
        long long risp=1e9;
        while(l<=r)
        {
            long long mid=(l+r)/2;
            long long tot=0;
            for(auto x: piles)
            {
                tot+=ceil((x+0.0)/(mid+0.0));
            }
            if(tot<=h)
            {
                risp=min(risp,mid);
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        return risp;
    }
};
