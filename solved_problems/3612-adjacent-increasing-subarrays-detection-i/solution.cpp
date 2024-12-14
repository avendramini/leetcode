class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        if(nums.size()<=1)
            return false;
        if(k==1)
        {
            return true;
        }
        
        for(int i=0;i<nums.size();i++)
            {
                if(i+2*k>nums.size())
                    continue;
                int l=1;
                bool ok =true;
                while(l<k)
                    {
                        if(nums[i+l]<=nums[i+l-1])
                            ok=false;
                        l++;
                    }
                l++;
                while(l<2*k){
                    if(nums[i+l]<=nums[i+l-1])
                        ok=false;
                    l++;
                }
                if(ok)
                    return true;
            }
        return false;
    }
};
