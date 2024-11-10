class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) 
    {
        for(auto x: nums)
            if(x>=k)
                return 1;
            
        int start=0;
        int end=0;
        bitset<32> b(nums[0]);
        vector<int> count;
        for(int i=0;i<32;i++)
            count.push_back(b[i]);
        while(end<nums.size()-1&&b.to_ulong()<k)
        {
            bitset<32> newb(nums[end+1]);
            for(int i=0;i<32;i++)
            {
                count[i]+=newb[i];
                if(b[i]==0&&newb[i])
                    b[i]=1;
            }
            end++;
        }
        if(b.to_ulong()<k)
            return -1;
        int ris=end-start+1;

        while(start<nums.size()-1)
        {
            bitset<32> newb(nums[start]);
            for(int i=0;i<32;i++)
            {
                count[i]-=newb[i];
                if(count[i]==0)
                    b[i]=0;
            }
            start++;
            while(end<nums.size()-1&&b.to_ulong()<k)
            {
                bitset<32> newb(nums[end+1]);
                for(int i=0;i<32;i++)
                {
                    count[i]+=newb[i];
                    if(b[i]==0&&newb[i])
                        b[i]=1;
                }
                end++;
            }
            if(b.to_ulong()>=k)
             ris=min(ris, end-start+1);
        }
        return ris;
    }
};
