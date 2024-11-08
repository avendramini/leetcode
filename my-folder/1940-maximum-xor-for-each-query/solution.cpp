class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) 
    {
        vector<int> cont(20,0);
        for(auto x : nums)
        {
            bitset<20> b(x);
            for(int i=0;i<maximumBit;i++)
            {
                cont[i]+=b[i];
            }
        }
        vector<int> ris;
        int start=0;
        int end=nums.size()-1;
        for(int q=0;q<nums.size();q++)
        {
            int k=0;
            int pow=1;
            for(int i=0;i<maximumBit;i++)
            {
                if(cont[i]%2==0)
                {
                    k+=pow;
                }
                pow*=2;
            }

            ris.push_back(k);
            bitset<20> b(nums[end]);
            for(int i=0;i<maximumBit;i++)
            {
                cont[i]-=b[i];
            }
            end--;
        }
        return ris;

    }
};
