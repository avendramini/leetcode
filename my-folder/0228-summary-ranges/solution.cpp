class Solution {
    #define ll long long
public:
    vector<string> summaryRanges(vector<int>& nums) {
        
        ll n=nums.size();
        vector<string> ris;
        for(int i =0;i<n;)
        {
            ll start=nums[i];
            ll scorso=nums[i];
            i++;
            while(i<n && nums[i]-scorso==1)
            {
                scorso=nums[i];
                i++;
            }
            if(scorso==start)
                ris.push_back(to_string(scorso));
            else
                ris.push_back(to_string(start)+"->"+to_string(scorso));
        }
        return ris;
    }
};
